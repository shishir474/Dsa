class Solution:
    def trap(self, nums: List[int]) -> int:
        # at each index, I need to calculate the amount of water that can be stored
        # for each index - find the length of the tallest pillar on the rhs and lhs
        # amount of water stored at index i = min(lhs[i-1], rhs[i+1]) - height[i]
        # if min(lhs[i-1], rhs[i+1]) - height[i] < 0: no water can be stored on the ith index

        # lhs[i] represents the length of the tallest pillar from index 0..i in nums
        # rhs[i] represents the length of the tallest pillar from index i..n-1 in nums

        n = len(nums)
        lhs = [0]*n
        rhs = [0]*n

        lhs[0] = nums[0]
        for i in range(1,n):
            lhs[i] = max(lhs[i-1], nums[i])

        rhs[n-1] = nums[n-1]
        for i in range(n-2,-1,-1):
            rhs[i] = max(rhs[i+1], nums[i])

        amt_of_water = 0
        for i in range(n):
            # no water will be stored at i==0 and i==n-1 indexes
            if i==0 or i==n-1:
                continue
            
            tmp = min(lhs[i-1], rhs[i+1]) - nums[i]
            if tmp > 0:
                amt_of_water += tmp

        return amt_of_water


# TC: O(3 * n) = O(n)
# SC: O(2 * n) = O(n)

# Cannot be optimised any further in terms of space complexity. 
# At each index, we need to know the tallest pillar on the lhs and rhs.