# Width of binary tree: --> level order traversal
# no of nodes between the first node and the last node in that level

# if we can index the nodes, then the question becomes too trivial.

# But how do we assign indexes to them?
# let's do a level order traversal and track (node, idx)
# initial configuration: (root, 1) tuple in deque

# The idea is:
#     if parent node's index is i
#     child indexes: (2 * i) & (2 * i + 1)

# lets maintain a map: node -> index

# and then we again do a level order traversal. We check the first and last node at each level
# we get their indexes --> width = mp[last_node] - mp[first_node]
# and then track max width across all levels

from collections import deque
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        mp = {}          # node, index
        dq = deque([(root, 1)])       # root, index

        # 1st level order where we assign indexes 
        while dq:
            front, idx = dq.popleft()
            mp[front] = idx         # assigning idx index to node
            if front.left:
                dq.append((front.left, 2*idx))
            if front.right:
                dq.append((front.right, 2*idx + 1))
                
        
        # 2nd level order traversal, where we compute width of each level and track the max_width
        max_width = 0
        dq.append(root)
        while dq:
            sz = len(dq)
            lo, hi = -1, -1
            
            for i in range(sz):
                front = dq.popleft()
                if i == 0:
                    lo = mp[front]
                if i == sz - 1:
                    hi = mp[front]
                    
                if front.left:
                    dq.append(front.left)
                if front.right:
                    dq.append(front.right)
                    
            max_width = max(max_width, hi - lo + 1)
            
            
        return max_width

 

# Clean code:
# Below is the cleaner and more efficient version of the above code
from collections import deque
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        # mp = {}          # node, index      we don't even need this map, because we are already tracking index in deque
        
        dq = deque([(root, 1)])       # root, index
        max_width = 0           # initialised as 0, root null condition already handled above
        while dq:
            sz = len(dq)
            lo, hi = -1, -1

            for i in range(sz):
                front, idx = dq.popleft()
                if i == 0:
                    lo = idx
                if i == sz - 1:
                    hi = idx
                    
                if front.left:
                    dq.append((front.left, 2*idx))
                if front.right:
                    dq.append((front.right, 2*idx + 1))
            
            max_width = max(max_width, hi - lo + 1)    
            
            
        return max_width