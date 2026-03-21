# https://leetcode.com/problems/longest-palindromic-substring/
class Solution:
    def expand_from_middle(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        
        return right - left - 1

    def longestPalindrome(self, s: str) -> str:
        # palindromes are summetrical around the center char
        # consider each char as the center and figure out how much you can expand around them
        n = len(s)  
        res_len = 0
        start, end = 0, 0

        for i in range(len(s)):
            len1 = self.expand_from_middle(s, i, i)        # odd length palindrome
            len2 = self.expand_from_middle(s, i, i+1)      # even length palindrome

            if max(len1, len2) > res_len:
                res_len = max(len1, len2)
                # find out the start and end coordinate using center point and res_len
                start  = i - ((res_len - 1) // 2)
                end = i + (res_len//2)

            # odd length: i center point, 
            # start  = i - [(len-1)/2]
            # end = i + (len/2)

            # even length: i, i+1 2 center points 
            # start  = i - [(len-1)/2]
            # end = i + (len/2)

            # imp part here is how you derive the start and end point using center
            # same start and end coordinates work both odd and even length strings
     
        

        return s[start : end+1]
    
    # TC: O(n^2)
    # SC: O(1)