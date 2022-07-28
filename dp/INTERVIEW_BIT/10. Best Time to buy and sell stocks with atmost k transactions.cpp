Problem Description

Given an array of integers A of size N in which ith element is the price of the stock on day i.

You can complete atmost B transactions.

Find the maximum profit you can achieve.

NOTE: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



Problem Constraints
1 <= N <= 500

0 <= A[i] <= 106

0 <= B <= 109



Input Format
The First argument given is the integer array A.

The Second argument is integer B.



Output Format
Return the maximum profit you can achieve by doing atmost B transactions.



int maxTransactions(vector<int> &A){
    int n = A.size();
    int totalProfit = 0;
    for(int i=1;i<n;i++){
        totalProfit+=max(0, A[i]-A[i-1]);
    }

    return totalProfit;
}

int Solution::solve(vector<int> &A, int k) {
    int n = A.size();
    if (k >= n / 2) return maxTransactions(A);
        
    int dp[k+1][n];

    for (int i = 0; i <= k; i++) {
        int tmpMax =  -A[0];
        for (int j = 0; j < n; j++) {
            if (i==0 || j==0) {dp[i][j] = 0; continue;}

            dp[i][j] = max(dp[i][j - 1], A[j] + tmpMax);
            tmpMax =  max(tmpMax, dp[i - 1][j - 1] - A[j]);
        }
    }

    return dp[k][n - 1];
    
}
