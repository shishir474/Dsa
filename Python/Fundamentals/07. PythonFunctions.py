# Python Function Arguments
# Default argument
# Keyword arguments (named arguments)
# Positional arguments
# Arbitrary arguments (variable-length arguments *args and **kwargs)

# Default Argument
# A default argument is a parameter that assumes a default value if a value is not provided in the function call for that argument. 
def myFun(x, y=50):
    print("x: ", x)
    print("y: ", y)
    
myFun(10)
# NOTE: Like C++ default arguments, any number of arguments in a function can have a default value. But once we have a default argument, all the arguments to its right must also have default values.


# Keyword Arguments
# The idea is to allow the caller to specify the argument name with values so that the caller does not need to remember the order of parameters.
def student(fname, lname):
    print(fname, lname)

student(fname="Shishir", lname="Singh")
student(lname="Singh", fname="Shishir")     # still works - order of arguments doesn't matter since we are using keyword arguments

# args and kwargs allows you to pass variable(any number) of arguments to a function
def myFun(*args):
    for arg in args:
        print(arg, end=" ")
    print()

myFun("Hello")
myFun("Hello", "Welcome")
myFun("Hello", "Welcome", "To")


# Passing variable no of keyword arguments 
def myFun2(**kwargs):
    for key,val in kwargs.items():
        print(key, val, end=" ")
    print()
    
myFun2(first="Geeks")
myFun2(first="Geeks", second="for")
myFun2(first="Geeks", second="for", third="Geeks")


# Nested Functions
# In python a function defined inside another function is known as inner or nested function.
# Nested functions can access variables of the enclosing scope

def f1():
    s = "You are the best"      # s is accessible throughout f1(), inside f2() also 
    def f2():                   # but variables defined inside f2() can't be accessed outside f2()
        print(s)        
    f2()
        
f1()


name = "Aarav"
def mydemo():
    name = "Shishir"    # both name's are different
    print(name)

mydemo()
print(name)


name = "Aarav"
def mydemo1():
    global name
    name = "Shishir"    # here we are referencing the global name 
    print(name)

mydemo1()
print(name)


# Pass by Reference and Pass by Value

def myFunc(x):
    x[0] = 20
    
lst = [10, 11, 12, 13, 14, 15]
myFunc(lst)
print(lst)


def myFun(x):
    x = [20, 30, 40]        # reference is broken

lst = [10, 11, 12, 13, 14, 15]
myFun(lst)  
print(lst)          # lst remains unaffected


def myFun(x):
    x = 20             # reference is broken

x = 10
myFun(x)             # x remains unaffected
print(x)


def swap(x, y):
    temp = x
    x = y               # reference is broken
    y = temp            # reference is broken

x = 2
y = 3
swap(x, y)      
print(x)                # x,y remains unaffected
print(y)


# Decorators in python
# In Python, decorators are a powerful and flexible way to modify or extend the behavior of 
# functions or methods, without changing their actual code. 
# A decorator is essentially a function that takes another function as an argument and returns 
# a new function with enhanced functionality.

def decorator(func):        # decorator function
    def wrapper():          # wrapper(*args, **kwargs) nested function inside decorator. It wraps the original function, adding additional functionality
        print("Before calling the function")        
        func()
        print("After calling the function")
    return wrapper

@decorator          # function being decorated
def greet():        
    print("Hello World!")

greet()
# decorator takes the greet function as an argument.
# It returns a new function (wrapper) that first prints a message, calls greet() and then prints another message.
# The @decorator syntax is a shorthand for greet = decorator(greet).


# Higher Order Functions

# In Python, higher-order functions are functions that take one or more functions as arguments, 
# return a function as a result or do both.

# Key Properties of Higher-Order Functions:
# Taking functions as arguments: A higher-order function can accept other functions as parameters.
# Returning functions: A higher-order function can return a new function that can be called later.

# a higher order function that takes another function as an argument
def func(f, x):
    return f(x)

def square(x):
    return x*x

print(func(square, 5))

# NOTE: Decorators in Python are a type of higher-order function because they take a function as input, modify it, and return a new function that extends or changes its behavior.


# Functions as First-Class Objects
# In Python, functions are first-class objects, meaning that they can be treated like any other object, 
# such as integers, strings, or lists. This gives functions a unique level of flexibility and allows them to be passed around 
# and manipulated in ways that are not possible in many other programming languages.

# What Does It Mean for Functions to Be First-Class Objects?
# Can be assigned to variables: Functions can be assigned to variables and used just like any other value.
# Can be passed as arguments: Functions can be passed as arguments to other functions.
# Can be returned from other functions: Functions can return other functions, which is a key concept in decorators.
# Can be stored in data structures: Functions can be stored in lists, dictionaries, or other data structures.

# assigning a function to a variable
def greet(name):
    print(f"Hello {name}!")

say_hi = greet      # assigning greet function to say_hi variable
say_hi("Shishir")

# passing function as an argument
def apply(func, x):
    func(x)
apply(greet, "Shishir")

# returning a function from another function
def make_x(f):
    def mult(x):
        return f * x
    return mult
dbl = make_x(3)
print(dbl(5))


# Built in python decorators

# @classmethod, @staticmethod, @property

# both @classmethod and @staticmethod are decorators used to define methods that aren't instance methods. These methods belongs to class
# @classmethod
    # received the class (cls) as the first argument
    # can access and modify class level attributes
    # useful when you need a method that's related to the class, but not tied to any specific object

class Employee:
    count = 0
    
    def __init__(self):
        Employee.count+=1       # access class variable using className.variable
    
    @classmethod
    def total_employees(cls):
        return cls.count
        
print(Employee.total_employees()) # Output: 0
e1 = Employee()
print(Employee.total_employees()) # Output: 1
    

# @staticmethod
# Does not receive self or cls as the first argument.
# Behaves like a regular function that happens to live inside a class.
# Use when the method doesn't need access to class or instance attributes.

class Math:
    @staticmethod
    def add(a,b):
        return a+b

print(Math.add(2,3))

# Think of it this way:
# @staticmethod: just a utility function sitting in the class. Use it for general purpose
# @classmethod: a class-aware method (e.g., factory pattern). Use it when you want to deal with class attributes


# property decorator
# It allows you to access a method like an attribute, without using parentheses.

class Circle:
    def __init__(self, radius):
        self._radius = radius   # convention: _radius is "private"
    
    @property
    def radius(self):
        return self._radius
    
    @radius.setter
    def radius(self, value):
        if(value < 0):
            raise ValueError("Radius cannot be negative!")
        else:
            self._radius = value
        
    @property
    def area(self):
        return 3.14 * self._radius ** 2
    
        
# Now you can access area like an attribute
c = Circle(3)
print(c.radius)     # Output: 3
print(c.area)        # Output: 78.5 ✅ (no parentheses!)

        
# Adding a Setter
# Use @<property_name>.setter to define how to update it:

# Traditional getters and setters
class Person:
    def __init__(self, name):
        self._name = name
    
    def getName(self):
        return self._name

    def setName(self, new_name):
        if new_name.strip():
            self._name = new_name
        else:
            raise ValueError("Name can't be empty!")
    
p1 = Person("Shishir")
print(p1.getName())             # Ugly ❌
p1.setName("Raj")
# p1.setName("")                # raises ValueError


# With @property
class Person:
    def __init__(self, name):
        self._name=  name
    
    @property
    def name(self):
        return self._name
    
    @name.setter
    def name(self, new_name):
        if new_name.strip():
            self._name = new_name
        else:
            raise ValueError("Name can't be empty")


p1 = Person("Shishir")
print(p1.name)          # you dont need to use parenthesis, since name is now an attribute
p1.name = "Bob"         # looks like direct access but it's validated!
print(p1.name)


# Real world application: BMI calculator
class Person:
    def __init__(self, weight, height):
        self.weight = weight  # in kg
        self.height = height  # in meters

    @property
    def bmi(self):
        return self.weight / (self.height ** 2)

p = Person(70, 1.75)
print(p.bmi)  # Output: 22.86 (calculated on the fly)



# Chaining Decorators
# means decorating a function with multiple decorators.
def decor(func):
    def inner():
        x = func()
        return x * x
    return inner

def decor1(func):
    def inner():
        x = func()
        return 2 * x
    return inner

@decor1
@decor
def num():
    return 10

print(num())  # returns 200 is equivalent to num = decor1(decor(num))




# Types of Decorators

# Function Decorators / simple_decorators

def simple_decorator(func):
    def wrapper():
        print("Before calling the function.")
        func()
        print("After calling the function.")
    return wrapper

@simple_decorator
def greet():
    print("Hello, World!")

greet()

# simple_decorator(func): takes the function as an argument(func) and returns a new function wrapper that adds some funcitonality before and after calling the original function


#  Method Decorators:

# Used to decorate methods within a class. They often handle special cases, such as the self argument for instance methods.

def method_decorator(func):
    def wrapper(self, *args, **kwargs):
        print("Before method execution")
        res = func(self, *args, **kwargs)
        print("After method execution")
        return res
    return wrapper

class MyClass:
    @method_decorator
    def say_hello(self):
        print("Hello!")

obj = MyClass()
obj.say_hello()

# method_decorator(func): tkaes the method (say_hello) as an argument (func). It returns a wrapper function 
# The wrapper must accept self because it is a method of an instance. self is the instance of the class and *args and **kwargs allow for other arguments to be passed if needed


# Class Decorators

# Class decorators are used to modify or enhance the behavior of a class. 
# Like function decorators, class decorators are applied to the class definition. 
# They work by taking the class as an argument and returning a modified version of the class.

def add_class_name(cls):       
    cls.class_name = cls.__name__
    return cls

@add_class_name                        # class decorator
class Person:
    pass

print(Person.class_name)

# add_class_name(cls): decorator adds a new attribute, class_name to class cls. The value of class_name is set to name of the class(cls.__name__)
# Result: when the class is defined, the decorator automatically adds the class_name attribute to it


# Lambda Functions;
# It's a small, anonymous function with a single expression, defined using word lambda. It's often used in 
# higher order functions for quick one-time operations

def fun(func, num):
    return func(num)
print(fun(lambda x: x**2, 5))

# Built in functions using function argument
# ex1: map()
list1 = [1,2,3,4]
res = list(map(lambda x: x*2, list1))      # filters map object, converted to list
print(res)

# ex2: filter()
res = list(filter(lambda x: x % 2 == 0, list1)) # returns filter object, converted to list
print(res)

# ex3: reduce
from functools import reduce
res = reduce(lambda x,y: x + y, list1)      # returns reduced value(int)
print(res)