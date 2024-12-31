# https://leetcode.com/problems/permutations-ii/

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # converted the input from list to mp, to handle duplicates
        # mp gives us the advantage that we will iterate over only unique keys
        mp = defaultdict(int)
        for i in nums:
            mp[i]+=1

        tans, ans = [], []
        def solve(tans, ans, n):
            if n==0:
                ans.append(tans[:])
                return 

            for i in mp:
                if mp[i] > 0:
                    tans.append(i)
                    mp[i]-=1
                    solve(tans, ans, n-1)
                    mp[i]+=1
                    tans.pop()
        
        solve(tans, ans, len(nums))
        return ans

# TC: O(n * n!) In the worst case if all the elements are unique, n! permuatation will be generated and constructing each permutation takes O(n) time
# SC: O(n * n!)