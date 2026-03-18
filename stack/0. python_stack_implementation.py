# Stack Implmentation in Python

# There are 3 ways to implement Stack in Python

# 1. Using lists        
    # # NOTE: Note: While simple, lists can be inefficient for very large, dynamically growing stacks 
    # # due to occasional memory reallocations (amortized O(1) but can have O(n) spikes.
    ## TC: amortized O(1) for push() and pop()
    
# 2. Using collection.deque
    ## TC: O(1) for push() and pop()
    
# 3. Using queue.LifoQueue 
    ## NOTE: for implementatoins in multi threaded environment where thread safety is essential.
    # It handles necessary locks to ensure operations are atomic, preventing race conditions
    
    
# collections.deque is implemented as a doubly linked list, which guarantees O(1) (constant time) complexity for
# append() (push) and pop() operations at both ends.

# Using a list for stack operations also provides O(1) amortized performance for append() and pop() at the end. 
# However, lists occasionally require memory reallocation as they grow, which can lead to performance bottlenecks (an O(n) operation). 
# deque avoids this issue, providing consistently fast operations.



# Common Stack Operations
# Operation 	Description	                            Python list method	collections.deque method	queue.LifoQueue method
# Push	        Adds an element to the top	                 append()	            append()	              put()
# Pop	        Removes and returns the top element	         pop()	                pop()	                  get()
# Peek	        Returns the top element without removing     stack[-1]	            stack[-1]	         Not directly supported, but can access the underlying queue for a peek
# isEmpty	    Checks if the stack is empty	             len(stack) == 0	    len(stack) == 0	          empty()



# Implementation 1
# Since deque is optimized for fast appends and pops, it is often preferred over lists for stack implementation.

# Stack Implementation using collection.deque
from collections import deque

stack = deque()
stack.append('a')
stack.append('b')
stack.append('c')

print(stack)

print('Stack top: ', stack[-1]) # accessing top most element

print('Stack Pop:', stack.pop())    # removes and returns the top/last element
print(stack)
print('size: ',len(stack))

while len(stack) > 0:
    top = stack[-1]
    print(top)
    stack.pop()



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


    
    
# Conclusion: 
# Stacks can be implemented in python primarily using 2 ways: lists and deque. While lists are simple,
# they offer amortized O(1) time complexity for push and pop operations.
# Whereas deque which are internally implemented as Doubly linked lists offer O(1) complexity for both push and pop.
# Hence deque is the recommended approach.


