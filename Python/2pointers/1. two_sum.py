# https://leetcode.com/problems/two-sum/description/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:    
        mp = {}  # val: idx
        for i,n in enumerate(nums):
            diff = target - n
            if diff in mp:
                return {mp[diff], i}
            mp[n] = i

        return
      
# // you cannot sort the array, positions will change



class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:    
        mp = {}  # val: idx
        for i in range(len(nums)):
            if target-nums[i] in mp:
                return {mp[target-nums[i]], i}
            mp[nums[i]] = i