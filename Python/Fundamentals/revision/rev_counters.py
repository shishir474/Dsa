# https://www.geeksforgeeks.org/python/counters-in-python-set-1/ [Revisist - some parts are pending, check the related links on this page]

from collections import Counter

# used to count the frequency of elements in an iterable (like lists, strings or tuples) or from a mapping (dictionary). 
num = [1, 2, 3, 4, 5, 1, 2, 3]
counter = Counter(num)
print(counter) # Counter({1: 2, 2: 2, 3: 2, 4: 1, 5: 1})
print(counter[1]) # 2
print(counter[4]) # 1
print(counter[6]) # 0 (not found, returns 0 instead of raising an error)

# why use Counter() instead of a regular dictionary?
# 1. cleaner and more efficient than using regular dictionaries for counting frequencies.
# 2. quickly counts the frequency of elements in an iterable with a single line of code.

Counter("hello world") # Counter({'l': 3, 'o': 2, 'h': 1, 'e': 1, ' ': 1, 'w': 1, 'r': 1, 'd': 1})