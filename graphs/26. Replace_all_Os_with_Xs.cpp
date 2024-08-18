// Q.7 Replace O's with X's
// Given a matrix that contains O's and X's. Replace all the O's that are surropunded by X's in all 4 directions;

// SOlution: 
// Call dfs from all the cells that contains O's and are at boundary. This way you will mark all the O's connected with boundary as visited
// Now whichever O's were not visited, are not connected to boundary and are surrounded by X. Replace all these O's
// The set of O's which are not connected to boundary are bound to be surrounded by X

int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

class Solution{
private:
    void dfs(int i, int j, vector<vector<char>>& mat, vector<vector<bool>>& vis){
        int n = mat.size(), m =mat[0].size();
        
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int newi = i+X[k];
            int newj = j+Y[k];
            if(newi>=0 and newi<n and newj>=0 and newj<m and mat[newi][newj]=='O' and !vis[newi][newj])
                dfs(newi,newj,mat,vis);
        }
    }
    
public:
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> input)
    {
        // code here
        vector<vector<char>> mat = input; // operate on the copy, do not alter the input
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' and !vis[i][0])
                dfs(i,0,mat,vis);
            if(mat[i][m-1]=='O' and !vis[i][m-1])
                dfs(i,m-1,mat,vis);
        }
        
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' and !vis[0][i])
                dfs(0,i,mat,vis);
            if(mat[n-1][i]=='O' and !vis[n-1][i])
                dfs(n-1,i,mat,vis);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' and !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
            
    }
};

// TC: O(n*m)  In the worst case we might have to visit each cell
// SC: O(n*m) for vis matrix and recursion call stack space. In worst case the matrix is filled with all O's

// --------------------X--------------------X-----------------------X------------------