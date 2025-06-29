# Variables
a = 15
b = 4

# Addition
print("Addition:", a + b)  

# Subtraction
print("Subtraction:", a - b) 

# Multiplication
print("Multiplication:", a * b)  

# Division
print("Division:", a / b) 

# Floor Division
print("Floor Division:", a // b)  

# Modulus
print("Modulus:", a % b) 

# Exponentiation
print("Exponentiation:", a ** b)

# Output
# Addition: 19
# Subtraction: 11
# Multiplication: 60
# Division: 3.75
# Floor Division: 3
# Modulus: 3
# Exponentiation: 50625


# The single division operator behaves abnormally generally for very large numbers. 
print(((10 ** 17) + 2) // 2)       # floor division

# Gives wrong output
print(int(((10 ** 17) + 2) / 2))         

x = 10000000000000000000006
if int(x / 2) == x // 2:
    print('yay')
else:
    print('no')
    
# The values should have matched if the single division behaved normally because 2 divides x
print(int(x/2))
print(x//2)

# This fact can be used to find the sum of first n numbers when n is large
n = 10000000000000000
s1 = (n * (n+1)) // 2       # this is correct
s2 = int((n * (n+1)) / 2)       # this is wrong for large n. Single division returns floating point values typecasting it to int using int()
print(s1, s2)

# Thus the result found by using the single division operator is Wrong, while the result found 
# by using the double division operator is Correct. This is a huge benefit of Double Division Operator over Single Division Operator in Python.

a, b = 10, 4
print(a & b)    # bitwise and
print(a | b)    # bitwise or
print(a ^ b)    # bitwise xor
print(a >> 1)    # right shift : divide by 2^1
print(a << 1)    # left shift : multiply by 2^1
print(~a) # -(10 + 1) = -11     # bitwise not which is equivalent to -(a+1)



# identity operator
a = 10
b = 10
c = 5
d = a

print(a is b) # false, ideally it should have been true, but the behaviour is not consistent here. Not sure because a and b are referencing to different object
print(a is d) # true


a = 10000
print(a,d)      # 10000 10 in case of single variable, it creates a copy and thus chnages are not reflected


# NOTE: Two variables that are equal do not imply that they are identical. 

a = [1, 2, 3]
b = a        # both a and b are referencing to the same object
b[0] = 100   # hence changes made to b are also visible in a
print(a, b)

a = [1, 2, 3]
b = a
c = [1, 2, 3]

print(a is b)      # True, because b points to the same object as a
print(a is c)      # False, because c is a new list with the same content
print(a == c)      # True, because values are the same




# Membership Operators
# in, not in
x = 24
y = 20
list = [10, 20, 30, 40, 50]

if x not in list:
    print('yes')
    
    
# Ternary Operators 
# also known as conditional expressions
# [on_true] if [expression] else [on_false]
a, b = 10,20
min = a if a < b else b         # makes the if else code compact
print(min)