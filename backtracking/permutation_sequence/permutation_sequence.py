# Brute force:
    # Use recursion to generate all the permuations and then sort them and return the kth permutation
from typing import List
class Solution:
    def getPermutation(self, n: int, k: int) -> List[int]:
        # generating all permuations - n! permutations in total
        input = list(range(1,n+1))
        input.sort()
        
        res = [] # this list will store all the permutations in sorted fashion

        def generateAllPermuations(idx):
            if idx >= len(input):
                print(input)
                res.append(input[:])
                return

            for i in range(idx, len(input)):
                input[idx], input[i] = input[i], input[idx]     # swap(input[i], input[idx])
                generateAllPermuations(idx + 1)
                input[idx], input[i] = input[i], input[idx]  # swap back again - standard backtracking practise


        generateAllPermuations(0)
    
        return res
    
sol = Solution()
res = sol.getPermutation(3,2)

print(res)

# TC: We will generate n! permutations and for each permutation, we will be making its deep copy whjich is O(n) work
# Thus total time will be O(n * n!)
# After that we will also perform sort that will take n!logn!

# SC: n! permutations will be generated and for each n space will be requird. Hence O(n * n!)

# ------------------------------------------------------
# Remeber: in interviews, we need to follow a process. Start off with a naive solution and then move to better / optimal solutoins
# ------------------------------------------------------


# Optimal solution
# n = 4, k = 17
# n!= 24 permutations possible
# Lets look into this mathematically. I'm looking to find k = 17th permutatoin

# set = [1,2,3,4]
# If I start the permuatation with 1 + [2,3,4]    --> 6 permuations
# what if I start my permutatoin with 2 + [1,3,4] --> 6 permuations
# what if I start my permutatoin with 3 + [1,2,4] --> 6 permuations
# what if I start my permutatoin with 4 + [1,2,4] --> 6 permuations

# I can start with 1 or 2 or 3 or 4
# The number of permutations that will start with 1 is 6 
# and the same applies for permutations starting with 2,3, and 4
# bcoz we are left with 3 nos and they will create 3! permuatatoins

# I'm looking for k = 17th permuation, which will fall in 3rd bucket. 
# So we know for sure that the permuation willl start with 3
# [1,2,3,4]
# bucket_idx = k // fact[n-1] => 17 // 3! = 2
# k = k - (fact[n-1]*bucket_idx) => 17 - (6 * 2) = 5
# remove 3 from input

# [1,2,4]
# bucket_idx = k // fact[n-1] => 5 // 2! = 2
# k = k - (fact[n-1]*bucket_idx) => 5 - (2 * 2) = 1
# remove 4 from input

# [1,2]
# bucket_idx = k // fact[n-1] => 1 // 1! = 1
# k = k - (fact[n-1]*bucket_idx) => 1 - (1 * 1) = 0
# remove 2 from input


# [1]
# bucket_idx = k // fact[n-1] => 0 // 0! = 0
# k = k - (fact[n-1]*bucket_idx) => 0 - (1 * 0) = 0
# remove 1 from input


from typing import List
class Solution2:
    def getPermutation(self, n: int, k: int) -> str:
        # n = 4, k = 17
        
        # k provided in the input follows 1 based indexing
        k = k - 1 # imp: convert k to 0 based

        # precompute factorials till n <= 10
        fact = [0] * 10
        fact[0] = fact[1] = 1
        for i in range(2,10):
            fact[i] = i * fact[i-1]

        # input list
        input = list(range(1,n+1))  # [1,2,...n]

        ans = ""
        while len(input) > 0:
            bucket_idx = k // fact[n-1]
            ans += str(input[bucket_idx])
            k = k - (fact[n-1] * bucket_idx)
            input.remove(input[bucket_idx])
            n -= 1

        return ans
        
        
    
sol = Solution2()
res = sol.getPermutation(3,2)

print(res)