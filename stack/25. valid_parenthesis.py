class Solution:
    def isValid(self, s: str) -> bool:
        lst = []
        for i in s:
            if i in ('(','{','['):
                lst.append(i)
            else:
                print(len(lst))
                if i==')':
                    if len(lst)==0 or lst[-1]!='(': return False
                    lst.pop()
                elif i=='}':
                    if len(lst)==0 or lst[-1]!='{': return False
                    lst.pop()
                else:
                    if len(lst)==0 or lst[-1]!='[': return False
                    lst.pop()
        
        return True if len(lst)==0 else False

# if it is an opening bracket, add it to the stack
# if it is a closing bracket
#     check if the top matches with the closing. If not return false
#     check if the stack is empty. If yes return false

# TC: O(n) each char processed exactly once
# SC: O(n)



# used deque for stack implementation
from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:

        # I accidentally overwrote string s with stack and was iterating over empty deque
        # hence updated the stack variable name to st.
        st = deque()
        for char in s:
            if char in ('(', '{', '['):
                st.append(char)
            else:
                if not st:       # closing bracket and stack is empty --> return False
                    return False
                else:
                    if char == ')' and st[-1] != '(':  # closing bracket, but stack top is not matching the corresponding closing brakcet
                        return False
                    elif char == '}' and st[-1] != '{':
                        return False
                    elif char == ']' and st[-1] != '[':
                        return False
                    st.pop()     # closing bracket, stack top is also matching, we pop it out

        # at the end of the loop, stack should be empty
        return not st
    
    

# Used list for stack implementation
class Solution:
    def isValid(self, s: str) -> bool:

        # I accidentally overwrote string s with stack and was iterating over empty deque
        # hence updated the stack variable name to st.
        st = []
        for char in s:
            if char in ('(', '{', '['): st.append(char)
            else:
                if not st: return False       # closing bracket and stack is empty --> return False
                else:
                    if char == ')' and st[-1] != '(':  # closing bracket, but stack top is not matching the corresponding closing brakcet
                        return False
                    elif char == '}' and st[-1] != '{':
                        return False
                    elif char == ']' and st[-1] != '[':
                        return False
                    st.pop()     # closing bracket, stack top is also matching, we pop stack top

        # at the end of the loop, stack should be empty
        return not st
        # with deque we get constant O(1) time complexity for push() and pop() operations
        # if we use list, it offers amortized O(1) for push and pop. Reason is list occasionally requirs memory reallocation as they grow, which can lead to bottlenecks O(n) operations
        
        # Conclusion : deque is preffered because it offers optimal push performance compared to lists when implementing stacks in python