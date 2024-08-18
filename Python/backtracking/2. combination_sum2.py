# https://leetcode.com/problems/combination-sum-ii/description/

# 40. Combination Sum II

# Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

# Each number in candidates may only be used once in the combination.

# Note: The solution set must not contain duplicate combinations.


class Solution:
    def solve(self, idx, t, a, path, ans):
        if t==0:
            ans.append(path[:])
            return
        if idx==len(a):
            return

        for i in range(idx,len(a)):
            if a[i] > t: # optimisation
                break
            # if first element or curr_element != prev_element && it is smaller than the target
            if ((i==idx or a[i]!=a[i-1]) and a[i]<=t):
                path.append(a[i])
                self.solve(i+1, t-a[i], a, path, ans)
                path.pop()

    # input array contains duplicates
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []
        path = []
        self.solve(0,target,candidates,path,ans)
        return ans

# Why sorting? To handle the duplicates. Sorting causes the equal elements to be placed adjacently
# At a certain index, add the current index only if 
#    ( it is the first element or its not equal to the prev element and that element should be less than the target)
# since I cannot use that same element again, call recursion on i+1
# Base case: when target becomes zero or when we have reached the end of array

# TC: In the worst case 2^n combinations will be generated. Hence O(2^n) + nlogn for sorting the array
# SC: O(2^n * k) The total space required to store all the valid combinations, assuming k is the average length of a combination
    # + O(n) for recursive stack space
