   
# 2. Search in a rotated sorted array [Unique Elements]
class Solution:
    # the first sol is to get the index of the minimum element and then apply 2 binary searches
    # The better solution is the below one where we directly apply the binary search. i.e in single binary search we can find the target, whereas in the above sol, we needed 3 bs in the worst case
    def search(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums)-1
        while(lo <= hi):
            # find the mid
            m = (lo+hi)//2

            #check if mid is the target element
            if nums[m]==target:
                return m

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

        return -1          
