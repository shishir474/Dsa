# In python, there are 2 ways to implement a priority queue. 
# 1. Using heapq module 
#     The heapq module operates on a standard Python list, transforming it into a heap in-place. 
#     This approach offers time complexity for insertions and removals and is more lightweight than the queue class.

# heapq --> module name
# heappush --> function inside that module
from heapq import heappush, heappop
pq = []
heappush(pq, 100)     # by default, builds min heap
heappush(pq, 20)
heappush(pq, 300)
heappush(pq, 250)

while pq:
    val = heappop(pq)
    print(val)



# 2. Using queue.PriorityClass
# Used in multi threaded environments. It has slighty more overhead than heapq due to built-in locking mechanisms

from queue import PriorityQueue
pq1 = PriorityQueue()

pq1.put(9)
pq1.put(6)
pq1.put(8)
pq1.put(5)

while not pq1.empty():
    val = pq1.get()
    print(val)


# Key Methods & Features
# Feature 	        heapq module	                                queue.PriorityQueue class
# Use Case	        Single-threaded applications .	                Multi-threaded applications requiring thread safety.
#                     where performance is critical
# Add Item	        heapq.heappush(heap, item)	                    pq.put(item)
# Remove Item	    heapq.heappop(heap)	                            pq.get()
# Thread Safety	    No, requires manual synchronization.	        Yes, it is thread-safe with internal locks.
# Time Complexity   O(log n) for push/pop operations.	            O(log n) for put/get operations.
# Max-Heap	        Can be simulated by using negative priorities.	Can be simulated by using negative priorities.
