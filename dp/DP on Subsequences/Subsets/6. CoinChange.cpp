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

Example 3:
Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104



Recurrence:
f(idx, target):
not_pick ith coin => f(idx+1, target)       target remains the same, just move to the next coin
pick ith coin => 1 + f(idx, target - arr[idx]).  can pick the same coin again hence idx

Base case:
if target == 0:return 0; because if the target is 0, min coins that we need to pick is 0
if idx >= arr.size() return 1e5; because if we have exhausted all coins and still have a target left, it is not possible


------------------------------------------------------

Recursive Solution 

class Solution {
public:
    int f(int idx, int target, vector<int>& arr){
        if(target == 0) return 0;
        if(idx >= arr.size()) return 1e5;
        
        int ans = f(idx+1, target, arr);
        
        if(arr[idx] <= target){
            ans = min(ans,  1 + f(idx, target - arr[idx], arr));
        }
        
        // return min of both the options
        return ans;
    }

    int coinChange(vector<int>& arr, int amount) {
        int ans = f(0, amount, arr);
        return ans == 1e5 ? -1 : ans;
    }
};

------------------------------------------------------

Recursion + memoisatoin

If you draw the recursion tree, you will see that there are overlapping subproblems. Hence we can apply memoisation

class Solution {
public:
    int t[13][10005];
    int f(int idx, int target, vector<int>& arr){
        if(target == 0) return 0;
        if(idx >= arr.size()) return 1e5;
        // adding memo
        if(t[idx][target] != -1) return t[idx][target];
        
        int ans = f(idx+1, target, arr);
        
        if(arr[idx] <= target){
            ans = min(ans,  1 + f(idx, target - arr[idx], arr));
        }
        
        // return min of both the options
        return t[idx][target] = ans;
    }

    int coinChange(vector<int>& arr, int amount) {
        memset(t, -1, sizeof(t));
        int ans = f(0, amount, arr);
        return ans == 1e5 ? -1 : ans;
    }
};

// TC: O(n * amount)
// SC: O(n * amount) + O(n) 
// O(n * amount) for dp array and O(n) for recursion stack



------------------------------------------------------

Tabulation Solution -- to get rid of auxilary stack space

int coinChange(vector<int>& arr, int target) {
    // idx -- 0 to n
    // target = target to 0
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

    // base case1 : target  = 0
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    // if empty array idx == n
    for(int j = 1; j<=target; j++) dp[n][j] = 1e5;

    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<= target; j++){
            dp[i][j] = dp[i+1][j];
            if(arr[i] <= j){
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - arr[i]]);
            }
        }
    }

    return dp[0][target] == 1e5 ? -1 : dp[0][target];

}

// TC: O(n * amount)
// SC: O(n * amount) 


------------------------------------------------------
// Space optimisation -- since ith row only depends on (i+1)th row, we can reduce the matrix to 2 rows

int coinChange(vector<int>& arr, int target) {
    // idx -- 0 to n
    // target = target. to 0
    int n = arr.size();
    vector<vector<int>> dp(2, vector<int> (target+1, 0));

    // base case1 : target  = 0
    for(int i=0;i<=1;i++) dp[i][0] = 0;
    // if empty array idx == n
    for(int j = 1; j<=target; j++) dp[1][j] = 1e5;

    int flag = 0;
    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<= target; j++){
            dp[flag][j] = dp[flag^1][j];
            if(arr[i] <= j){
                dp[flag][j] = min(dp[flag][j], 1 + dp[flag][j - arr[i]]);
            }
        }
        flag = flag^1
    }

    flag = flag^1;

    return dp[flag][target] == 1e5 ? -1 : dp[flag][target];

}

// TC: O(n * amount)
// SC: O(amount) 


