# There are 2 ways to implement a queue using arrays
# 1. infinite sized or dynamically growable array queue
# 2. fixed sized array

# 1. infinite sized or dynamically growable array queue -- Brute force
# we only maintain front pointer to track the first valid element. We insert at the next avaiable position at the end. 
# but No rear pointer is required and remove the element at front and increment front pointer.

# The only problem with this approach is space before front is never reused, which leads to space wastage and we also assumed 
# that array is conceptually infinite, but in practise memeory is finite and thus very large queues can cause memeory issues.

# Insert is O(1) since we simply append at the end
# pop() is also O(1) since we track the front element using front pointer and do front++.



#2 . Using fixed size arrays.
# 3 variables: front, rear, cnt, cap
# front --> tracks the front element of the queue
# rear --> new element is added at the rear position
# cnt -> at any instance, cnt indicates the no of elements in the queue
# cap -> represents the total capacity of the undeerlying array


class MyQueue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.rear = 0
        self.front = 0
        self.count = 0
        self.arr = [0] * capacity       # underlying array that will store elements
        
    def push(self, e):
        if self.count == self.capacity:
            return "Can't add this element. Queue is full"
        
        # rear points to the next position where next element will be added
        self.arr[self.rear % self.capacity] = e     # add the element   -- circular queue
        self.rear+=1                # move rear ptr
        self.count+=1               # update count
    
    
    def pop(self):
        if self.count == 0:
            return "Queue is empty!"
        
        # front points to the first valid element
        val = self.arr[self.front % self.capacity]    # add the element   -- circular queue
        self.front+=1               # move front ptr
        self.count-=1               # update count
        return val
    
    
    # to avoid naming conflict with front named variable, renamed it to get_front()
    def get_front(self):        
        if self.count == 0:
            return "Queue is empty!"
        # return the front element
        return self.arr[self.front % self.capacity]
    
    def size(self):
        return self.count
    
    def isEmpty(self):
        return self.count == 0
    
    def get_all_elements(self):
        # queue elements will be in range front to rear -  1 inclusive.
        # rear is the next index where new element will be added. Original queue is only till rear - 1 index
        print('Printing all queue elements')
        for i in range(self.front, self.rear):
            print(self.arr[i % self.capacity])  # taking module, bcoz we're dealing with circular queue
            
    
q = MyQueue(3)
q.push(10)
q.push(20)
q.push(30)


print(q.get_front())

q.pop()

q.push(40)

print(q.get_front())

q.get_all_elements()

# TC of all operatoins is O(1) -- credit to circular queue logic
# In the brute force solutoin, once an element was dequeued, the space at the front couldn't be used. We solved that
# problem by moving the rear & front pointers in circular directoin

# SC: O(capacity) # underlying storage for array 