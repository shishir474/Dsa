class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        n = numRows; 
        # matrix = [[0]*n for _ in range(n)] # n X n matrix
        
        matrix = []        

        for i in range(n):
            row  = [0] * (i+1)
            row[0] = 1
            row[i] = 1
            for j in range(1, i):
                row[j] = matrix[i-1][j-1] + matrix[i-1][j]

            matrix.append(row)

        
        return matrix