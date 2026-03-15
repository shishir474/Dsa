# https://leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        thead = dummy

        c1, c2 = l1, l2
        carry = 0

        # iterate until one of the lists is non empty / valid
        # or if carry is non zero
        while c1 or c2 or carry:
            val1 = c1.val if c1 else 0              # inline conditional expressoins - more pythonic
            val2 = c2.val if c2 else 0
      
            sum_val = val1 + val2 + carry
            carry = sum_val//10 

            # create a new node & add it next to dummy
            dummy.next = ListNode(sum_val%10) 
            dummy = dummy.next  # update dummy to dummy.next
            
            if c1:
               c1 = c1.next
            if c2:
                c2 = c2.next

        return thead.next
    
    # TC: O(max(n,m)) where n & m are the lengths of both the linked lists
        # We need to iterate thru both the lists simaltaneously, hence n + m
    # SC: O(1), not using any extra space, except the space required to store the output
    
    # Why is the tc not O(n + m)
    # O(n + m) is asymptotically correct, but O(max(n,m)) is the tighter bound
    # basically O(max(n,m)) <= O(n+m)
    
    # why not n + m ?
    # because we are not traversing the lists sequentially. 
    # We are traversing them in parallel
    # The tc would be n+m when we traverse the lists separately
    
    # so technically n + m is also correct, but max(n,m) provides a tighter bound
    