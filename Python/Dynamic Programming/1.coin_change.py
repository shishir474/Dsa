# https://leetcode.com/problems/coin-change/

# Can we use Greedy?
# pick the gretest denomination coin till we can and then switch to a lower value. No it does not work for all test cases. 
# There might be a scenario where picking lower denomination gives us a better result. 

# Points to look at
# 1. We have to return the min no of coins required to reach target
# 2. there is an infinite supply for each coin

# recursive function
# We will utilse the brute force approach + memoisation to save on recomputation of recursive calls. That's how you explore all possible options

# a coin can be picked only if it satisfies the below condition
# if coins[i] <= n:
    # Now I have 2 choices: pick and not pick
    # Since we have infinite supply of coins, in pick we have again 2 options: continue with the same coin or move the next coin
    # The 2nd pick call is redundent, no need. Since we have infinite supply, we will always stick to the current position
#     
#   res = min(1 + min(self.solve(n-coins[idx],idx,coins), self.solve(n-coins[idx],idx+1,coins)),
#                     self.solve(n,idx+1,coins))
# else:
#     # Definitely no option other that to not pick this coin
#     res = self.solve(n,idx+1,coins)


class Solution:
    def __init__(self):
        self.dp = {}

    def solve(self,n,idx,coins):
        if n==0:
            return 0
        elif idx==len(coins):
            return 1e9
        
        # check if the result is already precomputed
        if((n,idx) in self.dp):
            return self.dp[(n,idx)]

        # pick only if coins[i]<=n
        if coins[idx]<=n: 
            # I have 2 options, pick and non pick
            # pick again has 2 choice: continue with the same coin or move to the next coin, but the second case is not required. It will automatcially be handled
            res = min(1 + self.solve(n-coins[idx],idx,coins),
                    self.solve(n,idx+1,coins))
        else:
            # I cannot pick this coin, only one choice
            res = self.solve(n,idx+1,coins)

        # save the result
        self.dp[(n,idx)] = res

        return res

    
        
    def coinChange(self, coins: List[int], amount: int) -> int:
        # res[i] stores the no of ways we can make amount i

        if self.solve(amount,0,coins) == 1e9:
            return -1
        return self.solve(amount,0,coins)
    
    
    
    
# Bottom Up solution
class Solution:
    # can pick ith coin only if it satisfies the below condition
    # if (coins[i-1] <= j):
    # I have 2 options: 
        # Take this coin. and since we have infinite supply for each coin, I will stick to the same index
        # Not take this coin
        # dp[i][j] = min(1 + dp[i][j-coins[i-1]], 
                        # dp[i-1][j])
    def coinChange(self, coins: List[int], amount: int) -> int:
        # t[n+1][x+1]
        
        n,x = len(coins), amount

        t = [ [0 if j==0 else 1e9 for j in range(x+1)] for i in range(n+1)]
        
        for i in range(1,n+1):
            for j in range(1,x+1):
                if(coins[i-1] <= j):
                    t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j])
                else:
                    t[i][j] = t[i-1][j]
        

        if(t[n][x]==1e9):
            return -1
        return t[n][x]



        