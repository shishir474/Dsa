# in python, dictionaries are:
#     1. mutable
#     2. stores key-value pairs (keys must be unique and immutable, values can be of any type)
#     3. unordered (in python 3.7 and above, dictionaries maintain insertion

# creating a dictionary
# 1. using curly braces
d = {'name': 'Alice', 'age': 30, 'city': 'New York'}
# 2. using dict() constructor
d = dict(name='Alice', age=30, city='New York')

# accessing values in a dictionary
d = {'name': 'Alice', 'age': 30, 'city': 'New York'}
print(d['name']) # Alice
print(d.get('age')) # 30
print(d.get('country', 'USA')) # USA (default value if key not found)

# adding and updating key-value pairs in a dictionary
d = {'name': 'Alice', 'age': 30, 'city': 'New York'}
d['country'] = 'USA' # add new key-value pair
d['age'] = 31 # update existing key-value pair  

# removing dictionary items
d = {'name': 'Alice', 'age': 30, 'city': 'New York'}
del d['age'] # remove key-value pair with key 'age'
d.pop('city') # remove key-value pair with key 'city' and return its value
d.clear() # remove all key-value pairs from the dictionary  

# iterating through a dictionary
d = {'name': 'Alice', 'age': 30, 'city': 'New York'}
# iterate through keys
for key in d:
    print(key) # name, age, city

# iterate through values
for value in d.values():
    print(value) # Alice, 30, New York

# iterate through key-value pairs
for key, value in d.items():
    print(key, value) # name Alice, age 30, city New York
    
lst = [1, 2, 3]
mp = {}
for i in range(len(lst)):
    mp[lst[i]] = mp.get(lst[i], 0) + 1
    # mp[lst[i]]  = mp[lst[i]] + 1 # if the key is not present, it will raise a KeyError. To avoid this, we can use the get() method with a default value of 0. This way, if the key is not present, it will return 0 and we can add 1 to it.
    
    