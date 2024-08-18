# https://leetcode.com/problems/counting-bits/description/
# https://www.youtube.com/watch?v=RyBM56RIWrM&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=12

# Given an integer n, you have to return an array of size n+1 where arr[i] is count_of_set_bits(i)

class Solution:
    # Brute force is nlogn, but we could do better
    # Using dp, we can utilise the previously computed information and reuse it again to compute the no of set bits in the current no
    # 5 -> 0101
    
    # logn Solution to get the MSB
    def getPosOfMSB(self, n):
        pos,it=-1,0
        while(n > 0):
            if(n&1):
                pos = it
            n = n>>1
            it+=1
        return pos
    

    # O(1) Solution to get the MSB
    def getMsb(self, n):
        for i in range(31,-1,-1):
            # check if the ith bit is set, return i as it is the msb
            if(n&(1<<i)):
                return i


    def countBits(self, n: int) -> List[int]:
        res = [0]*(n+1)
        offset = 1
        for i in range(1,len(res)):
            if(offset*2 == i):
                offset *= 2
            res[i] = 1 + res[i - offset]
        return res
    
# TC: O(n)
# SC: O(n)
    

