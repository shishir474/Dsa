# SOl: Using recursion

# SOl2: Using BFS
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
            
        q = deque([root])
        level = 0
        while q:
            sz = len(q)
            while sz > 0:
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                sz-=1
            level+=1

        return level

# TC: O(n)
# SC: O(n)

