
# 3. Search in Rotated Sorted Array II [Duplicates]
# https://www.youtube.com/watch?v=w2G2W8l__pc

# Here the rotated sorted array can contain duplicates as well

# The only problem with having duplicates is in some cases you will not be able to figure out which half is the sorted half
# ex: [3 3 0 3 3 3 3]  # since we can have duplicates, the middle element can extend till the last point, hence programatically you cannot determine which is the sorted half using the above strategy

# This is the edge case: Intuition is -> Try to trim down the search space.
# First thing that we compare is mid, if it equals target, good. But in case nums[mid] != target and  nums[mid]=num[lo]=num[hi] it means we can strictly discard mid, lo and hi. So update lo = lo+1 and hi = hi-1
# nums[lo] = nums[m] = nums[hi]
# THis is the condition which is stopping me from identifying the sorted half

# Why the upper solution doesnt work?
# Identifying the sorted half was the crucial step, but the logic doesnt work in case of duplicates
 


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums)-1
        while(lo <= hi):
            # find the mid
            m = (lo+hi)//2

            #check if mid is the target element
            if nums[m]==target:
                return True
            
            # IMP: in this condition we cannot decide which is the sorted half, hence shrink the search space
            if(nums[lo] == nums[m] == nums[hi]):
                lo+=1
                hi-=1
                continue

            #figure out the sorted half
            if nums[lo] <= nums[m]: #left half sorted
                # check if target exists in the left half
                if nums[lo] <= target and target <= nums[m]:
                    #trim the right half
                    hi = m - 1
                else:
                    #trim the left half
                    lo = m+1
            else:
                #right half is sorted
                #check if the target exists in the right half
                if nums[m] <= target and target <= nums[hi]:
                    #trim the left half
                    lo = m+1
                else:
                    #trim the right half
                    hi = m-1

        return False  

# TC: logn
# In the worst case where we have a lot of duplicates, each time we reduce the search space by 1 frmo both ends
# so the avg case complexty becomes O(n/2) approximately