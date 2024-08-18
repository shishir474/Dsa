# https://leetcode.com/problems/word-break/

# 139. Word Break

# Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

# Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

# Example 1:

# Input: s = "leetcode", wordDict = ["leet","code"]
# Output: true
# Explanation: Return true because "leetcode" can be segmented as "leet code".


# Brute force will give TLE
    # Start from the left and check if the s[0:i+1] is present in wordDict. Call recursion for s[i+1:] and if the recursion returns True, return True
    # otherwise check for all possibilities
#Memoise
    # for each idx we can memoise the value

class Solution:
    def __init__(self):
        self.dp = {}

    def solve(self, s, idx, wordDict):
        if len(s) == idx:
            return True
        
        if idx in self.dp:
            return self.dp[idx]

        ans = False
        for i in range(idx,len(s)):
            if s[idx:i+1] in wordDict:
                if self.solve(s, i+1, wordDict):
                    ans = True
                    break

        self.dp[idx] = ans
        return ans

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        return self.solve(s, 0, wordDict)
    
TC;
SC: O(n)