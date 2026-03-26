# Conclusion:
# a tree is considered height balanced if 
# abs(height_left_subtree - height_right_subtree) <= 1
# and this should be true for all nodes

# precompute the height of each node and store it in a map. 
# This precomputation reduces the complexity from n^2 to O(n), because we won't have to calculate depth during each recursive call



# Brute Solution:
    # compute depth during the recursion call. This will make the solution n^2
    

# Better Solution
class Solution:
    def get_depth(self, root, mp) -> int:
        if not root:
            return 0
        mp[root] = 1 + max(self.get_depth(root.left, mp), 
                        self.get_depth(root.right, mp))
        return mp[root]

    def is_balanced_helper(self, root, mp) -> bool:
        if not root:
            return True
        
        height_left_subtree = mp[root.left] if root.left else 0
        height_right_subtree = mp[root.right] if root.right else 0
        is_root_balanced = True if abs(height_left_subtree - height_right_subtree) <= 1 else False

        if self.is_balanced_helper(root.left, mp) and self.is_balanced_helper(root.right, mp) and is_root_balanced:
            return True

        return False

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # a tree is considered height balanced if 
        # abs(height_left_subtree - height_right_subtree) <= 1
        # and this should be true for all nodes

        # precompute the height of each node and store it in a map
        mp = {}
        self.get_depth(root, mp)                    # O(n)
        return self.is_balanced_helper(root, mp)    # O(n)
    
    # TC: precomputation of depth of each node takes O(n) time and then another O(n) time to evaluate whether the tree is balanced
    # SC: O(n) for storing the depth of each node in map + O(n) for recursive stack space.
    
    
    
# cleaner version
class Solution:
    def get_depth(self, root, mp) -> int:
        if not root:
            return 0
        mp[root] = 1 + max(self.get_depth(root.left, mp), 
                        self.get_depth(root.right, mp))
        return mp[root]

    def is_balanced_helper(self, root, mp) -> bool:
        if not root:
            return True
        
        height_left_subtree = mp[root.left] if root.left else 0
        height_right_subtree = mp[root.right] if root.right else 0
        is_root_balanced = True if abs(height_left_subtree - height_right_subtree) <= 1 else False

        is_left_balanced = self.is_balanced_helper(root.left, mp)
        is_right_balanced = self.is_balanced_helper(root.right, mp)
        
        if is_left_balanced and is_right_balanced and is_root_balanced:
            return True

        return False

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # a tree is considered height balanced if 
        # abs(height_left_subtree - height_right_subtree) <= 1
        # and this should be true for all nodes

        # precompute the height of each node and store it in a map
        mp = {}
        self.get_depth(root, mp)                    # O(n)
        return self.is_balanced_helper(root, mp)    # O(n)
    




# Optimal Solution:

# can we optimise this any further?
# Yes, we can.
# we can avoid 2 traversals. we can also remove extra hashmap.
# we will return 2 things, height:int and is_balanced:bool

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # a tree is considered height balanced if 
        # abs(height_left_subtree - height_right_subtree) <= 1
        # and this should be true for all nodes

        def dfs(root):
            if not root:
                return 0, True      # (height, is_balanced) 
            
            lh, lb = dfs(root.left)
            rh, rb = dfs(root.right)
            
            height = 1 + max(lh, rh)
            is_balanced = True if lb and rb and abs(lh - rh) <= 1 else False
            
            return (height, is_balanced)
        
        return dfs(root)[1]
    
# Solution Highlights:    
    # simple O(N) solution with one single traversal
    # no extra hashmap needed.
    # no precomputation needed
    # computing depth and is_balanced simaltaneously
    
    # TC: O(n) -- visiting each node once
    # SC: O(n) -- recursive stack space
            
                
                
# NOTE: 
# This problem is very similar to computing diameter.

# we applied same sorts of optimizations in both the problem.

# The most optimized solution has 2 versions:

#     1. we can return 2 things from the function call and then compute the value for the current node using this.
#         In diameter calculation:  height and diameter
#         in this problem: height and is_balanced.
        
#     2. we can return something else and compute what is asked in the problem in the recursion
#         ex: in diameter calculation: we returned height, but updated the diameter during each
#         The recursion function returns height, and once the recursion completes we have the correct value of diameter
#         set in the instance variable.
        
#         can I use the same pattern here? Seems difficult. 
#         Yes, we can but it's a little less intuitive.
#         Below is the solution for that
#         we return the height. we get left and right subtree height and check if the curr node is balanced.
#         if not we return -1, signifying tree is not balanced at curr node.
#         similarly if left subtree height or right subtree height is -1, we return -1, indicating left or right subtree is not balanced.
     
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # a tree is considered height balanced if 
        # abs(height_left_subtree - height_right_subtree) <= 1
        # and this should be true for all nodes

        def dfs(root):
            if not root:
                return 0
            
            lh = dfs(root.left)
            if lh == -1:
                return -1           # left subtree not balanced
            
            rh = dfs(root.right)
            if rh == -1:
                return -1           # right subtree not balanced
            
            if abs(lh - rh) > 1:
                return -1           # current node is not balanced
            
            return 1 + max(lh, rh)
            
        
        return dfs(root) != -1          # -1 != -1 --> False
    
    # TC: O(n)
    # SC: O(h) where h is the height of the binary tree. 
    # This is O(logn) in complete binary tree and O(n) in skewed tree
    
#  Solution Highlights:    
    # simple O(N) solution with one single traversal
    # no extra hashmap needed.
    # no precomputation needed
    # terminates early, if the tree is unbalanced.