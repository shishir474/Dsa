# Python is an Object-Oriented Programming Language, everything in Python is related to objects, methods, and properties. 
# A class is a user-defined blueprint or a prototype, which we can use to create the objects of a class.

# A class defined in another class is known as an inner class or nested class.
# A parent class can have one or more inner classes but generally inner classes are avoided.

# Why inner class?
# For the grouping of two or more classes. Suppose we have two classes remote and battery. 
# Every remote needs a battery but a battery without a remote won't be used. So, we make the Battery an inner class to the Remote. It helps us to save code. 
# With the help of the inner class or nested class, we can hide the inner class from the outside world. Hence, Hiding the code is another good feature of the inner class.

# Types of inner classes are as follows: 
# a. Multiple inner class
# b. Multilevel inner class

# Example: Multiple inner class

# create outer class
class Doctors:
    def __init__(self):
        self.name = 'Doctor'
        self.den = self.Dentist()
        self.car = self.Cardiologist()

    def show(self):
        print('In outer class')
        print('Name:', self.name)

    # create a 1st Inner class
    class Dentist:
        def __init__(self):
            self.name = 'Dr. Savita'
            self.degree = 'BDS'

        def display(self):
            print("Name:", self.name)
            print("Degree:", self.degree)

    # create a 2nd Inner class
    class Cardiologist:
        def __init__(self):
            self.name = 'Dr. Amit'
            self.degree = 'DM'

        def display(self):
            print("Name:", self.name)
            print("Degree:", self.degree)


# create a object
# of outer class
outer = Doctors()
outer.show()

# create a object
# of 1st inner class
d1 = outer.den

# create a object
# of 2nd inner class
d2 = outer.car
print()
d1.display()
print()
d2.display()



# Example: Multilevel inner class

# create an outer class
class Geeksforgeeks:

    def __init__(self):
        # create an inner class object
        self.inner = self.Inner()

    def show(self):
        print('This is an outer class')

    # create a 1st inner class

    class Inner:
        def __init__(self):
            # create an inner class of inner class object
            self.innerclassofinner = self.Innerclassofinner()

        def show(self):
            print('This is the inner class')

        # create an inner class of inner

        class Innerclassofinner:
            def show(self):
                print('This is an inner class of inner class')


# create an outer class object
# i.e.Geeksforgeeks class object
outer = Geeksforgeeks()
outer.show()
print()

# create an inner class object
gfg1 = outer.inner
gfg1.show()
print()

# create an inner class of inner class object
gfg2 = outer.inner.innerclassofinner
gfg2.show()