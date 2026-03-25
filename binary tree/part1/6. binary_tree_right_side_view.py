from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # getting the rightside view is equivalent to finding the last node on each level.
        # simply do a level order traversal and get the last node at each level. 
        
        # left side view is equivalent to finding the first node at each level.
        
        # edge case: if root is null
        if not root:
            return []

        res = []
        dq = deque()
        dq.append(root)
        while dq:
            sz = len(dq)
            # traversing level by level
            for i in range(sz):
                front = dq.popleft()    # O(1)
  
                if i == sz - 1:     # means we're at the last node in the current level
                    res.append(front.val)
                
                if front.left:
                    dq.append(front.left)
                if front.right:
                    dq.append(front.right)
                

        return res

        # TC: O(n) --> traversing each node once
        
        # SC: the max width of the binary tree in the worst case if it's a complete binary tree, 
        # now assuming h is the height of the binary tree. 
        # if it's a complete binary tree, then n  = 2^(h+1) - 1
        # and width of the binary tree at last level will be 2^h which is nothing but n/2
        # Hence the space complexity is O(n/2) which is same as O(n)
        
        