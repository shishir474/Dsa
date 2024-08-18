class Solution:

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.cnt = 0
        self.res = -1

        def solve(root):
            if not root:
                return 
            solve(root.left)
            self.cnt+=1
            if self.cnt == k: # as soon as the kth smalles element is found
                self.res = root.val # set the res and return
                return
            solve(root.right)
        
        solve(root)
        return self.res


# TC: O(K)
# SC: O(n)

# Inorder traversal of a BST produces a sorted array. 