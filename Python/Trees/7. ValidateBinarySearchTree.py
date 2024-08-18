class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        def solve(lo, hi, root):
            if not root:
                return True
            if (lo <= root.val <= hi and 
                solve(lo, root.val-1, root.left) and
                solve(root.val+1, hi, root.right)):
                return True
            
            return False

        return solve(float('-inf'), float('inf'), root)
    
# TC: O(n)
# SC: O(n) recursive stack space

# during each recursive call we are ensuring that roots value is between lo and high. If it becomes out of bounds, it means it is not a bst
