# Given n and k, you have to return the kth permutation sequence

# Brute force solution is to generate all the n! permutations, store it in a ds and sort that. 
# TC: Time for generating all the permutations is O(n! * n). Time required for generating each permutation is n and there are n! permutations in total
# Plus sorting the n! permutations which is O(n!logn!)


# https://www.youtube.com/watch?v=wT7gcXLYoao&t=709s


# Non backtracking solution: 

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        # precomputation
        fact = [0]*11
        fact[0] = fact[1] = 1
        for i in range(2, 10):
            fact[i] = i*fact[i-1]
        
        digits = [] # stores all the digits from 1 to n
        for i in range(1,n+1):
            digits.append(i)

        ans = ""
        k = k - 1 # converting k to 0 based indexing
        while n > 0:
            bucket_size = fact[n-1]
            idx = k//bucket_size 
            ans += str(digits[idx])
            k = k%bucket_size
            digits.pop(idx) # removing the digit used is necessary
            n-=1
        
        return ans

# TC: O(n^2) the pop() opertaion takes O(1) time, but pop(idx) takes O(n) time bcoz this involves shifting the elements to the left
# SC: O(n) for storing the digits

# lst.pop() - removes last element -  O(1)
# lst.pop(idx) - removes specified idx -  O(n)
# lst.remove(value) - removes the first occurence of the value, gives ValueError if value is not present -  O(n) The value first need to be searched which will take O(n) plus then deleting causes shifting off all elements on right side of it
# del lst[idx] - removes specified idx - O(n) operation. causes shifting of elements
# del lst - deletes entire list -O(n) operation