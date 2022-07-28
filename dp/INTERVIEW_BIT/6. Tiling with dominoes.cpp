Tiling With Dominoes

Medium

222

9
Asked In:
Directi
Uber Technologies Inc
Problem Description
 
 

Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.

Return the answer modulo 109 + 7 .

NOTE:

See the sample explanation for better understanding.


Problem Constraints
1 <= A <= 105



const int mod = 1e9+7;
int Solution::solve(int n) {
    int A[n + 1], B[n + 1];
    A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1;
    for (int i = 2; i <= n; i++) {
        A[i] = (A[i - 2]%mod + (2%mod * B[i - 1]%mod)%mod)%mod;
        B[i] = (A[i - 1]%mod + B[i - 2]%mod)%mod;
    }
 
    return A[n];

}


Variations:
1. Tiling m*n floor with m*1 tiles
2. Tiling 2*n floor with 2*1 tiles