# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# Does a simple preorder string trversal ensure that the string is unambiguos?   Doubt
# 2 solutions:
#  DFS simple preorder : produces an unambiguous string which then can be easily decoded. Use N to store Nulls and , as delimiter
#  BFS Level order traversal
class Codec:

# O(N) for serialise a binary Tree: siple dfs traversal
# O(N) space recursive space
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        # first lets stores all the nodes values in string format separated by , in the res list
        res = []

        def dfs(node):
            # if the node is null, append N in the list
            if not node:
                res.append("N")
                return 
            # append the node's value 
            res.append(str(node.val))
            dfs(node.left)
            dfs(node.right)
        
        # call the dfs
        dfs(root)
        # print(res) ['1', '2', 'N', 'N', '3', '4', 'N', 'N', '5', 'N', 'N']

        # join the list elements separated by comma and return the string
        encoded_str = ','.join(res)
        # print(encoded_str)  "1,2,N,N,3,4,N,N,5,N,N"
        return encoded_str
    
        
# O(N) for deserialise a binary Tree: siple dfs traversal
# O(N) space recursive space
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        # you will be given the encoded_str. You have to decode this str construct the tree and return the root of that tree
        
        # split the string on comma. This will return a list of strings
        vals = data.split(",")  # ['1', '2', 'N', 'N', '3', '4', 'N', 'N', '5', 'N', 'N']
        # print(vals) # why are we spllitting the string on comma. Bcoz this way it will be easy for traversal. Traversing over the list is simpler than traversing over the string here coz the string contains , and we will have to tare care of that
        
        # idx which will used for iterating over the list. Using self, to create this as a global variable
        self.i = 0 # this is a global variable, and its value is maintained across all the recusive calls

        def dfs():
            if vals[self.i]=='N':
                self.i+=1
                return None
            # create a node with val[self.i] Note that this value is a string so typecast it into int
            node = TreeNode(int(vals[self.i]))
            self.i+=1 # increment the idx
            
            # call recursoin for left and right subtrees
            node.left = dfs()
            node.right = dfs()
            
            return node
        
        return dfs()