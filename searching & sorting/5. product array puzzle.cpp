Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to 
the product of all the elements of nums except nums[i].
If the array has only one element the returned list should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.
 

Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.


class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    typedef long long ll;
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        if (n==1) return {1}; // base case
        
        vector<ll> p(n),s(n);
        ll prod=1;
        for(int i=0;i<n;i++){
            prod = prod*nums[i];
            p[i]=prod;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            s[i]=prod;
        }
        
        vector<ll> res;
        for(int i=0;i<n;i++){
            if(i==0){
                res.push_back(s[i+1]);
            }
            else if(i==n-1){
                res.push_back(p[i-1]);
            }
            else{
                res.push_back(p[i-1]*s[i+1]);
            }
        }
        
        return res;
        
    
    }
};
