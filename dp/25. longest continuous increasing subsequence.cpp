674. Longest Continuous Increasing Subsequence

Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.


solution:
since its a subarray, it should be continuous. If subsequence we used to go from i-1 till 0 bcoz there diconnectivity is allowed , but since here it is subarray it should be continuous, so a[i]>a[i-1] then only we can extend a[i-1], otherwise dp[i]=1
length will be atleast 1, as there will be atleast 1 length subarrya ending at index i


class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int n=a.size();
        vector<int> t(n,1);
        // t[i]>=1
        
        int ans=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) t[i]=t[i-1]+1;
            ans=max(ans,t[i]);
        }
        
        return ans;
    }
};