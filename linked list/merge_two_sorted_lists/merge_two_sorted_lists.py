# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        curr1 = list1
        curr2 = list2

        # created a dummy node
        dummy = ListNode()
        # thead & dummmy both point to the same node
        thead = dummy

        # both lists are sorted - we can use 2 pointers
        while curr1 and curr2:
            if curr1.val <= curr2.val:
                dummy.next = curr1
                curr1 = curr1.next
            else: 
                dummy.next = curr2
                curr2 = curr2.next
            dummy = dummy.next


        # append the remaining list next to dummy
        # if curr1 is left
        if curr1:
            dummy.next = curr1
        
        # if curr2 is left
        if curr2:
            dummy.next = curr2

        # return final ans
        return thead.next

        # TC: O(n + m)
        # SC: O(1)

