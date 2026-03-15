# # In python, lists are:
# #     1. mutable
# #     2. ordered
# #     3. heterogeneous - can store different types of data
# #     4. indexed based - can access elements using their index

# # creating lists
# # 1. using square brackets
# l = [1, 2, 3, 4, 5]
# # 2. using list() constructor
# l = list([1, 2, 3, 4, 5])
# # 3. using list comprehension
# l = [i for i in range(1, 6)]    
# # 4. using range() function
# l = list(range(1, 6))   
# # 4. creating list with repeated elements
# l = [0] * 5 # [0, 0, 0, 0, 0]

# # adding elements to a list
# a = []
# a.append(10) # add 10 at the end
# a.insert(0, 5) # insert 5 at index 0
# a.extend([15, 20]) # add multiple elements at the end
# a.clear() # remove all elements from the list

# # updating elements in a list, since lists are mutable, we can update elements
# l = [1, 2, 3, 4, 5]
# l[0] = 10 # update element at index 0


# # remove elements from a list
# l = [1, 2, 3, 4, 5]
# l.remove(3) # remove first occurrence of 3
# l.pop() # remove and return last element
# l.pop(0) # remove and return element at index 0
# del l[0] # delete element at index 0
# del l # delete the entire list


# # how python stores lists elements in memory?
# # In python, list doesn’t store actual values directly. Instead, it stores references (pointers) to objects in memory
# # This means numbers, strings and booleans are separate objects in memory and the list just keeps their addresses.

# #Sum the list

# # solution 1
# lst = [1, 2, 3]
# n = len(lst)
# sum = 0
# for i in range(n):
#     sum += nums[i]
    
# # solution 2
# from functools import reduce
# sum = reduce(lambda x,y: x + y, nums)

# # list comprehension
# # List comprehension is a concise and powerful way to create new lists by applying an expression to each item in an existing iterable (like a list, tuple or range).
# # It helps you write clean, readable and efficient code compared to traditional loops.

# # why use list comprehension?
# # 1. clean code
# # 2. more readable
# # 3. faster execution than equivalent for loops

# # for loop vs list comprehension:
# lst = [1, 2, 3, 4, 5]
# res = []
# for val in lst:
#     res.append(val * val)

# # list comprehension
# res = [val ** 2 for val in lst]

# # conditional statements in list comprehension
# lst = [1, 2, 3, 4, 5]
# res = [val for val in lst if val%2 == 0]

# # creating list from a range
# res = [i for i in range(10)]

# # using nesteed loops:
# res = [(i,j) for i in range(3) for j in range(2)]   
# #  [(0, 0), (0, 1), (1, 0), (1, 1), (2, 0), (2, 1)]

# # flattening a list of lists:
# mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# res = [val for row in mat for val in row]


# # zip() is used to combine 2 or more iterables (like lists, tuples, strings, dictinaries)
# # element-wise into a single iterable of tuples. 
# # Each tuple contains elements that share the same index from each of the input iterables.

# a = [1, 2, 3]
# b = ['a', 'b', 'c']

# zipped = zip(a, b) # <zip object at 0x7f8
# zipped_list = list(zipped) # [(1, 'a'), (2, 'b'), (3, 'c')]     

# # no iterable passed
# list(zip()) # []

# # single iterable passed
# list(zip(a)) # [(1,), (2,), (3,)]

# # iterable of different lengths
# a = [1, 2, 3, 4]
# b = ['a', 'b']
# list(zip(a, b)) # [(1, 'a'), (2, 'b')] python stops pairing as soon as the shortest iterable is exhausted.

# # unzipping data with zip() - using *(asterisk) operator
# lst = [(1, 'a'), (2, 'b'), (3, 'c')]
# nums, chars = zip(*lst) # <zip object at 0x7f
# print(nums) # (1, 2, 3)
# print(chars) # ('a', 'b', 'c')

# # combine dictionary key, value pairs
# d = {'name':"Alice", 'age': 30, 'city': 'New York'}
# keys = d.keys()
# values = d.values()
# list(zip(keys, values)) # [('name', 'Alice'), ('age', 30), ('city', 'New York')]


# # enumerate() and zip()

# lst = ['a', 'b', 'c']
# for index, value in enumerate(lst):
#     print(index, value) # 0 a, 1 b, 2 c

# # we want to iterate through both lists simultaneously and also keep track of the index. 
# # We can use zip() to combine the lists and enumerate() to get the index.    
# a = [10, 20, 30]
# b = ['a', 'b', 'c']
# for index, (num, char) in enumerate(zip(a,b)):
#     print(index, num, char) # 0 10 a, 1 20 b, 2 30 c



# # dictionary comprehesion:

# # 1. creating a dictionary from two lists
# keys = ['name', 'age', 'city']
# values = ['Alice', 30, 'New York']

# # zip(keys, values) will give us an iterable of tuples 
# # then we can use dictionary comprehension to create a dictionary from these tuples/pairs
# d = {key: value for key, value in zip(keys, values)}
# # {'name': 'Alice', 'age': 30, 'city': 'New York'}


# # 2. using fromkeys() method
# # creates a dictionary by taking a group of keys and assigning the same value to all of them.
# d = dict.fromkeys(range(5), True)
# # {0: True, 1: True, 2: True, 3: True, 4: True}

# # 3. 
# fruits = ['apple', 'banana', 'cherry']
# d = {fruit: len(fruit) for fruit in fruits}
# # {'apple': 5, 'banana': 6, 'cherry': 6


# # Creating a list copy

# res = []
# path = [1,2,3]
# res.append(path)
# # Under the hood, res stores the reference of path. Now if you modify path, the changes will also reflect in res
# # Hence it's important to store the copy of path.
# res.append(path.copy())
# # or res.append(path[:])                # slicing always produces a new list
# # or res.append(list(path))

# # Important point here is: we are storing copy of temp_list.
# # There are multiple ways to create a copy of a list in python. All of them return a new list
# list(path)
# path.copy()
# path[:]     # recommended: because it is short and fast

# # ex:
# a = [1,2,3]
# b = a[:]        # slice the list from start to end

# print(a is b)       # False
# print(a == b)       # True

# # b has the same content, but is a different list object in memory. 
# # This matters in backtracking because if you don't store the copy, any changes made in the path, will reflect in the res as well.
# # Hence it is crucial that we store the copy of path.


# # Important nuance: Shallow copy
# a = [[1,2], [3,4]]
# b = a[:]            # this creates a shallow copy, only the outer container is copied, inner lists are still shared
# b[0].append(5)
# print(a)    # [[1,2,5], [3,4]]
# # because the inner lists are still shared.
# # Slicing copies the list container, but not nested objects

# # if you want to create a completely separate copy, use deepcopy() or list comprehension
# import copy
# b1 = copy.deepcopy(a)
# b1[0].append(5)
# print(a)    #  [[1,2], [3,4]]
# # now a and b1 are completely independent. b1 is a deep copy of a. Any changes made in either of them will not reflect in other

# b2 = [row[:] for row in a]      # copying each inner list individually
# b2[0].append(5)
# print(a)    #  [[1,2], [3,4]]


# # Rule of Thumb: Shallow Copy vs Deep Copy

# # If the list contains immutable elements

# # Use shallow copy.

# # Example elements:
# # int, float, string, tuple

# # Example:
# path = [1, 2, 3]
# res.append(path[:])
# # or
# res.append(path.copy())

# # Safe because integers cannot change.


# # If the list contains mutable elements
# # You usually need deep copy.
# # Mutable objects include:
# # list
# # dict
# # set
# # custom objects

# # Example:
# a = [[1,2], [3,4]]
# b = copy.deepcopy(a)


# # Why?
# # Immutable objects cannot change.
# # Example:
# a = [1,2,3]
# b = a[:]

# b[0] = 10
# print(a)

# [1,2,3] # Output:
# # Because integers are immutable.

# # Mutable objects can change internally.
# # Example:
# a = [[1,2], [3,4]]
# b = a[:]

# b[0].append(5)
# print(a)

# [[1,2,5],[3,4]] # Output:
# # Because both lists point to the same inner list.

# # Summary:
# # both path.copy() and path[:] create a shallow copy, not a deep copy

path = [1,2,3]
a = path.copy()
b = path[:]
# when we create copy like this, separate memory is allocated to both lists a & b.
print(path is a)        # False, bcoz sepearate memory is allocated to path and a
print(path == a)        # True, bcoz both path and a have the same content in same order
print(a is b)           # False, bcoz sepearate memory is allocated to a and b
print(a == b)           # True, bcoz both a and b have same content


# when shallow copy will not work, when you have nested lists or you are storing mutable objects(like list, set, dict) inside a list
path = [[1,2], [3,4]]
import copy
b = copy.deepcopy(path)
b[0].append(5)
print(path)     # [[1,2], [3,4]]
# changes are not reflected in path, because b is a deep copy of a.

b1 = path[:] # or path.copy() --> this creates a shallow copy.
# meaning, only the outer container is copied, inner lists are still shared
b1[0].append(5)
print(path)     # [[1,2,5], [3,4]]
# changes will reflect in path