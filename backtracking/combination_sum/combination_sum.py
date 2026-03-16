# https://leetcode.com/problems/combination-sum/

# You will be given an input array candidates and goal is to generate all possible subsets with sum equivalent to target

# There are 2 possible variation of this problem:

# first variant: if candidates list is unique
# second variant: if candidates contain duplicates

# Leetcode variant: clearly states that the given candidates are unique, 
# so we didn't need to worry about handling duplicates subsets

# Below is the straight forward solution: 
# Key highlights:   
    # 1. used inner functions concept in python
    # 2. since the questions states that all elements in candidates are unique, we can simply follow the standard approach
    # of generating subsets
    # at a given idx: if candidates[idx] <= target -- I have 2 options take it or leave it
    # if candidates[idx] > target -- I have only one option to leave it
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []        # list of lists which will be our final ans
        temp_list = []  # temp_list is used to store the subsets generated during recursion

        def helper(idx, target):
            if target == 0:
                res.append(temp_list[:])        # imp: append the copy of temp_list in res
                return
            if idx >= len(candidates):
                return

            if candidates[idx] <= target:       # 2 option: take it or leave it
                helper(idx+1, target)           # leave it
                temp_list.append(candidates[idx])   # take it
                helper(idx, target - candidates[idx])
                temp_list.pop()                     # pop_back() to revert back to prev state
            else:       # only 1 option: leave it
                helper(idx+1, target)
        
        helper(0,target)

        return res
        

# Input: candidates = [2,3,6,7], target = 7
# Output: [[2,2,3],[7]]

# TC: The tc is determined by the number of recursion calls and the amount of work being done during each call. In the worst case
    # 2^n calls will be made where n is the number of elements in the array. 
    # WHy 2^n calls? At each step we have 2 options, pick and not pick.
    # However its worth noting that pruning if(at[i] <= t) reduces the number of recursion calls in practise, so the actual runtime may be better than the worst case run time
    # TC: O(2^n)

#SC: Recursive Stack space: O(n) which is determined by the number of elements in the array. Plus the space occupied by the ans and path
    # THe path can store all the elements in the worst case. 
    # THe ans list stores all the valid combination. Each combintation can itself be of size n. So the space occupied by ans is O(n*m) where m is the number of valid combinations

# SC: O(n) + O(n*m) = O(n*m)






# Now what if the input candidates list is not unique/ contain duplicates

from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []        # list of lists which will be our final ans
        temp_list = []  # temp_list is used to store the subsets generated during recursion

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
                    helper(i, target - candidates[i])   # can pick the same element again
                    temp_list.pop()                     # pop to revert back to prev state
                    
                    
                    
        helper(0,target)

        return res
        
        
    def driver(self):
        target = 7
        input_lst = [2,3,2,3,7,7]
        input_lst.sort()        # sort the input list so that all duplicates are placed adjacently
        
        res = self.combinationSum(input_lst, target)
        
        for lst in res:
            for i in lst:
                print(i, end = ' ')
            print()
            
        
sol = Solution()
sol.driver()

# The goal is to generate unique subsets that sums to target. It is clearly stated in the problem that all elements in candidates [] are unique
# Thus we didn't need to worry about generation of duplicate subsets
# in the original problem statement, candidates were unique
# but what if candidates are not unique -> then how do you generate unique subsets
    # first sol that comes to my mind is to use sets. Using sets we can retain only unique subsets in the final ans.
    # But the problem is we are generating duplicate subsets and then detecting those duplicates at the time of insertion
    # What if we don't generate those duplicate subsets in the first place?
    # This forms the foundation for the second solution:
        # first we will sort the input list, so that duplicates are placed adjacent to each other
        # second thing is I'll not process the duplicates in candidates list
        # I'll simply take candidates[i] into consideration and move to the next state
            # now since we can use the same element again, next call is made for ith index, but with updated target
        # pop the element to revert back to prev state -- standard backtracking practise
        # now what if candidates[i] > target, taking that would make target < 0
            # either you could handle this as a separate base case
            # Better way would be to simply add an if check that guarantess that we process only those candidates <= target
            # also since the input list is sorted, all elements on rhs of candidate[i] will also be > target. So we can simply break out
        # The advantage of sorting the input list and not taking into consideration duplicate elements is we are not generating the duplicate subsets in the first place.
        # Rather than generating all the subsets and then detecting duplicates using set, this solution doesn't generate duplicates in the first place.
        
        
        