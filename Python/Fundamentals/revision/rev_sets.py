# in python, sets are:
#     1. mutable
#     2. unordered (does not maintain insertion order)
#     3. unindexed (cannot access elements using index)
#     4. does not allow duplicate elements
#     5. can store heterogeneous data types
#     6. implemented using hash tables internally
#     7. python sets are not thread safe; synchronization is needed when multiple threads access a set concurrently



# creating sets in python
# 1. using curly braces
s = {1, 2, 3, 4, 5}
# 2. using set() constructor
s = set([1, 2, 3, 4, 5])
# 3. empty set
s = set() # {} creates an empty dictionary, not a set
# 4. creating set using tuple
s = set((1, 2, 3, 4, 5))


# unordered, unindexed, and mutable
s = {1, 2, 3, 4, 5}
s.add(6) # add element to the set
s.remove(3) # remove element from the set
try:
    s[0]
except TypeError:
    print("Sets are unindexed, cannot access elements using index.")
    
    
# adding elements to a set
s = {1, 2, 3}
s.add(4) # add single element
s.update([5, 6]) # add multiple elements from an iterable (like list
s.update({7, 8}) # add multiple elements from another set
s.update((9, 10)) # add multiple elements from a tuple

for i in s:
    print(i) # 1, 2, 4, 5, 6, 7, 8, 9, 10 (order may vary since sets are unordered)
    
# memebership testing
s = {1, 2, 3, 4, 5}
print(3 in s) # True

# removing elements from a set
# remove(), discard(), pop(), clear()
s = {1, 2, 3, 4, 5}
s.remove(3) # remove element 3, raises KeyError if element not found
s.discard(4) # remove element 4, does not raise error if element not found
s.pop() # remove and return an arbitrary element from the set, raises KeyError if set is empty
s.clear() # remove all elements from the set


# frozen sets in python:
# it's a built in datatype in python that is similar to sets but immutable.
# Once created, you cannot add or remove elements from a frozenset. 
# They are hashable and can be used as keys in dictionaries or elements of other sets.

# creating a frozenset
# 1. using frozenset() constructor
fs = frozenset([1, 2, 3, 4, 5])
# 2. using frozenset() with a set
fs = frozenset({1, 2, 3, 4, 5})
# 3. using frozenset() with a tuple
fs = frozenset((1, 2, 3, 4, 5))


# Typecasting objects into sets
# 1. from list to set
lst = [1, 2, 3, 4, 5]
s = set(lst)
# 2. from tuple to set
t = (1, 2, 3, 4, 5)
s = set(t)
# 3. from string to set
s = set("Hello World") # {'H', 'e', 'l', 'o', ' ', 'W', 'r', 'd'} (order may vary since sets are unordered) 
# 4. from dictionary to set (only keys are added to the set)
d = {'name': 'Alice', 'age': 30, 'city': 'New York'}
s = set(d) # {'name', 'age', 'city'} (order may vary since sets are unordered)

# max and min values in a set
s = {1, 2, 3, 4, 5}
print(max(s)) # 5
print(min(s)) # 1

# solution 2:
# Sorting the set (converts it into a sorted list)
sorted_s = sorted(s)
print(sorted_s) # [1,2,3,4,5]
print(sorted_s[0]) # 1 (min value)
print(sorted_s[-1]) # 5 (max value)

# solution 3: using loops
max_val = float('-inf')
min_val = float('inf')
for num in s:
    max_val = max(max_val, num)
    min_val = min(min_val, num)
print(max_val) # 5
print(min_val) # 1


# python set operations:
# union, intersection, difference, symmetric difference
s1 = {1, 2, 3, 4, 5}
s2 = {4, 5, 6, 7, 8}

# union
print(s1 | s2) # {1, 2, 3, 4, 5, 6, 7, 8}
print(s1.union(s2)) # {1, 2, 3, 4, 5, 6, 7, 8}

# intersection
print(s1 & s2) # {4, 5}     
print(s1.intersection(s2)) # {4, 5} 

# difference
print(s1 - s2) # {1, 2, 3}
print(s1.difference(s2)) # {1, 2, 3}    

# symmetric difference - includes elements that are in either set but not in both.
print(s1 ^ s2) # {1, 2, 3, 6, 7, 8}
print(s1.symmetric_difference(s2)) # {1, 2, 3, 6, 7, 8}