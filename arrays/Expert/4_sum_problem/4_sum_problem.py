# Brute Force Solution: using 4 nested loops


# Better solution - using sets to find unique quads
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)

        # ans is a set of tuples
        ans = set()     # ans will store all the unique quads
        
        for i in range(n):    
            for j in range(i+1,n):
                seen = set()
                for k in range(j+1,n):
                    sum = nums[i] + nums[j] + nums[k]
                    
                    if target - sum in seen:
                        # found one possible quad - store the quad in sorted fashion for proper deduplication
                        quad = sorted([nums[i], nums[j], nums[k], target - sum])
                        ans.add(tuple(quad))
                    
                    seen.add(nums[k])

        # convert set of tuples back to list of lists
        return [list(quad) for quad in ans]

        # TC: O(n^3)
        # SC: O(n) for hashset + O(no_of_unique_quads * 2) for ans and final res

        # Interviewer will not be happy with 2 things
        # 1st we are using the hashset to look for the 4th value 
        # 2nd we are using a set to keep track of unique quads
        # also we are storing the quad elements in sorted fashion. In order to ensure set performs proper deduplication, it is imp to store the elements of the quad in sorted fashion

        # Why tuple instead of list in set?
        # ans.add([1,2,3,4])   # ❌ TypeError
        # ans.add((1,2,3,4))   # ✅

        # ➡️ Lists are mutable → unhashable
        # ➡️ Tuples are immutable → hashable

        # 2️⃣ Also, No overflow worries in Python
        #     You needed: long long in cpp

        #     Python integers are arbitrary precision, so:

        #     triplet_sum = nums[i] + nums[j] + nums[k]

        #     is always safe.
        

        
        
        
# Most Optimal Solution: 
    # constant space        

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        # question clearly states we dont want duplicate quads in the result.
        n = len(nums)
        res = []
        
        nums.sort()

        # we're trying to skip duplicates using val_j and val_i for nums[j] and nums[i] using the while loops
        # In Python, for i in range(...) ignores manual changes to i
        # The loop variable is overwritten by the next value from range
        # So your duplicate-skipping has NO effect

        # for i in range(n):
        #     for j in range(i+1,n):

        # Thus using while loops
        
        i = 0
        while i < n:
            j = i+1
            while j < n:
                l,r = j+1,n-1
                while l < r:
                    sum = nums[i] + nums[j] + nums[l] + nums[r]
                    if sum < target:
                        l+=1
                    elif sum > target:
                        r-=1
                    else:
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                        left = nums[l]      # skipping nums[l] duplicates
                        while l < r and nums[l] == left:
                            l+=1
                        right = nums[r]     # skipping nums[r] duplicates
                        while l < r and nums[r] == right:
                            r-=1
                
                val_j = nums[j] # skip all duplicates of nums[j]
                while j < n and nums[j] == val_j:
                    j+=1
            
            val_i = nums[i] # skip all duplicates of nums[i]
            while i < n and nums[i] == val_i:
                i+=1

        return res

# TC: O(nlogn) for sorting + O(n^3) for 3 nested while loops
# SC: O(1) - not using any extra space other than the res array
        