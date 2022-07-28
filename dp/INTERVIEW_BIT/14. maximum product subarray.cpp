Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]


corner case: [0 0 0 0 0]

int Solution::maxProduct(const vector<int> &A) {
    int n=A.size();
    int currmax=1, currmin = 1;
    
    int ans = *max_element(A.begin(), A.end());  // [-1]

    for(int i=0;i<n;i++){
        if (A[i]==0) {currmax = currmin = 1; continue;} // reset currmax and currmin when 0 is encountered
        int temp = A[i]*currmax;
        currmax = max({A[i]*currmax, A[i]*currmin, A[i]}); // [-1, 8]
        currmin = min({temp, A[i]*currmin, A[i]});  // [-1, -8]
        ans = max(ans, currmax);
    }

    return ans;
}