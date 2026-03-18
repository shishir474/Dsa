def main():
    # Your code here
    pass


# __name__ is a special built-in variable that gets its value depending on how the script is executed.
# for ex: if you run the file directly from the command line, __name__ will be set to "__main__". The condition evaluates to true and the main() function will be executed.
# But if you import the file as a module in another script, __name__ will be set to the name of the file (without the .py extension).
if __name__ == "__main__":
    main()
    
    
    
# Package vs Module vs Classes -- conceptual difference

# a module is a single .py file, which can contain classes, functoins, variables
# ex: 

# math_utils.py

def add(a, b):
    return a + b
class Calculator:
    pass

# This file = module

# Usage
# If I want to use the functions/classes inside this module
import math_utils
math_utils.add(2,3)

# or 
from math_utils import add
add(2,3)


# Package (folder of modules)

# A package is a directory that contains multiple modules.

# Example:

# my_package/
#     ├── __init__.py
#     ├── math_utils.py
#     ├── string_utils.py

# 👉 This folder = package

# Usage

# usage:
from my_package import math_utils


# real word examples
from collections import deque
# collections --> built in module 
# deque --> class inside that module

import numpy as np

# numpy (package)
#   └── random (module)
#         └── RandomState (class)
    
# Visual Hierarchy:
# Package (folder)
# │
# ├── Module (file.py)
# │     ├── Class
# │     ├── Function
# │     └── Variables
# │
# └── Sub-packages
