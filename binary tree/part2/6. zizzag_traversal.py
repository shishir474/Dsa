# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:        # edge case: root null check
            return []

        res = []
        cnt = 0         # used to track odd/even level
        
        dq = deque()
        dq.append(root)

        while dq:       # performing level order traversal
            sz = len(dq)
            curr_lvl = []
            
            for _ in range(sz):
                front = dq.popleft()

                curr_lvl.append(front.val)      # append val not node

                if front.left:
                    dq.append(front.left)
                if front.right:
                    dq.append(front.right)
            
             if cnt%2 == 1:
                # curr_lvl = curr_lvl[::-1] # returns a new reversed copy, original list remains unaffected. TC: O(N), SC:O(N)
                curr_lvl.reverse()          # reverses list in place, TC: O(N), SC: O(1)

            res.append(curr_lvl)
            cnt+=1
        
        return res
    
    # TC: O(n) + O(n): level order traversal and list reversal
    # SC: O(max width of the binary tree) = O(n)
    # n = 2^h - 1
    # and no of nodes in the last level of complete binary tree: 2^(h-1) = 2^h / 2 = (n + 1) / 2 = n / 2
    

# More Optimal Version:
# (without reversing the list) --> build in the correct order

from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:        # edge case: root null check
            return []

        res = []
        left_to_right = True
        
        dq = deque()
        dq.append(root)

        while dq:       # performing level order traversal
            sz = len(dq)
            curr_lvl = deque()
            
            for _ in range(sz):
                
                front = dq.popleft()

                if left_to_right:
                    curr_lvl.append(front.val)      # append val not node
                else:
                    curr_lvl.appendleft(front.val)  # appendleft, using deque 

                if front.left:
                    dq.append(front.left)
                if front.right:
                    dq.append(front.right)
            
            res.append(list(curr_lvl))
            left_to_right = not left_to_right
        
        return res
