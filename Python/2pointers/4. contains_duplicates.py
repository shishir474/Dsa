# https://leetcode.com/problems/contains-duplicate/description/

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Brute force n^2

        # sol2 
        # using sorting and check adj elements
        # nums.sort() #sorting brings all the equal elements adj to each other
        # i,j=0,1
        # while(j < len(nums)):
        #     if(nums[i] == nums[j]):
        #         return True
        #     i+=1
        #     j+=1
   
        # return False
        
        # TC: O(nlogn) SC:O(1) not considering the space required for sorting
        # In this case we do have a slightly better solution than brute force
        
        
        # SOL 3
        # iF we use a little bit of extra memory and its really a tradeoff. If we sacrifice sc, we can acheive better time complexity
        hashset = set()
        for i in nums:
            if i in hashset: #O(1)
                return True
            hashset.add(i) #O(1)
        
        return False
        # TC: O(n) SC:O(n) not considering the space required for sorting