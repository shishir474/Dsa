# https://www.youtube.com/watch?v=RyrVWP76lVo Using minheap

import heapq
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        min_heap = []

         # Add the first node of each list to the heap, if not None
        # klogk
        for i,node in enumerate(lists):
            if node:
                heapq.heappush(min_heap, (node.val, i ,node))

        dummy = ListNode(0)
        tail = dummy

        # Process the heap until it's empty
        # nlogk # in total you will process n elements, and at a time you will have k elements in your pq, which takes logk time 
        while min_heap:
            # Pop the smallest element from the heap
            value, i, node = heapq.heappop(min_heap)
            tail.next = node
            tail = tail.next

            # If the node has a next node, push it to the heap
            if node.next:
                heapq.heappush(min_heap, (node.next.val, i ,node.next))

        return dummy.next
        
# TC: O(nlogk)
# SC: O(k)
    
    
    
# Using Divide and conquer approach -- Neetcode
# https://www.youtube.com/watch?v=q5a5OiGbT6Q

# Pending

