# 1. Find minimum in a rotated sorted array
class Solution:
    def findMin(self, nums: List[int]) -> int:
        ans = 1e9
        lo,hi = 0,len(nums)-1
        while(lo <= hi):
            if(nums[lo]<=nums[hi]): # array is sorted, ans=. min(ans, num[lo])
                ans = min(ans, nums[lo]) # found the ans
                break
            m = (lo+hi)//2
            ans= min(ans, nums[m])
            if(nums[lo] <= nums[m]):
                lo = m+1
            else:
                hi = m-1
        
        return ans
    
# Strivers Solution : Better one
class Solution:
    # the idea is to find the sorted half. 
    # Then we can pick the minimum from the sorted half and compare it with our ans, and discard that part
    def findMin(self, nums: List[int]) -> int:
        ans = 1e9
        lo,hi=0,len(nums)-1
        while(lo <= hi):
            m = (lo+hi)//2

            #check if the left half is sorted
            if(nums[lo] <= nums[m]):
                #pick the min and compare it with ans
                ans = min(ans, nums[lo])
                
                #and then we can discard this half
                lo = m+1
            else:
                #right half is sorted
                #pick the min and compare it with ans
                ans = min(ans, nums[m])

                #and then we can discard this half
                hi = m-1
        
        return ans
    
    
 
# conclusion: any one half will be sorted either the left one or the right one