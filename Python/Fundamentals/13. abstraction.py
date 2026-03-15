
# 🔹 What is Abstraction in Python?
# ✅ Definition (Interview-style)

# Abstraction is an Object-Oriented Programming principle where we hide implementation details and expose only the essential features of an object.

# In simple terms:

# “Abstraction means showing what an object does, but hiding how it does it.”

# 🔹 Real-Life Example

# Think about a car:

# You use:

# start()

# accelerate()

# brake()

# But you don’t know:

# How fuel injection works

# How piston combustion happens

# How gearbox synchronizes

# That internal complexity is hidden — that’s abstraction.

# 🔹 Why Do We Need Abstraction?

# Reduces complexity

# Improves code maintainability

# Enforces a contract (especially useful in large systems)

# Helps in scalable architecture (very important in backend systems)

# 🔹 How is Abstraction Achieved in Python?

# Python provides abstraction using:

# Abstract Base Classes (ABC)

# abc module

# @abstractmethod decorator

# 🔹 Proper Example (Step-by-Step)

# Let’s design a Payment System (very realistic backend example).

# We want:

# Multiple payment types

# Common interface

# Enforced method implementation

✅ Step 1: Import ABC
from abc import ABC, abstractmethod
✅ Step 2: Create Abstract Class
class Payment(ABC):

    @abstractmethod
    def pay(self, amount):
        pass
# What’s happening here?

# Payment is an abstract class.

# pay() is an abstract method.

# Any subclass MUST implement pay().

# If not → Python throws error.

# ✅ Step 3: Concrete Implementations
class CreditCardPayment(Payment):
    
    def pay(self, amount):
        print(f"Processing credit card payment of ₹{amount}")
class UpiPayment(Payment):
    
    def pay(self, amount):
        print(f"Processing UPI payment of ₹{amount}")
# ✅ Step 4: Using It
payment1 = CreditCardPayment()
payment1.pay(1000)

payment2 = UpiPayment()
payment2.pay(500)
# 🔹 What Did We Achieve?

# User interacts with pay()

# Implementation differs internally

# Contract enforced by abstract class

# Extensible design

# If tomorrow you add:

class NetBankingPayment(Payment):
    def pay(self, amount):
        print(f"Processing Net Banking payment of ₹{amount}")

# No change needed in existing logic.

# That’s scalable design.

# 🔹 What Happens If We Don't Implement Abstract Method?
class CashPayment(Payment):
    pass

# If you try:

c = CashPayment()

# You’ll get:

# TypeError: Can't instantiate abstract class

# Because pay() is not implemented.

# This enforces strict abstraction.

# 🔹 Difference Between Abstraction and Encapsulation
# Abstraction	Encapsulation
# Hides implementation details	Hides internal data
# Achieved using ABC	Achieved using private variables
# Focus: What object does	Focus: How data is protected