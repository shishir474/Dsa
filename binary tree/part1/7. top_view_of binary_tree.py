# why dfs solution doesn't work?

# top view definition is:
#     min depth node at each horizontal distance.
#     So basically we want for each horizontal distance what is the min depth node. 
#     That will be our top view
    
# But our approach depends on:
#     first node visited in dfs traversal
#     DFS doesn't guarantee minimum depth

# Counter Example:
    #     1
    #    / \
    #   2   3
    #    \
    #     4
    #      \
    #       5
    
    # Horizontal distance
    # 1 → 0
    # 2 → -1
    # 3 → +1
    # 4 → 0
    # 5 → +1
        
    # Our DFS
    # 1 -> 2 -> 4 -> 5 -> 3
    
    # Map becomes:
    # width 0 → 1
    # width -1 → 2
    # width +1 → 5   ❌ WRONG (should be 3)
    
    # Why wrong? 
    # because we visited 5 before 3. 
    # But 3 is actually higher (closer to root)
    
    # Correct Approach: BFS (Level Order)
    # BFS guarantees topmost node or min depth node is visited first at each width
    
# Correct Solution

from collections import deque
class Solution:
    def topView(self, root):
        mp = {}     # width -> node value
        dq = deque()  # node, width
        dq.append((root, 0))
        while dq:
            front,width = dq.popleft()
            
            # first occurence = top view
            if width not in mp:
                mp[width] = front.data
            
            if front.left:
                dq.append((front.left, width - 1))
            if front.right:
                dq.append((front.right, width + 1))
        
        # iterate on map in the sorted fashion of keys
        # This ensures we are picking nodes from left to right fashion
        return [mp[key] for key in sorted(mp.keys())]
    
    # TC: simple level order traversal O(N)
    # SC: max width of the binary tree which is nothing but O(N)
    
    # for bottom view, we simply overwrite or in other words store the last occurence for each width
    # bottom view is same as max depth node corresponding to each horizontal distance
    
    
        
        

# Wrong Solution
# Below is the dfs code

class Solution:
    def topView(self, root):
        # mp is nothing but a dictionary. mp stores key-value pairs
        # dictionary also stores key-value pairs
        
        mp = {} # width -> node.val map
        # Will do a simple inorder traversal
        # could choose any traversal technique. But the question states that we need to return the nodes from left to right.
        # Hence going with inorder. We could also do it with preorder. This way we will give preference to topmost nodes first compared to the lower nodes.
        # and as far as res format is concerned, we could iterate thru the map key's in sorted fashion and generate the res.
        # for each width, we store only the first node's value
        
        # why preorder ? is important to understand. 
        # It is because we will priority the curr or root node first compared to the lower nodes in the traversal and this helps in generating the top view
        
        res = []
        
        def preorder(root, width):
            if not root:
                return
            
            # store key only if you're encountering for the first time
            if width not in mp: # this is the first time we're encountering this width
                mp[width] = root.data
            preorder(root.left, width - 1)
            preorder(root.right, width + 1)
            
        preorder(root, 0)
        
        # iterate keys in sorted order to construct the result in the right format 
        # ( we need to return nodes from left to right)
        for key in sorted(mp.keys()):
            res.append(mp[key])
        
        return res
        