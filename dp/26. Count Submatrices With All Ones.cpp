1504. Count Submatrices With All Ones

Given an m x n binary matrix mat, return the number of submatrices that have all ones.

Example 1:

Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation: 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.



Example 2:

Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation: 
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
 

Constraints:

1 <= m, n <= 150
mat[i][j] is either 0 or 1.


// First thing which comes to my mind is:
Create a 2D dp[][]. Iterate on the last row and last column and where input[i][j] == 1, mark dp[i][j] = 1
// Now, assuming n X m matrix
int ans = 0;
for(int i=n-2; i>=0; i--){      // bottom to top
    for(int j=m-2; j>=0; j--){   // right to left
        dp[i][j] = min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]}) + 1;     // min(right,bottom,bottomRight) + 1. This will be the length of square formed at this index
        // at each index, we are essentially storing the length of square matrix starting at that index
        ans += dp[i][j];
    }
}

// ans will store the #total no of square matrices that are possible in the given input[][]


// In this question, we have to consider all submatrices (not just the square ones) -- minor twist

// first step: some preprocessing
input = [[1,0,1],[1,1,0],[1,1,0]]
mat1 = [[1,0,1],[2,1,0],[2,1,0]];   mat1[i][j] stores the max I can extend towards right from (i,j)
mat2 = [[1,0,1],[2,1,0],[3,2,0]];   mat2[i][j] stores the max I can extend towards upper side  from (i,j)

if we precomputed mat1 (i.e we know the max we can expand towards right from each cell)

for(int i = 0; i < n ; i++){
    
    for(int j = 0; j < m; j++){
        
        if(mat1[i][j] == 0) continue;

        // expand height - 1,2, and so on and compute the minWidth along that height
        int minWidth = INT_MAX;

        for(int k = i; k < n; k++){ // as I increment the height of the matrix, 1*minWidth, 2*minWidth. -- essentially minWidth is the no of matrices that will get added

            minWidth = min(minWidth, mat1[k][j]);

            ans += minWidth;

        }

    }
}


if we precompute mat2 (i.e we know the max we can expand in the upper direction from each cell(i,j))

for(int i = 0; i< n; i++){
    for(int j = n-1;j >= 0;  j--){
        // expand width -1,2,and so on 
        int minHeight = INT_MAX;
        for(int k = j ; k < m; k++){
            minHeight = min(minHeight, mat2[i][k]);
            ans += minHeight;
        }
    }
}


// Steps in the Approach
// 	1.	Preprocessing to Count Consecutive 1s Horizontally:
// 	•	For each cell (i, j), compute a[i][j] as the number of consecutive 1s starting from (i, j) to the right in row i.
// 	•	If mat[i][j] == 1, a[i][j] is incremented based on the value of the next cell to the right (a[i][j + 1]). Otherwise, it is 0.
// Example for a row: [1, 1, 0, 1] → [2, 1, 0, 1] (right-to-left computation).

// Counting Submatrices:
// 	•	Iterate through each cell (i, j) in the matrix.
// 	•	For each starting cell (i, j), consider it as the top-left corner of possible submatrices.
// 	•	Use the preprocessed a array to calculate the number of submatrices with all 1s that can end in column j for rows starting from i to m.
// 	•	Track the minimum width (x) across rows i to k for column j (ensuring all elements in the submatrix are 1).
// 	•	Add x to the result (res) for each row.


// The preprocessing step ensures that you can quickly calculate the width of potential submatrices in O(1) time for any starting cell.
// 	The nested loops iterate over all possible top-left corners and expand downward, using the precomputed widths to efficiently count submatrices.


// 2 kinds of preprocessing can be done here: both will lead the same results



// Time Complexity:
// •	Preprocessing: O(m \times n) (one pass to calculate a).
// •	Counting submatrices: O(m \times n \times m) in the worst case, but typically much faster due to the decreasing width.
// •	Space Complexity: O(m \times n) for the auxiliary array a.

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(),n=mat[0].size();
        int a[m][n];
        
        // preprocessing
        for (int i=0;i<m;i++){
            int c=0;
            for (int j=n-1;j>=0;j--){
                if (mat[i][j]==1){
                    c++;
                }
                else{
                    c=0;
                }
                a[i][j] = c;
            }
        }
        

        int res=0;
        // traverse over the matrix
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int x=INT_MAX;
                // keep on incrementing the height from 1 and compute the min width. IF the min_width is x, it means you can make x submatrices of height h
                for (int k=i;k<m;k++){
                    x = min(x,a[k][j]);
                    res+=x;
                }
            }
        }
        
        return res;
        
    }
};


// Maintain prefix sum for X and Y 
//             xCount[i][j] represents the no of X in matrix from cell (0,0) to cell(i,j)
//             Similary yCount[i][j] represents the no of Y in matrix from cell (0,0) to cell(i,j)
//             At a particular cell, we need to determine the no of X and Y that lies in the matrix from (0,0) to (i,j) .
//             We need Equal no X and Y 


Follow ups:
Count Submatrices With Equal Frequency of X and Y 
Medium
Count square submatrices with all ones
Medium
1224. Maximum Equal Frequency
Hard