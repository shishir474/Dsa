# https://leetcode.com/problems/rotate-image/

# https://www.youtube.com/watch?v=fMSJSS7eO1w&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=47

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l,r = 0,len(matrix)-1
        
        while l < r:
            t,b = l,r
            for i in range(r-l):
                #save top left in temp var
                topleft = matrix[t][l+i]

                # move bottom left to top left
                matrix[t][l+i] = matrix[b-i][l]

                #move bottom right to bottom left
                matrix[b-i][l] = matrix[b][r-i]

                #move top right to bottom right
                matrix[b][r-i] = matrix[t+i][r]

                # save topleft to topright
                matrix[t+i][r] = topleft
            
            l += 1
            r -= 1
            
# TC: O(n^2)
# SC: O(1)