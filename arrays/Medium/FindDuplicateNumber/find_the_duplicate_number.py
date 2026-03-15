# Brute Force Solution
# Sort the array -  this will cause all the duplicates to come together and then you can compare adjacent elements to find the duplicate.

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        for i in range(n-1):
            if nums[i] == nums[i+1]:
                return nums[i]

        return -1
    
# TC: O(nlogn) - assuming you're using merge sort
# SC: O(1)

# Apart from the extra tc bcause of sorting, we are also distorting the input array.





# Better Solution:
# Use freq array. 

# Since the numbers are from 1 to n, we can create a freq array of size n+1 and store the frequency of each number.
# Using freq array is more efficient than using a hash map in terms of time complexity. We could have also used a set.

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        freq = [0]*n
        for i in range(n):
            freq[nums[i]]+=1
            if freq[nums[i]] > 1:
                return nums[i]

        return -1

# TC: O(N)
# SC: O(N)

#NOTE: The only way we can optimize this further is by reducing the space complexity to O(1) and that can be done only with the help of 2 pointers

# Optimal Solution


#  Tortoise method : slow and fast pointer approach where slow moves one step and fast moves two steps.
#  Now, since there is a duplicate number we can surely say that there is a cycle.
#  Since it is a cycle and slow moves one step and fast moves two steps, they will definitely meet at some point on the cycle.
#  First point of collision has been proved.
 
#  For the second point of collision, reset the fast pointer to start and move both slow and fast pointers one step at a time.
#  They will meet at the starting point of the cycle which is the duplicate number. 
 

# Assume the distance between start and first point of collision is 'a'.
# slow moved distance 'a' and fast moved distance 2*a
# Extra distane coverted by fast = a which will always be a multiple of cycle length 'c'

# a = n*c  (n = some integer)
# Why can we say this? because slow and fast pointer will meet at some point on the cycle. For this to happen fast must have covered extra distance in terms of complete cycles.
# That's why we can say a will be multiple of length of cycle 'c'.

# Assume distance between start and starting point of cycle is 'x'. So, distance between start point of cycle and first point of collision will be 'a - x'.
# Now since we moved both fast and slow pointer one step at a time, (assumption is we reset the fast pointer)
# so fast moves x 
# slow also moves x -- since they both are moving one step.They are bound to meet at the starting point of cycle which is the duplicate number.


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = nums[0]
        fast = nums[0]

        # Step1: Detect cycle
        while True:
            slow = nums[slow]           # slow moves 1 step
            fast = nums[nums[fast]]     # fast moves 2 steps
            if slow == fast: 
                break

        # Step2: find starting point of the cycle
        fast = nums[0]
        while slow != fast:         # both slow and fast moves 1 step
            slow = nums[slow]
            fast = nums[fast]

        return slow
    
    # TC: O(N)
    # SC: O(1)