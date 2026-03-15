#NOTE: There can always be only majority element whose freq is > N/2
# We cannot have more than 1 element with freq > N/2


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        
        mp = {}
        for num in nums:
            mp[num] = mp.get(num,0) + 1

        for key, value in mp.items():
            if value > n//2:
                return key

        return -1

# Maps in python behaves similar to unordered_map in C++
# Average case TC for insertion and lookup: O(1)
# Worst case: O(N) -- when all elements hash to the same bucket, but this is very rare

# TC average case: O(n)
# SC: O(n) - if all elements are distinct

    
# Most Optimal Solution - Boyer-Moore Voting Algorithm
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # lets say we assume nums[0] is our majority elemeent
        # algo is if nums[i] == maj_ele: count++ else count--
        # if count becomes 0, current element (nums[i]) becomes the majority element and count resets to 1

        # NOTE: it's not necessary that maj_ele will be the actual majority element. Verify it by iterating thru the array once and checking its count
        # One thing for sure which holds true is, if the majority element exists, then maj_element would be the ans.
        # and since its already guaranteed in the problem statement, we dont need to verify it
        maj_ele = nums[0]
        count = 1
        for i in range(1, len(nums)):
            if nums[i] == maj_ele:
                count+=1
            else:
                count-=1
            
            if count == 0: # reset the majority element
                maj_ele = nums[i]
                count = 1

        # no need to verify, since problem statement guarantees that majority element exists
        return maj_ele
    
# TC: O(n)
# SC: O(1)