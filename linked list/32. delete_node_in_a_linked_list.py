# https://leetcode.com/problems/delete-node-in-a-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # I'm not given head of the linked list, so I cannot traverse the list
        # The questoin clearly states that all the values in linked list are unique, and we need to delete the ListNode node which has some value
        # I can simply update the value of node with next node's value and delete the next node.
        # By doing this, we will remove the node's value from the list and also because of deleting next node (since the values will be duplicated), the length will also reduce by 1
        # for eex: 4 -> 5 -> 1 -> 9, assume we need to delete node 5
        # first step: update node's value with next node's value: 4 -> 1 -> 1 -> 9
        # second step: delete next node: 4 -> 1 -> 9
        # Effectively, we deleted node 5 

        # it's also guranteed that node is not the last node in the linked list
        node.val = node.next.val
        node.next = node.next.next


        
            
