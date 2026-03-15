class Solution:
    def maxSubArray(self, nums: List[int]) -> Tuple[int, int, int]:
        max_sum = float('-inf')
        curr_sum = 0

        start = end = temp_start = 0

        n = len(nums)
        for i in range(n):
            curr_sum += nums[i]

            if curr_sum > max_sum:
                max_sum = curr_sum
                start = temp_start
                end = i
                
            if curr_sum < 0:
                curr_sum = 0   # reset current sum
                temp_start = i + 1  # potential start of new subarray

        return max_sum, start, end