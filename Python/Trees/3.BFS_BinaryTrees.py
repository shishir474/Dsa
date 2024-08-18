class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return root
        ans = []
        q = collections.deque([root])
        while q:
            sz = len(q)
            t = [] # stores nodes of the current level
            while sz:
                node = q.popleft()
                t.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                sz-=1
            
            ans.append(t)
        
        return ans
    
#  SC:O(n) the max size of the queue can be n/2 in case of binary tree