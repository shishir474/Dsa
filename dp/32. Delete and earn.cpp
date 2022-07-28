740. Delete and Earn
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.


solutions:
This is similar to house robber problem.
[x-1,x,x,x,x,x,x+1,x+1]
If I choose to delete val x thn all values equal to x-1 and x+1 are also deleted

SO if I delete x, then I get x*freq(x) + solve(i1), where i1 index is the upper_bound of a[i]+1, i.e value just greater than a[i]+1, bcoz a[i]+1 is now deleted and cannot be considered
If I dont delete x, then then I can go to j, where j index is the upper_bound of a[i], i.e I can delete a[i]+1

TC: O(nlogn)
SC: O(n);
class Solution {
public:
    int t[20002];
    int solve(int i, vector<int>& nums){
        if(i>=nums.size()) return 0;
        
        if(t[i]!=-1) return t[i];
        
        int i1=upper_bound(nums.begin(),nums.end(),nums[i]+1) - nums.begin();
        int j=upper_bound(nums.begin(),nums.end(),nums[i]) - nums.begin();
        int op1 = nums[i]*(j-i) + solve(i1,nums);
        
        int op2 = solve(j,nums);
        
        return t[i]= max(op1,op2);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};