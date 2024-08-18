# https://leetcode.com/problems/combination-sum-iv/description/

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        mp = {}
        def solve(i, target):
            if target==0:
                return 1
            if i==len(nums):
                return 0
            if (i,target) in mp: #  memoisation key needs to include both i and target
                return mp[(i,target)]
            
            ans=0
            ans+=solve(i+1, target)

            if nums[i] <= target:
                ans+=solve(0, target-nums[i]) # generally we call recursion at i, but here we are considering all (1,1,2) and (1,2,1) as 2 different combinations, hence calling from 0

            mp[(i,target)] = ans
            return ans
        
        return solve(0, target)

        