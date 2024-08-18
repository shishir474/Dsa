# https://leetcode.com/problems/maximum-product-subarray/description/


# At each step, the new maximum product can be either the current number itself or the product of the current number with the previous maximum or minimum product.

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums: 
            return 0
        
        curr_max = curr_min = max_prod = nums[0]

        for num in nums[1:]:
            if num < 0: # if num is -ve then swap curr_max with curr_min
                curr_max, curr_min = curr_min, curr_max
            
            curr_max = max(num, curr_max*num) # max of curr_num or curr_max*num if the curr_max was +ve it could have gotten us a biggger nuber
            curr_min = min(num, curr_min*num) # min of curr_num or curr_min*num
            max_prod = max(max_prod, curr_max)
        
        return max_prod
    
# TC: O(n)
# SC: O(1)