# In python, lists are:
#     1. mutable
#     2. ordered
#     3. heterogeneous - can store different types of data
#     4. indexed based - can access elements using their index

# creating lists
# 1. using square brackets
l = [1, 2, 3, 4, 5]
# 2. using list() constructor
l = list([1, 2, 3, 4, 5])
# 3. using list comprehension
l = [i for i in range(1, 6)]    
# 4. using range() function
l = list(range(1, 6))   
# 4. creating list with repeated elements
l = [0] * 5 # [0, 0, 0, 0, 0]

# adding elements to a list
a = []
a.append(10) # add 10 at the end
a.insert(0, 5) # insert 5 at index 0
a.extend([15, 20]) # add multiple elements at the end
a.clear() # remove all elements from the list

# updating elements in a list, since lists are mutable, we can update elements
l = [1, 2, 3, 4, 5]
l[0] = 10 # update element at index 0


# remove elements from a list
l = [1, 2, 3, 4, 5]
l.remove(3) # remove first occurrence of 3
l.pop() # remove and return last element
l.pop(0) # remove and return element at index 0
del l[0] # delete element at index 0
del l # delete the entire list


# how python stores lists elements in memory?
# In python, list doesn’t store actual values directly. Instead, it stores references (pointers) to objects in memory
# This means numbers, strings and booleans are separate objects in memory and the list just keeps their addresses.

#Sum the list

# solution 1
lst = [1, 2, 3]
n = len(lst)
sum = 0
for i in range(n):
    sum += nums[i]
    
# solution 2
from functools import reduce
sum = reduce(lambda x,y: x + y, nums)

# list comprehension
# List comprehension is a concise and powerful way to create new lists by applying an expression to each item in an existing iterable (like a list, tuple or range).
# It helps you write clean, readable and efficient code compared to traditional loops.

# why use list comprehension?
# 1. clean code
# 2. more readable
# 3. faster execution than equivalent for loops

# for loop vs list comprehension:
lst = [1, 2, 3, 4, 5]
res = []
for val in lst:
    res.append(val * val)

# list comprehension
res = [val ** 2 for val in lst]

# conditional statements in list comprehension
lst = [1, 2, 3, 4, 5]
res = [val for val in lst if val%2 == 0]

# creating list from a range
res = [i for i in range(10)]

# using nesteed loops:
res = [(i,j) for i in range(3) for j in range(2)]   
#  [(0, 0), (0, 1), (1, 0), (1, 1), (2, 0), (2, 1)]

# flattening a list of lists:
mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
res = [val for row in mat for val in row]


# zip() is used to combine 2 or more iterables (like lists, tuples, strings, dictinaries)
# element-wise into a single iterable of tuples. 
# Each tuple contains elements that share the same index from each of the input iterables.

a = [1, 2, 3]
b = ['a', 'b', 'c']

zipped = zip(a, b) # <zip object at 0x7f8
zipped_list = list(zipped) # [(1, 'a'), (2, 'b'), (3, 'c')]     

# no iterable passed
list(zip()) # []

# single iterable passed
list(zip(a)) # [(1,), (2,), (3,)]

# iterable of different lengths
a = [1, 2, 3, 4]
b = ['a', 'b']
list(zip(a, b)) # [(1, 'a'), (2, 'b')] python stops pairing as soon as the shortest iterable is exhausted.

# unzipping data with zip() - using *(asterisk) operator
lst = [(1, 'a'), (2, 'b'), (3, 'c')]
nums, chars = zip(*lst) # <zip object at 0x7f
print(nums) # (1, 2, 3)
print(chars) # ('a', 'b', 'c')

# combine dictionary key, value pairs
d = {'name':"Alice", 'age': 30, 'city': 'New York'}
keys = d.keys()
values = d.values()
list(zip(keys, values)) # [('name', 'Alice'), ('age', 30), ('city', 'New York')]


# enumerate() and zip()

lst = ['a', 'b', 'c']
for index, value in enumerate(lst):
    print(index, value) # 0 a, 1 b, 2 c

# we want to iterate through both lists simultaneously and also keep track of the index. 
# We can use zip() to combine the lists and enumerate() to get the index.    
a = [10, 20, 30]
b = ['a', 'b', 'c']
for index, (num, char) in enumerate(zip(a,b)):
    print(index, num, char) # 0 10 a, 1 20 b, 2 30 c



# dictionary comprehesion:

# 1. creating a dictionary from two lists
keys = ['name', 'age', 'city']
values = ['Alice', 30, 'New York']

# zip(keys, values) will give us an iterable of tuples 
# then we can use dictionary comprehension to create a dictionary from these tuples/pairs
d = {key: value for key, value in zip(keys, values)}
# {'name': 'Alice', 'age': 30, 'city': 'New York'}


# 2. using fromkeys() method
# creates a dictionary by taking a group of keys and assigning the same value to all of them.
d = dict.fromkeys(range(5), True)
# {0: True, 1: True, 2: True, 3: True, 4: True}

# 3. 
fruits = ['apple', 'banana', 'cherry']
d = {fruit: len(fruit) for fruit in fruits}
# {'apple': 5, 'banana': 6, 'cherry': 6
