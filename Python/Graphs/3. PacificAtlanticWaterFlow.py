class Solution:
    def __init__(self):
        self.vis = set()
        self.X = [-1,0,1,0]
        self.Y = [0,1,0,-1]
    
    def dfs(self, i, j, heights, mat):
        n = len(heights)
        m = len(heights[0])
    
        self.vis.add((i,j))
        mat[i][j] = 1

        for k in range(4):
            newi = i + self.X[k]
            newj = j + self.Y[k]
            if newi>=0 and newi<n and newj>=0 and newj<m and (newi,newj) not in self.vis and heights[newi][newj]>=heights[i][j]:
                self.dfs(newi,newj,heights,mat)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n, m = len(heights), len(heights[0])
        
        # nXm matrix 
        pacific = [[0 for j in range(m)] for i in range(n)]
        atlantic = [[0 for j in range(m)] for i in range(n)]

        #pacific left col
        for i in range(n):
            if (i,0) not in self.vis: 
                self.dfs(i,0,heights,pacific) 
        for i in range(m):
            if (0,i) not in self.vis: 
                self.dfs(0,i,heights,pacific) 
        # print(pacific)
        
        self.vis.clear()
         #atlantic right col
        for i in range(n):
            if (i,m-1) not in self.vis: 
                self.dfs(i,m-1,heights,atlantic) 
        for i in range(m):
            if (n-1,i) not in self.vis: 
                self.dfs(n-1,i,heights,atlantic) 

        # print(atlantic)
        
        ans = []

        for i in range(n):
            for j in range(m):
                if pacific[i][j] and atlantic[i][j]:
                    ans.append([i,j])

        return ans
    
    
    
 