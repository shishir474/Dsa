// Recursive solution 

class Solution {
public:
// coins[i] >= 1,  consider this case where coins {0,0,1} and target = 1
// {0,1} {0,1}, {0,0,1}, {1} -- 4ways
    int f(int idx, int amount, vector<int> &coins){
        if(amount == 0) return 1;
        if(idx >= coins.size()) return 0;

        int ans = f(idx+1, amount, coins);
        if(coins[idx] <= amount){
            ans = ans + f(idx, amount - coins[idx], coins);
        }

        return ans;
    }
    int change(int amount, vector<int>& coins) {
        return f(0, amount, coins);
    }
};

// TC: O(2^n) - for each index we have 2 choice, either pick the coin or not pick the coin
// SC: O(n) - for the recursion stack

----------------------------------------------------

// Recursion + memoisation

If we draw the recursion tree, we'll notice that there are many overlapping subproblems. Hence memoising this could help us in optimising the solution.

class Solution {
public:
// coins[i] >= 1,  consider this case where coins {0,0,1} and target = 1
// {0,1} {0,1}, {0,0,1}, {1} -- 4ways
    int t[302][5002];
    int f(int idx, int amount, vector<int> &coins){
        if(amount == 0) return 1;
        if(idx >= coins.size()) return 0;
        // add memo
        if(t[idx][amount] != -1) return t[idx][amount];

        int ans = f(idx+1, amount, coins);
        if(coins[idx] <= amount){
            ans = ans + f(idx, amount - coins[idx], coins);
        }

        return t[idx][amount] = ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(t, -1, sizeof(t));
        return f(0, amount, coins);
    }
};


// TC: O(n * amount) - for each index we have 2 choice, either pick the coin or not pick the coin
// SC: O(n * amount) + O(n) 
// O(n * amount) for dp array and O(n) for the recursion stack



----------------------------------------------------

Tabulation Solution

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        // base case 1 amount = 0
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        // base case 2 idx== n
        for(int j = 1; j <= amount; j++) dp[n][j] = 0;

        // idx -- 0 to n 
        // target -- target to 0

        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i+1][j];
                if(coins[i] <= j){
                    dp[i][j] = dp[i][j] + dp[i][j-coins[i]];
                }
            }
        }

        return dp[0][amount];


    }
};


----------------------------------------------------

Space optimised Solution

since ith row only depends on (i+1)th row, we can reduce the matrix to 2 rows

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // fact: int < long long < unsigned long long
        // There is one edge case, for which we need unsigned long long. 
        vector<vector<unsigned long long>> dp(2, vector<unsigned long long>(amount+1, 0));
        // base case 1 amount = 0
        for(int i = 0; i <= 1; i++) dp[i][0] = 1;
        // base case 2 idx== n
        for(int j = 1; j <= amount; j++) dp[1][j] = 0;

        // idx -- 0 to n 
        // target -- target to 0    

        int flag = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= amount; j++){
                dp[flag][j] = dp[flag^1][j];
                if(coins[i] <= j){
                    dp[flag][j] = dp[flag][j] + dp[flag][j-coins[i]];
                }
            }

            flag = flag^1;
        }

        flag = flag^1;
        return dp[flag][amount];


    }
};

// TC: O(n * amount) 
// SC: O(amount) 


