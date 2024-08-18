# https://leetcode.com/problems/set-matrix-zeroes/description/

# https://www.youtube.com/watch?v=T41rL0L3Pnw&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=45



class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n,m = len(matrix), len(matrix[0])

        rowZero = False 
        
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    #when a 0 is encouterd, we do 2 things:
                    # set (0,j) as 0 indicating the jth column needs to be marked as 0
                    matrix[0][j] = 0

                    if i > 0:
                        # and set (i,0) as 0 indicating the ith row needs to be marked as 0
                        matrix[i][0] = 0
                    else:
                        rowZero = True


        for i in range(1,n):
            for j in range(1,m):
                if matrix[i][0]==0 or matrix[0][j]==0:
                    matrix[i][j]=0


        # First col: First check the col condition: Because if we would have first checked the row condition, it would have marked the first row 0 and matrix[0][0] would also be marked 0, which will make the first col 0
        if matrix[0][0]==0:
            for i in range(n):
                matrix[i][0] = 0

        # First row
        if rowZero:
            for j in range(m):
                matrix[0][j] = 0
        


        # TC: O(n*m) the tc will remain the same no matter any approach we flow
        # SC: O(1) But it is the sc that we are optimising on using this approach. Constant space solution

        # Any method we take will atleast take O(m*n) or O(m+n) space atleast. Using this method, we are able to solve this in constant space