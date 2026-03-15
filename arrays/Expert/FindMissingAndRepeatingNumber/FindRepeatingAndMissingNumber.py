
# Better solution using frequency array
class Solution:
    def findMissingAndRepeating(self, arr, n):
        n = len(arr)
        freq = [0] * (n + 1)
        
        for i in range(n):
            freq[arr[i]] += 1
            
        missing = -1
        repeating = -1
        
        for i in range(1, n + 1):
            if freq[i] == 0:
                missing = i
            elif freq[i] == 2:
                repeating = i   
            
            if missing != -1 and repeating != -1:
                break
            
        return (missing, repeating)
    
# TC: O(n)
# SC: O(n) for frequency array




# Optimal solution using maths

class Solution:
    def findMissingAndRepeating(self, arr, n):
        n = len(arr)
        s = n * (n + 1) // 2
        s2 = n * (n + 1) * (2 * n + 1) // 6
        
        sum_arr = 0
        sum2_arr = 0
        for i in range(n):
            sum_arr += arr[i]
            sum2_arr += arr[i] * arr[i]

        # Let missing be x and repeating be y
        # s - (x - y) = sum_arr => x - y = s - sum_arr
        # s2 - (x^2 - y^2) = sum2_arr => x^2 - y^2 = s2 - sum2_arr

        diff = s - sum_arr  # x - y
        diff_sq = s2 - sum2_arr  # x^2 - y^2

        # x + y = (x^2 - y^2) / (x - y)
        add = diff_sq // diff  # x + y

        missing = (diff + add) // 2
        repeating = add - missing

        return (missing, repeating)
    
    # TC: O(n)
    # SC: O(1)

# In python, unlike cpp, there is no concept of long long. They is no overflow concern. 
# Python automatically allocates more memory for large integers. But the program becomes slower with very large integers.

# Python integers have arbitrary precision and don’t overflow like C++, 
# but very large integers increase memory usage and slow down arithmetic operations.

# ⚡ Rule of thumb for Python DSA
# Use // for integer division
# Don’t fear overflow — fear time & memory


# Optimal Solution 2 using bitwise logic


class Solution:
    def findMissingAndRepeating(self, arr, n):
        n = len(arr)
        xor_all = 0
        for i in range(n):
            xor_all ^= arr[i]
            xor_all ^= (i + 1)
            
        # find the rightmost set bit in xor_all
        for i in range(32):
            if xor_all & (1<<i):
                pos = i 
                break
        
        # divide elements into 2 bucekts based on bit value at pos position in arr and numbers from 1 to n
        # zero and one bucket
        # zero will store xor of all elements with 0 at pos position
        # one will store xor of all elements with 1 at pos position
        zero = 0
        one = 0
        for i in range(n):
            # check if pos bit is set in arr[i]
            if arr[i] & (1<<pos):
                one ^= arr[i]
            else:
                zero ^= arr[i]
                
            # check if pos bit is set in (i+1) which is basically number from 1 to n
            if (i + 1) & (1<<pos):
                one ^= (i + 1)
            else:
                zero ^= (i + 1)
                
        # now one and zero contains either missing or repeating number
        # to find which is missing and which is repeating, we can check in original array
        # check the freq of one in arr
        count_one = 0
        for i in range(n):
            if arr[i] == one:
                count_one += 1
                
        if count_one == 0:
            missing = one
            repeating = zero
        else:
            missing = zero
            repeating = one

        return (missing, repeating)
    
    
    # TC: O(n)
    # SC: O(1)