class Solution:
    def merge_two_sorted_arrays(self, nums, lo, mid, hi) -> None:
        # nums[lo..mid] & nums[mid+1..hi]
        temp = []       # temp[] will store the final merged sorted array
        i = lo
        j = mid + 1
        while i <= mid and j <= hi:
            if nums[i] > nums[j]:
                temp.append(nums[j])
                j+=1
            else:
                temp.append(nums[i])
                i+=1
        
        while i <= mid:
            temp.append(nums[i])
            i+=1

        while j <= hi:
            temp.append(nums[j])
            j+=1

        # copy elements from temp back into nums
        for i in range(lo, hi+1, 1):
            nums[i] = temp[i - lo]

        # nums[lo..hi] is now sorted
        

    def get_count_during_merge(self, nums, lo, mid, hi) -> int:
        # nums[lo..mid] & nums[mid+1..hi]
        count = 0

        i = lo
        j = mid + 1

        # sol1: to count the pairs

        for i in range(lo, mid + 1, 1):
            while j <= hi and nums[i] > 2*nums[j]:
                j+=1
            count+= (j - (mid+1))

        # sol2: to count the pairs
        # while i <= mid and j <= hi:
        #     if nums[i] > 2*nums[j]:
        #         j+=1
        #     else:
        #         count+= (j - (mid+1)) # adding j - (mid+1) bcoz j does not follow 0-based indexing
        #         i+=1

        # if i <= mid:        # if j gets exhausted first, pairs corresponding to remaining i
        #     # remaining i elements count = (mid - i + 1) 
        #     # contribution for each i = (j - (mid + 1))
        #     count+= (mid - i + 1) * (j - (mid+1))


        # Standard step of merging 2 sorted arrays

        # merge both the sorted arrays
        self.merge_two_sorted_arrays(nums, lo, mid, hi)

        return count
        

        
    # utility function on which recursion is called
    def reverse_pairs_helper(self, nums, lo, hi):
        if lo >= hi:
            return 0
        
        mid = (lo + hi) // 2

        count = 0
        count += self.reverse_pairs_helper(nums, lo, mid)
        count += self.reverse_pairs_helper(nums, mid + 1, hi)
        count += self.get_count_during_merge(nums, lo, mid, hi)

        return count


    def reversePairs(self, nums: List[int]) -> int:
        return self.reverse_pairs_helper(nums, 0, len(nums)-1)
        
        
# TC: O(logn) since we are dividing the array each time into 2 halves and then O(n) during merge + O(N) during counting pairs 
# So overall tc becomes O(2*nlogn)

# We optimised the countPairs function -- by making sure that for each i, we are not starting comparisons from the first ele in arr[m+1..hi]
# This basically reduces the complexity to O(n)


# SC: O(n): using O(n) space while performing the merge operation 
