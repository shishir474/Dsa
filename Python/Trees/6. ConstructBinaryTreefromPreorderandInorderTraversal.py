# Construct Binary Tree from Preorder and Inorder Traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        mp = {}
        for i,val in enumerate(inorder):
            mp[val] = i # val -> idx
        
        def solve():
            if len(preorder)==0 and len(inorder)==0:
                return None
            root = TreeNode(preorder[0])
            # for i,val in enumerate(inorder):
            #     if val == preorder[0]:
            #         idx = i
            #         break
            idx = mp[preorder[0]]
            # [0:idx]
            root.left = self.buildTree(preorder[1:idx+1], inorder[0:idx]) # the number of elements in the preorder and inroder will always be same
            root.right = self.buildTree(preorder[idx+1:], inorder[idx+1:])

            return root
        
        return solve()
    
#  optimised finding the index using a map
#  This solution only works if both the trees has unique elements
#  TC: is still O(N^2) slicing operation takes O(n) time
# SC: O(n) time for storing mp