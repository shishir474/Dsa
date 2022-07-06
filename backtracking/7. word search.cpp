Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true




int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

class Solution {
public: // idx -> 1    
    bool isValid(int newi, int newj,int idx, vector<vector<char>>& board,string word){
        if(newi>=0 and newj>=0 and newi<board.size() and newj<board[0].size() and board[newi][newj]==word[idx])
            return true;
        return false;
    }
    
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string word){
        if (idx>=word.size()) return true;
        
        char ch = board[i][j];
        board[i][j] = '$';
        
        bool ans = false;
        
        for(int k=0;k<4;k++){
            int newi=i+X[k], newj=j+Y[k];
            if(isValid(newi,newj,idx,board,word)){
                if(dfs(newi,newj,idx+1,board,word)){
                    ans = true; 
                    break;
                }
            }
        }
        
        board[i][j] = ch;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,1,board,word)) return true;
                }
            }
        }
        
        return false;
        
    }
};