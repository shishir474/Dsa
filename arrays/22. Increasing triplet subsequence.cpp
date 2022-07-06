Increasing Triplet Subsequence

Solution
Given an integer array nums, return true if there exists a triple of 
indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.

Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

// solutiuon 1
maintain prefix array where p[0..i] stores min element till ith index
maintaing suffix array where s[i..n-1] stores the max element from i to (n-1)th index
so if for any j in range [1..n-2]  p[i-1] < a[j] < s[i+1] then return true
TC:O(N) SC: O(N)


O(1) space solution

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
           int small=INT_MAX,big=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= small) small=nums[i];
            else if(nums[i] <= big) big=nums[i];
            else return true;
        }
        return false;
    }
};