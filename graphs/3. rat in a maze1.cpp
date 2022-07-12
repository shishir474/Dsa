Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.


You dont need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.




Expected Time Complexity: O((4N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

int X[]={1,0,0,-1};
int Y[]={0,-1,1,0};
class Solution{
    public:
    
    bool isSafe(int i, int j, vector<vector<int>> &mat, int n){
        if(i>=0 and i<n and j>=0 and j<n and mat[i][j]==1 and mat[i][j]!=-1) return true;
        return false;
    }
    
    void dfs(int i, int j, vector<vector<int>> &mat, int n, string path, vector<string>& res){
        if(i==n-1 and j==n-1){
            res.push_back(path);
            return;
        }
        int c=mat[i][j];
        mat[i][j]=-1; // marked visisited
        for(int k=0;k<4;k++){
            if(isSafe(i+X[k],j+Y[k],mat,n)){
                if(k==0) path.push_back('D');
                else if(k==1) path.push_back('L');
                else if(k==2) path.push_back('R');
                else path.push_back('U');
                dfs(i+X[k],j+Y[k],mat,n,path,res);
                path.pop_back();
            }
        }
        mat[i][j]=c;
        
    }
    vector<string> findPath(vector<vector<int>> &mat, int n) {
         vector<string> res;
         if (mat[0][0]==0) return res;
         
         string path="";
         dfs(0,0,mat,n,path,res);
         return res;
    }
};

