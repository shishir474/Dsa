# 143. Reorder List

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # find the middle element
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # second stands at the beginning of the second half
        second = slow.next
        prev = slow.next = None

        # reverse the second half
        while second:
            next = second.next
            second.next = prev
            prev = second
            second = next
        
        first, second = head, prev
        # merge 2 halfs
        while second:
            tmp1, tmp2 = first.next, second.next
            first.next = second
            second.next = tmp1
            first = tmp1
            second = tmp2
        
# Iterative and recursive solution both exists
# TC: O(n), SC: O(1)




        


        