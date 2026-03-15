class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n= len(nums)

        pivot = -1
        # step1: find the pivot point
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                pivot = i
                break
        
        if pivot == -1:
            nums.reverse()
            return
        
        for j in range(n-1, pivot, -1):
            if nums[j] > nums[pivot]:
                # swap nums[j] and nums[pivot]
                nums[j], nums[pivot] = nums[pivot], nums[j]
                break
        
        # sort nums[pivot+1...n-1]
        nums[pivot+1:] = sorted(nums[pivot+1:])
        
        # TC: O(n) + O(nlogn) = O(nlogn)
        # SC: O(1)