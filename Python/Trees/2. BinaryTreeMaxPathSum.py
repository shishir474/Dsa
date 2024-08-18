# https://www.youtube.com/watch?v=Hr5cWUld4vU&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=61


# https://leetcode.com/problems/binary-tree-maximum-path-sum/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # solve function doesnt return anything useful. 
    # We are using this compute the max Path sum by traversing all the nodes and calculating the max sum possible at each node and then updating the ans
    # How are we calculating the max sum at each node. Basically it will contain the node's value, now if the left tree returns a +ve value, we can add this to the curr nodes sum, similarly if right node returns a +ve value, we can also add this to curr nodes sum
    # so at a curr node, curr node + leftNodeSum(add only if leftNodeSum > 0) + rightNodeSum(add only if rightNodeSum > 0)
    # compare the curr nodes sum with ans and update ans accordingly
    # Now what to return?
    # From a node, we will return curr_nodes value + max(leftNodeSum,  rightNodeSum, 0). But if max value of left and right nodes is -ve, then we will add 0, instead of adding -ve value to the curr nodes sum
    # Hence we have added 0 in the max condition to ensure if both left and right node sum are negative we dont include that only return currnode's value
    # TC:O(N) - O(1) work at each node, total of n nodes
    # SC: O(n) - recursive stack space

    # what is the max path sum at each node - THis will surely contain the curr nodes value + leftNodeSUm and rightNodeSum subject to the condition if they are +ve, then only it is beneficial to add them to curr node
    # what is the max value that we can return from a particular node -- curr node + max(leftNodeSum, rightNodeSum, 0)

    # solve returns max path sum without split
    def solve(self, root, ans):
        if not root:
            return 0

        leftSum = self.solve(root.left)

        rightSum = self.solve(root.left)

        # best sum possible from this root
        currSum = root.val
        if leftSum > 0: currSum+=leftSum
        if rightSum > 0: currSum+=rightSum

        # compute max path sum with split
        ans = max(ans, currSum)

        # the best sum that we can return from this root
        return root.val + max({leftSum, rightSum, 0})
        

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = float('-inf')
        self.solve(root, ans)
        return ans