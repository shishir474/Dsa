# defaultdict is a subclass of the built-in dict class. 
# It automatically assigns a default value to any key that is accessed but not already present in the dictionarya
# which means we don't need to check if a key exists before accessing it. This can simplify code and avoid KeyError exceptions.

# syntax:
    # defaultdict(default_factory)

# default_factory is a callable(like int, list, set, str or a custom function) that provides the default value for a key that is accessed but not already present in the dictionary.
# If default_factory is None, then accessing a missing key will raise a KeyError, just like a regular dictionary.

from collections import defaultdict
d = defaultdict(int)
nums = [1, 2, 3, 4, 2, 4, 1, 2]
for num in nums:
    d[num] += 1

print(d) # defaultdict(<class 'int'>, {1: 2, 2: 3, 3: 1, 4: 2})
print(d[1])
print(d[5]) # 0 (default value for int is 0)

# grouping words by their first letter using defaultdict
words = ["apple", "ant", "banana", "bat", "carrot", "cat"]
d = defaultdict(list)
for word in words:
    d[word[0]].append(word)
    
print(d) # defaultdict(<class 'list'>, {'a': ['apple', 'ant'], 'b': ['banana', 'bat'], 'c': ['carrot', 'cat']})


# Behind the scenes, defaultdict uses the special __missing__() method:

# It is automatically called when a key is not found.
# If a default_factory is provided: its return value is used.
# If default_factory is None: a KeyError is raised.

from collections import defaultdict
d = defaultdict(lambda: "not present")      # you can also pass custom function 
print(d['key1']) # not present (default value from lambda function)
print(d['key2']) # not present (default value from lambda function)