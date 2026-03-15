class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)

        i = 0
        
        last_index = 0  # points to the position where next unique element will be placed
        
        while i < n:
            j = i
            while j < n and nums[j] == nums[i]:
                j+=1
            nums[last_index] = nums[i]
            last_index+=1
            i = j

        return last_index

# TC: O(n) - althogh it looks like we're using nested loop, each element is processed only once.
# SC: O(1)



# Dry run        
#            li
# [0,0,1,1,1,2,2,3,3,4]
#    1 2 3 4            