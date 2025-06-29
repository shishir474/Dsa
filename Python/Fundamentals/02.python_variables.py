# # Assigning values to variables
# # Dynmamic Typing: Python variables are dynamically typed, meaning the same variable can hold different types of values during execution.
# x = 5
# x = "Shishir"
# print(x)

# # Multiple assignments
# a = b = c = 100
# print(a,b,c)

# # assigning different values
# a,b,c = "Shishir", 24, 85
# print(a,b,c)

# # Typecasting
# # int(), str(), float()
# s = "10"
# n = int(s)
# cnt = 5
# f = float(cnt)
# age = 25
# s = str(age)

# print(n,f,s)

# # Getting type of variable
# n = 42
# f = 3.14
# s = "Hello, World!"
# li = [1, 2, 3]
# d = {'key': 'value'}
# bool = True

# print(type(n))   
# print(type(f)) 
# print(type(s))   
# print(type(li))     
# print(type(d))     
# print(type(bool))

# # Output
# # <class 'int'>
# # <class 'float'>
# # <class 'str'>
# # <class 'list'>
# # <class 'dict'>
# # <class 'bool'>

# Scope of variable

# Variables defined inside a function are local to that function.
def my_function():
    x = 5   # local scope
    print(x)
    
my_function()   # output: 5
# print(x)      #Error: NameError: name 'x' is not defined


# Global Variable
# Variables defined outside any function are global and can be accessed inside functions using the global keyword.
a = 10
def modify():
    a = 5       # this a is different than the global a
    print('Inside modify function ', a)
modify()
print('In global scope', a)

a = 10
def modify_new():
    # if you want to access global variable inside this function: use global keyword
    global a
    a = 5      # here you are referencing the global a 
    print('Inside modify_new function ', a)
modify_new()
print('In global scope', a)



# Object reference

x = 5
y = x       #
print(f"x: {x}, y: {y}")        # x: 5, y: 5
x = 'geeks'
print(f"x: {x}, y: {y}")        # x: geeks, y: 5
# changing x does not impact y. This is the concept of shared reference

y = 'computer'
print(f"x: {x}, y: {y}")
# Original object 5 has no longer has any references and becomes eligible for garbage collection


# Delete a variable

x = 10
print(x)

# removes the variable from the namespace. This effectively deletes the variable and frees up the memory it was using
del x

# trying to print or access x after deletion will raise an error
# print(x)      # Uncommenting this line will raise NameError: name 'x' is not defined



# Swapping 2 variables
a,b = 5,10
a,b = b,a
print(a,b)

# Counting characters in a string : len()
s = "Shishir"
print("length of the word:", len(s))