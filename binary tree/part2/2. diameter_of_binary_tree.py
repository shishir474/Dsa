# Conclusion:


# 1. Precompute the depth of each node and store it in a hashmap

# 2. diameter = max(left_diamter, right_diameter, case_when_diameter_passes_thru_root)

# case_when_diameter_passes_thru_root = left_depth + right_depth + 2

# 2 corresponds to the edges that connects root to left subtree and right subtree.

# It would be something like:
#     case_when_diameter_passes_thru_root = left_depth + right_depth
#     if root.left: case_when_diameter_passes_thru_root += 1
#     if root.right: case_when_diameter_passes_thru_root += 1

# Generally, a leaf node is considered to have depth = 1, but here the depth 
# would be considered as 0, since we're counting the edges and not the nodes.
# Therefore subtracting 1.
# left_depth = self.get_depth(root.left) - 1
# right_depth = self.get_depth(root.right) - 1






# Brute Force Solution
class Solution:
    # get_depth is O(n) time complexity wise
    # and space complexity wise it's also O(n) -- max depth of the recursion tree and that will be n in case of skewed tree
    def get_depth(self, root):
        if not root:
            return 0
        return 1 + max(self.get_depth(root.left), self.get_depth(root.right))

    # get_diameter() is O(n^2), since for each node, we are calling get_depth() which is O(n) in itself.
    # So overall the solution becomes O(n^2). Ofcourse we can optimize this. We will precompute the depth and store it in a hashmap
    # something like node -> depth. This can be done in O(n) time and this will convert our solution from n^2 to O(n).
    # space complexity wise -- are we using any extra space over here? No, I don't think so. Just a couple of variables.
    # But there's going to be recursive stack space which will be equivalent to depth of the recursion tree which is O(n) again in skewed tree.
    def get_diameter(self, root):
        if not root: 
            return 0
        
        ld = self.get_diameter(root.left)   # left diamter
        rd = self.get_diameter(root.right)  # right diamter
        lh = self.get_depth(root.left) - 1  # left depth, this is O(N)
        rh = self.get_depth(root.right) - 1 # right depth, this is O(N)
        
        ans = max(ld, rd)   # ans is max of left_diameter, right_diameter, and the case if diameter passes thru root
        case1_res = lh + rh
        if root.left: case1_res+=1
        if root.right: case1_res+=1
        ans = max(ans, case1_res)
        return ans

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # we have 3 possibilities
        #1. diamter passes thru the root:
            # 2 + x + y, 2 (assuming both left and right subtrees exists) and x & y represents the depth of left & right subtree
        # 2. diatmer is present in the left subtree
        # 3. diamter is present in the right subtree
        return self.get_diameter(root)
    
    

    
# Better Solution: 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # get_depth is O(n) time complexity wise
    # and space complexity wise it's also O(n) -- max depth of the recursion tree and that will be n in case of skewed tree
    def get_depth(self, root, mp):
        if not root:
            return 0
        mp[root] =  1 + max(self.get_depth(root.left, mp),
                            self.get_depth(root.right,mp))
        return mp[root]

    def get_diameter(self, root, mp):
        if not root: 
            return 0
        
        ld = self.get_diameter(root.left, mp)   # left diamter
        rd = self.get_diameter(root.right, mp)  # right diamter
        # lh = self.get_depth(root.left) - 1  if root.left else 0      # left depth
        # rh = self.get_depth(root.right) - 1 if root.right else 0     # right depth
        lh = mp[root.left] - 1 if root.left else 0      # left depth, this is O(1)
        rh = mp[root.right] - 1 if root.right else 0     # right depth, this is O(1)
        
        ans = max(ld, rd)   # ans is max of left_diameter, right_diameter, and the case if diameter passes thru root
        case1_res = lh + rh
        if root.left: case1_res+=1
        if root.right: case1_res+=1
        ans = max(ans, case1_res)
        return ans

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # we have 3 possibilities
        #1. diamter passes thru the root:
            # 2 + x + y, 2 (assuming both left and right subtrees exists) and x & y represents the depth of left & right subtree
        # 2. diameter is present in the left subtree
        # 3. diameter is present in the right subtree

        mp = {}     # node --> depth
        self.get_depth(root, mp)
        return self.get_diameter(root, mp)
    
    


# Optimal Solution

# We're currently doing :
#     1st pass --> compute depth O(n)
#     2nd pass --> compute diameter O(n)
# We're using extra hashmap space O(n)

# Can we do it in single traversal O(n) and no extra map?
# yes, we can

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = 0

        def get_depth(root):
            nonlocal diameter

            if not root:
                return 0

            ld = get_depth(root.left)
            rd = get_depth(root.right)

            diameter = max(diameter, ld + rd)   # we're first reading the diameter and then assigning value to it.
                                                # THis varaible is not defined in the local scope, so trying to read it, before assigning value to it is giving unbound local error.
            # either make it a class variable (self.diameter) or explicitly mention it as nonlocal                                                

            return 1 + max(ld,rd)

        get_depth(root)

        return diameter
    

#####.   Same Solution Using instance variable:        #####

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0       # intance variable

        def get_depth(root):
            if not root:
                return 0

            ld = get_depth(root.left)
            rd = get_depth(root.right)

            self.diameter = max(self.diameter, ld + rd)   # we're first reading the diameter and then assigning value to it.
                                                # THis varaible is not defined in the local scope, so trying to read it, before assigning value to it is giving unbound local error.
            # either make it a class variable (self.diameter) or explicitly mention it as nonlocal                                                

            return 1 + max(ld,rd)

        get_depth(root)

        return self.diameter
    
# Why this is the best solution?
#     1. Each node is visited once.
#     2. Only one single traversal
#     3. No hashmap is used.
#     4. Depth & diameter computed together.
    
# we will be calculating and returning the depth at each node. 
# But simaltaneously, in the same function call we will also keep track of the diamter.
# Remember, get_depth() function returns the depth, but this line
# self.diameter = max(self.diameter, ld + rd)  
# is where we are leveragin the depth's and computing the diameter.
# self.diameter is an instance variable, which is reused across all function calls.

# TC: O(N)    -- visited each node once
# SC: O(h)    -- recursive stack space. For balanced trees, height would be logn and for skewed tree, it would be n.
    


# slight improvement (return both values)
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if not root:
                return 0, 0     # (diameter, height)

            ld, lh = dfs(root.left)
            rd, rh = dfs(root.right)

            height = 1 + max(lh, rh)
            diameter = max(ld, rd, lh + rh)

            return diameter, height

        return dfs(root)[0]

# TC: O(N)    -- visited each node once
# SC: O(h)    -- recursive stack space. For balanced trees, height would be logn and for skewed tree, it would be n.
    
    
    
    
 


# ------------------------------------------------------------------------------------    
    
# Some python specific nuances

# Instead of using nonlocal diameter, can we use global diameter?
# No, this will not work.

# diameter is defined inside the function, so it's not global.
# When we say global diameter, python looks for a variable defined at the module level.
# diameter = 0        # outside all functions.

# 2 possibilities
# 1. No global diameter exists
    # returns NameError or unexpected behaviour
# 2. You defined a global diameter. let's say outside the class.
    # it's a bad practise. The value will be shared across all function calls.
    # So it may reuse the same variable across test cases. 
    # Also it's not thread safe, breaks encapsulation
    
# Correct choices:
    # 1. use nonlocal (best for nested functions)
    # 2. or use class variables self.diameter
    
# Key Difference
    # keyword        scope
    # local           inside function 
    # nonlocal        enclosing function
    # global          entire file/module

# ⚡ Bonus Insight (very useful)
def outer():
    x = 10
    def inner():
        nonlocal x   # refers to outer's x

# vs

x = 10
def func():
    global x   # refers to global x
    
# Final Takeaways
# Use nonlocal → for nested functions
# Avoid global → unless absolutely necessary


# Class Variable vs Instance Variable
# class variable is defined at the class level and it's shared across all instances.
# instance variable is defined within constructor and it is unique to that particular instance

class Student:
    school = "ABC school"       # class variable
    
    def __init__(self, name):
        self.name = self.name   # instance variable
    
s1 = Student("Shishir")
s2 = Student("Rahul")

print(s1.school)        # ABC school
print(s2.school)        # ABC school
# both objects/instances share the same school or variable

# modify class variable
Student.school = "XYZ school"

print(s1.school)        # XYZ school
print(s2.school)        # XYZ school

# NOTE: attempting to update class variable thru instances, doesn't update class variable.
# Creates new instance variable instead
s1.school = "My school"



    
# NOTE: Below solution throws errors. There's python scoping related errors.
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = 0        # this is NOT global

        def get_depth(root):
            global diameter     # this does NOT work

            if not root:
                return 0

            ld = get_depth(root.left)
            rd = get_depth(root.right)

            diameter = max(diameter, ld + rd)   # we're first reading the diameter and then assigning value to it.
                                                # THis varaible is not defined in the local scope, so trying to read it, before assigning value to it is giving unbound local error.
            # either make it a class variable (self.diameter) or explicitly mention it as nonlocal                                                

            return 1 + max(ld,rd)

        get_depth(root)

        return diameter