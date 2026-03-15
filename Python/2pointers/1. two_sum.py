# https://leetcode.com/problems/two-sum/description/

# Solution1: Using 2 nested loops. TC: O(n^2), SC: O(1)

# Solution2: sort the input array and 2 pointers TC: O(nlogn) + O(n)
# SC: O(1)

# Solution3: linear solution using sets. For each element, check if you encoutered its complimentary element.
# TC: O(n) 
# SC: O(n) -- assuming all elements are distinct

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