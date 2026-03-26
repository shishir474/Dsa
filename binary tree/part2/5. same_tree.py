# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def dfs(root1, root2):
            if not root1 and not root2:         # both nodes are null
                return True
            if not root1 or not root2:          # either of them is null
                return False
            
            if root1.val != root2.val:          # value mismatch
                return False

            # root is identical, left and right subtree must also be identical
            return dfs(root1.left, root2.left) and dfs(root1.right, root2.right)

        return dfs(p, q)
    
    # TC: O(n) -- one single traversal on both trees simaltaneously
    # SC: O(H) - recursive stack space, which is equivalent of tree's height.
    # if it's a balanced tree, h = O(logn)
    # if it's a skewed tree, h = O(n)