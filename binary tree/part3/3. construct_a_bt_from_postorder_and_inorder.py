# This is the most clear solution and is most the intuitive one.
# Here the order in which recursion calls are made doesn't matter much,
# since we are explicltiy passing the boundaries for both the arrays

# Better Solution
# using pointers
# in_left & in_right --> left and right pointers for inorder
# post_left & post_right --> left and right pointers for postorder
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # provides O(1) lookup
        inorder_mp = {val: idx for idx, val in enumerate(inorder)}

        def helper(post_left, post_right, in_left, in_right):
            if in_left > in_right or post_left > post_right:      # adding conditions for both is inmp
                return None
            
            root_val = postorder[post_right]       # create root with post_order[post_right] value
            
            idx = inorder_mp[root_val]
            nums_left = idx - in_left           # no of elements in left subtree
            nums_right = in_right - idx
            
            root = TreeNode(root_val)
            
            root.left = helper(post_left, post_left + nums_left - 1, in_left, idx - 1)
            root.right = helper(post_left + nums_left, post_right - 1, idx + 1, in_right)
            
            return root

        return helper(0, len(postorder) - 1, 0, len(inorder) - 1)
    
    
    # TC: O(n)  -- O(1) work during each recursive call and n recursive calls
    # SC: O(n) - hashmap + recursive stack space
    
    
# Optimal Solution:
# We dont need 4 pointers to track boundaries of both inorder and postorder. 
# Only tracking boundaries of inorder is sufficient. 
# # because both preorder and postorder follow a linear sequence in which the roots are created.
# In case of preorder, we start from idx = 0, and incase of post order we start from n - 1
# where n = len(post_order)
# because that will be our root element and then we increase/decrease the idx pointer respectively.
# preorder's root goes from left to right
# postorder's root goes from right to left


class Solution:
    def buildTree(self, inorder: List[int], post_order: List[int]) -> Optional[TreeNode]:
        # provides O(1) lookup
        inorder_mp = {val: idx for idx, val in enumerate(inorder)}

        self.post_idx = len(post_order) - 1

        # only need to track inorder boundaries.
        # In case of preorder, we start from idx = 0, and incase of post order we start from n - 1
        # where n = len(post_order)
        # because that will be our root element and then we increase/decrease the idx pointer respectively.
        # preorder's root goes from left to right
        # postorder's root goes from right to left
        def helper(in_left, in_right):
            if in_left > in_right:                     # edge case
                return None
            
            root_val = post_order[self.post_idx]       # create root with post_order[self.post_idx] value
            self.post_idx -= 1                          # decrease root idx
            
            idx = inorder_mp[root_val]
            
            root = TreeNode(root_val)

            # postorder --> left, right, root
            # Since we are traversing backwards: root --> right --> left
            # so we should build right subtree before left subtree -- This order matters
            root.right = helper(idx + 1, in_right)
            root.left = helper(in_left, idx - 1)

            return root

        return helper(0, len(inorder) - 1)