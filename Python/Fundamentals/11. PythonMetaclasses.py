# https://www.geeksforgeeks.org/python/python-metaclasses/

# TODO: come back to this later

# In Python, type is both:
# A function that returns the type of an object.
# A metaclass (a class that creates classes).

# Case 2: type() as a Class Constructor (Advanced)
# You can dynamically create a class using the type() function like this:
MyClass = type('MyClass', (object,), {'x': 5, 'show': lambda self: print(self.x)})
obj = MyClass()
obj.show()  # Output: 5

# Breakdown:
# type('ClassName', (BaseClasses,), dict_of_attributes_and_methods)
# 'MyClass' → Name of the new class
# (object,) → Tuple of base classes (like inheritance)
# {...} → Class attributes and methods


# 🧠 type and Metaclasses
# When you define a class like this:
class Foo:
    pass
# Python actually does something like:
Foo = type('Foo', (object,), {})

# In short:
# All classes in Python are created using type — either explicitly or behind the scenes.

# ✅ This dynamic class creation is useful when:
# You're building classes at runtime (e.g., from config or database)
# You need to generate many similar classes programmatically