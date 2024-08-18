# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
# https://www.youtube.com/watch?v=1pkOgXD63yU&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=2
# TC: O(n)
# SC: O(1)

# 2pointer solution
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mx_profit = 0
        l,r,n = 0,1,len(prices)
        while(r < n):
            if(prices[r] - prices[l] > 0):
                mx_profit = max(mx_profit, prices[r]-prices[l])
            else:
                l = r
            r+=1
        
        return mx_profit
        