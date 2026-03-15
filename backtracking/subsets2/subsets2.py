# https://leetcode.com/problems/subsets-ii/

# SOLUTION 1: using sets to get rid of duplicate subsets

# we are using sets to track duplicate subsets, therefore sorting input array is not required. 
# But we need to store each subset in sorted form, so that sets can deduplicate them effectively.
# remember: [1,2] and [2,1] both are essentially the same subsets. Hence by storing them in sorted fashion, sets will be able to deduplicate them correctly.
# Only problem with this solution is we are using an extra set to get rid of duplicate subsets, which is not really efficient/
# We are generating all the subsets including duplicates during recursion and only remove them afterward when inserting into the set.
# which means we are doing extra work that could have been avoided.
# By sorting the array first, duplicate elements become adjacent, which allows us to skip duplicates during the recursion itself. 
# This way we generate only unique subsets, instead of generating all subsets and filtering duplicates later.

class Solution:
    def helper(self, nums, idx, temp_list, res):
        if idx >= len(nums):
            res.add(tuple(sorted(temp_list)))       # [1,2] and [2,1] both subsets are identical, hence storing the subsets in sorted form
            return                                  # so that sets can deduplicate them correctly

        # 2 options: take it or ignore it
        # ignoring it
        self.helper(nums, idx+1, temp_list, res)
        # taking it
        temp_list.append(nums[idx])
        self.helper(nums, idx+1, temp_list, res)
        temp_list.pop()


    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = set()         # using sets to track duplicatessub
        self.helper(nums, 0, [], res)
        return [list(t) for t in res]


        # subsets and subsequence are not the same thing. 

        # A subsequence is obtained by deleting zero or more elements without changing the order of the remaining elements.

        # Example:
        # arr = [1, 2, 3]

        # Valid subsequences:

        # []
        # [1]
        # [2]
        # [3]
        # [1,2]
        # [1,3]
        # [2,3]
        # [1,2,3]

        # Invalid subsequence:
        # [2,1]   ❌ (order changed)

        # Key rule:
        # Original order must be preserved



        # A subset comes from set theory and order does not matter.
        # Example:

        # set = {1,2,3}

        # Subsets:

        # {}
        # {1}
        # {2}
        # {3}
        # {1,2}
        # {1,3}
        # {2,3}
        # {1,2,3}

        # Here:

        # {1,2} = {2,1}

        # because order doesnt matter.



        # Why they look the same in many problems
        # When generating subsets from an array, we usually maintain the original order while building them. That makes the generated subsets also valid subsequences.

        # Example:

        # nums = [1,2,3]

        # Both approaches generate:

        # []
        # [1]
        # [2]
        # [3]
        # [1,2]
        # [1,3]
        # [2,3]
        # [1,2,3]

        # So they look identical, even though the definitions differ.


        # Key difference summarized
        # Property	Subsequence	Subset
        # Order matters	✅ Yes	❌ No
        # Based on	Arrays/strings	Sets
        # [1,2] vs [2,1]	Different	Same
        
        
        # Complexity intuition

        # Let n be the number of elements.

        # Your approach:

        # Generate 2^n subsets
        # Insert into set

        # Optimal approach:
        # Generate only unique subsets

        # So the optimized approach avoids unnecessary recursion branches.


        # Conclusion: Using a set removes duplicates after generation, but sorting allows us to skip duplicate 
        # elements during backtracking so we generate only unique subsets, avoiding redundant work.
        
        
        
        # We want all unique subsequences (subsets) of the array:

        # [4, 4, 4, 1, 4]

        # Since duplicates are ignored and order inside a subset does not matter, this is equivalent to generating subsets from the multiset:

        # {1, 4, 4, 4, 4}

        # Here:

        # 1 appears 1 time

        # 4 appears 4 times

        # So the unique subsets depend only on:

        # taking 0 or 1 copy of 1

        # taking 0–4 copies of 4

        # Number of unique subsets:

        # (1 + 1) × (4 + 1) = 10



        # General Formula (very useful in interviews)

        # If an array has frequencies:

        # v₁ appears f₁ times
        # v₂ appears f₂ times
        # ...
        # vₖ appears fₖ times

        # Number of unique subsets:

        # (f₁ + 1)(f₂ + 1)...(fₖ + 1)

        # For this case:

        # (1+1)(4+1) = 10







# Solution 2

class Solution:
    def helper(self, nums, idx, temp_list, res):
        res.append(temp_list.copy())   # temp_list is a mutable list, and Python stores a reference to it.
        # Later when you modify temp_list (append/pop), all entries in res that reference it also change. Hence storing the copy.

        if idx >= len(nums):
            return

        for i in range(idx, len(nums)):
            if i == idx or nums[i] != nums[i-1]:    # this conditiion ensures, we are not generating the duplicate subsets during recursion in the first place
                temp_list.append(nums[i])
                self.helper(nums, i+1, temp_list, res)
                temp_list.pop()

       
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort() # sorting is crucial. if condition Logic in the helper function only works if the input array is sorted
        res = []
        self.helper(nums, 0, [], res)

        return res
    
    
    # TC: O(n * 2^n)
    # SC: O(n * 2^n) + O(n)
    
    # Complexity Explaination:
    # if all elements are unique, then you will end up generating 2^n subsets, and for each subset you are doing O(n) work while copying
    # Hence tc is O(2^n * n)
    # SC: If all elements are unique, we will end up generating all 2^n subsets, and for each subset O(n) space. So O(2^n * n) space required for storing the subsets
    # and O(n) is the recursive stack space
    
    
    
    
    
# More Pythonic version:

# Improvements:
# 1> Use nested helper function. Insted of passing nums and res around, the inner function captures them from the scope, making the code cleaner
# 2> Removed unnecessary base condition. if block in the helper function is unnecessary. The loop already stops recursion.

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort() # sorting is crucial. if condition Logic in the helper function only works if the input array is sorted
        res = []
        
        def helper(idx, temp_list):
            res.append(temp_list.copy())   # temp_list is a mutable list, and Python stores a reference to it.
            # Later when you modify temp_list (append/pop), all entries in res that reference it also change. Hence storing the copy.
            
            for i in range(idx, len(nums)):
                if i == idx or nums[i] != nums[i-1]:    # this conditiion ensures, we are not generating the duplicate subsets during recursion in the first place
                    temp_list.append(nums[i])
                    helper(i+1, temp_list)
                    temp_list.pop()
                    
        helper(0, [])

        return res
    
    
    # Important point here is: we are storing copy of temp_list.
    # There are multiple ways to create a copy of a list in python
    # list(temp_list)
    # temp_list.copy()
    # temp_list[:]
    
    # All 3 approaches return a new list identical with temp_list
    
    # ex: a = [1,2,3]
    # b = a[:]        # slice the list from start to end
    # b = a[0:len(a)] , both are same
    
    # slicing always return a new list
    
    # Why .copy() is needed
        # "Because the list is mutated during recursion, and we need to store a snapshot of its current state."