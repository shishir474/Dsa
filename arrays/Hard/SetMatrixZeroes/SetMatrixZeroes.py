# Better Solution: 
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        n = len(matrix)
        m = len(matrix[0])

        # equivalent to vector<int> row(n,0), col(m,0)
        row = [0] * n
        col = [0] * m

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    row[i] = 1
                    col[j] = 1

        # row[i] == 1 means convert all elements in ith row to 0
        # col[j] == 1 means convert all elements in jth col to 0

        for i in range(n):
            for j in range(m):
                if row[i] == 1 or col[j] == 1:
                    matrix[i][j] = 0
        # TC: O(m*n) + O(m*n) = O(2 * m * n) = O(m * n)
        # SC: O(m) + O(n)


# Optimal Solution: O(1) space
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        m = len(matrix[0])

        # In order to solve this in place, I will treat 0th col as my row[] and 0th row as col[]
        # ofcourse since (0,0) is common in both, for tracking 0th col, I'll have a separate variable
        # idea is simple: I'll iterate over the matrix: if matrix[i][j] == 0: mark matrix[i][0] = 0
        # and matrix[0][j] = 0
        # we have to mark ith row and jth column as 0. If it's 0th column - we're tracking it in a separate variable
        # bcoz matrix[0][0] = 0 means we need to mark 0th row as 0
        # if col0 = 0 -> it means we need to mark 0th col as 0

        col0 = 1
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    # mark ith row 0
                    matrix[i][0] = 0
                    
                    # mark jth col 0 
                    if(j != 0):
                        matrix[0][j] = 0
                    else:
                        col0 = 0

        
        # step2: traverse matrix 1->n and 1->m bcoz values in these cells depends on 0th row and 0th col.
        # so we cannot update 0th row and 0th column first. 

        for i in range(1,n):
            for j in range(1,m):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # step3: update 1st row: we update 1st row before updating 1st col - The order is necessary here bcoz
        # say you update 1st column first that will convert matrix[0][0] to 0 and this will trigger 0th row to be marked as 0

        # first row is updated only if matrix[0][0] = 0
        # and first col is updated only if col0 = 0
        if matrix[0][0] == 0:
            for j in range(m):
                matrix[0][j] = 0

        # step4; update 1st col
        if col0 == 0:
            for i in range(n):
                matrix[i][0] = 0


        # TC: O(m*n) + O(m*n) + O(m) + O(n) = O(2 * m * n) = O(m * n)
        # SC: O(1)