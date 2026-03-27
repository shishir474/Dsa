# https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

# left boundary excluding leaf
#  + 
# leaf nodes
#  + 
# right boundary in reverse direction excluding leaf


# left boundary (lb):
#     keep moving left if possible, else move right.
#     once you reach leaf node, that's when you break out.
#     we'll start the lb from root.left.
#     The idea is, we first put root into the data structure and initialise curr to root.left
#     This will be the starting point of left boundary.
#     now move left if possible, else move right
    
# Leaf nodes:
#     we'll use inorder traversal (left root right).
#     we have to generate the leaf nodes from left to right. Inorder will help us to acheive that.
#     Why not level order traversal?
#     We might Not have all leaf nodes at the same level. Thus leaf nodes closer to root, will appear first.
    
# right boundary (rb):
#     starting point of right boundary will be root.right.
#     move right if possible else move left.
#     once you reach leaf node, that's when you break out.
    
# Key Takeaway:
#     for left boundary to exist, root.left must exist. 
#     if root.left is null, left boundary doesn't exist
#     Same is the case for right boundary, root.right must exist.
#     because that is our starting point

'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def is_leaf(self, root):
        if not root.left and not root.right:
            return True
        return False
        
    def boundaryTraversal(self, root):
        if not root:
            return []
        if self.is_leaf(root):          # edge case: in case of only 1 node, below code adds it twice
            return [root.data]          # first in lb and then in the bb
            
        lb, rb, bb = [], [], []     # left boundary(lb), right boundary(rb), bb(bottom boundary)
        
        lb.append(root.data)
        
        # left boundary
        curr = root.left                # imp: starting point of left boundary is root.left
        while curr:
            if self.is_leaf(curr): 
                break
            lb.append(curr.data)
            if curr.left:               # if left exists, then only move left
                curr = curr.left
            else:                       # left doesn't exist, move right
                curr = curr.right
            
        # bottom boundary
        def inorder(root):
            if not root: 
                return
            inorder(root.left)
            if self.is_leaf(root):
                bb.append(root.data)
            inorder(root.right)
            
        inorder(root)
            
        # right boundary
        curr = root.right               # imp: starting point of rb is root.right
        while curr:
            if self.is_leaf(curr):
                break
            rb.append(curr.data)
            if curr.right:              # if right exists, then only move right
                curr = curr.right
            else:                       # right doesn't exist, move left
                curr = curr.left
            
        rb = rb[::-1]
        
        res = lb + bb + rb
        return res
            
        
    # TC: O(3 * n)
    # SC: O(n)
    
# Tree examples:    
# [1, 2, 3, null, 5, 6, null, 8, 9, null, 10]
# [1, null, 3,  null, 4, null, 5]       --> skewed tree