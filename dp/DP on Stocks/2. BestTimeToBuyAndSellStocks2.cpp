https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Best Time to Buy and Sell Stock II

// Space Optimisation Technique used here are important for interviews

You have been given prices of stocks on each day. You are allowed to buy and sell stocks. In the part 1, you were allowed to buy once and sell once, but over here you can buy as many times as you want and you can sell as many times as you want.
You have to find the maximise the profit
    B  S  B  S
[7, 1, 5, 3, 6, 4]
    4 + 3 = 7
Before buying any stock, you need to sell the previous stock. You cannot do 2 straight buys. This is the clear instruction given to you.
    B  B  S  S.  --> not allowed 
[7, 1, 5, 3, 6, 4]

*** Problem Analysis **

At each index, we have multiple options. 
If we have not bought any stock - then I can either buy or skip
If we have bought a stock - then I can either sell it or hold it

A lot of ways -- so you try all ways and choose the maximum one.

Trying all ways -- recursion

How to write recurrence?
The standard procedure of writing recurrence is to express everything in terms of index 

Express everything in terms of index f(idx)
Now do we need any other parameter here?
On any index, I have to know whether I have bought a stock previously or not.
Because if you have bought a stock previously, then you cannot buy the stock at the current index again. You can either sell it or hold it 
But on the contrary if you have not bought a stock previously, then you can either buy it or skip it

To track this, we'll maintain a buy variable which indicates whether we have bought a stock or not.
if buy = true --> bought a stock previously
else --> not bought a stock previously

if buy == true:
    // either I can sell the stock at this point or I can hold the stock 
    // If I hold the stock, we simply move to next index i+1 and buy remains true (since we didn't sold the stock -- so in future we already hold this stock)
    // If I sell the stock, I'll make gain prices[i] and I simply move to next index i+1, with buy as false (since we sold the stock and we dont hold it anymore)
    // return the max of both the cases 
    return max(solve(i+1, 1), prices[i] + solve(i+1, 0));
else:
    // buy is false - we dont hold any stock
    // Either I can buy the stock at this point or I can skip.
    // If I buy stock, I'll be putting in -prices[i] (hence minus sign) and simply move to next index i+1 with buy = true (since we bought a stock)
    // If I skip, (we didn't hold any stock previusly nor bought anything at this point), so buy remains false, and we move to next index i+1
    // return max of both cases 
    return max(solve(i+1,0), -prices[i] + solve(i+1, 1));


----------------------------------------------
Other way of looking at this is:

if buy == true:
    // If I decide to buy at that day, the profit I'll add is -prices[i] and move to next day (i+1, 0) - you cannot buy again hence 0
    // If you decide to skip on that day, the profit you make is 0 and you move to next day (i+1, 1)  
    return max(-prices[i] + solve(i+1, 0), solve(i+1, 1));
else:
    // If you decide to sell, the profit that you'll make is prices[i], and you move to next day i+1 with buy as true
    // if you decide to hold, the profit you make is 0 and you move to next day i+1 with buy as false
    return max(prices[i] + solve(i+1, 1), solve(i+1, 0));

Base Case:
    // If you have empty array, return 0 -- you cannot make any profits with []

----------------------------------------------
// psuedo code -- recursion
solve(int i, bool buy){
    if (i >= arr.size()) return 0;

    if(buy){    // I have previously bought a stock. At this point, either I can sell it or hold it
        return max(prices[i] + solve(i+1, 0), solve(i+1, 1));
    }
    else{ // I have not bought any stock - Either I can buy or I can skip 
        return max(-prices[i] + solve(i+1, 1), solve(i+1, 0));
    }

}
// TC: O(2^n) - at every index 2 options take or not take 
// SC: O(n) - auxilary stack space

----------------------------------------------

// We can definitely optimse the recursive solution, because there will be overlapping subproblems.
// If you try to draw the recursion tree, you will notice that there are overlapping subproblems of f(idx, buy). So you can definitely apply the memoisation technique. The changing parameters are idx and buy 
// value of idx from 0 to n-1 ( n different values)
// value of buy - 0 or 1 ( 2 different values)
// dp[n][2] -- this will be the DP state that you'll use to optimise

// memoised the above psuedo code -- recursoin + memoisation
    int t[30005][2];
    vector<int> arr;            // created a global reference for prices, so that we dont need to pass in function calls
    int solve(int i, bool buy){
        if (i >= arr.size()) return 0;
        // added memoisation 
        if(t[i][buy] != -1) return t[i][buy];

        if(buy){    // I have previously bought a stock. At this point, either I can sell it or hold it
            return t[i][buy] = max(arr[i] + solve(i+1, 0), solve(i+1, 1));
        }
        else{ // I have not bought any stock - Either I can buy or I can skip 
            return t[i][buy] = max(-arr[i] + solve(i+1, 1), solve(i+1, 0));
        }

    }
    int maxProfit(vector<int>& prices) {
        memset(t, -1, sizeof(t));
        arr = prices;
        return solve(0, 0);
    }

    // TC: O(n * 2) = O(n)
    // SC: O(n * 2) + O(n)
        // O(n * 2) for dp array & O(n) for auxilary stack space


----------------------------------------------

// Tabulation

// In order to remove this auxilary stack space - we have to apply tabulation
Steps of Tabulation:
1. Write base case
2. Write all the changing parameters
3. Copy the recurrence 

Base case was idx >= n
We will create a dp[n+1][2] and we'll be starting with dp[n][0] = dp[n][1] = 0;
// In recusion we went from 0 to n-1. In tabulation we'll do the reverse of this i.e from n-1 to 0
// what about buy? It will go from 0 to 1

vector<vector<int>> dp(n + 1, vector<int>(2, 0));

dp[n][0] = dp[n][1] = 0;

for(int i = n - 1; i >= 0; i--){
    for(int buy = 0; buy <= 1; buy++){
        if(buy){    // I have previously bought a stock. At this point, either I can sell it or hold it
            dp[i][buy] = max(arr[i] + dp[i+1][0], dp[i+1][1]);
        }
        else{ // I have not bought any stock - Either I can buy or I can skip 
            dp[i][buy] = max(-arr[i] + dp[i+1][1], dp[i+1][0]);
        }
    }
}

return dp[0][0];    // in the end, you dont want to hold any stock hence return dp[0][0] and not dp[0][1] (this means you are holding a stock)

    // TC: O(n * 2)
    // SC: O(n * 2)

----------------------------------------------

// Space Optimised technique:
// Since the ith index only depends on i+1, we dont need to maintain dp[n+1][2]. Instead dp[2][2] will work fine.

vector<vector<int>> dp(2, vector<int>(2, 0));
dp[1][0] = dp[1][1] = 0;

int flag = 0;           // flag indicates the current row which we are filling

for(int i = n - 1; i >= 0; i--){
    for(int buy = 0; buy <= 1; buy++){
        if(buy){    // I have previously bought a stock. At this point, either I can sell it or hold it
            dp[flag][buy] = max(arr[i] + dp[flag^1][0], dp[flag^1][1]);
        }
        else{ // I have not bought any stock - Either I can buy or I can skip
            dp[flag][buy] = max(-arr[i] + dp[flag^1][1], dp[flag^1][0]);
        }
    }
    // after each row, flip the flag
    flag = flag^1;
}

// toggle the flag one more time - since after the last row, you'd have toggled it 
flag = flag^1;

return dp[flag][0];

// TC: O(n*2)
// SC: O(1)