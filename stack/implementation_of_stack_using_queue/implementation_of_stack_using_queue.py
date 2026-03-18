# https://leetcode.com/problems/implement-stack-using-queues/description/

from collections import deque
class MyStack:

    def __init__(self):
        self.q = deque()

    def push(self, x: int) -> None:
        self.q.append(x)
        # make push expensive - rotate queue to bring new element to front
        for i in range(len(self.q) - 1):
            self.q.append(self.q.popleft())

    def pop(self) -> int:
        if len(self.q) == 0:        # added empty queue check, though question guarantees pop() will not be called on empty queue
            return -1
        return self.q.popleft()    # stack is lifo, pop() removes and return the last added element

    def top(self) -> int:
        if len(self.q) == 0:        # added empty queue check, though question guarantees pop() will not be called on empty queue
            return -1
        return self.q[0]   # access the last element

    def empty(self) -> bool:
        # return len(self.q) == 0 
        return not self.q       # pythonic way of writing, same as above line
    
        # if q is non empty: self.q return True, not True equals False, we return False
        # if q is empty: self.q return False, not False equals True, we return True

        # In python, objects have truth values. for ex: list, deque, dict etc
        # empty --> means False
        # non empty --> means True



# Below solution is not recommneded. Because you used dq.pop() and dq[-1] which are not standard queue operations.
# Queue operations are append() and popleft()
from collections import deque
class MyStack:

    def __init__(self):
        self.q = deque()

    def push(self, x: int) -> None:
        self.q.append(x)

    def pop(self) -> int:
        if len(self.q) == 0:        # added empty queue check, though question guarantees pop() will not be called on empty queue
            return -1
        return self.q.pop()    # stack is lifo, pop() removes and return the last added element

    def top(self) -> int:
        if len(self.q) == 0:        # added empty queue check, though question guarantees pop() will not be called on empty queue
            return -1
        return self.q[-1]   # access the last element

    def empty(self) -> bool:
        return len(self.q) == 0 


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()


# the advantage of using deque is I can access elements from both the ends of the queue. 
# popleft() and pop() removes and returns the front & rear element in our queue
# q[0] and q[-1] returns the value at the front & rear positions in the queue


#TC of all operations is O(1)