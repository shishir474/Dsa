# https://leetcode.com/problems/missing-number/description/

# Brute force sol is to use a hashset, which takes O(n) time and O(n) space
# Better solution is to utilise the xor property of the number, This sol takes O(n) time and O(1) space
class Solution:
    # i xor i = 0 xor of 2 identical nbr is 0
    # i xor 0 = 1 xor of i and 0 is 1
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        xor_val = 0
        for i in range(n+1): # 0 to n
            xor_val = xor_val^i
        for i in nums:
            xor_val = xor_val^i
        return xor_val