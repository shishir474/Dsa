# https://leetcode.com/problems/container-with-most-water/description/

# Note; This is not a binary search. Its a 2pointer solution
# In binary search we always discard one half of the array and half the search space during each iteration
class Solution:
    def maxArea(self, nums: List[int]) -> int:
        ans = 0
        left,right = 0,len(nums)-1
        while(left < right): # we need atleast 2 pillars hence left < right condition
            tmp = min(nums[lo], nums[hi]) * (hi - lo)
            ans = max(ans, tmp)
            
            # how to update pointers. THe pointer which points to the lower height, we dont want that
            if nums[left] < nums[right]:
                lo+=1
            else:
                hi-=1
        return ans
    
#: TC: O(n)
# SC: O(1)

# Brute force is to check each pair and find the pair which gives us the max ans This is n^2

#Intution of 2 pointer
# Initialise left to 0 and right to n-1? WHy bcoz I want the width to be as maximum as possible.
# Also if the left pillar and right pillar are 2 tallest pillars then we have instantanuosly found our piillars

# How to update our left and right pointers?
# Small height pillars are our limiting factor, so the pillar that has got a small height, want to move away from that 

# So we take the min of 2 heights and then we nmultiply it with the base
