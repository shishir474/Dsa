# https://leetcode.com/problems/coin-change/description/


class Solution:
    def coin_change_helper(self, idx, target, coins, dp):
        if target == 0:
            return 0    # no coins required
        if idx >= len(coins):
            return float('inf')
        
        if dp[idx][target] != -1:
            return dp[idx][target]

        # not take -- we simply move on to next index and target stays same
        ans = self.coin_change_helper(idx+1, target, coins, dp)
        
        # take  -- but only if coins[idx] <= target
        # we stay at the same idx (coz infinite supply of each coin), but target gets reduced by coins[idx]
        if coins[idx] <= target:
            ans = min(ans, 1  + self.coin_change_helper(idx, target - coins[idx], coins, dp))

        dp[idx][target] = ans
        return ans

        

    def coinChange(self, coins: List[int], target: int) -> int:

        # NOTICE: if coins[i] <= target, I'm forcing myself to take coins[i] as much as possible.
        # What if, taking coins[i] doesn't produce any valid combination. Cleary, greedy isn't gonna work here.
        # We will have to explore all possible combinations using recursion and optimise it using dp.

        # The only difference between this problem and striver's sde sheet one is 
        # here the coins[] can be dynamic and not necessarily sorted
        # whereas the striver's sheet one had fixed set/variety of coins = [1,2,5,10,20,50,100,500,1000]

        n = len(coins)

        # n X (target + 1)
        dp = [[-1] * (target + 1) for _ in range(n)]
        
        ans = self.coin_change_helper(0, target, coins, dp)

        return -1 if ans == float('inf') else ans