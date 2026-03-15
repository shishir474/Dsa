#NOTE: There can always be at most 2 elements whose freq is > N/3
# We cannot have more than 2 elements with freq > N/3
# So there can be atmost 2 elements whose freq is more than n/3 and they will be unique.
# which means ele1 and ele2 will not be same

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 1:
            return nums

        # n > 1: so we'll have atleast 2 elements
        count1,count2 = 0,0
        ele1 = None
        ele2 = None

        # ele1 and ele2 will be 2 different elements.
        # there's always a risk of nums[0] and nums[1] to be same - in that case we will set both ele1 and ele2 with same values, which will be incorrect
        # It's imp to start from 0th index bcoz we cannot set ele1 and ele2 as 1st and 2nd elements of our arrays
        for i in range(n):
            if count1 == 0 and ele2 != nums[i]:         # need to reset ele1
                ele1 = nums[i]      # I can only reset if ele2 != arr[i]
                count1 = 1
            elif count2 == 0 and ele1 != nums[i]: # reset count2 and ele2
                ele2 = nums[i] # but I can reset ele2 only iff ele1 != nums[i]
                count2+=1
            elif nums[i] == ele1:
                count1+=1
            elif nums[i] == ele2:
                count2+=1
            else:
                count1-=1
                count2-=1

        
        # ele1 and ele2 might be the majority elements. We'll need to verify it
        # Either both of them are majority elements or one of them is majority element or none of them is majority element
        count1, count2 = 0,0
        for num in nums:
            if num == ele1:
                count1+=1
            elif num == ele2:
                count2+=1

        res = []
        if count1 > n//3:
            res.append(ele1)
        if count2 > n//3:
            res.append(ele2)
        
        return res


# TC: O(n)
# SC: O(1)
        