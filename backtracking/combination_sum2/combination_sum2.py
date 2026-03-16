# https://leetcode.com/problems/combination-sum-ii/

# Variant of combination sum1
# Key differences, in combination sum1, it was guaranteed that the input candidates list will have all unique elements
# here the candidates can have duplicate elements as well
# Goal is same : we need to generate unique subsets that sums to target in both the problems
# in combination sum1, an element could be used multiple times, here an element could only be used once



class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []        # list of lists which will be our final ans
        temp_list = []  # temp_list is used to store the subsets generated during recursion

        candidates.sort()   # sort the candidates list so that all duplicates are placed adjacent to each other

        def helper(idx, target):
            if target == 0:
                res.append(temp_list[:])        # imp: append the copy of temp_list in res, bcoz lists in python stores the references of inner list which will undergo modification during recursion
                return                          # thus in order to store the current snapshot, we store it's copy. temp_list[:] returns a shallow copy of temp_list with separate memory allocated to the new copy.
    
            for i in range(idx, len(candidates)):
                
                # first optimization: dont consider duplicates
                if i == idx or candidates[i] != candidates[i-1]:    # making sure that we don't process duplicate candidates
                
                    # second optimization: exclude processing of invalid candidates
                    if candidates[i] > target: break    # input list is sorted and if candidates[i] > target, there is no point exploring further
                
                    temp_list.append(candidates[i])     # candidates[i] <= target, for sure
                    helper(i+1, target - candidates[i])   # can pick the same element again
                    temp_list.pop()                     # pop to revert back to prev state
                    
                    
                    
        helper(0,target)

        return res
    
# TC: O(2^n) This is the upper bound, the actual runtime will be lower than this because we are prunning recursion tree - avoiding exploring all unnecessary paths which wont give us any results
# The worst case would happen when all elements are unique ( in which case we will have to process them all)

# SC: O(n * 2^n) upper bound of the space complexity. Assuming the length of each subset is n and total no of valid subsets that sums to target are 2^n.
# In reality, the numbers will be lower than this
