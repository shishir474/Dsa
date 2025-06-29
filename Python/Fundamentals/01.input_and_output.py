# input() to take user input. By default returns user input in form of string
name = input("Enter your name")
print(name)

age = 25
city = "New York"

# You can print multiple variables by separating them with comma
print(name, age, city)

# taking multiple input from user in single line
x,y = input("Enter two values: ").split()

a = "Hello World"
b = 10
c = 11.22
d = ("Geeks", "for", "Geeks")
e = ["Geeks", "for", "Geeks"]
f = {"Geeks": 1, "for":2, "Geeks":3}

print(type(a))
print(type(b))
print(type(c))
print(type(d))
print(type(e))
print(type(f))

# Output
# <class 'str'>
# <class 'int'>
# <class 'float'>
# <class 'tuple'>
# <class 'list'>
# <class 'dict'>

amount = 150.75
print(f"Amount: ${amount}")
print("Amount: ${:.2f}".format(amount))


# to execute code from terminal: python3 <relative file path>
