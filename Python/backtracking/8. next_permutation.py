# https://leetcode.com/problems/next-permutation/description/


class Solution:
    def reverse(self, lo, hi, nums):
        while lo<=hi:
            nums[lo], nums[hi] = nums[hi], nums[lo]
            lo+=1
            hi-=1
        
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # find the inflection point
        n, idx = len(nums), -1

        for i in range(n-1, 0, -1):
            if nums[i-1] < nums[i]:
                idx = i-1
                break
        
        if idx==-1:
            self.reverse(0,n-1,nums)
            return
        
        print(idx)
        # find the first element greater that nums[idx]
        for j in range(n-1,idx,-1):
            if nums[j] > nums[idx]:
                # swap nums[i], nums[j]
                nums[i], nums[j] = nums[j], nums[i]
                self.reverse(idx+1,n-1,nums)
                return

# TC: O(n)
# SC: O(1)