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
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int x=INT_MAX;
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