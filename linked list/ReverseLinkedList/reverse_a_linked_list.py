# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        
        # use while curr instead of while curr != None -- more pythonic
        while curr:         
            # preserve next
            # Avoid using next as variable name. next is a built in python function so it's better to avoid shadowing it.
            nxt = curr.next
            # reversing the direction - pointing current's next to prev
            curr.next = prev
            # update prev and curr: prev moves to curr and curr moves to next
            prev = curr
            curr = nxt

        return prev
        
        
        
# TC: iterating thru the list once - hence the tc is O(N)
# SC: not using any extra space, hence sp is O(1)        




# RECURSIVE SOLUTION

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        res = self.reverseList(head.next)
        head.next.next = head
        head.next = None    # imp to terminate the list
        return res
        
# TC: O(N)
# SC: O(N) recursive stack space 
# so iterative sol is preferred
