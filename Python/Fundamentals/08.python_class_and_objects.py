# Why Python Uses 'Self' as Default Argument

# In Python, when defining methods within a class, the first parameter is always self. 
# The parameter self is a convention not a keyword 

class Car:
    def __init__(self, brand, model):
        self.brand = brand  # Set instance attribute
        self.model = model  # Set instance attribute

    def display(self):
        return self.brand, self.model

# Create an instance of Car
car1 = Car("Toyota", "Corolla")

# Call the display_info method
print(car1.display())  # Output: This car is a Toyota Corolla

# Explanation: In this example, 'self' is used to refer to the instance of the class, 'car1.' 
# Without the explicit use of 'self,' it would be unclear which instance the method is referring to and the code might become ambiguous.


# self in __init__: Used to assign values (brand and model) to the specific instance (car1).
# self in display_info: Refers to the same car1 instance to access its attributes (brand and model).


# Magic Methods or Dunder Methods

# Python provides several special methods, known as magic methods or dunder methods (dunder means double underscores).
# These methods start and end with double underscores (e.g., __init__, __add__, __len__, __repr__, etc.). 
# One such powerful magic method is __new__, which plays an important role in instance creation.

# __new__ vs __init__

# Whenever a class is instantiated, two methods are called:
# __new__ : Responsible for creating a new instance of the class.
# __init__ : Initializes the instance.

class A:
    def __new__(cls):
        print("Creating Instance")
        return super(A,cls).__new__(cls)
    
    def __init__(self):
        print("Initialising Instance")

# __new__ method is called first to create an instance of the class A. and then __init__ method to initialise the instance
# Return Value: Must return an instance of the class (cls) or another class.
# If __new__ returns an object of another type, __init__ will not be called.
# Return Value of __init__ --> None (__init__ method does not return anything)

# __new__ method is responsible for creating a new instance of a class. It allocates memory and returns the new object. It is called before __init__
# __init__ method initialises the newly created instance and is uses as a constructor. Constructors are a special method that are automatically called when an object is created from a class. It's main role is to initialse the object by setting up it's attributes
# __init__ method is called immediately after the object is created by __new__method and is responsible for initialising attrbutes of the instance
# __new__ method is rarely overriden but useful for customizing object creation and especially in singleton patterns


# Syntax:

# class ClassName:

#     def __new__(cls, *args, **kwargs):
#         # Custom instance creation logic
#         instance = super(ClassName, cls).__new__(cls, *args, **kwargs)
#         return instance

# Parameters:
# cls : The class itself.
# *args : Positional arguments passed to __new__ .
# **kwargs : Keyword arguments passed to __new__ .


# __str__ method determines what gets displayed when you print an object of the class. 
# __str__ makes your object printable in a human readable way
class Person:
    def __init__(self, name, age):
        # this is where your instance is initialised
        self.name = name
        self.age = age
        
    def __str__(self):
        return f"Name: {self.name}, Age: {self.age}"

p1 = Person("Shishir", 23)
print(p1)         # Output: Name: Shishir, Age: 23
# 🔹 Without __str__, you'd get something like: # <__main__.Person object at 0x...>  # Not helpful!

# Example 1: What happens if __new__ does not return an instance?
class A:
    def __new__(cls):
        print("Creating instance")

    def __init__(self):
        print("Initializing instance")

print(A())      
# Output: 
# Creating instance
# None

# since __new__ method does not return an instance of the class, __init__ method will not be called


# Example 2
class A:
    def __new__(cls):
        print("Creating instance")
        return "Hello, World!"

print(A())

# __new__ method should return an instance of class A, but here it returns the string "Hello, World!". So python does not create an instance of A, and thus __init__ method is never called


# Example 3: Returning an instances of another class
class GeeksforGeeks:
    def __str__(self):
        return "GeeksforGeeks Instance"
​
class Geek:
    def __new__(cls):
        return GeeksforGeeks()
    
    def __init__(self):
        print("Inside init")
​
print(Geek())
# __new__ method returns an instance of another class, and thus __init__ method is never called.
# When print(Geek()) is executed, it prints "GeeksforGeeks Instance" from the __str__ method of GeeksforGeeks.


# Types of Constructors

# Default Constructor
# A default constructor does not take any parameters other than self. It initializes the object with default attribute values.
class Car:
    def __init__(self):
        #Initialize the Car with default attributes
        self.make = "Toyota"
        self.model = "Corolla"
        self.year = 2020

# Creating an instance using the default constructor
car = Car()


# 2. Parameterized Constructor
# A parameterized constructor accepts arguments to initialize the object's attributes with specific values.
class Car:
    def __init__(self, make, model, year):
      
        #Initialize the Car with specific attributes.
        self.make = make
        self.model = model
        self.year = year
​
# Creating an instance using the parameterized constructor
car = Car("Honda", "Civic", 2022)





# Dynamic Attributes in python