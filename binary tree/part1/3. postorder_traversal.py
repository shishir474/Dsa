# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def helper(root):
            if root is None:
                return None
            helper(root.left)
            helper(root.right)
            res.append(root.val)

        helper(root)
        return res
    
    # TC: O(n)
    # SC: O(n) for recursion stack space + O(n) for res