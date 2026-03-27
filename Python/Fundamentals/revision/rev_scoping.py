class Student:
    school = "ABC school"       # class variable
    
    def __init__(self, name):
        self.name = name   # instance variable
    
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
print(Student.school)   # XYZ school
print(s2.school)        # XYZ school
print(s1.school)        # My school

# This also tells me one thing, that if there exists an instance variable with the same name as class variable.
# priority order: instance variable  --> class variable

# if you access that variable, in this case "school" using that instance, the instance variable will have a higher priority.
# Of course, if the instance variable doesn't exist, python will check whether it's a class variable.
# If it's not defined in the class also, then it checks in the parent classes (inheritance)

# attribute lookup order
# when we do
s1.school
# Python searches in this order
# 1. Instance namespace (s1.__dict__)
# 2. Class namespace (Student.__dict__)
# 3. Parent classes (MRO - inheritance chain)
# 4. ❌ NOT global scope

# Object attribute lookup NEVER checks global variables



# Some python scoping specific nuances

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
    
    
    
class Solution:
    diameter = 0   # class variable

# Now:

s1 = Solution()
s2 = Solution()

s1.diameter = 10

print(s1.diameter)  # 10  (instance variable created)
print(s2.diameter)  # 0   (still class variable)