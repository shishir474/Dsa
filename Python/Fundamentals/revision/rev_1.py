age = int(input("Enter your age: "))

if age < 18:
    print("You are a minor.")
elif age < 65:
    print("You are an adult.")
else:
    print("You are a senior citizen.")
    
for i in range(0,10,2):
    print(i)
    
    

# Python is dynamically typed language. Thus providing type hint is completely optional.
# Although adding type info in the input arguments and return type is recommended as good practise in production/large codebases.
# Reason is : provides better readability

#Python type hints are not enforced at runtime. They are mainly used by static type checkers and IDEs to detect type errors before execution.
# If we want to enforce this at runtime, we must enforce it manually
def add(x: int, y: int) -> int:
    return x + y

add("a", "b")   # static checker warns

# runtime enforcement: we must enfore it manually
def add(x: int, y: int) -> int:
    if not isinstance(x, int) or not isinstance(y, int):
        raise TypeError("Arguments must be integers")
    return x + y

# There are some libraries that enforce types automatically like pydantic, typeguard, and beartype
# Example with typeguard:

from typeguard import typechecked       # install typeguard module: pip3 install typeguard

@typechecked
def add(x: int, y: int) -> int:
    return x + y

# Now Python enforces types

# Python chooses this design instead of strict typing (like Java or C++), which is a really interesting design decision.