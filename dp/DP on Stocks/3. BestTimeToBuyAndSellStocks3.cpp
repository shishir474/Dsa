Best time to buy and sell stock 3.

Given a prices[] which indicates the price of the stock on ith day. You need to maximise the total profit that you can make 
Constraint is you can only do 2 transactions atmost. 
and again, before buying any stock, you need to sell the previous stock. You cannot do 2 straight buys.

i - index
buy - 0 or 1 
k - number of transactions left. We can only do atmost k transations.

If buy == true: // which means that we already bought a stock before
    // I have 2 options, either I can sell it or I can hold it 
    return max(prices[i] + solve(i+1, 0, k-1), solve(i+1, 1, k));
else 
    // which means that we haven't bought a stock yet
    // I have 2 options, either I can buy it or I can skip the current index and buy in future
    return max(-prices[i] + solve(i+1, 1, k-1), solve(i+1, 0, k));

----------------------------------------------------------------

Another way to look at it

if buy == true:
    // I'll buy the stock or I'll skip this
    return max(-prices[i] + solve(i+1, 0, k), solve(i+1, 1, k));
else:
    // I'll sell the stock (completed 1 txn) or I'll hold it
    return max(prices[i] + solve(i+1, 1, k-1), solve(i+1, 0, k));

// a transaction is only considered complete once you sell the stock 

----------------------------------------------------------------

Base case:
if (i >= n || k == 0) return 0;

// 3 changing parameters (i, buy, k)
// buy + sell comprise of 1 transaction. 
// When you sell then only a txn is considered complete

----------------------------------------------------------------

// recursive solution
int solve(int i, int buy, int k){
    if (i >= n || k == 0) return 0;

    if (buy == true) {
        // I have 2 options, either I can sell it or I can hold it
        return max(prices[i] + solve(i+1, 0, k-1), solve(i+1, 1, k));
    } else {
        // which means that we haven't bought a stock yet
        // I have 2 options, either I can buy it or I can skip the current index and buy in future
        return max(-prices[i] + solve(i+1, 1, k), solve(i+1, 0, k));
    }
}
//  TC: O(2^n)  - at each index, I have 2 options (buy/sell)
// SC: O(n) - auxilary stack space 


------------------------------------------------------

// recursive + memoisation
int t[100002][2][3];
vector<int> arr;
int solve(int i, int buy, int k){
    if (i >= arr.size() || k == 0) return 0;
    // added memoisation
    if(t[i][buy][k] != -1) return t[i][buy][k];

    if (buy == true) {
        // I have 2 options, either I can sell it or I can hold it
        return t[i][buy][k] = max(arr[i] + solve(i+1, 0, k-1), solve(i+1, 1, k));
    } else {
        // which means that we haven't bought a stock yet
        // I have 2 options, either I can buy it or I can skip the current index and buy in future
        return t[i][buy][k] = max(-arr[i] + solve(i+1, 1, k), solve(i+1, 0, k));
    }
}

int maxProfit(vector<int>& prices) {
    memset(t, -1, sizeof(t));
    arr = prices;
    return solve(0, 0, 2);
}

// TC: O(n * 2 * 2)
// SC: O(n * 2 * 2) + O(n)
// O(n * 2 * 2) for dp array and O(n) for the recursion stack


----------------------------------------------------------------
To get rid of recusive stack space, writing a tabulation solution 
int dp[n+1][2][3];

// dp[n][][] = 0; base case 1
for(int buy = 0; buy <= 1; buy++){
    for(int k = 0; k <= 2; k++){
        dp[n][buy][k] = 0;
    }
}
// dp[][][0] = 0; base case 2
for(int i=0; i<=n ; i++){
    for(int buy = 0; buy <= 1; buy++){
        dp[i][buy][0] = 0;
    }
}

for(int i = n-1; i>=0; i--){
    for(int buy = 0; buy <= 1; buy++){
        for(int k = 1; k<=2; k++){
            if (buy == true) {
                // I have 2 options, either I can sell it or I can hold it
                dp[i][buy][k] = max(arr[i] + dp[i+1][0][k-1], dp[i+1][1][k]);
            } else {
                // which means that we haven't bought a stock yet
                // I have 2 options, either I can buy it or I can skip the current index and buy in future
                dp[i][buy][k] = max(-arr[i] + dp[i+1][1][k], dp[i+1][0][k]);
            }
        }
    }
}

return dp[0][0][2];     // our ans will be at dp[0][0][2] value after completing 2 transactions and we not owning any stock 

TC: O(n * 2 * 3)
SC: O(n * 2 * 3) - for dp array
No auxilary stack space as we have converted it to tabulation

-------------------------------------------------------------------

Space optimization:
Since the ith state only depends on the (i+1)th state, we can reduce the 3D dp into constant space using flag variable 

int dp[2][2][3];

// dp[n][][] = 0; base case 1
for(int buy = 0; buy <= 1; buy++){
    for(int k = 0; k <= 2; k++){
        dp[1][buy][k] = 0;
    }
}
// dp[][][0] = 0; base case 2
for(int i=0; i <= 1 ; i++){
    for(int buy = 0; buy <= 1; buy++){
        dp[i][buy][0] = 0;
    }
}

int flag = 0;   // flag represents the current row which will be filling

for(int i = n-1; i>=0; i--){
    for(int buy = 0; buy <= 1; buy++){
        for(int k = 1; k<=2; k++){
            if (buy == true) {
                // I have 2 options, either I can sell it or I can hold it
                dp[flag][buy][k] = max(arr[i] + dp[flag^1][0][k-1], dp[flag^1][1][k]);
            } else {
                // which means that we haven't bought a stock yet
                // I have 2 options, either I can buy it or I can skip the current index and buy in future
                dp[flag][buy][k] = max(-arr[i] + dp[flag^1][1][k], dp[flag^1][0][k]);
            }
        }
    }
    // toggle the flag 
    flag = flag ^ 1;
}

// after filling the last row, the flag would have toggled 1 more time, hence flipping it again
flag = flag ^ 1;
return dp[flag][0][2]; 

// TC: O(n * 2 * 2)
// SC: O(1) - constant space