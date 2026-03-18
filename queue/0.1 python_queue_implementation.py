# implementation of queue in python

# Implementation Methods
# Python offers several methods to implement a queue:

# 1. using collections.deque (recommended for general use)
    # deque (double ended queue) from built-in collections module is optimized for fast appends and pops from both ends, 
    # providing O(1) complexity for these operations.
    # Enqueue: use append()
    # Dequeue: use popleft()
    
from collections import deque
q = deque()
q.append('a')
q.append('b')
q.append('c')

# deque supports indexing as well
front = q[0]        # access front element

while len(q) > 0:
    front = q.popleft() # removes and returns the front element
    print(front)
    
# TC for pushing and popping an element:
# push: O(1)
# pop: O(1) 
    


# 2. Using queue module (recommended for multi-threading)
    # Built in queue module provides synchronized queue classes (Queue, PriorityQueue, LifoQueue) that are specifically 
    # designed for safe information exchange between multiple threads in a concurrent program
    # Enqueue: use put()
    # Dequeue: use get()
    
from queue import Queue
q = Queue()
q.put(1)
q.put(2)
q.put(3)

while q.empty() == False:
    front = q.get() # removes and returns the front element
    print(front)
    
# TC for pushing and popping an element:
# push: O(1)
# pop: O(1) 
    
    
# 3. Using lists (Inefficient)
# A standard python list can also function as a queue, but it is inefficient because removing the first element pop(0), 
# requires shifting all other elements, resulting in O(n) tc for dequeing.
# in python lists, pop(i) --> removes and returns the element at ith index and requires shifting all other elements on rhs which is O(n)
# pop() removes and returns the last element which is O(1)

q1 = []
q1.append(100)
q1.append(200)
q1.append(300)

while len(q1) > 0:
    front = q1.pop(0)
    print(front)

# TC for pushing and popping an element:
# push: O(1)
# pop: O(n) 

    
# collections.deque vs queue.Queue
# 1. In python, both can be used as queues, but deque is not thread safe, meaning it is meant for single threaded applications.
#   On the other hand, Queue is thread safe by using internal locks and conditional variables, ensuring that concurrent operations do not corrupt data.
# 2. Queue is significantly slower than deque because of the overhead of these synchronization mechanisms. 
#   deque is many times faster for single threaded operations.
# 3. deque can be used to implement both queues and stacks within a single thread. Offers O(1) constant time complexity for append() (enqueue) 
#   and popleft() (dequeue) operations. For stacks, Offers O(1) constant time complexity for append() (push) and pop() (pop) operations. 


# Conclusion:
# deque is the most preferred approach for implementing queues (particularly in single threaded environments) because it is much faster than queue.Queue class. 
# Queue has additional overhead due to synchronization mechanisms. lists are not recommneded because pop(0) (dequeuing) is O(n) operations



# Feature 	        collections.deque	                 queue.Queue	                        heapq (Priority Queue)
# Primary Use Case	General purpose queues/stacks 	    Multi-producer, multi-consumer queue 	Data access based on priority, 
#                   in a single thread.                 for inter-thread communication.         not insertion order.

# Ordering	        FIFO (First-In, First-Out) 	        FIFO (default), LIFO (LifoQueue), 	    Min-heap (retrieves the lowest 
#                   or LIFO (Last-In, First-Out).       or priority (PriorityQueue).            priority item first).

# Performance	    O(1) for appends/pops           	Slower than deque due to 	            O(log n) for insert and
#                   from either end.                    locking overhead.                       extract-min operations.
                    
# Thread Safety	    Thread-safe for atomic append() 	Fully thread-safe with built-in locks 	Not inherently thread-safe; 
#                   and popleft() operations.           and blocking I/O.                       requires manual locking in multi-threaded contexts.

# Implementation  	Doubly-linked list.	                Internally uses collections.deque and 	Implemented using a min-heap list algorithm.
#                                                       adds synchronization mechanisms.