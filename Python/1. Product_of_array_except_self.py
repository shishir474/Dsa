# https://leetcode.com/problems/product-of-array-except-self/description/

# Dp solution also exists be creating prefix and postfix array
# TC: O(n) SC: O(1) Most optimal solution
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1]*len(nums)
        prefix = 1
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]
        postfix = 1
        for i in range(len(nums)-1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]
        
        return res
    
    
    
    
# cool way to construct prefix and postfix array in python

import operator
from itertools import accumulate

prefix = list(accumulate(nums, operator.mul))
suffix = list(accumulate(reversed(nums), operator.mul))

# accumulate() returns an iterator. It takes 2 args first the list and second the operator that will be applied. By defualt the operator is +
