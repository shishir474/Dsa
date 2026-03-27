# Given a binary tree, we have to determine whether its symmetric around root.
# In order for it to be symmetric, left subtree should be mirror of right subtree.
# which means root1's left subtree should be identical with root2's right subtree
# and root1's right subtree should be identical with root2's left subtree

# root1 and root2 are left and right subtree of root

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:                    # edge case
            return True
        
        def is_identical(root1, root2):
            if not root1 and not root2:
                return True
            if not root1 or not root2:
                return False

            if root1.val != root2.val:
                return False
            
            return is_identical(root1.left, root2.right) and is_identical(root1.right, root2.left)


        return is_identical(root.left, root.right)
    
    # TC: O(n) -- we need to visit each node atleast once.
    # SC: O(h) -- depth of the recursion stack space.
    
    
# Iterative Solution:
# same complexity, different style

# we will be storing tuples -- node pairs
# simaltaneously performing level order traversal on both the trees and checking if they are symmetric.
# for symmetricity: we compare (n1.left and n2.right) and (n1.right and n2.left)
# for identicalness: we compare (n1.left and n2.left) and (n1.right and n2.right)

from collections import deque
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:                    # edge case
            return True
        
        dq = deque([(root.left, root.right)])
        while dq:
            n1, n2 = dq.popleft()       # 2 nodes n1 & n2
            
            if not n1 and not n2:       # both n1 and n2 are null, they are identical, move next
                continue
            
            if not n1 or not n2 or n1.val != n2.val:    # if either of them are null or value mistmach, they are not identical
                return False
            
            dq.append((n1.left, n2.right))      # compare n1.left and n2.right
            dq.append((n1.right, n2.left))      # compare n1.right and n2.left
            
        return True
    
    # TC: O(n) -  level order traversal, visiting each node once
    # SC: O(width) which is O(n)
    # see the proof in part1
    
            
            

    