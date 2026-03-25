# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


# Vertical Order Traversal Summary
# get the list of nodes corresponding to each width. 
# The nodes will already be arranged in increasing order of their depth's. Level Order takes care of that.
# sort the list --> so that it first sorts on their depths and if depth's are same sorts them on increasing order of their values.

# TC: O(n) --> level order traversal
# SC: O(n) for deque + O(n) for hashmap --> 
# deque's max width equivalent to max width of the binary tree 


# dry run
    #     1
    #    / \
    #   2   3
    #  / \  /  
    # 4   6 5

    # mp:         # width -> list of (depth, node.val)
    #     -2 -> [(2,4)] 
    #     -1 -> [(1,2)]      
    #      0 -> [(0,1), (2,6), (2,5)]
    #     +1 -> [(1,3)]
        
    # This will how map will look like 
    # We have mapped for each width the list of nodes that has that width. Also tracking their depths.
    # The question wants us to return answers from left to right, so we process width in the increasing order
    # so width = -2, then -1, then 0 and so on.
    # Now for each width, you might have multiple nodes either at different or same depth.
    # For ex: corresponding to width 0, we've 3 nodes 1,6,5
    # the question states that if we have multiple nodes for a given width, we return them in increasing order of their depths
    # and if for the same depth, we have multiple nodes, we return them in increasing order of their value.
    # so for width = 0 --> nodes order should be 1,6,5
    
    # Now remember that for a given width, level order will always produce nodes in increasing order of their depths. So that part is taken care off. 
    # But if 2 or more nodes have the same depth, then we need to sort them in increasing order of their values. 
    # so we need to sort this list of pairs corresponding to mp[0]
    # first on the basis of their depth's (i.e the first element) and if their depth is same then on basis of their values (i.e their second element)
    
    # Say you have been given a list of pairs and you need to write custom comparator.
    # lst = [(1, 2), (1, 5), (2, 1), (2, 3)]
    # lst.sort()      # sorts on basis of 1st element, if they are equal sorts on basis of 2nd element
    


from collections import deque
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        # we simply do a level order traversal
        # and track horizontal distance & level of each node.
        # Of course, in each column you can have multiple nodes with different depths
        # we want to retrieve nodes in increasing order of width's
        # and for a given column, nodes should be arranged in increasing order of depth
        # and if at a given depth for a given column, we have more than 1 node, then we sort them in increasing order of values.

        # Also, for a given width, the nodes will always be present in non decreasing() order of their depth. Why because we're using level order which prioritizes nodes closer to the root.


        # we will create a map which will map width to list of nodes
        mp = {} # width -> [(depth,node)]
        # at the end for each we just sort the list in increasing order of values

        dq = deque([(root, 0, 0)])     # (node, width, depth)
        while dq:
            node, width, depth = dq.popleft()
            # print(node.val)

            # mp[width].append(node.val)
            # mp.get(width,[]).append(node.val)     # This doesn't update the map. mp.get() returns [] and you append to it. But that doesn't get relfected back in mp
            # instead do this
            if width not in mp: # first create an entry for it
                mp[width] = []      
            mp[width].append((depth, node.val))  # and then append value to it

            if node.left:
                dq.append((node.left, width - 1, depth + 1))
            if node.right:
                dq.append((node.right, width + 1, depth + 1))
        

        res = []
        for key in sorted(mp.keys()):       # increasing order of width's
            # for each width: we sort in increasing order of depth's and if 2 or more nodes have same depth, then we sort them in increasing order of values.
            temp = []
            for depth, val in sorted(mp[key]):
                temp.append(val)
            res.append(temp)

        
        return res