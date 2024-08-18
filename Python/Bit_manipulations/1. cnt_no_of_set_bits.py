# https://leetcode.com/problems/number-of-1-bits/description/
class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while(n > 0):
            if n&1:
                cnt+=1
            n = n>>1
        return cnt
    
# TC: O(logn)

class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        for i in range(0,32):
            #check if the ith bit is set
            if(n&(1<<i)):
                cnt+=1
        return cnt
# TC: O(1) Solution