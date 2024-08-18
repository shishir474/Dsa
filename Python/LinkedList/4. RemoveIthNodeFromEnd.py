# https://www.youtube.com/watch?v=XVuQxVej6y8&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=43

# intution: left ptr is at beginning of the list and right ptr is shifted by n
# then we shift each ptr by 1, which ensures the space between left and right is n always
# since it is a single linked list, for deleting a node, you must stand at a node previous to the node which has to be deleted or you can maintain a prev or you can initialise your left to dummy node


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        left, right = dummy, head
        
        while n>0 and right:
            right = right.next
            n-=1
        
        while right:
            left = left.next
            right = right.next
            
    #now left stands at a point prev to the node which has to be deleted
        left.next = left.next.next
        return dummy.next
        
#: TC:O(n) since it is a 2ptr technique,
# SC: O(1)