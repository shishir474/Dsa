# Encapsulation and Access Modifiers

# 1. encapsulation refers to the bundling of data (attributes) and methods (functions) that operate on the data into a single unit, typically a class. 
# 2. It also restricts direct access to some components, which helps protect the integrity of the data and ensures proper usage.
# 3. It is the process of hiding the internal state of an object and requiring all interactions to be performed through an object's methods. 
# This approach:
# Provides better control over data.
# Prevents accidental modification of data.
# Promotes modular programming.

# Python achieves encapsulation through public, protected and private attributes.

# How Encapsulation Works :
# Data Hiding: The variables (attributes) are kept private or protected, meaning they are not accessible directly from outside the class. Instead, they can only be accessed or modified through the methods.
# Access through Methods: Methods act as the interface through which external code interacts with the data stored in the variables. For instance, getters and setters are common methods used to retrieve and update the value of a private variable.
# Control and Security: By encapsulating the variables and only allowing their manipulation via methods, the class can enforce rules on how the variables are accessed or modified, thus maintaining control and security over the data.

# Example:
# Encapsulation is like having a bank account system where your account balance (data) is kept private. You can't directly change your balance by accessing the account database. Instead, the bank provides you with methods (functions) like deposit and withdraw to modify your balance safely.
# Private Data (Balance): Your balance is stored securely. Direct access from outside is not allowed, ensuring the data is protected from unauthorized changes.
# Public Methods (Deposit and Withdraw): These are the only ways to modify your balance. They check if your requests (like withdrawing money) follow the rules (e.g., you have enough balance) before allowing changes.


# Access Modifiers in Python

# Encapsulation is one of the four principles used in Object Oriented Paradigm. It is used to bind and hide data to the class. 
# Data hiding is also referred as Scoping and the accessibility of a method or a field of a class can be changed by the developer. 
# The implementation of scoping is different for different programming language. 
# For example, statically typed, compiled language has direct support to scoping with the help of keywords which are mentioned when the method or field is declared. 
# However Python does not have such keywords since it is a scripting language, and it is interpreted instead of being compiled. 
# Mainly, Access Modifiers can be categorized as Public, Protected and Private in a class.

# Python uses the '_' symbol to determine the access control for a specific data member or a member function of a class. 
# Access specifiers in Python have an important role to play in securing data from unauthorized access and in preventing it from being exploited. 
# But it is not like other languages like Java and C++ since Python uses the concept of Name Mangling for achieving data hiding.

# A Class in Python has three types of access modifiers:

# Public Access Modifier: Theoretically, public methods and fields can be accessed directly by any class.
# Protected Access Modifier: Theoretically, protected methods and fields can be accessed within the same class it is declared and its subclass.
# Private Access Modifier: Theoretically, private methods and fields can be only accessed within the same class it is declared.

# We are mentioning "Theoretically" because python doesn't follow the textbook definition of such specifications. Instead, it depends on the programmer/organization as well as a unique feature of python called as name mangling using which we can mimic the actual security provided by access modifiers.


# Public Members
# Public members are accessible from anywhere, both inside and outside the class. These are the default members in Python. The attributes are declared without any underscore prefixes. 

# program to illustrate public access modifier in a class
class Geek:

    # constructor
    def __init__(self, name, age):

        # public data members
        self.geekName = name
        self.geekAge = age

    # public member function
    def displayAge(self):

        # accessing public data member
        print("Age: ", self.geekAge)


# creating object of the class
obj = Geek("R2J", 20)

# finding all the fields and methods which are present inside obj
print("List of fields and methods inside obj:", dir(obj))

# accessing public data member
print("Name:", obj.geekName)

# calling public member function of the class
obj.displayAge()

# We are using dir() function to list down all the member variables and functions of the Geeks object which can be accessed. We can clearly see geekName, geekAge, displayAge and other inbuilt methods such as __str__, __sizeof__, etc. 
# Output
# List of fields and methods inside obj: ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', 
# '__ge__', '__getattribute__', '__getstate__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', 
# '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', 
# '__str__', '__subclasshook__', '__weakref__', 'displayAge', 'geekAge', 'geekName']
# Name: R2J
# Age:  20




# Protected members
# Protected members are identified with a single underscore (_). They are meant to be accessed only within the class or its subclasses.
# Protected Attribute (_age) attribute is prefixed with a single underscore, which by convention, suggests that it should be treated as a protected member. It's not enforced by Python but indicates that it should not be accessed outside of this class and its subclasses.

# program to illustrate protected access modifier in a class

# super class
class Student:

    # protected data members
    _name = None
    _roll = None
    _branch = None

    # constructor
    def __init__(self, name, roll, branch):
        self._name = name
        self._roll = roll
        self._branch = branch

    # protected member function
    def _displayRollAndBranch(self):

        # accessing protected data members
        print("Roll:", self._roll)
        print("Branch:", self._branch)

# derived class
class Geek(Student):

    # constructor
    def __init__(self, name, roll, branch):
        Student.__init__(self, name, roll, branch)

    # public member function
    def displayDetails(self):

              # accessing protected data members of super class
        print("Name:", self._name)

        # accessing protected member functions of super class
        self._displayRollAndBranch()


stu = Student("Alpha", 1234567, "Computer Science")
print(dir(stu))

# protected members and methods can be still accessed
print(stu._name)
stu._displayRollAndBranch()

# Throws error
# print(stu.name)
# stu.displayRollAndBranch()

# creating objects of the derived class
obj = Geek("R2J", 1706256, "Information Technology")
print("")
print(dir(obj))

# calling public member functions of the class
obj.displayDetails()

# NOTE: we can still access protected members of Student class directly by specifying the correct name of field and method i.e. adding underscore before them since it was declared by that name. 


# Private members
# Private members are identified with a double underscore (__) and cannot be accessed directly from outside the class. Python uses name mangling to make private members inaccessible by renaming them internally.
# Private Attribute (__salary): This attribute is prefixed with two underscores, which makes it a private member. Python enforces privacy by name mangling, which means it renames the attribute in a way that makes it hard to access from outside the class.
# Method (salary): This public method provides the only way to access the private attribute from outside the class.
# Direct Access Attempt: Trying to access the private attribute directly (obj.__salary) will result in an AttributeError, showing that direct access is blocked. This is Python's way of enforcing encapsulation at a language level.

# program to illustrate private access modifier in a class

class Geek:

    # private members
    __name = None
    __roll = None
    __branch = None

    # constructor
    def __init__(self, name, roll, branch):
        self.__name = name
        self.__roll = roll
        self.__branch = branch

    # private member function
    def __displayDetails(self):

        # accessing private data members
        print("Name:", self.__name)
        print("Roll:", self.__roll)
        print("Branch:", self.__branch)

    # public member function
    def accessPrivateFunction(self):

        # accessing private member function
        self.__displayDetails()

# creating object
obj = Geek("R2J", 1706256, "Information Technology")
print(dir(obj))

# Throws error - you cannot access private members like this
# obj.__name
# obj.__roll
# obj.__branch
# obj.__displayDetails()

# To access private members of a class: Hack to access private members obj._ClassName__attributeName
print(obj._Geek__name)
print(obj._Geek__roll)
print(obj._Geek__branch)
obj._Geek__displayDetails()

# In this program, __name, __roll, and __branch are private members, __displayDetails() method is a private member function
# However, we can still access private members of a class outside the class. We cannot directly call obj.__name bcoz they throw errors.
# In the list of callable fields (dir(obj)), we can see that __name is saved as _Geek__name, __age is saved as _Geek__age, __displayDetails is saved as _Geek____displayDetails
# This conversion is called name mangling where the python interprater automatically converts any member preceded with __(2 underscores) to _<ClassName>__<memberName>
# Hence we can still call all the supposedly private data members of a class using the above convention

# NOTE: THis means all these access modifiers are not strict like other languages such as C++/Java/C#, since they can still be accessed if they are called by their mangled/original names

# 2 leading underscores indicates private variable, 2 leading and 2 trailing underscores indicates magic methods like __init__, __str__


# Private Methods in python
# Encapsulation is one of the fundamental concepts in object-oriented programming (OOP) in Python.
# It describes the idea of wrapping data and the methods that work on data within one unit. This puts restrictions on accessing variables and methods directly and can prevent the accidental modification of data.
# A class is an example of encapsulation as it encapsulates all the data that is member functions, variables, etc. 
# Now, there can be some scenarios in which we need to put restrictions on some methods of the class so that they can neither be accessed outside the class nor by any subclasses. To implement this private methods come into play.

# There are 2 ways you can access private methods
# 1. using a public method which serves as a interface and internally call the private method
# 2. Using name mangling. _<className>__<methodname>

class A:
    
    # Declaring a public method
    def fun(self):
        print("public method")

    # Declaring a private method
    def __fun(self):
        print("private method")
    
    # calling private method via another method
    def funUtil(self):
        self.fun();
        self.__fun()
    
obj = A()
obj.funUtil()


# Using Name Mangling
class A:
    
    # Declaring a public method
    def fun(self):
        print("public method")

    # Declaring a private method
    def __fun(self):
        print("private method")
    
obj = A()

# calling the private method 
# through name mangling
obj._A__fun()
        
    
    


# Below example demonstrates encapsulation by using double underscore(__) to make the balance attribute private
# The class provides methods to deposit, withdraw and view the balance securely.
class Bank:
    def __init__(self, name, bal = 0):
        self.name = name
        self.__balance = bal      # private variable defined using __(double underscore) default initialised to 0
    
    def deposit(self, amt):
        if amt > 0: self.__balance += amt
    
    def withdraw(self, amt):
        if amt > 0 and amt < self.__balance: 
            self.__balance -= amt

    def get_bal(self):
        return self.__balance
    
acc = Bank("Alice", 400)
acc.deposit(300)
acc.withdraw(150)
print(acc.get_bal())
# print(acc.__balance)      __balance attribute is private, it cannot be accessed directly from outside the class