# Tuples are:
#     1. Ordered
#     2. Immutable
#     3. Heterogeneous (can contain different data types)
#     4. Indexed (can access elements using their index)

# creating a tuple
# 1. using parentheses
t = (1, 2, 3, 4, 5)
# 2. using list
t = tuple([1, 2, 3, 4, 5])
# 3. using built-in function
t = tuple('Geeks')


# accessing elements in a tuple
t = (1, 2, 3, 4, 5)
# using indexing
print(t[0]) # 1
# using slicing
print(t[1:4]) # (2, 3, 4)
print(t[-1]) # 5
print(t[::-1]) # (5, 4, 3, 2, 1)    
# using unpacking
a, b, c, d, e = t
print(a, b, c, d, e) # 1 2 3


# concatenation of tuples
# 2 or more tuples can be concatenated using + operator
t1 = (1, 2, 3)
t2 = (4, 5, 6)
t3 = t1 + t2
print(t3) # (1, 2, 3, 4, 5, 6)

# NOTE: Only same datatypes can be concatenated. For example, you cannot concatenate a tuple and a list.


# deleting a tuple
# using del statement
t = (1, 2, 3, 4, 5)
del t


# tuple unpacking with * (asterisk)
t = (1, 2, 3, 4, 5)
a, *b, c = t
print(a) # 1
print(b) # [2, 3, 4]        
print(c) # 5

# NOTE: " * " operator can be used in tuple unpacking to grab multiple items into a list. 
# This is useful when you want to extract just a few specific elements and collect the rest together.

# https://www.geeksforgeeks.org/python/python-tuples/ [Revisit - pending, check the related links on this page ]