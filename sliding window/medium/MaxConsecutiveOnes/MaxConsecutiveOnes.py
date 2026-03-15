class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        n = len(nums)

        # idea is : we are only interested in bunches of 1s. So I'll only look for those.
        # My starting point would be 1 and I'll keep on expanding as much as possible(until I encounter 0 or reach end of array)
        # This will be one possible ans
        
        max_len = 0

        i = 0       # i..j is the window. We only need 1s in our window
        
        while i < n:
            # keep on moving i(starting point of window) until its not at 1
            while i < n and nums[i] == 0:
                i+=1
            
            j = i       # start j from ith index and keep on expanding until nums[j] == 1
            
            while j < n and nums[j] == 1:
                j+=1
            
            max_len = max(max_len, j - i)
            
            i = j

        return max_len

        # TC: O(n)
        # SC: O(1)