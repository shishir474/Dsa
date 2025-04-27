// 174. Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        // if mat[n-1][m-1] > 0, then dp[n-1][m-1] will be 0 indicating we can just start with 1 and we'll be able to reach the dest
        // if mat[n-1][m-1] <= 0, then we would need abs(mat[n-1][m-1]) + 1 health to reach dest
        dp[n-1][m-1] = mat[n-1][m-1] > 0 ? 0 : mat[n-1][m-1];

        for(int i=n-2;i>=0;i--){// last col
            // if mat[i][m-1] + dp[i+1][m-1] > 0, it means dp val at this pos will be 0 and we can just start with health = 1, since we're guaranteeed that we'll make it to dest from  (i+1,m-1)
            dp[i][m-1] =  mat[i][m-1] + dp[i+1][m-1] > 0 ? 0 : mat[i][m-1] + dp[i+1][m-1];
        }
        for(int i=m-2;i>=0;i--){// last row
            dp[n-1][i] = mat[n-1][i] + dp[n-1][i+1] > 0 ? 0 : mat[n-1][i] + dp[n-1][i+1] ;
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j] = mat[i][j] + max(dp[i][j+1], dp[i+1][j]) > 0 ? 0 : mat[i][j] + max(dp[i][j+1], dp[i+1][j]) ;
            }
        }

        return abs(dp[0][0]) + 1;
    }
};

// you cannot have health 0 at any point.
// TC: O(n*m)

// binary search could also be used , lo = 0, hi = 1e9
// but its tc will be more than the dp solution