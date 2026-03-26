# distance between 2 nodes l1 and l2
# root->l1 + root->l2 - 2 * root->lca
# 2 + 2 -2.1 = 2

# This solution assumes the following:
# 1. both p and q nodes exists in the binary tree. 
    # lca doesn't make sense if the nodes are not present

# 2. the question clearly states all node.val are unique

# 3. p != q

# LCA definition: 
    # first node where p and q split into different subtrees.
    
    
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def lca_helper(root, p, q):
            if not root:                    # root null check
                return None
            if root == p or root == q:      # root equality check
                return root

            left_lca = lca_helper(root.left, p, q)
            right_lca = lca_helper(root.right, p, q)
            
            if left_lca and right_lca:      # both are not null, it means root is the lca
                return root
            elif left_lca:  
                return left_lca
            else:                           # why else instead of elif rightlca?
                return right_lca            # if both are null return null. This handles both cases

        return lca_helper(root, p, q)
    
    # TC: O(n) - visiting each node once
    # SC: O(h) - recursive stack space, equivalent to the height of the binary tree. 
    # O(logn) in case of binary tree and O(n) in case of skewed tree
    

# can this code be optimised any further?
# no, this is the most optimal solution.

# but we can improve the coding style and make it more minimal and clean
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def lca_helper(root, p, q):
            # these 2 checks can be combined, but this is more clear
            if not root:                    # root null check
                return None
            if root == p or root == q:      # root equality check
                return root

            left_lca = lca_helper(root.left, p, q)
            right_lca = lca_helper(root.right, p, q)
            
            if left_lca and right_lca:      # both are not null, it means root is the lca
                return root
            
            return left_lca or right_lca
           
        return lca_helper(root, p, q)
    
    

# when can we do better than O(N)?
# Only in BST

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def lca_helper(root, p, q):
            # these 2 checks can be combined, but this is more clear
            if not root:                    # root null check
                return None
            if root == p or root == q:      # root equality check
                return root
            
            if p.val < root.val and q.val < root.val:
                lca_helper(root.left, p, q)
            elif p.val > root.val and q.val > root.val:
                lca_helper(root.right, p, q)
            else:
                return root
           
        return lca_helper(root, p, q)
    
    # TC: O(logn)   -- because at each step, we are reducing the input by half.