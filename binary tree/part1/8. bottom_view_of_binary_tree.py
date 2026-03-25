# Correct Solution

from collections import deque
class Solution:
    def bottomView(self, root):
        mp = {}     # width -> node value
        dq = deque([(root, 0)])  # node, width
        while dq:
            front,width = dq.popleft()
            
            # last occurence = bottom view
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
    