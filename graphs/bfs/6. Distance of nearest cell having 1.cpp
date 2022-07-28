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