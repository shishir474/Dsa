343. Integer Break

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:

2 <= n <= 58


class Solution {
public:
    int t[59];
    int solve(int n){
        if (n<=2) return 1;
        if (t[n]!=-1) return t[n];

        // n --> is split into i and (n-i)
        // what's the best value that we could get for (n-i) -> either it can be solve(n-i) or we could also just use (i, (n-i)) keep as is
        // (i, solve(n-i))
        // op1 = i * (n-i); 
        // op2 = i * solve(n-i) 
        // tans = max(op1, op2)
        // finalans = max(finalans, tans)
        int finalans = 0;
        for (int i=1;i<n;i++){
            int op1 = i * (n-i); 
            int op2 = i * solve(n-i); 
            int tans = max(op1, op2);
            finalans = max(finalans, tans)
        }
        
        return t[n] = finalans;
    }
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};

// TC: O(N)
// SC: O(N)
