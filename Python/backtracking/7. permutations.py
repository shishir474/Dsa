# https://leetcode.com/problems/permutations/

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def solve(i, ans):
            if i==len(nums):
                ans.append(nums[:])
                return

            for j in range(i, len(nums)):
                #swap nums[i] and nums[j]
                nums[i], nums[j] = nums[j], nums[i]
                solve(i+1, ans)
                nums[i], nums[j] = nums[j], nums[i] # backtrack
        
        solve(0, ans)
        return ans

# Time Complexity:
# The time complexity is O(N * N!), where N is the length of the input list nums. This is because there are N! permutations, and each permutation requires O(N) time to create a copy and store it.
# Space Complexity:
# The space complexity is O(N * N!) to store all the permutations, where N! is the number of permutations and each permutation takes O(N) space. Additionally, there is the recursive call stack, which can go as deep as O(N).
        