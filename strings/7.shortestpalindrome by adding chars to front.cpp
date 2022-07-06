 214. Shortest Palindrome
 You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"

 int longestPrefixSuffix(string s){
        int n = s.length();
        int lps[n];
        lps[0] = 0;
        int len = 0;
        int i=1;
        while (i<n){
            if (s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{  
                if (len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
       }
        
      return lps[n-1];
    }
    
    string shortestPalindrome(string s) {
       string t = s, ans = s;
       reverse(t.begin(), t.end());
       int l = longestPrefixSuffix(s+"$"+t);
       string add = s.substr(l);
       reverse(add.begin(), add.end());
       ans = add+ans;
       return ans;
           
    }