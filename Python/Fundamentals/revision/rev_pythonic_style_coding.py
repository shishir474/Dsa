from collections import deque
class MyStack:

    def __init__(self):
        self.q = deque()
        
    def empty(self) -> bool:
        # return len(self.q) == 0 
        return not self.q       # pythonic way of writing, same as above line
    
        # if q is non empty: self.q return True, not True equals False, we return False
        # if q is empty: self.q return False, not False equals True, we return True

        # In python, objects have truth values. for ex: list, deque, dict etc
        # empty --> means False
        # non empty --> means True