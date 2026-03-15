# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getLength(self, head):
        count = 0
        curr = head
        while curr:
            count+=1
            curr = curr.next
        return count

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # removing nth node from the end of the list is 
        # equivalent to removing (len - n + 1)th node from the front 
        # where len is the length of the list
        len = self.getLength(head)

        # edge case: if I need to remove 1st node from the front
        if len - n + 1 == 1:
            return head.next
        
        prev = None
        curr = head
        count = 1
        while curr:
            if count == len - n + 1:
                prev.next = curr.next # remove curr node
            prev = curr
            curr = curr.next
            count+=1

        return head
    
    # TC: O(n) - this code just performs single iteration thru the list
    # SC: O(1) - no extra space utilized