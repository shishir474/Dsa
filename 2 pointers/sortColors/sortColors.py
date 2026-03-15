class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Famous Dutch National Flag algo which sorts an array containing only 0,1,2
        # sorts the array in place in one single pass

        n = len(nums)
        lo = mid = 0
        hi = n - 1

        while mid <= hi:
            if nums[mid] == 0:
                #swap nums[mid] with nums[lo], lo++, mid++
                nums[lo], nums[mid] = nums[mid], nums[lo]
                lo+=1
                mid+=1
            elif nums[mid] == 1:
                mid+=1
            else:
                # swap(nums[mid], nums[hi]), hi--
                nums[mid], nums[hi] = nums[hi], nums[mid]
                hi-=1

            
        # TC: O(N)
        # SC: O(1)