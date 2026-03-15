class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if len(nums) == 0:
            return 0

        nums.sort()

        # we'll track the last_smaller element
        # if curr_element == last_smaller + 1 , include that curr_eleemnt
        # if curr_element == last_smaller -- skip that curr_eleement
        # else start off fresh

        ans = 1
        last_smaller = float('-inf')
        for num in nums:
            if num == last_smaller:
                continue
            elif num == last_smaller + 1:
                count += 1
                last_smaller += 1
                ans = max(ans, count)
            else:
                last_smaller = num
                count = 1

        return ans
    
    
# TC: O(nlogn) + O(n)
# SC: O(1) 
    
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        
        # instead of iterating on nums, iterate on set s -- this will be more efficient. There's no additional benefit of processing the same element again.
        for x in s:
            if x-1 not in s: # x is a starting point of a sequence
                count = 0
                while x in s:
                    count+=1
                    x+=1
                
                ans = max(ans, count)

        return ans
    
# TC: O(n)
# SC: O(n)