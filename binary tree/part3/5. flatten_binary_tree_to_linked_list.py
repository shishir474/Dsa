# NOTE: 
# 1. You are not allowed to create new nodes. 
# You need to rearrange the given nodes and convert it into linkedlist.

# What would be the recursive solution?
# helper() would return 2 things: head & tail of flattened linked list.
# Idea is pretty simple
# we have the root. if root is null, there is nothing to flatten, hence we return (None, None)
# lh, lt = flatten(root.left)           -- left subtree flattened ll head and tail
# rh, rt = flatten(root.right)          -- right subtree flattened ll head and tail

# root.right = lh
# lt.right = rh
# This would be true in ideal scenario. 
# What if left subtree doesn't exist?
# then root.right = rh

# if lh:      # if left subtree exists:
#     root.right = lh
#     lt.right = rh
# else:       # left subtree doesn't exist
#     root.right = rh

# we need to return head & tail of flattened ll.
# root will be the head

# ideally ll would look like 
# root -> lh -> lt -> rh -> rt
# assuming left and right both subtrees exist.
# if right subtree exists --> tail = rt
# but if right subtree doesn't exist --> tail should be lt
# if both don't exist --> tail = root


# Better Solution
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def helper(root):
            if not root:
                return None, None               # (head, tail) of flattened ll   
        
            lh, lt = helper(root.left)     # first flatten left subtree
            rh, rt = helper(root.right)    # then flatten right subtree
            
            root.left = None               # set left as null
            
            if lh:                         # if left subtree exists
                root.right = lh            # root.right points to lh
                lt.right = rh              # and lt.right points to rh
            else:
                root.right = rh            # if left subtree doesn't exist, root.right points to rh
                
            tail = rt or lt or root     # if right subtree exists --> tail = rt
                                        # but if right subtree doesn't exist, tail should be lt
                                        # if both don't exist --> tail = root
            return root, tail
        
        return helper(root)[0]
                
        
        # TC: O(n)  -- during each recursive call we are just manipulating pointers.
        # SC: O(n) --> recursive stack space. No extra space being used other than this.
        
        
        
# Optimised Solution:
    # reverse preorder
    # preorder  = root --> left --> right
    # reverse preorder = right --> left --> root.    
    
    # preorder: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    # reverse preorder : 6 -> 5 -> 4 -> 3 -> 2 -> 1
    # 6 -> 5
    # 4-> 3 -> 2 
    
    #     1
    #    / \
    #   2   5
    #  / \   \
    # 3   4   6
    
# perform a simple reverse order traversal (right, left, root)
# at the root, perform the logic of reversing the linkedlist
# initialised a prev pointer to null
# root's next or root.right points to self.prev
# set root's left to null
# self.prev becomes root
# at the end you would get the flattened linked list following preorder logic
# you would be manipulating the pointers in place. Thus no extra space required.
 
# Most Optimal Solution   
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.prev = None
        def rev_preorder(root):
            if not root:
                return
            
            rev_preorder(root.right)
            rev_preorder(root.left)
            
            root.right = self.prev      # reversing linked list logic
            root.left = None
            self.prev = root
            
        rev_preorder(root)
        return root
            
    # TC: O(n) -- reverse preorder traversal, visits each node once
    # SC: O(h) -- recursive stack space
        

# Could you solve this iteratively?
# yes, we can

# Benefit of iterative solutino would be we will get rid of recursive stack space.
# This is just an extension of the recursive prorder solution.

class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:            # edge case: need to handle this separately, unlike recursive solutions
            return None         

        s = []                  # using stack - LIFO
        s.append(root)
        
        while s:
            top = s.pop()
            if top.right:
                s.append(top.right)
            if top.left:
                s.append(top.left)
            
            top.right = s[-1] if len(s) > 0 else None   # stack.top() which is s[-1]
            top.left = None
            
        return root
        
        # TC: O(n) -- reverse preorder traversal, visits each node once
        # SC: O(n) -- we're using a stack.
        
        # So techinicall, no improvement in time/space complexity


            
        
# Extreme naive solution: (not recommended)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Brute force solution
# perform preorder traversal and store all the nodes in a list
# then traverse thru this list and set the left ptr of each node as null
# and right ptr to res[i+1] bcoz we need to return flattened linked list which follows preorder fashion.

class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        res = []
        def preorder(root):
            if not root:
                return 
            res.append(root)
            preorder(root.left)
            preorder(root.right)
        
        preorder(root)      # store the preorder traversal in the res list.

        for i in range(len(res) - 1):
            res[i].left = None
            res[i].right = res[i+1]

        return root
    
    # TC: O(N) simple preorder traversal
    # SC: O(N) for res list.


    
# Optimal

# Can we do it without any extra space?
# reverse preorder traversal iteratively

class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        res = []
        def preorder(root):
            if not root:
                return 
            res.append(root)
            preorder(root.left)
            preorder(root.right)
        
        preorder(root)      # store the preorder traversal in the res list.

        for i in range(len(res) - 1):
            res[i].left = None
            res[i].right = res[i+1]

        return root

