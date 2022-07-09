322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1



class Solution {
public:
    int coinChange(vector<int>& coins, int x) {
        int n=coins.size();
        int t[n+1][x+1];
        for(int i=0;i<=n;i++){
            t[i][0] = 0;
        }
        for(int j=1;j<=x;j++){
            t[0][j]=INT_MAX-1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=x;j++){
                if(coins[i-1]<=j){
                    t[i][j]=min(1+t[i][j-coins[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        if(t[n][x]==INT_MAX-1) return -1;
        return t[n][x];
    }
};