# https://leetcode.com/problems/number-of-islands/

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        # n X m grid
        vis = [[False]*m for _ in range(n)]
        
        X = [-1, 0, 1, 0]
        Y = [0, 1, 0, -1]

        def is_valid(i, j):
            return i >=0 and i < n and j>=0 and j < m and not vis[i][j] and grid[i][j] == '1'

        def dfs(i, j):
            vis[i][j] = True
            
            for k in range(4):
                newi = i + X[k]
                newj = j + Y[k]

                if is_valid(newi, newj):
                    dfs(newi, newj)


        island_cnt = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1' and not vis[i][j]:     # both conditions important
                    dfs(i,j)
                    island_cnt += 1

        return island_cnt
    
    # TC: O(n * m)
    # traversing thru the entire matrix and calling dfs from only those cells which have 1 and not visited.
    # a dfs call might traverse thru the entire matrix in the worst case --> which will be O(n * m)
    # vis[][] ensures that we visit each cell once. So we will atmost traverse thru the entire matrix
    # and that will cost us O(n * m) time
    
    # SC: O(n * m) for vis matrix + O(4) space for X[] and Y[] constant space (can ignore it) + 
    # O(n * m) recursive stack space
    
    
# Space optimisation:

# we could remove vis[][] completely.
# by simply assigning grid[i][j] = '0'        # mark visited
# But this would modify the input which is not considered a good practise.


