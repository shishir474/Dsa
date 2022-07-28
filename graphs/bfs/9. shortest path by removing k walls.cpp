Given a 2-D binary matrix of size n*m, where 0 represents an empty space while 1 represents a wall you cannot walk through. You are also given an integer k.
You can walk up, down, left, or right. Given that you can remove up to k walls, return the minimum number of steps to walk from the top left corner (0, 0) to the bottom right corner (n-1, m-1).
Note: If there is no way to walk from the top left corner to the bottom right corner, return -1.


Example 1:

Input: n = 3, m = 3, k = 1
mat = {{0, 0, 0},
       {0, 0, 1},
       {0, 1, 0}}
Output:
4
Explanation:
We can remove any one of the walls and
reach the bottom in 4 moves.  
Example 2:

Input:
n = 2, m = 2, k = 0
mat[] = {{0, 1},
         {1, 0}}
Output:
-1
Explanation:
There's no way of reaching the bottom
corner without removing any walls.

Your Task:
The task is to complete the function shotestPath() which takes three integers n, m, and k and also a matrix of size n*m as input and returns the minimum number of steps to walk from the top left corner to the bottom right corner.


Constraints:
1 ≤ n,m ≤ 50
0 ≤ k ≤ n*m
Top left and bottom right corners doesnt have 1

SOLUTION:

Store unique trio inside the queue, storing repeated ones increases the runtime hence will give TLE. 
Trio contains (i,j,rem_bal)
from i,j we can move in 4 directions, st we are inside the grid always, if newk<0 for any newi,newj cell, then that cell is also invalid and we cant go there

There will be n*m*k  unique combinations trios. hence the tc is O(n*m*k)
Expected Time Complexity: O(n*m*k).
Expected Auxiliary Space: O(n*m*k). for vis matrix




struct cell{
      int i,j,k;
      cell(int row, int col, int kbal){
          i=row;
          j=col;
          k=kbal;
      }
  };
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        int X[4]={-1,0,1,0};
        int Y[4]={0,1,0,-1};
        queue<cell> q;
        
        if(mat[0][0]==1) k--;
        
        if(k<0) return -1;
        
        q.push(cell(0,0,k));
        

        // vis set was giving compila error, hence used 3d vis matrix
  //      unordered_set<cell> vis;
        
//        vis.insert(cell(0,0,k));
        
        int vis[n+1][m+1][k+1];
        memset(vis,0,sizeof(vis));
        
        vis[0][0][k]=1;
        
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                cell f=q.front();
                q.pop();
                
                if(f.i==n-1 and f.j==m-1){
                    return steps;
                }
                
                for(int k=0;k<4;k++){
                    int newi=f.i+X[k], newj=f.j+Y[k];
                    if(newi>=0 and newi<n and newj>=0 and newj<m){
                        int newk=f.k;
                        if(mat[newi][newj]==1) newk=f.k-1;
                        
                        if(newk<0) continue;
                        
                        if(!vis[newi][newj][newk]){
                            vis[newi][newj][newk]=1;
                            q.push(cell(newi,newj,newk));
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }