# Numeric - int, float, complex
# Sequence Type - string, list, tuple
# Mapping Type - dict
# Boolean - bool
# Set Type - set, frozenset
# Binary Types - bytes, bytearray, memoryview

# 1. Numeric Data Types in Python

a = 5
print(type(a))      # <class 'int'>

b = 5.0
print(type(b))      # <class 'float'>

c = 2 + 4j
print(type(c))      # <class 'complex'>


# 2. Sequence Data Types in Python

# String Data type
s = 'Welcome to the Geeks World'
print(s)

# check data type 
print(type(s))

# access string with index
print(s[1])
print(s[2])
print(s[-1])

# Output
# Welcome to the Geeks World
# <class 'str'>
# e
# l
# d


# List Data type
# Lists are just like arrays, declared in other languages which is an ordered collection of data.
# It is very flexible as the items in a list do not need to be of the same type.
# heterogenous, mutable, ordered collection

# Empty list
a = []

# list with int values
a = [1, 2, 3]
print(a)

# list with mixed int and string
b = ["Geeks", "For", "Geeks", 4, 5]
print(b)



# Tuple Data Type
# Just like a list, a tuple is also an ordered collection of Python objects. The only difference between a tuple and a list is that tuples are immutable. Tuples cannot be modified after it is created.
# heterogenous, immutable, ordered collection
tup1 = (1,2.0,"Shishir")
print(tup1)


# Set data type
# heterogenous, unordered_collection, iterable, mutable, and has no duplicate elements

# initializing empty set
s1 = set()

s1 = set("GeeksForGeeks")
print("Set with the use of String: ", s1)

# creating a set with an iterable object
s2 = set(["Geeks", "For", "Geeks", 200.2])
print("Set with the use of List: ", s2)


# Access set items
# since sets are unordered, you cannot accesss elements by referring to an index 
# but we can loop over it or also use in / not in operators

set1 = set(["Geeks", "for", "Geeks"])
for i in set1:
    print(i, end=" ")
print()
print("Geeks" in set1)


# Dictionary Data Type
# key value pairs, keys must be unique and are case sensitive

# Creating empty dictionary
d = dict()
d1 = {}
print(d, type(d), d1, type(d1))

# using dict() constructor
d2 = dict({1:'Shishir', 2:'Ram', 3:"Ajay"})
print(d2, type(d2))

# access values using [] or get()
print(d2[1])
print(d2.get(1))