# Standard Recursive Solution
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def maxDepthHelper(root):
            if not root: 
                return 0
            return 1 + max(maxDepthHelper(root.left), maxDepthHelper(root.right))
        
        return maxDepthHelper(root)
    
    # TC: O(n) - since we'll be exploring each node exactly once
    # SC: O(n) - recursive stack space which is equivalent to max depth of the recursion tree.
    # and the max depth could be O(N) in case of a skewed tree (worst case). 
    # In the case of a balanced binary tree, height h = O(logn) base 2
    
    
    
    
    
# Iterative solution:
from collections import deque
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        # iterative solution: using level order traversal
        max_depth = 0
        dq = deque([(root, 1)]) # node, depth
        while dq:
            front, depth = dq.popleft()
            max_depth = max(max_depth, depth)
            if front.left:
                dq.append((front.left, depth+1))
            if front.right:
                dq.append((front.right, depth+1))

        return max_depth
    
    # TC: O(N) - since we're performing level order traversal, traversing through each node once.
    # SC: O(max_size_of_deque) which will be equivalent to max_width and this will happen in case of a complete binary tree.
    # max_width of a binary tree is O(N)
    
    
# Can we optimse it any further?
# Yes, we can. We don't need to store depth in queue. Just a variable would be enough.

# more space optimized, just incrementing the depth at each level
from collections import deque
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        # iterative solution: using level order traversal
        depth = 0
        dq = deque([root]) # node
        
        while dq:
            sz = len(dq)
            depth += 1          # simply increment the depth at each level
            for i in range(sz):
                front = dq.popleft()
                if front.left:
                    dq.append(front.left)
                if front.right:
                    dq.append(front.right)
                    
        return depth

    
# NOTE:
# 1. relation between n (number of nodes and h max depth of the binary tree)

    # Best case : complete binary tree
    # 2^0 + 2^1 + 2^2 + .. + 2^h-1  = n
    # This is a GP series. Sum of GP series: (a.r^n - 1) / (r-1)
    # where a is the first term and r  is the ratio or multiplying factor.
    # a = 1, r = 2
    #  = (2^h - 1)/(2-1)
    #  = 2^h - 1 = n
    #  2^h = n + 1
    #  h = log(n+1) base 2

    # So, h = O(logn)


    # In case of skewed tree:
    #     h = n

    # So, h = O(n)

    # “In a balanced binary tree, height is logarithmic in number of nodes, O(log n), 
    # while in the worst case (skewed tree), height becomes linear, O(n).”



# 2. Max width of the binary tree

# max_width = 2^(h-1)
# where h is the max depth and assuming that it's a complete binary tree.
# Now we know that: n = 2^h - 1
# 2^h = n + 1
# max_width = 2^h / 2 = (n + 1) / 2
# so max width ~ n/2
# Hence max_width = O(n)

# For skewed tree: 
#     max_width = O(1)