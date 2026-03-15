# in python strings are immutable meaning they cannot be modified after they are created.

# string slicing:
s = "Hello World"
print(s[0:5]) # Hello
print(s[6:]) # World
print(s[:5]) # Hello
print(s[-5:]) # World
print(s[::-1]) # dlroW olleH

# String immutability
s = "Hello"
# s[0] = 'h' # This will raise an error because strings are immutable

# deleting a string --> use del keyword
s = "Hello"
del s

# common string methods
s = " Hello World "
print(len(s))
print(s.lower())
print(s.upper())
print(s.split()) # ['Hello', 'World']
print(s.strip()) # Hello World
print(s.replace("World", "Python")) # Hello Python
print(s.find("World")) # 6
print(s.find("Python")) # -1 (not found)
print(s.count("o")) # 2    
print(s.isdigit()) # False

# concatenating and repeating strings
s1 = "Hello"
s2 = "World"
print(s1 + " " + s2) # Hello World
print(s1 * 3) # HelloHelloHello


# converting int to string
n = 42
s = str(n) # '42'
n = int(s)

# handling invalid input string: use try-except block
try:
    n = int("abc") # This will raise a ValueError
except ValueError:
    print("Invalid input string for conversion to int.")