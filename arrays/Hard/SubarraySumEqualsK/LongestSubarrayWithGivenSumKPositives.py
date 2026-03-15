# Given an array arr[] of size n containing integers, the task is to find the length of the longest subarray having sum equal to the given value k.

# Note: If there is no subarray with sum equal to k, return 0.

# Examples: 

# Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
# Output: 6
# Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.

# Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
# Output: 5
# Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.

# Input: arr[] = [10, -10, 20, 30], k = 5
# Output: 0
# Explanation: No subarray with sum = 5 is present in arr[].




# Brute Force Solution:
    # Generate sum of all subarrays and check if it equals k      
    # TC: O(n^2)  
    # SC: O(1)


# Optimal Solution 1:
# Using Hashing

# Approach: Since we can have both +ve, zeroes and -ve numbers, it's not guaranteed that prefix sum will always move monotonically. It might increase/decrease/stay same. 
# Understanding this is key to solving the problem using prefix sums and hashing.
# bcoz of this reason, the prefix_sum can repeat at different indices. Thus for those scenario, we will be only interested in knowing the index of first occurence bcoz that will give me the longsest subarray with sum K
# If question states that array will only contain > 0 elements, the prefix sum wont repeat at all and will only move in monotonically increasing manner.

class Solution:
    def longestSubarrayWithSumK(self, arr: List[int], k: int) -> int:
        mp = {} # map to store prefix_sum -> first_index
        prefix_sum = 0
        max_length = 0
        
         # edge case: if the prefix itself has sum k
        for i in range(len(arr)):
            prefix_sum += arr[i]
            if prefix_sum == k:
                max_length = max(max_length, i + 1)

            # if we have encountered a prefix with sum = prefix - k
            if prefix_sum - k in mp:
                subarray_length = i - mp[prefix_sum - k]
                max_length = max(max_length, subarray_length)
            
            # store only the first occurrence of the prefix_sum
            if prefix_sum not in mp:
                mp[prefix_sum] = i
                
        return max_length
    
    # TC: O(n)
    # SC: O(n)
    
    
    
    
# Most Optimal Solution 2:
# sliding window approach (only works if elements are >= 0))

class Solution:
    def longestSubarrayWithSumK(self, arr: List[int], k: int) -> int:
        i = 0
        j = 0
        current_sum = 0
        max_length = 0
        
        while j < len(arr):
            current_sum += arr[j]
            
            while current_sum > k:
                current_sum -= arr[i]
                i += 1
            
            if current_sum == k:
                max_length = max(max_length, j - i + 1)
                
            j += 1
        
        return max_length
    
    # TC: O(n)
    # SC: O(1)