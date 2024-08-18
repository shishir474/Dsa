# https://leetcode.com/problems/longest-substring-without-repeating-characters/



class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charset = set()
        ans, i = 0, 0
        for j in range(len(s)):
            while s[j] in charset:
                charset.remove(s[i])
                i+=1
            charset.add(s[j])
            ans = max(ans, j-i+1)
        return ans

#sliding window is a very good technique that helps us reduce the complexity to O(n)
# TC: O(n)
# SC: O(n) set stores all the characters of the string in the worst case