# Brute Force Solution
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        
        ans = 0
    
        for i in range(n-1):
            # max_val indicates the best price on which we can sell
            max_val = float('-inf')
            for j in range(i+1,n):
                max_val = max(max_val, prices[j])

            ans = max(ans, max_val - prices[i])

        return ans

        # TC: O(n^2)
        # SC: O(1)
        

# Better Solution
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        
        # max_price[i] = gives max prices in arr[i .. n-1]
        max_price = [-1] * n
        max_price[n-1] = prices[n-1]
        for i in range(n-2, -1, -1):
            max_price[i] = max(prices[i], max_price[i+1])

        ans = 0
        for i in range(n-1):
            curr_best_profit = max_price[i+1] - prices[i]
            ans = max(ans, curr_best_profit)

        return ans

        # TC: O(n) + O(n) = O(n)
        # SC: O(n)
        
        
# Optimal Solution
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        max_price = prices[n-1]
        max_profit = 0
        for i in range(n-2, -1, -1):
            value = max_price - prices[i]
            max_profit = max(max_profit, value)
            max_price = max(max_price, prices[i])

        return max_profit

        # TC: O(N)
        # SC: O(1)