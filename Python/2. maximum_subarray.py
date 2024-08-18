# https://leetcode.com/problems/maximum-subarray/description/
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = -1e9
        curr_sum = 0
        for i in nums:
            curr_sum+=i
            if curr_sum > max_sum:
                max_sum = curr_sum
            if curr_sum < 0:
                curr_sum = 0

        return max_sum
    

# Cool way of iterating over loops in python
for i,val in enumerate(nums):
    print(i,val)
    
    
# get the max subarray as well
def getMaxSubArray(self, nums):
    curr_sum = 0
    max_sum = 0
    
    temp_s = 0 # temp_start indicates the point from where we should begin considering the nxt subarray
    
    start = 0 # start and end indicate the maxSumSubarray
    end = 0
    
    for i in nums:
        curr_sum+=i
        if curr_sum > max_sum:
            # update the max_sum, start and end
            max_sum = curr_sum
            start = temp_s
            end = i
        if curr_sum < 0:
            # reset my curr_sum to 0 and temp_s to i+1
            curr_sum = 0
            temp_s = i+1

    return max_sum, nums[start:end+1]

    
max_sum, maxSubarray = getMaxSubArray(nums)
print(max_sum, maxSubarray)
    
