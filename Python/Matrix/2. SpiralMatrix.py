class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n,m = len(matrix), len(matrix[0])
        n1,n2,m1,m2 = 0,n-1,0,m-1
        ans = []

        # n1<=n2 and m1<=m2 THis condition must always satisfy
        while (n1<=n2 and m1<=m2):
            # left to right
            for j in range(m1,m2+1):
                ans.append(matrix[n1][j])  
            n1+=1 # first row processed

            #top to bottom
            for i in range(n1,n2+1):
                ans.append(matrix[i][m2])
            m2-=1 # last col processed

            if n1<=n2:
                #right to left
                for j in range(m2,m1-1,-1):
                    ans.append(matrix[n2][j])
                n2-=1 # last row processed

            if m1<=m2:
                # bottom to top
                for i in range(n2,n1-1,-1):
                    ans.append(matrix[i][m1])
                m1+=1 # first col processed

    
        return ans
    
# TC: O(n*m) each cell is visited exactly once
# SC: O(1) no extra space being used, other than storing the ans