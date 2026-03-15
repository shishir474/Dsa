
Recurrence: 
f(idx, cap):
if you are not picking the current element -- f(idx+1, cap) i.e move to next item and cap remains same.
If you are picking the current element and pick only if its weight <= cap -- f(idx, cap - weight[idx]) i.e pick the current item and reduce the cap by weight[idx] and since we can pick the same item again, idx remains same.

Base case: 
if cap == 0 return 0; No more capacity left, so no more profit can be made
if idx >= profit.size() return 0; No more items left to consider

-----------------------------------------------------------------------

Recursive Solution

int f(int idx, int cap, vector<int> &profit, vector<int> &weight){
    
    if(cap == 0 || idx >= profit.size()) return 0;

    int ans = f(idx+1, cap, profit, weight); // not picking this item, cap remains same
    if(weight[idx] <= cap)          // picking this item, since we can pick it again hence idx and cap reduces to cap-weight[idx]
        // can only pick this item if weight[idx] <= cap 
        ans = max(ans, profit[idx] + f(idx, cap - weight[idx], profit, weight));
    
    return ans;
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return f(0, w, profit, weight);
}

// TC: O(2^n) - for each index we have 2 choice, either pick the coin or not pick the coin
// SC: O(n) - for the recursion stack

-------------------------------------------------------

Recursion + memoisation

If you draw a recursion tree you will notice that there are overlapping subproblems. Hence we can memoise this to create an efficient solution.

int t[1002][1002];
int f(int idx, int cap, vector<int> &profit, vector<int> &weight){

    if(cap == 0 || idx >= profit.size()) return 0;
    if(t[idx][cap] != -1) return t[idx][cap];

    int ans = f(idx+1, cap, profit, weight); // not picking this item, cap remains same
    if(weight[idx] <= cap)          // picking this item, since we can pick it again hence idx and cap reduces to cap-weight[idx]
        // can only pick this item if weight[idx] <= cap 
        ans = max(ans, profit[idx] + f(idx, cap - weight[idx], profit, weight));
    
    return t[idx][cap] = ans;
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    memset(t, -1, sizeof(t));
    return f(0, w, profit, weight);
}

// TC: O(n * w) - for each index we have 2 choice, either pick the coin or not pick the coin
// SC: O(n * w) + O(n) 
// O(n * w) for dp array and O(n) for the recursion stack

-------------------------------------------------------

Tabulation Solution -- to get rid of auxilary stack space

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // memset(t, -1, sizeof(t));
    // return f(0, w, profit, weight);

    vector<vector<int>> dp(n+1, vector<int>(w+1,0));
    // base case 1: cap == 0
    for(int i = 0; i<=n; i++) dp[i][0] = 0;
    // base case 2: if idx >= n
    for(int j = 1; j<=w; j++) dp[n][j] = 0;

    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<= w; j++){
            dp[i][j] = dp[i+1][j];
            if(weight[i] <= j)          // picking this item, since we can pick it again hence idx and cap reduces to cap-weight[idx]
                // can only pick this item if weight[idx] <= cap 
                dp[i][j] = max(dp[i][j], profit[i] + dp[i][j - weight[i]]); 
        }
    }

    return dp[0][w];

}

// TC: O(n * w)
// SC: O(n * w) 

-------------------------------------------------------

Space optimisation -- since ith row only depends on (i+1)th row, we can reduce the matrix to 2 rows


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // memset(t, -1, sizeof(t));
    // return f(0, w, profit, weight);

    vector<vector<int>> dp(2, vector<int>(w+1,0));
    // base case 1: cap == 0
    for(int i = 0; i<=1; i++) dp[i][0] = 0;
    // base case 2: if idx >= n
    for(int j = 1; j<=w; j++) dp[1][j] = 0;

    int flag = 0;

    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<= w; j++){
            dp[flag][j] = dp[flag^1][j];
            if(weight[i] <= j)          // picking this item, since we can pick it again hence idx and cap reduces to cap-weight[idx]
                // can only pick this item if weight[idx] <= cap 
                dp[flag][j] = max(dp[flag][j], profit[i] + dp[flag][j - weight[i]]); 
        }

        flag = flag^1;
    }

    flag = flag^1;

    return dp[flag][w];

}

// TC: O(n * w)
// SC: O(w) 