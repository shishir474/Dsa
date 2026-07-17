Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
  
TC: O(n*m);
SC: o(n)

  
  struct cell{
        int i,j,time;
        cell(int x, int y, int t){
            i=x; j=y; time=t;
        }
    };
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int X[]={-1,0,1,0};
        int Y[]={0,1,0,-1};

        int n=grid.size(), m=grid[0].size();

        queue<cell> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(cell(i,j,0));
                }
            }
        }
        
        // bfs will give the min time for all fresh oranges.  have to determine mx value this min time required
        int mx=0;
        
        // This loop will run m*n times in worst case, since there are m*n elements 
        while(!q.empty()){
            cell f=q.front();
            q.pop();
            int i=f.i, j=f.j, t=f.time;
            mx =max(mx, t);
            for(int k=0;k<4;k++){
                int newi=i+X[k], newj=j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==1){
                    grid[newi][newj]=2;
                    q.push(cell(newi,newj,t+1));
                }
            }
        }
        
        // If any fresh orange remains, return -1, all oranges were not rot
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return mx;
        
    }