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