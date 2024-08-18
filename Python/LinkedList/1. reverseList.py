class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr, prev = head, None
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev 
        # TC: O(n) SC : O(1) : 2 pointers solution, not using any extra space
        
        
        
#recursive solution: TC: O(n), SC: O(n) recursive stack space
class Solution:
    def solve(self, curr):
        if curr is None or curr.next is None:
            return curr
        tail = curr.next # save the next 
        curr.next = None # break the link
        newHead = self.solve(tail) # call recursion
        tail.next = curr # attach curr to tail
        return newHead

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.solve(head)