# Solution 1
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # n^2 solution is more than enough
        res = [1]*len(nums)
        for i in range(1,len(nums)):
            for j in range(i-1,-1,-1):
                if nums[j] < nums[i]:
                    res[i] = max(res[i], 1+res[j])
        
        return max(res)

# TC: O(n^2)
# SC: O(n)


# Solution 2    
# nlogn solution also exists: but its bit tricky
