Water flow: INTERVIEW BIT

Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.



Problem Constraints
1 <= M, N <= 1000

1 <= A[i][j] <= 109



Input Format
First and only argument is a 2D matrix A.



Output Format
Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.



Example Input
Input 1:

 A = [
       [1, 2, 2, 3, 5]
       [3, 2, 3, 4, 4]
       [2, 4, 5, 3, 1]
       [6, 7, 1, 4, 5]
       [5, 1, 1, 2, 4]
     ]
Input 2:

 A = [
       [2, 2]
       [2, 2]
     ]


Example Output
Output 1:

 7
Output 2:

 4


Example Explanation
Explanation 1:

 Blue Lake ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
           *   *   *   *   * Red Lake
 Water can flow to both lakes from the cells denoted in parentheses.

Explanation 2:

 Water can flow from all cells.



SOLUTION:
TC: O(m*n);
sc:O(m*n);
 
int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};
void helper(vector<vector<int> > &mat, int i, int j, vector<vector<bool> >& ocean){
    int n=mat.size(), m=mat[0].size();
    if (ocean[i][j]==1) return;
    ocean[i][j]=1;
    for(int k=0;k<4;k++){
        int newi=i+X[k], newj=j+Y[k];
        if(newi>=0 and newi<n and newj>=0 and newj<m and mat[newi][newj]>=mat[i][j]){
              helper(mat,newi,newj,ocean);
        }
    }
}


int Solution::solve(vector<vector<int> > &mat) {

    int n=mat.size(), m=mat[0].size();
    int ans=0;

// pacific[i][j]==1 -> this cell {i,j} is reachable to pacific
// atlantic[i][j]==1 -> this cell {i,j} is reachable to atlantic

    vector<vector<bool> > pacific(n, vector<bool> (m, false));
    vector<vector<bool> > atlantic(n, vector<bool> (m, false));


// so call dfs from all the cells from where we can reach the pacific
    for(int j=0;j<m;j++){
        helper(mat,0,j,pacific);
    }
    for(int i=0;i<n;i++){
        helper(mat,i,0,pacific);
    }

// so call dfs from all the cells from where we can reach the atlantic
    for(int j=0;j<m;j++){
        helper(mat,n-1,j,atlantic);
    }
    for(int i=0;i<n;i++){
        helper(mat,i,m-1,atlantic);
    }

// cells from where we can reach both pacific and atlantic are our ans
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pacific[i][j]==true && atlantic[i][j]==true){
                ans++;
            }
        }
    }

    return ans;
}