# Implementation 2
# Stack implementation using list
s1 = []
s1.append('1')
s1.append('2')
s1.append('3')

print(s1)

print('Stack Top: ', s1[-1])

while len(s1) > 0:
    top = s1[-1]
    print(top)
    s1.pop()        # removes and returns the top/last element
    
    
    
    
    
# creating a dedicated Stack class to provide better encapsulation
# Enclosed the above code in class

class Stack:
    def __init__(self):
        self.stack = []
        
    def push(self, e) -> None:
        self.stack.append(e)
    
    def pop(self):
        if self.isEmpty():
            return "stack is empty"
        return self.stack.pop()
    
    def size(self) -> int:
        return len(self.stack)
    
    def isEmpty(self) -> bool:
        return len(self.stack) == 0
    
    def top(self):
        if self.isEmpty():
            return "stack is empty"
        return self.stack[-1]
    
    
s = Stack()
s.push(1)
s.push(2)
s.push(3)

print("Stack: ", s.stack)
print("Pop: ", s.pop())
print("Stack after Pop: ", s.stack)
print("Peek: ", s.top())
print("isEmpty: ", s.isEmpty())
print("Size: ", s.size())

# TC for all operations: amortized O(1)
