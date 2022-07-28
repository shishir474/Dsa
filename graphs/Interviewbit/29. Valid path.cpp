Valid Path

Medium

126

50
Asked In:
Morgan Stanley
Amazon
Codenation
more
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.

Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note :  We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.




Input Format

1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle
Output Format

Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
Constraints

0 <= x, y, R <= 100
1 <= N <= 1000
Center of each circle would lie within the grid
For Example

Input:
    x = 2
    y = 3
    N = 1
    R = 1
    A = [2]
    B = [3]
Output:
    NO
   
Explanation:
    There is NO valid path in this case

SOLUTION:

point (x,y) lies inside a circle with center (xc,yc)  only when (x-xc)^2 + (y-yc)^2 <= R*R
= means point lies on the circle boundary.
SO using this concept, mark all the cells that cannot be visited and then just apply dfs from (0,0). & check if (x,y) can be visited 
Before this check if (0,0) of (x,y) is blocked by any cell, then return 0;

    int X[] = {-1,-1,0,1,1,1,0,-1};
int Y[] = {0,1,1,1,0,-1,-1,-1};

void dfs(int i, int j, vector<vector<int> >& mat, vector<vector<bool> >& vis){
    
    if (i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || vis[i][j]==1 || mat[i][j]==-1) return;

    vis[i][j] = 1;

    for(int k=0;k<8;k++){
        int newi = i+X[k], newj = j+Y[k];
        dfs(newi,newj,mat,vis);
    }
}
string Solution::solve(int x, int y, int N, int R, vector<int> &a, vector<int> &b) {

    vector<vector<int> > mat(x+1, vector<int> (y+1, 0));

    // TC: (x*y*N) for x*y cells and SC O(xy)
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            // check if i,j point is within any circle. we have to check for all the circles
            for(int k=0;k<N;k++){
                int xc = a[k], yc = b[k];
                if ((((i-xc)*(i-xc)) + ((j-yc)*(j-yc))) <= R*R){
                    mat[i][j]=-1;  // block i,j cell
                    break;
                }
            }


        }
    }

    vector<vector<bool> > vis(x+1, vector<bool> (y+1, false));
    
    if (mat[0][0]==-1 || mat[x][y]==-1) return "NO";

    dfs(0,0,mat,vis);

    if (vis[x][y]) return "YES";
    return "NO";


}
