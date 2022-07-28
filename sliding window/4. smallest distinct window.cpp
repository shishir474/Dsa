   Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"
 


Your Task:  
You dont need to read input or print anything. Your task is to complete the function findSubString() which takes the string  S as input and returns the length of the smallest such window of the string.


Expected Time Complexity: O(256.N)
Expected Auxiliary Space: O(256)


map and set were giving tle. HENCE used unordered_map and unordered_set


   int findSubString(string s)
    {
        unordered_set<char> set(s.begin(),s.end());
        
        int k=set.size();
        
        unordered_map<char,int> mp;
        
        int ans=s.length();
        
        int i=0,j=0;
        
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()==k){
                while(mp[s[i]]>1){
                    mp[s[i]]--;
                    i++;
                }
                ans = min(ans, j-i+1);
            }
            j++;
        }
        
        return ans;
        
    }