# https://www.youtube.com/watch?v=Yan0cv2cLy8&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=25

# https://leetcode.com/problems/jump-game/

# This problem has 2 Solution
# 1. which is the brute force solution which takes n^m time which can be optimised using caching the results -> which is basically the dp Solution
# 2. Using Greedy: For intuition refer to the above yt video

# Greedy Solution
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        goal = n-1
        for i in range(n-2,-1,-1):
            if i+nums[i] >= goal:
                goal = i
        
        return True if goal==0 else False
    
# TC: O(n)
# SC: O(1)




# DP solution 
class Solution:
    def __init__(self):
        self.dp = {}

    def solve(self, idx, nums):
        if idx >= len(nums)-1:
            return True
        if nums[idx]==0:
            return False
        
        if idx in self.dp:
            return self.dp[idx]
        
        ans = False
        for i in range(1,nums[idx]+1):
            if self.solve(idx+i, nums):
                ans = True
                break
        
        self.dp[idx] = ans
        return ans

    def canJump(self, nums: List[int]) -> bool:

       return self.solve(0,nums)

    
# TC: O(n*m) where m is the value in the nums. Basically its a quadratic time solution
# SC: O(n)
