# Inheritance
# Inheritance is a fundamental concept in object-oriented programming (OOP) that allows a class (called a child or derived class) to inherit attributes and methods from another class (called a parent or base class). 
# This promotes code reuse, modularity, and a hierarchical class structure.

# a parent class (also known as a base class) defines common attributes and methods that can be inherited by other classes. 
# These attributes and methods serve as the foundation for the child classes. By using inheritance, child classes can access and extend the functionality provided by the parent class.
# A child class (also known as a subclass) is a class that inherits properties and methods from its parent class. The child class can also introduce additional attributes and methods, or even override the ones inherited from the parent.

# a subclass is a class that inherits attributes and methods from another class, known as the superclass or parent class. 
# When you create a subclass, it can reuse and extend the functionality of the superclass.
# This allows you to create specialized versions of existing classes without having to rewrite common functionality. 



# Method overriding 

# Method overriding is an ability of any object-oriented programming language that allows a subclass or child class to provide a specific implementation of a method that is already provided by one of its super-classes or parent classes.
# When a method in a subclass has the same name, the same parameters or signature, and same return type(or sub-type) as a method in its super-class, then the method in the subclass is said to override the method in the super-class.

# The version of a method that is executed will be determined by the object that is used to invoke it. If an object of a parent class is used to invoke the method, then the version in the parent class will be executed, 
# but if an object of the subclass is used to invoke the method, then the version in the child class will be executed. In other words, it is the type of the object being referred to (not the type of the reference variable) that determines which version of an overridden method will be executed.

class Parent:
    def __init__(self):
        self.value = "Inside parent"
    
    def show(self):
        print(self.value)
        
class Child(Parent):
    def __init__(self):
        super().__init__()      # call parent constructor
        self.value = "Inside child"
    
    def show(self):
        print(self.value)
        
obj1 = Parent()
obj2 = Child()

obj1.show()     # Should print "Inside Parent"
obj2.show()     # Should print "Inside Child"


# Program demonstrating calling
# parent's class method
# inside the overriden method

# Using Classname: parent's class methods can be called using Parent classname.method(self) 
# Note: need to pass self as parameter to pass object reference when using classname to invoke parent's class method
class Parent:
    def show(self):
        print("inside parent")
        
class Child(Parent):
    
    def show(self):        
    
        # calling the parent's class
        # show method
        Parent.show(self)
        print("Inside child")
        
    
obj = Child()    
obj.show()

# using super(): here we dont need to use self while calling
class Parent:
    def show(self):
        print("inside parent")
        
class Child(Parent):
    
    def show(self):        
    
        # calling the parent's class
        # show method
        super().show()
        print("Inside child")
        
obj1 = Child()    
obj1.show()







# Example 1:
# Animal is the base class with the __init__ method to initialise the name attribute and a sound method.
# Dog is a subclass inherited from Animal. It overrides the sound method to provide a specific implementation for Dogs
class Animal:
    def __init__(self, name):
        self.name = name
        
    def sound(self):
        raise NotImplementedError("Subclasses must implement this method")

class Dog(Animal):
    # overrides the parent class method
    def sound(self):
        # Dog specific sound
        return "Woof"
    
a = Animal("Generic Animal")
print(a.name)
# print(a.sound())  Subclasses need to implement this method

d = Dog("Tommy")
print(d.name)
print(d.sound())
    

# Example2:
class Shape:
    # color is a generic property of any shape
    def __init__(self, color):
        self.color = color
        
    # area's implementation will be subclass's specific. Each subclass must provide its own implementation
    def area(self): 
        raise NotImplementedError("Subclasses must implement this method")
        

# Cirle class inherits Shape-- will have color and radius
class Circle(Shape):    
    def __init__(self, color, radius):
        super().__init__(color)
        self.radius = radius
    
    def area(self):
        # Circle specific area calculation
        return 3.14 * self.radius ** 2
    
    
c = Circle("Red", 3)
print(c.area()) # This will give you an error until unless you have provided circle's area implementation


# ------------------------------------------------------------------------------------------------------------------------------------------------------


# Class and Instance Attributes

# Class attributes belong to the class itself and they will be shared by all the instances.
# Whereas instance attributes are not shared by objects. Every object has its own copy of the instance attribute

# vars() and dir() functions to list the instance and class attributes

# vars() -> displays the instance user defined attributes in the form of a dictionary
# dir() -> returns a list of all attributes and methods available including both - user defined attributes and built-in ones(inherited from the class and base classes like object)

# Example
class emp:
    def __init__(self):
        self.name = 'xyz'
        self.salary = 4000

    def show(self):
        print(self.name)
        print(self.salary)

e1 = emp()
print("Dictionary form :", vars(e1))
print(dir(e1))

# Output :

# Dictionary form :{'salary': 4000, 'name': 'xyz'}
# ['__doc__', '__init__', '__module__', 'name', 'salary', 'show']


# ------------------------------------------------------------------------------------------------------------------------------------------------------

# self in python class

# self refers to current object instance. Wheneveer we create an object from a class, self represents the current object instance.
# It is essential for accessing  attributes and methods within the class. and is used as the first parameter to refer to the current object. 
# It allows methods within the class to access and modify the object's attributes, making each object independent of others.

# When we call a method on an object, self automatically gets passed, referring to the specific instance of the class the method is acting upon.
# Without self, python wouldn't know which instance's attributes or methods to refer to 

# __init__ method is called when a new instance of the class is created. 
# This method serves as the constructor for the class and initializes the object's attributes.
# The first argument of the __init__ method must always be self, as it allows the method to set instance attributes for the object being created.


# ------------------------------------------------------------------------------------------------------------------------------------------------------

class Animal:
    def __init__(self, species):
        self.species = species      # base class attribute
    
class Dog(Animal):      # Dog class inherits the Animal Class
    def __init__(self, name, age):  
        super().__init__("Dog")     # super() calls the parent class constructor
        self.name = name
        self.age = age
    
dog = Dog("Buddy", 3);          # Dog instance

print(f"{dog.name} is a {dog.species} of {dog.age} years")


# Example 2:

# Even though the VegType class does not have its own constructor(__init__), it's still able to initialse ftype from its parent classs FoodType
class FoodType:
    def __init__(self, ftype):
        self.ftype = ftype
    
    def getFType(self):
        return self.ftype
    
class VegType(FoodType):
    def vegFoods():
        return {'Spinach', 'Bitter Gourd'}
    
vType = VegType(ftype="Vegetarian")
print(vType.getFType())
print(vType.vegFoods())


# What's happening
# class VegType(FoodType):
#     pass    # No __init__ defined here

# When you do this, python automatically uses the constructor(__init__) of the parent class (FoodType) if the child class (VegType) does not define its own.OverflowError
# so when you write:
# vType = VegType(ftype="Vegetarian")
# python looks for VegType.__init__, doesn't find it - so it moves up to the parent class and uses 
# FoodType.__init__(self,ftype)
# and that's why self.ftype is successfully initialised


# How Python Resolves This?
# Python follows the Method Resolution Order (MRO):
# Looks in the class itself
# Then in the parent class(es), left to right
# So, VegType.__init__ → not found → use FoodType.__init__


# What If You Override __init__ in VegType?
# If you define a constructor in VegType, you'll have to explicitly call the parent constructor if you want to keep initializing ftype:
# class VegType(FoodType):
#     def __init__(self, ftype, region):
#         super().__init__(ftype)  # Call parent constructor
#         self.region = region
# Without super().__init__(ftype), ftype would not be initialized.


# What if I don’t define a constructor (__init__) in the parent class either?
# In that case, Python will fall back to the default constructor provided by the base object class.
# class FoodType:  # No __init__ defined
#     pass

# class VegType(FoodType):  # No __init__ here either
#     pass

# v = VegType()  # ✅ This works!
# This runs just fine, because Python provides a default no-argument constructor.


# 🚫 But what if you try to pass arguments?
# v = VegType('Vegetarian')  # ❌ TypeError!
# ❌ Output:
# TypeError: VegType() takes no arguments

# Why?
# Because neither VegType nor FoodType defines an __init__ method.
# So Python uses the default object.__init__, which accepts only self (i.e., no additional arguments).


# ✅ Summary

# Situation	                        What Happens?
# No __init__ in parent or child	    Python uses default constructor (object.__init__)
# You call class with arguments	        ❌ Fails unless an __init__ accepts them
# You define __init__ in parent	        ✅ Child can use it unless overridden
# You define __init__ in child only	    You must handle all init logic yourself

# 🧠 Key Rule:
# If you want to pass arguments during object creation, you must define an __init__() method (in the class or in one of its parents) that accepts those arguments.



