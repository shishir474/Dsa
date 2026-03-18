# https://www.naukri.com/code360/problems/sort-a-stack_985275?leftPanelTabValue=PROBLEM

# sorts the given input stack
# using recursion

def sortStack(stack):
    # given data structure is a python list 
    # as list have all the similar operations available so use them
    # Write your code here
    
    # base case: if the stack is already sorted
    if len(stack) == 0:
        return stack
    
    # pop the top most element
    topmost_ele = stack.pop()

    # call recursoin on remaining stack
    # returns new_stack sorted in desc order
    sorted_stack = sortStack(stack)

    # just need to place the top_most element in the correct position in new_stack
    temp = []
    while sorted_stack and sorted_stack[-1] >= topmost_ele:
        temp.append(sorted_stack.pop()) 
    
    # insert the topmost_element
    sorted_stack.append(topmost_ele)

    # transfer eleements back into new_stack
    while temp:
        sorted_stack.append(temp.pop())

    return sorted_stack

# TC: for each recursino call , we are doing (n+n = 2*n) work and in total there will be n recursive calls. 
# Hence the overall time complexity will O(n^2)
# SC: O(N) for temp[]  + O(n) for recursion stack = O(n)
# The depth of the recursion tree will be n (effectively same as size of the stack)