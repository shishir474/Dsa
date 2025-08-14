You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1


// Again I have two choices: either include the coin or exclude it.
// If I include the coin, I reduce the amount by the coin's value
// If I exclude the coin, I move to the next coin without changing the amount.
// f(i, j) = f(i, j - coins[i]) + f(i - 1, j) & I can only take the coin if coins[i] <= j
// TC: O(n*x)
// SC: O(n*x)
class Solution {
public:
    int change(int x, vector<int>& a) {
    int n=a.size();
    int t[n+1][x+1];
    for(int i=0;i<n+1;i++) t[i][0] = 1;
    for(int j=1;j<=x;j++) t[0][j] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            t[i][j] = t[i-1][j];
            if (a[i-1]<=j){
                t[i][j] = (t[i][j]+t[i][j-a[i-1]]);
            }
        }
    }
    
    return t[n][x];
	
    }
};

// Solution 2: Space Optimized DP - use flag
// SC: O(2*x) - Space Optimized DP
// TC: O(n*x)

// Implement later
