# Brute force : check each substring if it is a palindrome -> O(n^3)

# https://leetcode.com/problems/palindromic-substrings/

# https://www.youtube.com/watch?v=4RACzI5-du8&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=56

# Sol1:
    #  Using DP: TC: n^2, SC: n^2

# Optimised Solution
class Solution:
    def countPali(self, l, r, s):
        res = 0
        while(l>=0 and r<len(s) and s[l]==s[r]):
            res+=1
            l-=1
            r+=1
        
        return res

    def countSubstrings(self, s: str) -> int:
         # considering each position as the center of the string and then expanding around that 
        cnt = 0

        for i in range(len(s)): # O(n)
            # odd length palindrome
            cnt+=self.countPali(i,i,s)
            # even length palindrome
            cnt+=self.countPali(i,i+1,s)

        return cnt

# TC: O(n^2)
# SC: O(1)