# Brute Force : generate the sum of all subarrays and check if it equals k
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)

        count = 0

        for i in range(n):
            sum = 0
            # generate sum for each subarray
            for j in range(i, n):
                sum += nums[j] # this sum is the sum of subarray nums[i..j]
                if sum == k:
                    count += 1

        return count
    
# TC: O(n^2)
# SC: O(1)




# Most Optimal Solution
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = {} # map used to store prefix_sum -> freq

        # Prefix sums do not follow a monotonic (increasing or decreasing) pattern
        # because the array can contain both positive and negative numbers.
        # As a result, the running sum may increase or decrease at any step.
        # This observation is important—if all elements were positive,
        # the prefix sum would always be strictly increasing.

        # count of subarrays with sum k
        count = 0
        prefix_sum = 0

        for num in nums:
            prefix_sum += num
            
            # edge case: if the prefix itself has sum k
            if prefix_sum == k:
                count += 1

            # if we have encountered a prefix with sum = prefix - k
            if prefix_sum - k in mp:
                count += mp[prefix_sum - k]
            
            mp[prefix_sum] = mp.get(prefix_sum,0) + 1  

        return count

    # TC: O(n)
    # SC: O(n)