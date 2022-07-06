Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<vector<int>>& res,int n){
        if (idx==n-1){
            res.push_back(nums);
            return;
        }
        
        for(int i=idx;i<n;i++){
            swap(nums[i], nums[idx]);
            solve(i+1,nums,res,n);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        solve(0,nums,res,n);
        return res;
    }
};