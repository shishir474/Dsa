# Given an inorder and preorder traversal. 
# You will always be able to create a unique binary tree

# The question guarantees min length of given input list is 1.
# each value in preorder and inorder is unique


# Below code is correct, but is unoptimised. 
# There are several issues here:
#     1. irdx = inorder.index(preorder[0])   # O(n) operation
#     This is O(n) each time. Called for every node leads to O(n^2) solution

# 2. Extra space usage because of list slicing
    # we are creating new list during using slicing during each recursion call.
    # These can be avoided.

# Brute Solution

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0 and len(inorder) == 0:        # handle length 0
            return None
        if len(preorder) == 1 and len(inorder) == 1:        # handle length 1
            return TreeNode(preorder[0])

        root = TreeNode(preorder[0])
        irdx = inorder.index(preorder[0])   # inorder_root_index       O(n)
     
        inl = inorder[0:irdx]
        inr = inorder[irdx+1:]
     
        l = len(inl)
        prel = preorder[1: 1 + l]
        prer = preorder[1+l:]

        root.left = self.buildTree(prel, inl)
        root.right = self.buildTree(prer, inr)

        return root
    
    
# better solution: using pointers for tracking preorder and inorder
# no extra space coz of list slicing
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # provides O(1) lookup
        inorder_mp = {val: idx for idx, val in enumerate(inorder)}

        def helper(pre_left, pre_right, in_left, in_right):
            if in_left > in_right or pre_left > pre_right:      # adding conditions for both is inmp
                return None
            
            root_val = preorder[pre_left]       # create root with preoder[pre_left] value
            
            idx = inorder_mp[root_val]
            nums_left = idx - in_left           # no of elements in left subtree
            
            root = TreeNode(root_val)
            
            root.left = helper(pre_left + 1, pre_left + nums_left, in_left, idx - 1)
            root.right = helper(pre_left + nums_left + 1, pre_right, idx + 1, in_right)
            
            return root

        return helper(0, len(preorder) - 1, 0, len(inorder) - 1)
    
    # TC: O(n)  -- O(1) work during each recursive call and n recursive calls
    # SC: O(n) - hashmap + recursive stack space
    
    
    
# Cleaner version code 
# 
# -- we don't need to track boundaries of both inorder and preorder.
# Only tracking boundaries of inorder is sufficient
# for preorder, we will have an instance variable self.pre_idx which will be shared across all recursive calls.
# value of self.pre_idx will tell us the index that we need to utilise to create root and 
# will be incremented during each call 

# we will use hashmap to find the index of root in inorder
# we will use pointers instead of list slicing

# in_left --> inorder_left ptr
# in_right -> inorder_right_ptr

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # provides O(1) lookup
        inorder_mp = {val: idx for idx, val in enumerate(inorder)}
        
        self.pre_idx = 0                    # preorder_index ptr points to root

        def helper(in_left, in_right):
            if in_left > in_right:
                return None
            
            root_val = preorder[self.pre_idx]       # create root with preoder[pre_idx] value
            self.pre_idx += 1                       # increase pre_idx by 1
            
            idx = inorder_mp[root_val]
            
            root = TreeNode(root_val)
            root.left = helper(in_left, idx - 1)
            root.right = helper(idx + 1, in_right)
            
            return root

        return helper(0, len(inorder) - 1)
    
    # TC: O(n) -- during each call we are doing O(1) work
    # SC: O(n)  -- for hashmap and recursive stack space
    