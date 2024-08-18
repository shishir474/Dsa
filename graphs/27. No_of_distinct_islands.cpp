
// Q.9 Number of distint islands
// Given a boolean grid which contains 0's and 1's you have to count the distinct number of islands
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Output:
// 1
// Explanation:
// grid[][] = {{1, 1, 0, 0, 0}, 
//             {1, 1, 0, 0, 0}, 
//             {0, 0, 0, 1, 1}, 
//             {0, 0, 0, 1, 1}}
// Same colored islands are equal.
// We have 2 equal islands, so we 
// have only 1 distinct island.

// Example 2:

// Input:
// grid[][] = {{1, 1, 0, 1, 1},
//             {1, 0, 0, 0, 0},
//             {0, 0, 0, 0, 1},
//             {1, 1, 0, 1, 1}}
// Output:
// 3
// Explanation:
// grid[][] = {{1, 1, 0, 1, 1}, 
//             {1, 0, 0, 0, 0}, 
//             {0, 0, 0, 0, 1}, 
//             {1, 1, 0, 1, 1}}
// Same colored islands are equal.
// We have 4 islands, but 2 of them
// are equal, So we have 3 distinct islands.

// The challenge is how do we store the shape of an island, so that if we get the same island in the future, we won't include that in the count

// For an island, subtract the base coordinate from all the coordinates and perform dfs. Also store the dfs traversals in a path vector.
// Maintain a set, which will keep track of unique paths

// Base coordinate is the point from where we start our dfs traversal

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
        
class Solution {
  private:
    int n,m;
    void dfs(vector<vector<int>>& grid,int start_x, int start_y, int i, int j, vector<vector<int>>& vis, vector<pair<int,int>>& path){
        vis[i][j]=true;
        path.push_back({i-start_x, j-start_y}); // main step: subtract the base coordinate from all the coordinates 
        
        for(int k=0;k<4;k++){
            int newi = i+X[k];
            int newj = j+Y[k];
            if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==1 and !vis[newi][newj])
                dfs(grid,start_x,start_y,newi,newj,vis,path);
        }
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        n = N;
        m = M;
        
        vector<vector<int>> vis(n,vector<int>(m,false));
        
        set<vector<pair<int,int>>> unique_paths;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    vector<pair<int,int>> path;
                    dfs(grid,i,j,i,j,vis,path);
                    unique_paths.insert(path);
                }
            }
        }
        
        return unique_paths.size();
        
        
    }
};




// TC: O(n X m X log(n X m)) + O(n X m X 4)
//  (n*m*log(n*m)) -> for the for loop and set insertion
//  and dfs would be O(n*m*4), basically covers each cell exaclty once and explore neighbours in the 4 directions

// SC: O(n*m) for vis + o(n*m) for set
// set will store all the elements of the grid in the worst case