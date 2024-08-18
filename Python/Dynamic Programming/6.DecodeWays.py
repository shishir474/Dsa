# https://leetcode.com/problems/decode-ways/description/

# 91. Decode Ways


class Solution:
    def __init__(self):
        self.dp = {}
        self.mp = {}
        for i in range(1,27):
            self.mp[str(i)] = chr(64+i)
        # print(1, str(1))
        # print(65, str(65), chr(65))

    def solve(self, idx, s):
        if idx == len(s): # imp: return 1, found one possible breakage
            return 1
        if idx in self.dp:
            return self.dp[idx]

        ans = 0
        # pick the idx char only if it is valid
        if s[idx] in self.mp:
            ans += self.solve(idx+1,s)
        #pick the idx,idx+1 char only if the substr s[idx:idx+2] is valid, but before that check if the length of the string is atleast 2
        if idx<=len(s)-2 and s[idx:idx+2] in self.mp:
            ans += self.solve(idx+2,s)
        
        self.dp[idx] = ans
        return ans

    def numDecodings(self, s: str) -> int:
        return self.solve(0,s) # returns the no of ways in which we can decode the string
        
# Base case: when idx==len(s) which means we have reached the end of the string or can also be thuoght of as when empty string is given
    # we return 1
# The question quarantees that input string len >= 1. It means if we get empty string, it means we have found 1 valid combination
# hence we return 1 instead of returning 0 in the base case
# used dp, in order to avoid recomputation of the same indexes. 
# TC: O(n)
# SC: O(n) 