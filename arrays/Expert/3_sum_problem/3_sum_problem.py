# Brute Force Solution: 3 nested loops



# Better Solution:: usings sets to track unique triplets.
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        
        nums.sort()
        
        ans = set()

        i = 0
        while i < n:
            j = i + 1
            k = n - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:        # target is 0 in this problem
                    triplet = sorted([nums[i], nums[j], nums[k]])
                    ans.add(tuple(triplet))    
                elif sum < 0:
                    j += 1
                else:
                    k -= 1
            
            i += 1

        # convert set of tuples into list of lists
        return [list(triplet) for triplet in ans]


    # using sets to track unique triplets, it adds extra overhead.
    # we need to store the triplets in sorted fashion to ensure sets deduplication works properly
    # we can do it in O(1) space just by manipulating the pointers

    # TC: O(n^2) for 2 nested loops + O(nlogn) for sorting
    # SC: O(1) -- ignoring the extra space for the ans[]

# -4 -1 -1 0 1 2



# Optimal solution: manipulating pointers to avoid duplicates
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)

        ans = []

        # in order to use the 2 pointers based approach, we'll need to sort the array
        nums.sort()

        i = 0

        while i < n:
            j = i + 1
            k = n - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:        # target is 0 in this problem
                    ans.append([nums[i], nums[j], nums[k]])
                    # process duplicates of nums[j] and nums[k]
                    val_j = nums[j]
                    while j < k and nums[j] == val_j:
                        j+=1

                    val_k = nums[k]
                    while j < k and nums[k] == val_k:
                        k-=1
                        
                elif sum < 0:
                    j += 1
                else:
                    k -= 1
            
            # process duplicates of i
            val_i = nums[i]
            while i < n and nums[i] == val_i:
                i+=1

        # convert set of tuples into list of lists
        return ans


    # using sets to track unique triplets, it adds extra overhead.
    # we need to store the triplets in sorted fashion to ensure sets deduplication works properly
    # we can do it in O(1) space just by manipulating the pointers

    # TC: O(n^2) for 2 nested loops + O(nlogn) for sorting
    # SC: O(1) -- ignoring the extra space for the ans[]

# -4 -1 -1 0 1 2