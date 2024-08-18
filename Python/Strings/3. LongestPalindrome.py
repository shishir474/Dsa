# Brute force solution
# Tc to check if a string is palindrome is O(n) and we have n^2 substring. So overall TC becomes: O(n^3) SC: O(1)

# Better solution
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        t = [[False for j in range(n)] for i in range(n)]

        # single length palindrome
        for i in range(n):
            t[i][i] = True
        
        # double length palindrome
        for i in range(n-1):
            if s[i]==s[i+1]:
                t[i][i+1] = True

        # fill the dp matrix from bottom to top 
        for i in range(n-3,-1,-1):
            for j in range(i+2,n):
                if s[i]==s[j] and t[i+1][j-1]==True:
                    t[i][j] = True


        # length, l, r
        ans = (float('-inf'),None, None)

        for i in range(n):
            for j in range(i,n):
                if t[i][j]==True:
                    if j-i+1 > ans[0]:
                        ans = (j-i+1, i, j)
        
        
        return s[ans[1]: ans[2]+1]
    
#  DP solution
# TC: O(n*n)
# SC: O(n*n)


# Optimised Solution:
# Instead of finding the substrings that start at the ith position, we will find the substrings that has ith char as the middle of the substring and then start expanding around this
# so basically we are calculating for each position how many substrings can be constructed considering ith as the middle pos

# https://www.youtube.com/watch?v=XYQecbcd6_c&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=55

class Solution:
    def longestPalindrome(self, s: str) -> str:
        # considering each position as the center of the string and then expanding around that 
        ans = ""
        ans_len = 0

        for i in range(len(s)): # O(n)
            # odd length string
            l,r = i,i # O(n)
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if r-l+1 > ans_len:
                    ans_len = r-l+1
                    ans = s[l:r+1]
                l-=1 # l moves towards left
                r+=1 # r moves towards right

            # even length string
            l,r = i,i+1 # O(n)
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if r-l+1 > ans_len:
                    ans_len = r-l+1
                    ans = s[l:r+1]
                l-=1
                r+=1
        
        return ans
        
# TC: O(n^2)
# SC: O(1)