Paint House!

Medium

170

4
Asked In:
LinkedIn
Problem Description

There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.



Problem Constraints
1 <= N <= 105

1 <= A[i][j] <= 103



Input Format
First and only argument is an 2D integer matrix A of size N x 3 denoting the cost to paint the houses.



Output Format
Return an integer denoting the minimum total cost to paint all houses.



Example Input
Input 1:

 A = [  [1, 2, 3]
        [10, 11, 12]
     ]


Example Output
Output 1:

 12

int dp[100001][3];
int helper(int i,int n, vector<vector<int> > &A, int color){
    if (i>=n) return 0;
    if (dp[i][color] != -1) return dp[i][color];
    if (color==0){
        return dp[i][color] = A[i][0] + min(helper(i+1,n,A,1), helper(i+1,n,A,2));
    }
    else if(color==1){
        return dp[i][color] = A[i][1] + min(helper(i+1,n,A,0), helper(i+1,n,A,2));
    }else{
        return dp[i][color] = A[i][2] + min(helper(i+1,n,A,0), helper(i+1,n,A,1));
    }
}
int Solution::solve(vector<vector<int> > &A) {
    memset(dp,-1,sizeof(dp));
    int n=A.size();
    int ans1 = helper(0,n,A,0);
    int ans2 = helper(0,n,A,1);
    int ans3 = helper(0,n,A,2);

    return min({ans1,ans2,ans3});
}
