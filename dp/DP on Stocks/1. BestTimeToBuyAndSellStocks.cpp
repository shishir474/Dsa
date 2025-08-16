// There are 6 problems in DP on stocks.
// In interviews you cannot skip the space optimisation technique. This is expected in all the coding interviews

121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.



// Solution 1: Using prefix_min[] and suffix_max[]

If you are selling on ith day, you buy on the minimum price from 1st -> (i - 1)th day
So for every guy if you keep track of the minimum price on the left, my job is done 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // keep track of the min price in the prefix [0 .. i] in prefix_min[i]
        // keep track of the max price in the suffix [i .. n-1] in suffox_max[i]
        vector<int> prefix_min(n), suffix_max(n);
        prefix_min[0] = prices[0];
        for(int i = 1; i < n; i++){
            prefix_min[i] = min(prefix_min[i - 1], prices[i]);
        }

        suffix_max[n-1] = prices[n-1];
        for(int i = n-2; i>=0; i--){
            suffix_max[i] = max(prices[i], suffix_max[i+1]);
        }

        // at this point we know what's the min prices till the ith index i.e in prefix[0..i]
        // and what's the max price from (i+1 to n-1) 

        int max_profit = INT_MIN;
        for(int i=0; i< n-1; i++){
            max_profit = max(max_profit, suffix_max[i + 1] - prefix_min[i]);
        }

        // if you can't return any profit, return 0
        return max_profit <= 0 ? 0 : max_profit;

    }
};

// TC: O(N) for building prefix_min, suffix_max and final ans computation
// SC: O(2*N)


// Solution 2: Space optimised solution

// If you are selling on ith day, you buy on the minimum price from 1st -> (i - 1)th day

int mini = arr[0], max_profit = 0;  // the profit on 0th day is 0
for(int i = 1; i < n; i++){
    max_profit = max(max_profit, arr[i] - mini);
    mini = min(mini, arr[i]);
}

return max_profit;



// Thinking the other way around 

// If you keep track of the max value from the right side, that will be your selling point


int maxi = arr[n-1], max_profit = 0;
for(int i = n-2; i >= 0; i--){          // I'm buying on the ith day & I know the max selling price
    max_profit = max(max_profit, maxi - arr[i]);
    maxi = max(maxi, arr[i]);
}

return max_profit;

// If you keep track of the max value from the right side, that will be your selling point 
// At ith index if you choose to buy the stock, the max profit you can get is mx - prices[i]
// and you keep on updating max as you move backwards (from right to left)

TC: O(N) 
SC: O(N)