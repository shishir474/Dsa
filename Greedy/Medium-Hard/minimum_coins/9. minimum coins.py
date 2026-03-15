# problem from striver's SDE sheet


coins = [1,2,5,10,20,50,100]
# infinite supply of coins 
# target = 70

# We have to find min no of coins needed to reach target.

# I have to find minimum:
    # - I can have a greedy solution or dp based solution.
    
    # Now I need to figure out, which one is going to work here
    
    # Greedy solution: At each instance, I will take the max value coin that's possible.
    # This will reduce the no of coins. 
    # IMP: greedy solution works only iff the coins[] system is canonical, not merely static. This is an example of canonical coins system [1,2,5,10,20,50,100]
    # why static coins also does not work? -- ex: [1,3,4] and target = 6
    # greedy fails here. SO its important that coins should be canonical 
    
    
    # TC of greedy solution: O(n), SC: O(1)
    
    # if the input coins[] is of special nature -- always use greedy approach because its much efficient than the recursion one
    
    # What does canonical mean (in Coin Change)?
    # A canonical coin system is a set of coin denominations for which the greedy algorithm always produces an optimal (minimum-coin) solution for every target value.
    
    # Examples of canonical coin systems
    # [1, 2, 5, 10, 20, 50, 100]   ← Indian currency
    # [1, 5, 10, 25]              ← US coins
    # [1, 2, 5, 10, 20, 50]
    # For every target, greedy gives the minimum number of coins.
    
    # Examples of NON-canonical coin systems
    # [1, 3, 4], target = 6
    
    # Greedy assumes:
    # “Taking the largest coin now will never block a better solution later.”
    # That assumption is true only for canonical systems.
    
    # Real-world currencies are designed to be canonical so that:
    # Cashiers can make change greedily
    # No complex computation is required

    # Final Refined Summary
    #     “For this problem, greedy works because the coin denominations form a canonical coin system, 
    #     where choosing the largest possible coin at each step always leads to an optimal solution. 
    #     This allows us to solve the problem in O(n) time and O(1) space.

    #     However, for the general Coin Change problem with arbitrary coin denominations, greedy fails because 
    #     locally optimal choices may block globally optimal solutions. In such cases, we model the problem 
    #     as an unbounded knapsack and solve it using dynamic programming with time and space complexity O(n × target).”

class Solution:
    
    # greedy solution: coz input is of special nature
    def get_minimum_coins(target: int) -> int:
        num_of_coins = 0
        
        for i in range(len(coins)-1, -1, -1):
            if coins[i] <= target:
                # basically take target // coins[i] coins of coins[i]
                num_of_coins += (target // coins[i])
                target -= (target // coins[i]) * coins[i]
                
        if target != 0:
            return -1
        
        return num_of_coins
        
    

# If coins[] is dynamic or arbitrary, greedy can fail:
coins = [1,3,4]
target = 6

# Greedy: 4 + 1 + 1 --> 3 coins 
# Optimal: 3 + 3 -> 2 coins

# Hence: Greedy is not a general solution for Coin Change.

# dp - based solution
f(idx, target):
    f(idx + 1, target)
    if arr[idx] <= target:
        1 + f(idx, target - arr[idx]) # since I can use the same coin again(bcoz of the infinite supply), hence next recursive call is made to idx
        
# TC of dp solution: O(n * target)
# SC: O(n * target)
    
    
# only if the input coins[] is of special nature (ie its fixed) -- then only greedy solution works
# In all the other scenarios - we'll have to go with recursion + memoisation solution. This is a full proof solution but has higher time and space complexity