// THis problem can be solved using both KMP algorithm & Rabin Karp Algorithm 
214. Shortest Palindrome

You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.



// Solved using Rabin karp algorithm

In Rabin karp, we take the original input string s and its reverse string s1 
Now we try comparing the prefix of s with the suffix of s1. If they match then that prefix is a palindrome
We have to find the longest palindromic prefix 
String comparison is O(N) and doing this operation N times gonna be O(N^2)
Instead we are going to generate hash of the prefix and suffix string.
Integer comparison is O(1). SO instead of comparing string, we'll essentially compare the generated hash values(integers)

if the prefix & suff ix hash matches, then we have found a potential palindromic prefix. We have to find the longest prefix which is palindrome 



Brute Force Solutoin
class Solution {
public:
    bool isPalindrome(string s){
        int i=0, j = s.length()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    string shortestPalindrome(string s) {
        // trick here is to find the longest palindromic substring starting from 0th index and then we can add the remaining string from the input in front by reversing it 
        // Essentially the goal here is to find longest palindromic prefix (prefix obviously starts from 0th index)
        
        int n = s.length();

        if(n == 0) return "";
        // Brute force
        for(int i = n - 1; i>=0; i--){
            if(isPalindrome(s.substr(0,i+1))){      // this is the longest palindromic prefix
                string suffix = s.substr(i+1);
                reverse(suffix.begin(),suffix.end());
                return suffix + s;
            }   
        }


        return "";

        
    }
};



// RABIN KARP SOLUTION - https://www.youtube.com/watch?v=niOT-FK1RH8&ab_channel=NeetCodeIO

// Hash comparison is O(1) which is much more efficient than the string comparison which is O(N) & this is the idea on which Rabin karp is based on
// This algo uses the concept of rolling hash where we keep on computing the hash of each prefix and suffix

class Solution {
public:

    string shortestPalindrome(string s) {
        // trick here is to find the longest palindromic substring starting from 0th index and then we can add the remaining string from the input in front by reversing it 
        // Essentially the goal here is to find longest palindromic prefix (prefix obviously starts from 0th index)
        
        int n = s.length();
        const int mod = 1e9 + 7;

        if(n == 0) return "";
        
        // s, s1 = reverse(s)
        // we are essentially trying to match prefix of s and suffix of s1. If they match, then that prefix of s is a palindrome

        long long int prefix = 0, suffix = 0, base = 29, power = 1, last_index = 0;
        for(int i=0;i<n;i++){
            int ch =  s[i] - 'a' + 1;   // a->1, b->2, ... z-> 26

            // calculate the prefix and suffix hash
            prefix = (prefix * base)%mod; // left shift
            prefix = (prefix + ch)%mod;    // used mod to avoid overflow errors

            suffix = ((power * ch)%mod + suffix)%mod;
            power = ((power%mod) * (base%mod))%mod;

            // if prefix and suffix hash matches, then it this prefix is a palindrome
            if(prefix == suffix){   
                last_index = i;     // last_index essentially points to the last index of the longest palindromic prefix
            }
        }

        // extract the remaining suffix, reverse it and prepend it to the front of the original string
        string suffixStr = s.substr(last_index+1);
        reverse(suffixStr.begin(), suffixStr.end());
        return suffixStr + s;

        
    }
};

// TC: O(N) -- This is reduced from O(N^2) to O(N) because of the rolling hash techinique
// SC: O(N)







// KMP Solution -  https://www.youtube.com/watch?v=JoF0Z7nVSrA&ab_channel=NeetCode

In KMP first step is preprocessing and creating a lps[] which longest prefix suffix
lps[0] = 0; This is always 0
for lps[i], we never consider the entire prefix s[0..i]
lps[i] stores the longest prefix which is also a suffix for string s[0..i], but we never consider complete string s[0..i]

TC of KMP algorithm
    Building LPS[] O(2*n)
    Finding whether needle string exists in the haystack string O(n + m)

    Overall complexity : O(n + m)

Find the Index of the First Occurrence in a String - Leetcode 28



int solve(string haystack, string needle){
    // return the first index in haystack where needle is present. Brute force of doind this is O(n * m).
    // USING KMP this can be reduced to O(n + m)

    int n = haystack.size(), m =needle.size();

    // constructing lps[] -- preprocessing
    vector<int> lps(m,0);   // lps[0] will always be 0
    int prevLPS = 0;        // prevLPS is an index 
    for(int i=1;i<m;i++){
        // compare s[i] and s[prevLPS]
        if(s[i] == s[prevLPS]){
            lps[i] = prevLPS + 1;
            prevLPS += 1;
            i += 1;
        }
        else if(prevLPS == 0){
            lps[i] = 0;
            i += 1;
        }
        else{
            prevLPS = lps[prevLPS - 1];
        }
    }

    // Check if needle exists in haystack
    int i = 0, j = 0;   // 2 pointers i,j pointing to beginning of needle & haystack
    while(i < n){
        // if haystack[i] and needle[j] matches, increment i and j
        if(haystack[i] == needle[j]){       
            i++; j++;
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }

        // if j reaches end of needle string - we found the entire string
        if(j == m){
            return i - m;       // we basically need to return the starting point where we found the needle in haystack
        }

    }

    // needle not found
    return -1;


}





// SHORTEST PALINDROME SOLUTION 
    // USING KMP

class Solution {
public:
    int longestPrefixSuffix(string s){
        int m = s.length()
        vector<int> lps(m,0);   // lps[0] will always be 0
        int prevLPS = 0;        // prevLPS is an index 
        for(int i=1;i<m;i++){
            // compare s[i] and s[prevLPS]
            if(s[i] == s[prevLPS]){
                lps[i] = prevLPS + 1;
                prevLPS += 1;
                i += 1;
            }
            else if(prevLPS == 0){
                lps[i] = 0;
                i += 1;
            }
            else{
                prevLPS = lps[prevLPS - 1];
            }
        }

        return lps[m-1];        // this value indicates the length of the longest palindromic prefix.
        // obviously this is the prefix substring we are talking about essentially the s.substr(0, l + 1) where l = lps[m-1]
        // This is the longest palindromic prefix substring.
        // Brute force of finding this string is, consider each substring starting from the beginning and check if it's a palindrome which is O(n^2).
        // However, with KMP we can find it in O(n) time.
    }

    string shortestPalindrome(string s) {
        string t = s, ans = s;
        reverse(t.begin(), t.end());

        // find the lps(longest prefix suffix of s + "$" + rev(s))
        int l = longestPrefixSuffix(s+"$"+t);

        string add = s.substr(l);
        reverse(add.begin(), add.end());
        ans = add+ans;
        return ans;       
    }
}
