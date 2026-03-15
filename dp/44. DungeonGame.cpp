// 174. Dungeon Game
The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
 

Example 1:

Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
Example 2:

Input: dungeon = [[0]]
Output: 1
 

Constraints:

m == dungeon.length
n == dungeon[i].length
1 <= m, n <= 200
-1000 <= dungeon[i][j] <= 1000


DP State:
dp[i][j] = the minimum health debt (negative or zero) you must "cover" at cell (i, j) to guarantee you can reach the end safely.
Why Negative or Zero?
If the sum of your current cell and the best path ahead is positive, you don’t need extra health at this cell (just need 1 to survive).
If it’s negative, you need to "cover" that debt with extra initial health.

How the Recurrence Works
Base Case:
At the princess''s cell (bottom-right), if the cell is positive, you need 0 extra health (just need 1 to survive).
If negative, you need to cover the negative value.

Transition:
For each cell, you look at the best path ahead (either right or down), and see what the minimum health debt is from those paths.
If your current cell plus the best path ahead is positive, you’re safe (need 0 extra).
If negative, you need to cover that debt.

Why Return abs(dp[0][0]) + 1?
dp[0][0] tells you the maximum health debt you’ll ever have along the optimal path.
You need at least 1 health at all times, so you need to start with abs(dp[0][0]) + 1 health to ensure you never drop to 0 or below.


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


Follow Ups
    Unique Paths
    Medium              -- DONE
    Minimum Path Sum
    Medium              -- DONE
    Cherry Pickup
    Hard
    Minimum Path Cost in a Grid
    Medium
    Minimum Health to Beat Game [LC PREMIUM]
    Medium                      -- DONE 
    Paths in Matrix Whose Sum Is Divisible by K
    Hard
    Check if There is a Path With Equal Number of 0's And 1's [LC PREMIUM]
    Medium



Minimum Health to Beat Game [LC PREMIUM]    
You are playing a game that has n levels numbered from 0 to n - 1. You are given a 0-indexed integer array damage where damage[i] is the amount of health you will lose to complete the ith level.

You are also given an integer armor. You may use your armor ability at most once during the game on any level which will protect you from at most armor damage.

You must complete the levels in order and your health must be greater than 0 at all times to beat the game.

Return the minimum health you need to start with to beat the game.

 

Example 1:

Input: damage = [2,7,4,3], armor = 4
Output: 13
Explanation: One optimal way to beat the game starting at 13 health is:
On round 1, take 2 damage. You have 13 - 2 = 11 health.
On round 2, take 7 damage. You have 11 - 7 = 4 health.
On round 3, use your armor to protect you from 4 damage. You have 4 - 0 = 4 health.
On round 4, take 3 damage. You have 4 - 3 = 1 health.
Note that 13 is the minimum health you need to start with to beat the game.
Example 2:

Input: damage = [2,5,3,4], armor = 7
Output: 10
Explanation: One optimal way to beat the game starting at 10 health is:
On round 1, take 2 damage. You have 10 - 2 = 8 health.
On round 2, use your armor to protect you from 5 damage. You have 8 - 0 = 8 health.
On round 3, take 3 damage. You have 8 - 3 = 5 health.
On round 4, take 4 damage. You have 5 - 4 = 1 health.
Note that 10 is the minimum health you need to start with to beat the game.
Example 3:

Input: damage = [3,3,3], armor = 0
Output: 10
Explanation: One optimal way to beat the game starting at 10 health is:
On round 1, take 3 damage. You have 10 - 3 = 7 health.
On round 2, take 3 damage. You have 7 - 3 = 4 health.
On round 3, take 3 damage. You have 4 - 3 = 1 health.
Note that you did not use your armor ability.

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long s = 0;
        int mx = damage[0];
        for (int& v : damage) {
            s += v;
            mx = max(mx, v);
        }
        return s - min(mx, armor) + 1;
    }
};