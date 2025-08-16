Best Time to Buy and Sell Stock with Transaction Fee

You are given prices[] which indicates the price of the stock on the ith day. You can do as many transactions(buy-sell) as you want, but each transaction has a fee assoicated with it.
You need to maximise the profit that you can generate 


// This is the general recurrence relation
solve(idx, buy){
    if(buy == true){
        // I'll buy stock or I'll skip this
        // If I buy stock I cannot buy in the future hence 0 and If I skip it I can buy in the future hence 1
        return max(-prices[idx] + solve(idx+1, 0), solve(idx+1, 1));
    } else {
        // I'll sell stock or I'll hold it. 
        // If I sell stock I can buy in the future hence 1 and If I hold it I cannot buy in the future, hence 0
        return max(prices[idx] + solve(idx+1, 1), solve(idx+1, 0));
    }
}

// TC: O(2^n)   -- at each day we have 2 choices (buy/sell or skip)
// SC: O(n) -- auxillary stack space

-----------------------------------------------------

// Now each time we complete a transaction, we need to pay a txn fee

// recusion + memoisation solution
vector<int> arr;
int transactionFee = -1;                    // created a global variable so we dont need to pass in the function calls
int t[50004][2];
int solve(int idx, int buy){
    if (idx >= arr.size()) return 0;
    // adding memoisation
    if(t[idx][buy] != -1) return t[idx][buy];
    if(buy == true){
        // I'll buy stock or I'll skip this
        // If I buy stock I cannot buy in the future hence 0 and If I skip it I can buy in the future hence 1
        return t[idx][buy] = max(-arr[idx] + solve(idx+1, 0), solve(idx+1, 1));
    } else {
        // I'll sell stock or I'll hold it. 
        // If I sell stock I can buy in the future hence 1 and If I hold it I cannot buy in the future, hence 0
        return t[idx][buy] = max(arr[idx] - transactionFee + solve(idx+1, 1), solve(idx+1, 0));
    }
}


int maxProfit(vector<int>& prices, int fee) {
    arr = prices;
    transactionFee = fee;
    memset(t, -1, sizeof(t));
    // 0,1 because we are starting from 0th index and we would first need to buy 
    return solve(0, 1);
}

// TC: O(n * 2)
// SC: O(n * 2) + O(n)
// O(n * 2) for the dp array and O(n) for the recursion stack


-----------------------------------------------------

Tabulation Solution - to get rid of auxilary stack space

int t[n+1][2];
t[n][0] = t[n][1] = 0;
for(int i = n-1; i >= 0; i--){
    for(int buy = 0; buy <= 1;  buy++){
        if(buy == 1){
            t[i][buy] = max(-arr[i] + t[i+1][0], t[i+1][1]);
        } else {
            t[i][buy] = max(arr[i] - transactionFee + t[i+1][1], t[i+1][0]);
        }
    }
}
return t[0][1];
// This state which we return in the tabulation approach should be same as the one in the memoization approach solve(0, 1)

// TC: O(n * 2)
// SC: O(n * 2)

-----------------------------------------------------

Space Optimised Solution:
Since the ith row only depends on the (i+1)th row, we can optimise our space complexity to O(1) by maintianing 2 rows in our dp array effectively making our space complexity O(1)

int t[2][2];
t[1][0] = t[1][1] = 0;
int flag = 0;           // flag represents the current row which we are filling
for(int i = n-1; i >= 0; i--){
    for(int buy = 0; buy <= 1;  buy++){
        if(buy == 1){
            t[flag][buy] = max(-arr[i] + t[1-flag][0], t[1-flag][1]);
        } else {
            t[flag][buy] = max(arr[i] - transactionFee + t[1-flag][1], t[1-flag][0]);
        }
    }
    flag = 1 - flag;
}

flag = 1 - flag;

return t[flag][1];

// TC: O(n * 2)
// SC: O(1)