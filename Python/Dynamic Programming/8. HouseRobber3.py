# https://leetcode.com/problems/house-robber-iii/description/


class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        mp = {}
        def solve(root):
            if not root:
                return 0
            if root in mp:
                return mp[root]
            # picking root
            option1 = root.val
            if root.left:
                option1 += solve(root.left.left) + solve(root.left.right)
            if root.right:
                option1 += solve(root.right.left) + solve(root.right.right)
            
            # not picking root
            option2 = solve(root.left) + solve(root.right)

            ans = max(option1, option2)
            mp[root] = ans
            return ans
        
        return solve(root)

# TC: O(n)  each node is visited exaclty once
# SC: O(n) map will store the results corresponding to all the n nodes
