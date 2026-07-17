from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        vis = [[False]*m for _ in range(n)]

        q = deque()

        is_one_present = False

        # push all the potential starting points in queue
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    vis[i][j] = True
                    q.append((i,j,0))       # i,j,dist
                elif grid[i][j] == 1: 
                    is_one_present = True

        if len(q) == 0:            # edge case: if no potential starting points
            if is_one_present:
                return -1
            return 0

        X = [-1,0,1,0]
        Y = [0,1,0,-1]


        def is_valid(i, j):
            return i>=0 and i<n and j>=0 and j<m and grid[i][j] == 1 and not vis[i][j]

        ans = float('-inf')

        while q:
            i,j,d = q.popleft()
            print(i,j,d)
            ans = max(ans, d)

            for k in range(4):
                new_i = i + X[k]
                new_j = j + Y[k]
                if is_valid(new_i, new_j):
                    vis[new_i][new_j] = True
                    q.append((new_i, new_j, d+1))


        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and not vis[i][j]:
                    return -1
        
        return ans



# TC: O(n*m) where n and m are the dimensions of the grid. We visit each cell at most once.
# SC: O(n*m) in the worst case when all oranges are rotten and we have to store all of them in the queue and visited array. In practice, it will be less than this if there are fewer rotten oranges.

    