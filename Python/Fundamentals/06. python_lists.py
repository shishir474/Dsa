# Python Lists

# 1. lists are dynamic sized array(automatically grows and shrinks)
# 2. can store all types of items(including another list) in a list
# 3. It may contain mixed type of items(heterogenous), this is possible because a list mainly stores references at contiguous locations and actual items maybe stored at different locations.
# 4. They are Mutable. Hence, we can modify, replace or delete the items.
# 5. List are ordered. It maintain the order of elements based on how they are added.
# 6. Accessing items in List can be done directly using their position (index), starting from 0.

# NOTE: List stores the references(pointers) to the actual objects in memory. Python internally creaets separate objects for each items and then stores their memory addresses inside the list


# Creating list

# 1. usign [] brackets
list1 = [1,2,"Shishir",30.2,['a','b','c']]

# 2. Using list constructor
# pass an iterable(like a string, tuple or another list) to list function
a = list("Shishir")
b = list(((1,2,3)))
c = list([1,2,"Shishir",30.2,['a','b','c']])
print(a,b,c)

#3. Creating list with repeated elements
# Create a list [0, 0, 0, 0, 0, 0, 0]
b = [0] * 7


# Accessing list elements

# python indexes start at 0, so ar[0] will access the first element
# negative indexes allows us to access elements from the end of the list, index -1 represents the last eleement of the list
a = [1,2,3,4,5]

a = [10, 20, 30, 40, 50]

# Access first element
print(a[0])    

# Access last element
print(a[-1])


# Adding elements into list 

# append(): Adds an element at the end of the list
# insert(): Adds an element at a specific position 
# extend(): Adds multiple elements to the end of the list

# Adding 10 to end of list
a.append(10)  
print("After append(10):", a)  

# Inserting 5 at index 0
a.insert(0, 5)
print("After insert(0, 5):", a) 

# Adding multiple elements  [15, 20, 25] at the end
a.extend([15, 20, 25])  
print("After extend([15, 20, 25]):", a)


# Updating elements into list

# we can change the value by accessing it using its index

a = [1,2,3]

# change 2nd element
a[1] = 25


# Removing elements from list 

# remove(): Removes the first occurence of an element. If the item is not found, raises ValueError
# pop(): Removes the element at a specific index or the last element if no index is specified
# del statement: deletes an element at a specific index
# clear() or del statement to remove all elements of the list

a = [10, 20, 30, 40, 50]

# Removes the first occurrence of 30
a.remove(30)  
print("After remove(30):", a)

# Removes the element at index 1 (20)
popped_val = a.pop(1)  
print("Popped element:", popped_val)
print("After pop(1):", a) 

# Deletes the first element (10)
del a[0]  
print("After del a[0]:", a)

# Deletes all the elements of the list
a.clear()

a = [2]* 10
del a[:] 


# Iterate over lists in python

# using for loop
a= [1,3,5,7,9]
for val in a:
    print(val)
    
# Using For loop and Range() method
for i in range(len(a)):
    print(a[i])

# Using While loop
i = 0
while i < len(a):
    print(a[i])
    i+=1
    
# Using enumerate(): This method provides both the index {i} and the value {val} of each element during the loop
for i,val in enumerate(a):
    print(i,val)
    
# Using List Comprehension: is similar to for loop, provides shortex syntax for looping
[print(val, sep=" ") for val in a]

# NOTE: this is not a recommended way to iterate through lists as it creates a new list (extra space)


# Iterate over a list of lists in python
a = [[1,2], [3,4], [5,6]]
for i in a:
    for j in i:
        print(j, end=" ")

print()

# Using enumerate(): this is useful when we want to know the position of each sublist
for i,val in enumerate(a):
    print(i,val)

# using List comprehension to flatten a nested list
# [element outer_for_loop, inner_for_loop]
b = [j for i in a for j in i ]
print(b)

# using itertool.chain() --> returns a chain object
# lets us combine multiple iterables into one.
from itertools import chain
print(list(chain(*a)))

a = [[1, 2], [3, 4], [5, 6]]
# chain(*a) = chain([1,2], [3,4], [5,6])
# Output: 1, 2, 3, 4, 5, 6

# NOTE: * is the unpacking operator. It spreads out the elements of the list a as individual lists

# Syntax	    Meaning
# chain(a)	       a single iterable: [[1,2],[3,4]]
# chain(*a)	       multiple iterables: [1,2], [3,4], ...

a = [1,2,3]
b = ["Shishir","Raj"]
c = [True, False, True]
print(list(chain(a,b,c)))

li = [1, 2, 3, 4, 5, 6]
a, b, *rest = li
print(a, b, rest)

a, *mid, c = li
print(a, mid, c)

li = [1, [2, 3], 4]
a, (b1, b2), c = li
print(a,b1,b2,c)




# List comprehensions

# a way to create lists using a concise syntax. 
# It allows us to generate a new list by applying an expression to each item in an existing iterable (such as a list or range). This helps us to write cleaner, more readable code compared to traditional looping techniques.

# Syntax:
    # [expression for item in iterable if condition]

# item: is the current element taken from the iterable
# iterable: is a sequence or collection(like list, tuple, set)
# expression: the transformation or value to be included in the new list

# This syntax allows iteration, transfomation, and conditional filtering all in one line

list1 = [1,2,3,4,5]
squared_list = [val ** 2 for val in list1]      # 1 line
print(squared_list)

# traditional for loop style: 3 lines
squared_list = []
for val in list1:
    squared_list.append(val ** 2)
print(squared_list)


# conditional statements in list comprehension
res = [val for val in list1 if val%2 == 0]


# Creating a list from range
# Creates a list of numbers from 0 to 9
list1 = [i for i in range(10)]

# list comprehension on nested loops
coordinates = [(i,j) for i in range(3) for j in range(3)]
print(coordinates)

# Flattening a list of lists
mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
flattend_mat= [j for i in mat for j in i]
print(flattend_mat)



# Slicing and List Comprehension
# its a powerful combination for handling and manupulating lists
# Syntax
    # [expression for item in list[start:stop:step] if condition]

a = [1,2,3,4,5]

# create a new list where each element in the first 3 elements is multipled by 2
res = [val * 2 for val in a[:3]]

# Filtering even numbers from the last 3 elements
res = [val for val in a[-3:] if val%2 == 0]

# Extract squares of alternate elements
res = [val ** 2 for val in a[::2]]



# Lambda Function wiht list comprehension

# Lambda function is an anonymous function(i.e a function without a name)
# As we already know, def keyword is used to define normal/named function, lambda keyword is used to create anonymous functions in python

# syntax:
    # lambda arguments: expression
    # map(function, iterable) --> returns map object
            # map(function, iterable) returns an iterator where the function is applied to each item of the iterable.
            # It transforms each element using the given function.
    # filter(function, iterable) --> returns filter object
            # filter(function, iterable) returns an iterator with only the elements from the iterable for which the function returns True.
            # If the function is None, it removes all falsy values (like 0, None, '', False, etc.).
    # zip(iterable1, iterable2, ...) --> returns zip object
            # zip() combines multiple iterables (like lists or tuples) element by element into tuples.
            # It’s like "zipping up" two lists so that elements at the same position are paired together.

# map(function, iterable)

# using named function
def square(x):
    return x ** 2
   
nums = [1,2,3,4]
print(list(map(square,nums)))

print(list(map(lambda x: x**2, nums)))
   
list1 = [i for i in range(1,11)]
print(list(map(lambda x: x ** 2, list1)))


# filter(function, iterable)

nums = [1,2,3,4,5]
print(list(filter(lambda x: x%2 == 0, nums)))
# filter() will only pick those values for which lambda function evaluates true

items = [0, 1, False, 2, '', 3]
print(list(filter(None, items)))    # if filter's lambda function is None, it will filter our falsy values 


# list comprehension with 2 lists

# zip(iterable1, iterable2, ... , strict = True)
# strict is an optional parameter: If True, throws ValueError if the iterables are not of same length
# zip() combines iterables into tuples

a = [1, 2, 3, 4]
b = [5, 6, 7, 8]

print(list(zip(a,b, strict=True)))

print(list(zip("abcdef", range(3), range(4))))
# stops at the shortest iterable.

# unzipping with *
pairs = [('x', 1), ('y', 2), ('z', 3)]
letters, numbers = zip(*pairs)
print(letters, numbers)

# NOTE: zip() does not cover all possible pairs, only considers elements at the same level
res = [(x,y) for x,y in zip(a,b) if x+y >= 10]
print(res)


# Some more ways to use list comprehension with 2 lists

# Using enumerate(): if you want to access the index of the elements from the lists, enumerate() can be used to iterate through both the index and the element of each list

# enumerate() gives both the index i and the pair (x,y) of corresponding elements from the lists a and b
# list comprehension creates new list containing tuples of the index and elements from both list
res = [(i,x,y) for i,(x,y)in enumerate(zip(a,b))]
print(res)




# most frequent element in a list

# NOTE: list1.count(x) --> returns the freq of x in list1

list1 = [2, 1, 2, 2, 1, 3]
# key argument tells max() what value to use for comparison, for each element. It lets you customise the behaviour
print(max(list1))       # gives max element of the list1
print(max(set(list1), key=list1.count))  # gives the element with max freq in list1
print(max(list1, key=list1.count))      # this will also work, but there's one caveat: duplicate work
# max() will call list1.count(x) for every item in the list - including duplicates, which is inefficient for large list



print(max(list1, key=list1.count))
# max() will call list.count() for every item in the list and then picks the one that return max value for list.count.

# sol2: naive solution
max_freq = 0
num = 0;
for val in set(list1): # only iterating through unique element
    if list1.count(val) > max_freq:
        max_freq = list1.count(val)
        num = val;
print(num)


# Solution3: Using counter
from collections import Counter
print(Counter(list1).most_common(1)[0][0])  # most frequent element
# Counter(iterable) --> returns the count of each element in the iterable
# List the n most common elements and their counts from the most common to the least.  
# If n is None, then list all element counts.

s = "SHISHIR"
print(Counter(s))


# using dictionary
max_freq = 0
dict = {}
for val in list1:
    dict[val] = dict.get(val,0) + 1
    if(dict[val] > max_freq):
        max_freq=  dict[val]
        num = val
print(num, val)


print(list(reversed(list1)))


# List Sorting
a = ["Python", "C", "Java", "JavaScript", "Go"]

# sorted(iterable, [key], [reverse]) --> returns a new sorted list 
# key lets you customize the sorting order
# reverse boolean lets you sort in descending order
sorted(a, key=len)
print(a)

nums = [2,5,3,4,1]
print(sorted(nums))

# sort() -> None
# sorts the list inplace, unlike sorted(list) which returns a new list
# key lets you customize the sorting order
# reverse boolean lets you sort in descending order
nums.sort()


t =  (3,4,2,4)
print(sorted(t))
# tuple are immutable means can't be modified. Hence you cannot sort that in place



# List reverse()

# reversed(li) --> returns a reversed iterator
# li.reverse() --> None (reverses the list in place)


# List copy()   

# a.copy() does not take any arguments and creates and returns a shallow copy of the list a

a = [1,2,3]
b=  a.copy()

print(a, b)
b.append(100)
b[0] = 200

print(a,b)
# NOTE: The orig list remains unchanged. This shows that the lists are independent

# Copying list of lists
a = [[1,2],[3,4]]
b = a.copy()
b[0][0] = 100
print(a, b)
# The orig list is modified. Even though copy() creates a shallow copy. Modyfying the inner list in copied list affects the original list , bcoz both lists reference the same inner lists

a = [1, 'two', 3.0, [4, 5], {'key': 'value'}]
b = a.copy()
b.append(100)       # here changes will not reflect, bcoz both are independent
b[3].append(100)    # here changes will reflect bcoz they both share the same reference
print(a,b)

# deepcopy()
from copy import deepcopy
b = deepcopy(a)
print('before deep copy',a,b)
b[3].append(100)    # here changes will not reflect, bcoz of deepcopy()
print('after deep copy',a,b)    


# check if two lists are identical
a = [1,3,2,4]
b = a.copy()
# using all() and zip()
print(all(val1 == val2 for val1,val2 in zip(a,b)))
# using equality ==  operator
print(a == b)



# combining 2 sorted lists
a = [1, 3, 5]
b = [2, 4, 6]
# solution 1: using sorted() with concatenation
print(sorted(a+b))

# solution2: using 2 pointers (manual approach)
c = []
i = j = 0
while(i < len(a) and j < len(b)):
    if(a[i] <= b[j]):
        c.append(a[i])
        i+=1
    else:
        c.append(b[j])
        j+=1

# one of them a or b will be exhausted at this point, so appending the remaining elements of them
c.extend(a[i:])
c.extend(b[j:]) 

# solution3: using chain
print(sorted(chain(a,b)))

