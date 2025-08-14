Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

solution:
t[m][n] -> used same logic as for determining the biggest square matrix
[
  [0,3,2,1],
  [1,2,2,1],
  [0,1,1,1]
]



class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        int t[m][n];
        // initialise dp matrix
        memset(t,0,sizeof(t));
        
        // intialise last col
        for(int i=m-1;i>=0;i--){
            if (matrix[i][n-1])
            t[i][n-1] = 1;
            else t[i][n-1] = 0;
        }
        
        // intialise last row
       for(int j=n-1;j>=0;j--){
            if (matrix[m-1][j])
            t[m-1][j] = 1;
            else t[m-1][j] = 0;
        }
        
        // fill dp matrix
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if (matrix[i][j]==1)
                    t[i][j] = min({t[i][j+1], t[i+1][j], t[i+1][j+1]}) + 1;
            }
        }
        
        // eval ans
        int count=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
               count+=t[i][j];
            }
        }
        
        return count;
    }
};

Follow ups:
Count Submatrices With All Ones
Medium
