# https://leetcode.com/problems/reverse-words-in-a-string/

# Pythonic one liner (best solution)
class Solution:
    def reverseWords(self, s: str) -> str:
        # slices the list, reverses it and then join all elements using " " as separator
        return " ".join(s.split()[::-1])
    
    
    
# without using built-in functions like split
class Solution:
    def reverseWords(self, s: str) -> str:
        # without using built-in functions like split
        words = []
        word = ""
        for char in s:
            if char == ' ':
                if word:    # append only if word is valid
                    words.append(word)
                    word = ""
            else:
                word += char 
                
        # append the last word
        if word:
            words.append(word)
            
        return " ".join(words[::-1])
    
    
# difference between lst[::-1] and lst.reverse()

# lst[::-1] is list slicing syntax
# lst[start: end: step]
# start = beginning (default)
# end = end (default)
# step = -1 -> go backwards

lst = [1,2,3,4]
print(lst[::-1])    # [4,3,2,1]

# lst[::-1] produces a new reversed list
# The original list remains intact


# difference between [::-1] and .reverse()
# feature                       [::-1]                                              list.reverse()
# Returns new list                Yes                                                   No
# Modifies original list          No                                                    Yes
# Return value                    new list                                              None
# works on                        any sequence like (list, string, tuple)               only list
# TC                              O(n)                                                  O(n)

# Using slicing
lst = [1,2,3,4]
rev = lst[::-1]
print(lst) # [1,2,3,4]
print(rev) # [4,3,2,1]

# Using reverse()
lst = [1,2,3,4]
rev = lst.reverse()
print(lst) # [4,3,2,1]
print(rev) # None

# Strings case
s = "hello"
print(s[::-1])  # "olleh"
# works because slicing works on sequences

# But:
# s.reverse()  # wrong
# strings are immutable, so can't be reversed in place

# When to use what
# use slicing [::-1] when:
#     you want a new reversed copy
#     your original sequence should stay intact

# use .reverse() when
    # you want to modify list in-place.
    # you care about memory optimization
    
# Summary 
# [::-1] creates a new reversed copy using slicing, while list.reverse() reverses the list in-place and returns None.”



# different reversal techniques in python

# 1. slicing [::-1]
# pros: 
#     # works with all sequences like list, string, tuples 
#     # the original input stays intact
#     # most pythonic way
# cons:
#     creates a new copy
# TC: O(n)
# SC: O(n)

# 2. reversed(seq)
# returns a reverse iterator. Does not modify the original sequence
# Does not create a list immediately
nums = [1,2,3,4]
rev = reversed(nums)

print(rev)      # <list_reverseiterator object>
print(list(rev))
print(nums)     # original seq stays intact

# pros:
    # memory efficient (lazy iterator)
# cons:
    # it does not create a list immediately 
# TC: O(n)
# SC: O(n)  -- only when you create a list using the reverse iterator
    
    
# 3. .reverse() (list only)
lst.reverse()
# pros:
#     1. modifies the list in-place
#     2. memory efficient. No extra memory
# cons:
    # 1. only for lists
    # 2. returns None
    # 3. Alters input
# TC: O(n)
# SC: O(1)

# 4. Manual loop
rev = []
for i in range(len(lst) - 1, -1, -1):
    rev.append(lst[i])
    
# Pros:
    # 1. works everywhere
# cons:
    # 1. Verbose
# TC: O(n)
# SC: O(n)    

# 5. 2 pointers swap (in-place)
lo, hi = 0, len(lst)-1
while lo < hi:
    lst[lo], lst[hi] = lst[hi], lst[lo]
    lo += 1
    hi -= 1
# TC: O(n)
# SC: O(1)    

    
# what is join() ?
# join() is used to combine the elements of an iterable (like list/tuple) into a single string

# syntax:
# separator.join(iterable)

# iterable --> list, tuple etc

words = ["hello", "world"]
res = " ".join(words)
print(res)  # hello word

# different separators
# 1. space
" ".join(["a", "b", "c"])   # "a b c"

# 2. comma
",".join(["a", "b", "c"])   # "a,b,c"

# 3. empty string
"".join(["a", "b", "c"])   # "abc"

#NOTE: important rule: since join() method combines all the elements of an iterable and returns a string, all the elements of iterable should be string
nums = [1,2,3,4]
# print(" ".join(nums))       # Error 

# fix:
print(",".join(map(str, [1,2,3])))  # "1,2,3"
