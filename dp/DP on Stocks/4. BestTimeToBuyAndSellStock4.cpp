Best Time to Buy and Sell Stock 4. 

This problem is actually an extension of the Best Time to Buy and Sell Stock 3 problem.
In this problem, we are allowed to make at most k transactions, whereas in the previous one, we were allowed to make atmost 2 transactions.

class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        // THis is the most optimised Solution -- For knowing the intuition refer to Best Time To Buy and Sell Stock 3 problem
        
        int dp[2][2][k+1];

        // dp[n][][] = 0; base case 1
        for(int buy = 0; buy <= 1; buy++){
            for(int k1 = 0; k1 <= k; k1++){
                dp[1][buy][k1] = 0;
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
                for(int k1 = 1; k1 <= k; k1++){
                    if (buy == true) {
                        // I have 2 options, either I can sell it or I can hold it
                        dp[flag][buy][k1] = max(arr[i] + dp[flag^1][0][k1-1], dp[flag^1][1][k1]);
                    } else {
                        // which means that we haven't bought a stock yet
                        // I have 2 options, either I can buy it or I can skip the current index and buy in future
                        dp[flag][buy][k1] = max(-arr[i] + dp[flag^1][1][k1], dp[flag^1][0][k1]);
                    }
                }
            }
            // toggle the flag 
            flag = flag ^ 1;
        }

        // after filling the last row, the flag would have toggled 1 more time, hence flipping it again
        flag = flag ^ 1;
        return dp[flag][0][k]; 

        // TC: O(n * 2 * k)
        // SC: O(k) - linear space
    }
};