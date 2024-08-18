class Solution:
    def solve(self, lo, hi, nums):
        n = hi-lo+1
        if n==1:
            return nums[lo]
        elif n==2:
            return max(nums[lo], nums[lo+1])

        t = [0]*n
        t[0] = nums[lo]
        t[1] = max(nums[lo],nums[lo+1])

        for i in range(2,n):
            t[i] = max(nums[i+lo] + t[i-2], t[i-1])
        
        return t[n-1]

    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return nums[0]
        elif n==2:
            return max(nums[0], nums[1])
        return max(self.solve(0,n-2,nums), self.solve(1,n-1,nums))

# Houses are arranged in a circular fashion, which means If I loot 1st house, I cannot loot the n-1 th house and If I choose to loot n-1 th house, then I cannot loot 1st house
# so the best way to deal with this condition is 
#     return max(solve(0,n-2,nums), solve(1,n-1,nums))
# Here we have made sure that first call is made for 0 to n-2, which excludes n-1 th house
# and second call excludes the 1st house (1,n-1)

# TC: O(n) + O(n)
# SC: O(n)


        