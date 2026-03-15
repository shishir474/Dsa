# https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

# Better Solution: using memoisation
class Solution:
    def __init__(self):
        self.mp = {}        # creating map for memoisation
        
    def helper(self, arr, idx, sum):
        if sum == 0:
            return True
        if idx >= len(arr):
            return False
        if (idx, sum) in self.mp:       # mp is defined as an attribute inside __init__ constructor. 
            return self.mp[(idx,sum)]   # reference it as self.mp and not as mp
        

        if arr[idx] <= sum: # have 2options - take it or leave it
            ans = self.helper(arr, idx+1, sum - arr[idx]) or self.helper(arr, idx+1, sum)    
        else:   # no option, will have to ignore it
            ans = self.helper(arr, idx+1, sum)    
    
        # python does not allow assignment inside return:            
        self.mp[(idx, sum)] = ans   # first save the ans in map and then return in the next step
        return ans
        
        
    def isSubsetSum (self, arr, sum):
        self.mp = {}    # reset map before each call
        return self.helper(arr, 0, sum)
        
              
    # TC: O(n * target)
    # SC: O(n * target) + O(n)
    # O(n * target) for memoization and O(n) for auxiliary stack space
    
    
    
    
# Optimal Solutoin: bottom up appraoch (iterative solution) - helps gettin rid of auxilary stack space
class Solution:

    def isSubsetSum (self, arr, sum):
        n = len(arr)
        # dp[n+1][target+1] --> we need to create 2D dp arrrayt of size (n+1) X (target+1)
        dp = [[False]*(sum+1) for i in range(n+1)]
        
        # step1 : fill the base case
        # base case 1: sum == 0, 
        for i in range(n+1):
            dp[i][0] = True
        # base case 2, when n == 0 and you need to make some sum
        # except sum == 0, all dp[0][i] will be False
        
        for i in range(1, n+1): 
            for j in range(1, sum+1):
                if arr[i-1] <= j:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]
                else:
                    dp[i][j] = dp[i-1][j]
                    
                    
        return dp[n][sum]
    
    
    # TC: O(n * target)
    # SC: O(n * target) 
    
    

# Most Optimal solution
# since ith row only depends on (i-1)th row, we can further reduce the size of the dp array 

class Solution:

    def isSubsetSum (self, arr, sum):
        n = len(arr)
        # dp[n+1][target+1] --> we need to create 2D dp arrrayt of size (2) X (target+1)
        dp = [[False]*(sum+1) for i in range(2)]
        
        # step1 : fill the base case
        # base case 1: sum == 0, 
        for i in range(2):
            dp[i][0] = True
        # base case 2, when n == 0 and you need to make some sum
        # except sum == 0, all dp[0][i] will be False
        
        flag = 1
        for i in range(1, n+1): 
            for j in range(1, sum+1):
                if arr[i-1] <= j:
                    dp[flag][j] = dp[flag^1][j] or dp[flag^1][j-arr[i-1]]
                else:
                    dp[flag][j] = dp[flag^1][j]
                
            # after filling each row, flip the flag
            flag = flag^1
                    
                    
        # flip flag one more time to compensate the last flip
        flag = flag^1
                    
        return dp[flag][sum]
        
    # TC: O(n * target)
    # SC: O(2 * target) which is equivalent to O(target)