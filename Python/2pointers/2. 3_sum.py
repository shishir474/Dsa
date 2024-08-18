# https://leetcode.com/problems/3sum/

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        print(nums)

        i,n = 0, len(nums)
        while(i < n):
            j,k = i+1,n-1
            while(j < k):
                print(i,j,k)
                if(nums[i] + nums[j] + nums[k] == 0):
                    ans.append([nums[i],nums[j],nums[k]])
                    a,b = nums[j], nums[k]
                    while(j < k and nums[j]==a):
                        j+=1
                    while(j < k and nums[k]==b):
                        k = k-1
                elif(nums[i] + nums[j] + nums[k] < 0):
                    j+=1
                else:
                    k=-1
            z = nums[i]
            while(i < n and nums[i]==z):
                i+=1
        

        return ans