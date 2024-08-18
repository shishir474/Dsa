# https://leetcode.com/problems/word-search/

class Solution:
    def dfs(self, i, j, idx, vis, board, word):
        n,m = len(board), len(board[0])
        if idx==len(word):
            return True

        X = [-1,0,1,0]
        Y = [0,1,0,-1]
        
        vis[i][j] = True
        for k in range(4):
            newi, newj= i+X[k], j+Y[k]
            if newi>=0 and newi<n and newj>=0 and newj<m and vis[newi][newj]==False and board[newi][newj]==word[idx]:
                if self.dfs(newi,newj,idx+1,vis,board,word):
                    return True

        vis[i][j] = False
        return False


    def exist(self, board: List[List[str]], word: str) -> bool:
        n,m = len(board), len(board[0])
        vis = [[False for j in range(m)]for i in range(n)]

        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    if self.dfs(i,j,1,vis,board,word):
                        return True

        return False

# Brute force solution: using backtracking

# TC: O(n * m * dfs)
# The depth of the call stack of dfs function will be O(len(word)). For each position, we have 4 options, so overall tc of dfs is 4^len(word) 


# SC: O(n*m) for vis + O(len(word)) recursive stack space





class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n,m = len(board), len(board[0])
        vis = [[False for j in range(m)] for i in range(n)]
        
        def dfs(i,j,idx):
            if idx==len(word):
                return True
            if i < 0 or i>=n or j<0 or j>=m or board[i][j] != word[idx] or vis[i][j] == True:
                return False
            
            vis[i][j] = True
            res = (dfs(i-1,j,idx+1) or 
                dfs(i+1,j,idx+1) or
                dfs(i,j-1,idx+1) or
                dfs(i,j+1,idx+1))
            
            vis[i][j] = False
            return res

        for i in range(n):
            for j in range(m):
                if dfs(i,j,0): return True
        
        return False