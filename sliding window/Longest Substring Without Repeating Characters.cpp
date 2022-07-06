Longest Substring Without Repeating Characters

Solution
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


class Solution {
public:
    // BOTH SOLUTIONS ARE ACCEPTED, but 2nd one is more optimised
    int lengthOfLongestSubstring(string s) {
        
        if (s.length()==0) return 0; // empty string ans will be zero
        
        // otherwise ans is atleast one
        int i=0,j=0,ans=1;
        
        map<char,int> mp;
        
        while(j<s.length()){
            mp[s[j]]++;
            
            if (mp[s[j]] > 1){
                
                ans = max(ans,j-i);
                
                while(mp[s[j]] > 1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        
        ans=max(ans,j-i);  // IMP step consider case: "abcde" where no repeating char is present
        
        return ans;
    }    
};