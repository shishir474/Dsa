# https://leetcode.com/problems/reverse-bits/

class Solution:
    def reverseBits(self, n: int) -> int:
        # iterate over the nbr and see if the 2^ith bit is set. If yes, then set the 2^(31-i)the bit of ans
        ans = 0
        for i in range(0,32):
            # check if ith bit is set
            if(n&(1<<i)):
                #set the (31-i)th bit
                ans = ans | (1<<(31-i))
        
        return ans
    