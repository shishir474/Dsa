152. Maximum Product Subarray

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

// We have to find the maximum product of a contiguous subarray in the given array.

// Brute force: can be done in O(n^2) time complexity by checking all possible subarrays.

// But we need to do it in O(n) time complexity.

input[]: 2      3                -2                         4
mx[]:    2    max(6,6,3)= 6.  max(-12,-6,-2)= -2        max(-8,-48,4)=4
mn[]:    2    min(6,6,3)= 3.  min(-12,-6,-2)= -12.      min(-8,-48,4)=-48

ans = max(ans, mx[i], mn[i]);
// This will give us the maximum product of a contiguous subarray.

// recurrence relation:
mx[i] = max(mx[i-1]*nums[i], mn[i-1]*nums[i], nums[i])
mn[i] = min(mx[i-1]*nums[i], mn[i-1]*nums[i], nums[i])



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mx[n],mn[n];
        
        mx[0]=mn[0]=nums[0];
        
        int ans=nums[0];
        
        for(int i=1;i<n;i++){
            mx[i]=max({mx[i-1]*nums[i], mn[i-1]*nums[i], nums[i]});
            mn[i]=min({mx[i-1]*nums[i], mn[i-1]*nums[i], nums[i]});
            ans = max({ans,mx[i],mn[i]});
        }
        
        return ans;
    }
};