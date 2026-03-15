# Functions

# default arguments
def myFun(x, y=50):
    print("x:", x)
    print("y:", y)
    
    
# keyword arguments 
def greet(name, message):
    print(f"{message}, {name}!")
    
# order of the arguments does not matter when we use keyword arguments
greet(name="Alice", message="Hello")
greet(message="Hello", name="Alice")


# positional arguments
def greet(name, age):
    print(f"Hello, {name}! You are {age} years old.")
    
greet("Bob", 30)
greet(30, "Bob")  # This will cause an error because the order of arguments is important for positional arguments


# Arbitrary arguments
# *args for variable number of positional arguments
# **kwargs for variable number of keyword arguments
def myFun(*args, **kwargs):
    print("Positional arguments:", args)
    print("Keyword arguments:", kwargs)
    
    for arg in args:
        print(arg)
        
    for key, value in kwargs.items():
        print(f"{key}: {value}")
        
myFun(1, 2, 3, name="Alice", age=30)


# Functions within functions (inner function)
def outer_function(text):
    s = "Outer function says: " + text
    def inner_function():
        print(text)
    inner_function()
    
    
# Anonymous functions (lambda)
# def is used to create normal functions, while lambda is used to create anonymous functions (functions without a name).
def square(x): return x * x
square = lambda x: x * x


# pass by reference and pass by value
def myFun(x):
    x[0] = 10  # Modifying the first element of the list

lst = [1, 2, 3]
myFun(lst)
print(lst)  # Output: [10, 2, 3] - The original list is modified because lists are mutable and passed by reference


def myFun2(x):
    x = 10  # Reassigning x to a new value
    
num = 5
myFun2(num)
print(num)  # Output: 5 - The original variable is not modified because integers are immutable and passed by value

# IMP:
# Mutable objects: lists, dictionaries, sets, etc. are mutable and passed by reference.
# Immutable objects: integers, floats, strings, tuples, etc. are immutable and passed by value


# recursion:
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
    
    
# local and global variables

# summary:
# local variables are defined inside a function and can only be accessed within that function. They are created when the function is called and destroyed when the function exits.
# global variables are defined outside of any function and can be accessed from anywhere in the code. They exist for the duration of the program.
# NOTE: the interpreter first tries to find a variable in the local scope, then in the global scope. If it doesn't find it in either, it raises a NameError.
# If you define a local and global variable with the same name, the local variable will shadow the global variable within the function. To modify a global variable inside a function, you need to use the global keyword.

# modifying global variable inside a function
# Python assumes s is local since we try to modify it. But no local s exists before that line, so an error occurs.
def fun():
    global s
    s+="GFG"        # Modify global variable    
    print(s)

s = 'I love geeks for geeks'    
fun()


a = 1  # Global variable

def f():
    print("f():", a)  # Uses global a

def g():
    a = 2  # Local shadows global
    print("g():", a)

def h():
    global a
    a = 3  # Modifies global a
    print("h():", a)

print("global:", a)
f()
print("global:", a)
g()
print("global:", a)
h()
print("global:", a)

# Output
# global: 1
# f(): 1
# global: 1
# g(): 2
# global: 1
# h(): 3
# global: 3



# why python uses self as default argument

# By default python passes self as the first agrument to every method defined in a class. 
# The self parameter represents instance of the class itself, allowing you to access and modify its attributes and methods.


class Car:
    def __init__(self, brand, model):
        self.brand = brand
        self.model = model
        
    def display(self, brand, model):
        print(f"Car: {brand} {model}")
        
car1 = Car("Toyota", "Camry")
car1.display("Honda", "Civic")  # Output: Car: Honda Civic

# self in __init__ is used to assign the values of brand and model to a specific instance of the Car class (car1 in this case).
# self in display is used to access the same instance
# python automatically passes the instance (car1) as the first argument to both __init__ and display methods, allowing us to use self to refer to that instance within the methods.


# why python passes self?
# To make program more explicit than inplicit. By pasing self, python ensures
# 1. clarity: It is clear that the method is operating on an instance of the class. Makes code easier to read
# 2. flexibility: you can use any name like this, but self is a standard.
# 3. consistency: keeps all methods uniform across classes

# Unlike some other programming languages, Python doesn’t hide this reference automatically. 
# This makes it clear and unambiguous that the method is operating on an instance of the class, 
# which improves readability and avoids confusion (especially in inheritance).

class Circle:
    def __init__(self, r):
        self.r = r
    
    def area(self):
        return 3.14 * self.r * self.r
    
c1 = Circle(5)
print(c1.area())  # Output: 78.5



# First Class Functions:

# In Python, functions are treated as first-class objects. This means they can be used just like numbers, strings, or any other variable. You can:

# 1. Assign functions to variables.
# 2. Pass them as arguments to other functions.
# 3. Return them from functions.
# 3. Store them in data structures such as lists or dictionaries.

# This ability allows you to write reusable, modular and powerful code.

# 1. Assigning Functions to Variables
def msg(name):
    return f"Hello, {name}!"

# assigning function to a variable
f = msg

# calling the function using the variable
print(f("Alice"))  # Output: Hello, Alice!

# 2. Passing Functions as Arguments
def msg(name):
    return f"Hello, {name}!"

def fun1(func, name):
    return func(name)

fun1(msg, "Bob")  # Output: Hello, Bob!

# 3. returning Functions from Other Functions
def fun1():
    def fun2():
        return "Hello from fun2!"
    return fun2

f1 = fun1()
print(f1())  # Output: Hello from fun2!

# 4. storing functions in data structures
def add(x, y):
    return x + y
def subtract(x, y):         
    return x - y

# storing functions in dictionary
d = {
    'add': add,
    'subtract': subtract
}
# Calling functions from the dictionary
print(d['add'](5, 3))  # Output: 8
print(d['subtract'](5, 3))  # Output: 2


# Python Lambda Functions

# Lambda functions are small anonymous functions, meaning they do not have a defined name.
# created using lambda keyword for short, simple operations
# 1. No name, unless you assign it to a variable
# 2. Can only contain a single expression (but you can return multiple values using tuples)
# 3. implicit return of that expression    

# Lambdas are small, short-lived functions created and used immediately.

# syntax: 
a = lambda x: x ** 2
    
# 1. Function name (a): Stores the lambda function so it can be reused later.
# 2. Lambda keyword (lambda): Defines an anonymous (inline) function in Python.
# 3. Argument (x): The input value passed to the lambda function.
# 4. Expression (x**2): The operation performed on the argument and returned as the result.

# usecases:

# conditional checking
check = lambda x: "positive" if x > 0 else "negative" if x < 0 else "zero"
# lambda functions are anonumous functions, unless assigned to a variable. So that we can use it later
print(check(5))  # Output: positive
print(check(-3)) # Output: negative
print(check(0))  # Output: zero

# 2. with list comprehension:
lst = [lambda i: i**2 for i in range(5)]
for func in lst:
    print(func())  # Output: 0, 1, 4, 9, 16
    
    
# 3. used with filter(), map(), reduce()
nums = [1, 2, 3, 4, 5]
even = filter(lambda x: x%2 == 0, nums)     # returns filter object
print(list(even))  # Output: [2, 4]

double = map(lambda x: x*2, nums)  # Output: [1, 4, 9, 16, 25]. # returns map object
print(list(double))     

from functools import reduce
from tokenize import Single
from xml.etree.ElementInclude import include
sum_of_nums =reduce(lambda x,y: x + y, nums) # reduce returns a single value
print(sum_of_nums)  # Output: 15

# def vs lambda keyword:

# Feature	            lambda Function	                    Regular Function (def)
# Definition	        Single expression with lambda.	        Multiple lines of code.
# Name	                Anonymous or named if assigned.	        Must have a name.
# Statements	        Single expression only.	                Can include multiple statements.
# Documentation	        Cannot have a docstring.	            Can include docstrings.
# Reusability	        Best for short, temporary functions.	Better for reusable and complex logic

      
# Inner Functions: https://www.geeksforgeeks.org/python/python-inner-functions/ [Revisit - pending]

# uses an inner function as a wrapper to log details before calling the actual function

import logging
logging.basicConfig(level=logging.INFO) 

def logger(func):
    def wrapper(*args, **kwargs):
        logging.info(f"Executing {func.__name__} with args: {args} and kwargs: {kwargs}")
        return func(*args, **kwargs)
    return wrapper

@logger
def add(x, y):
    return x + y

print(add(5, 3))  # Output: 8 and logs the execution details


# Decorators: https://www.geeksforgeeks.org/python/decorators-in-python/. [Revisit - pending]
# A decorator is essentially a function that takes another function as an argument and returns a new function with enhanced functionality.

def decorator(func):
    def wrapper(*args, **kwargs):
        print('before caling')
        func()
        print('after calling')
    return wrapper

@decorator
def greet():
    print("Hello, World!")
    
greet()  # Output: before calling, Hello, World!, after calling

# decorator takes the greet function as an argument.
# It returns a new function (wrapper) that first prints a message, calls greet() and then prints another message.
# @decorator syntax is a shorthand for greet = decorator(greet).