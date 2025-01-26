// Check if There Is a Valid Parentheses String Path

class Solution {
public:
    int t[102][102][205]; // the max length of the string can  never exceed 205
    bool solve(int i, int j, vector<vector<char>>& grid, int bal){
        int n = grid.size(), m = grid[0].size();
        if (i>=n or j>=m) return false; // if index out of bound - return false
        
        if (grid[i][j]=='(') bal++; // index is within the bounds
        else bal--;
         
        if (bal < 0) return false; // if bal < 0 - return false 

        // if already computed
        if (t[i][j][bal] != -1) return t[i][j][bal];  // memoisation: i, j, bal 3 factors
        
        // base case: reached the end and bal is 0 - return true
        if(i==n-1 and j==m-1) {
            return bal==0; // bal should be 0 at the end
        }

        // now I have 2options: move down or right
        bool ans = false;
        ans = ans or solve(i, j+1, grid, bal);
        ans = ans or solve(i+1, j, grid, bal);

        return t[i][j][bal] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, grid, 0);
    }
};

// TC: O(n*m*k)
// SC: O(n*m*k) where k is the max length of the string