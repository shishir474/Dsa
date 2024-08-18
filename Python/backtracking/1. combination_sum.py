# https://leetcode.com/problems/combination-sum/description/

# 39. Combination Sum

# Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

# The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
# frequency
#  of at least one of the chosen numbers is different.

# The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

# Example 1:

# Input: candidates = [2,3,6,7], target = 7
# Output: [[2,2,3],[7]]
# Explanation:
# 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
# 7 is a candidate, and 7 = 7.
# These are the only two combinations.




class Solution:
    def solve(self, i, t, a, path, ans):
        if t==0:
            ans.append(path[:]) # Changed ans.append(path) to ans.append(path[:]) to append a copy of path instead of the original list.
            return
        elif i==len(a):
            return
        
        #not pick
        self.solve(i+1,t,a,path,ans)
        #pick
        if a[i] <= t:
            path.append(a[i])
            self.solve(i,t-a[i],a,path,ans)
            path.pop()


    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        path = []
        self.solve(0,target,candidates,path,ans)
        return ans


# TC: The tc is determined by the number of recursion calls and the amount of work being done during each call. In the worst case
# 2^n calls will be made where n is the number of elements in the array. 
# WHy 2^n calls? At each step we have 2 options, pick and not pick.
# However its worth noting that pruning if(at[i] <= t) reduces the number of recursion calls in practise, so the actual runtime may be better than the worst case run time
# TC: O(2^n)

#SC: Recursive Stack space: O(n) which is determined by the number of elements in the array. Plus the space occupied by the ans and path
# THe path can store all the elements in the worst case. 
# THe ans list stores all the valid combination. Each combintation can itself be of size n. So the space occupied by ans is O(n*m) where m is the number of valid combinations

# SC: O(n) + O(n*m) = O(n*m)