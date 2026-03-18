# https://leetcode.com/problems/implement-queue-using-stacks/

# Recommended approach:
# use lists: we use 2 stacks in_stack and out_stack.
# All the push operations will be performed on in_stack.
# pop() and peek() will happen from out_stack.
# So whenver pop() or peek() is called, transfer operatoin will transfer (only iff out_stack is empty) 
# all the elements from in_stack to out_stack
# at any given time, elements could be present in both in_stack and out_stack.
# Thus in order to check if queue is empty, both in_stack and out_stack must be empty.
# out_stack elements have higher priority over in_stack elements, because eleements willl be popped / peeked from output always.
# Thus if output stack has non zero elements, pop() or peek() will consume those elements first and then when out_stack becomes empty and pop() or peek() is called again, 
# we will transfer the elements from in_stack to out_stack

class MyQueue:
    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    def push(self, x: int) -> None:
        self.in_stack.append(x)        # we append only in input_stack

    def pop(self) -> int: 
        if not self.empty():        # call pop() and peek() only if queue is non empty
            self._transfer()        # whenever pop() or peek() is called, transfer() operation is triggered
            return self.out_stack.pop()         # but we only transfer elements from input to output stack if output stack is empty. Bcoz if out is not empty, we will prioritise output stack elements because they have higer priority

    def peek(self) -> int:
        if not self.empty():    
            self._transfer()
            return self.out_stack[-1]
        
    def empty(self) -> bool:        # queue is empty if both input and output stacks are empty
        return not self.out_stack and not self.in_stack
    
    def _transfer(self):
        # transfer all the elements from in_stack to out_stack only if out_stack is not empty
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        
    # TC: push(), empty() --> O(1)
    # pop(), peek() --> amortized O(1)
    
    # O(1) vs amortized O(1) conceptual difference
    # O(1) → every operation always takes constant time
    # Amortized O(1) → most operations are O(1), but some are expensive; averaged over many operations it becomes O(1)




# Below code is not the recommended approach for interviews. 

# Questoin was to implement a queue using stacks. We used a deque, whihc is already a queue like data strucutre.
# So our solution is essentially : queue using queue
from collections import deque
class MyQueue:

    def __init__(self):
        self.s = deque()

    def push(self, x: int) -> None:
        self.s.append(x)

    def pop(self) -> int:
        return self.s.popleft() # removes and returns the front element

    def peek(self) -> int:
        return self.s[0]    # accessing the front element

    def empty(self) -> bool:
        return len(self.s) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()


# The reason we choose deque for stack implementation and not lists is 
# in lists, if we want to remove the front element, pop(0) will be an O(n) operatoin as it will trigger a shift for all the elements on the rhs
# whereas if we use deque, we can use popleft() operation to remove the front element which is essentially an O(1) operation.
# dequeu's are internally implemented using Doubly linked lists, so insertions and removal of nodes from both the nodes is an O(1) operation