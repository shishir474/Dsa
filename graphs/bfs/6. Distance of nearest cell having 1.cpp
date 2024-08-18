Distance of nearest cell having 1

Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.

TC: o(n*m):
SC:O(n*m);

queue wali while loop n*m times chalegi bcoz queue me n*m elements ayenge
 //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int X[]={-1,0,1,0};
        int Y[]={0,1,0,-1};

	    int n=grid.size(), m=grid[0].size();
	    vector<vector<int> > res(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int> > q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                res[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        auto f=q.front();
	        q.pop();
	        int i=f.first, j=f.second;
	        for(int k=0;k<4;k++){
	            int newi=i+X[k], newj=j+Y[k];
	            if(newi>=0 and newi<n and newj>=0 and newj<m){
	                if(res[i][j]+1 < res[newi][newj]){
	                    res[newi][newj] = 1+res[i][j];
	                    q.push({newi,newj});
	                }
	            }
	        }
	    }
	    
	    return res;
	   
	}


// Q.6 Distance of nearest cell having 1

// Given a binary grid, you have to compute the shortest distance from 1 for each cell

// Solution 1: uses visited array: This is the recommended solution as it gives more clarity
vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        
        vector<vector<int>> ans(n, vector<int>(m,0)); // stores the shortest dist from 1
        vector<vector<bool>> vis(n,vector<bool>(m,false)); // keeps track of vis vertex
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,{j,0}});
                    vis[i][j]=true;
                }
            }
        }
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
    
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second.first;
            int dist=q.front().second.second;
            
            ans[i][j]=dist;
            
            q.pop();
            
            for(int k=0;k<4;k++){
                int newi=i+X[k];
                int newj=j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m and !vis[newi][newj]){
                    vis[newi][newj] = true;
                    q.push({newi,{newj,dist+1}});
                }
            }
            
        }
        
        return ans;
        
        
        
    }

// SOlution 2:
// without using vis array: Basically intialiase the ans matrix with 1e9 for each cell
// Insert all the cells with cell value=1 in queue and mark their values in ans cell as 0
// Now start processing elements from queue. Element will be of form (i,j) coordinates
// explore its neighbours(valid ones which are within the boundary of the matrix) and check if the 1+cost_curr < cost_nb
// If the condition is true: update the cost_of_nb and push the cell into the queue
// if(valid cell + ans[i][j]+1 < ans[newi][newj]){
    // ans[newi][newj] =  ans[i][j] + 1;
    // q.push({i,j});
// }
// This condition prevents us from revisiting the already vis vertex: why let's see an example: Assume your are coming from cell A to B. Now while standing at B, you wont go back to A. THe new cost for A isn't better than its prev cost and hence we will not go back to already visited vertex

// SOlution 2 : without visited vertex
    
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        
        vector<vector<int>> ans(n, vector<int>(m,1e9)); // stores the shortest dist from 1

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
    
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int newi=i+X[k];
                int newj=j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m and ans[i][j]+1 < ans[newi][newj]){ // ans[i][j]+1 < ans[newi][newj] THis condition will help us prevent visit the already visited vertex
                    ans[newi][newj] = 1 + ans[i][j];
                    q.push({newi,newj});
                }
            }
            
        }
        
        return ans;
                
    }

// TC: of both approaches is O(n*m)
// SC: of both approaches is O(n*m)