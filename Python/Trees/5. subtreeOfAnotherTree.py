
# https://leetcode.com/problems/subtree-of-another-tree/description/

# https://www.youtube.com/watch?v=E36O5SWp-LE&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=64 Neetcode solutions

# Most optimised solution:
# This method also helps in serialising the binary tree

# sol1:
class Solution:        
    def solve(self, root, mp):
        if not root:
            return "$"
        s = ""
        s += str(root.val)
        s += self.solve(root.left, mp)
        s += self.solve(root.right, mp)
        
        mp[s] += 1
        return s


    def isSubtree(self, root: Optional[TreeNode], subroot: Optional[TreeNode]) -> bool:
        if not root and not subroot:
            return True
        elif not root and subroot:
            return False
        elif root and not subroot:
            return True

        mp = defaultdict(int)
        s = self.solve(root, mp)
        # print(mp) defaultdict(<class 'int'>, {'1$$': 1, '2$$': 1, '41$$2$$': 1, '5$$': 1, '341$$2$$5$$': 1})
        # print(s) 341$$2$$5$$
        
        newmp = defaultdict(int)
        s1 = self.solve(subroot, newmp)
        if s1 in mp:
            return True
        return False
        
# TC: O(n)        
# SC: O(n)



# Sol2: Neetcode solutions
class Solution:        
    def isIdentical(self, root1, root2):
        if not root1 and not root2:
            return True
        elif not root1 or not root2:
            return False
        
        return (root1.val==root2.val and 
            self.isIdentical(root1.left,root2.left) and 
            self.isIdentical(root1.right,root2.right))


    def isSubtree(self, root: Optional[TreeNode], subroot: Optional[TreeNode]) -> bool:
        if not root and not subroot:
            return True
        elif not root and subroot:
            return False
        elif root and not subroot:
            return True

        # check if the tree at root is identical 
        if self.isIdentical(root, subroot):
            return True
        
        # check in the left subtree, see if its identical and also in the right subtree
        return self.isSubtree(root.left, subroot) or self.isSubtree(root.right, subroot)
        

# TC: O(n^2) TC of isIdentical function is O(n). So for each node we are doing O(n) work and we have n nodes
# Thus Overall TC is O(n^2)

# SC: O(n) recusive stack space





# SOL3: TC: O(n*m) where n and m are the respective number of nodes in both trees
# 
#Generating the serialised version is O(n) but checkSubstring(s1, s2) Function is O(n*m) where n and m is the length of s1 and s2

# Overall TC is quadratic  As you can see, there is no difference in complexity between sol1 and sol2. But sol1 is shorted

# Uses Logic used in Serialise of Binary Tree


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # get the preorder traversals of both trees and check if the subRoot's preorder is a subtring of the root's preorder traversa;
    # But this solution does not work. EX: root = [12], subroot = [2] -> 
    # s1 = "12,N,N" & s2 = "2,N,N" clearly s2 is a substring of s1, but subRoot is not part of root
    # Thus it is clear that simple prorder doen't confirm if it is a subroot of another tree. We also need inroder to confirm this
    # s1_in = "N,12,N", s2_in = "N,2,N" Clearly s2 is not a substring of N1. hence false

    # serialises the tree in inorder fashion
    def serialise_inorder_helper(self, root, res):
        if not root:
            res.append('N')
            return
        
        self.serialise_inorder_helper(root.left, res)
        res.append(str(root.val))
        self.serialise_inorder_helper(root.right, res)

    def serialise_inorder(self, root):
        res = []
        self.serialise_inorder_helper(root, res)
        return ",".join(res)
    
    def serialise_preorder_helper(self, root, res):
        if not root:
            res.append('N')
            return
        
        res.append(str(root.val))
        self.serialise_preorder_helper(root.left, res)
        self.serialise_preorder_helper(root.right, res)
        
    # serialises the tree in preorder fashion
    def serialise_preorder(self, root):
        res = []
        self.serialise_preorder_helper(root, res)
        return ",".join(res)
    
    # checks if s2 is a substring of s1
    def checkSubstring(self, s1, s2):
        if len(s2) > len(s1):
            return False
        for i in range(len(s1)-len(s2)+1):
            isSubstring = True
            for j in range(len(s2)):
                if s2[j] != s1[i+j]:
                    isSubstring = False
                    break
            if isSubstring:
                return True
        
        return False

     
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root and not subroot:
            return True
        elif not root and subRoot:
            return False
        elif root and not subRoot:
            return True

        in_root = self.serialise_inorder(root)
        in_subRoot = self.serialise_inorder(subRoot)
        pre_root = self.serialise_preorder(root)
        pre_subRoot = self.serialise_preorder(subRoot)

        print(in_root)
        print(in_subRoot)
        print(pre_root)
        print(pre_subRoot)

        if self.checkSubstring(in_root, in_subRoot) and self.checkSubstring(pre_root, pre_subRoot):
            return True
        

        return False

        