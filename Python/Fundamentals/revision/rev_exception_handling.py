# https://www.geeksforgeeks.org/python/python-exception-handling/. [ Revisit -- some items pending]

# Exception Handling allows a program to gracefully handle unexpected events (like invalid input or missing files) without crashing. 
# Instead of terminating abruptly, Python lets you detect the problem, respond to it, and continue execution when possible.

# Difference Between Errors and Exceptions
# Error: Serious problems in the program logic that cannot be handled. Examples include syntax errors or memory errors.
# Exception: Less severe problems that occur at runtime and can be managed using exception handling (e.g., invalid input, missing files).

Syntax:
    
try:
    # code that may raise an exception
except ExceptionType1:
    # code to handle ExceptionType1
except ExceptionType2:
    # code to handle ExceptionType2
except Exception as e:
    # code to handle any other exception, e contains the exception object with details about the error
else:
    # code that runs if no exceptions were raised in the try block
finally:
    # code that always runs, regardless of whether an exception occurred or not (useful for
    
    
# Common Types of exceptions in python :
# ArithmaticError
# ValueError -- if trying to type cast a str into int or invalid value
# NameError -- if variable does not exist
# ZeroDivisionError -- division by 0
# IndexError -- index out of bounds

# creating custom exceptions:

class AgeError(Exception):
    pass

def set_age(age):
    if age < 0:
        raise AgeError("age cannot be negative")