Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input :     [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]


corner case: [0 0 0 0 0]

int Solution::maxProduct(const vector<int> &A) {
    int n=A.size();
   
    int ans = *max_element(A.begin(), A.end());
    
    int mx=A[0], mn=A[0];
    
    for(int i=1;i<n;i++){
        int a = max({mx*A[i], mn*A[i], A[i]});
        int b = min({mx*A[i], mn*A[i], A[i]});
        ans = max(ans, a);
        mx = a; 
        mn = b;
    }

    return ans;
}
