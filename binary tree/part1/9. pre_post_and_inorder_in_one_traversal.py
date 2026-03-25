# So the idea is we will generate the preorder, postorder and inorder simaltaneously in a single traversal
    #     1
    #    / \
    #   2   3
    #    \
    #     4
    #      \
    #       5
    
# we'll have a stack which will store (node, num)
# Initial configuration s.push((root, 1))

# Few steps that we need to remember:
# you pull out an element from the stack:
# Now if the num == 1
    # then that guy will go into the preorder 
    # and you push that pair again by doing num++
    # and if's left exists, you also push that

# if num == 2   
    # add that guy into the inorder. WHy inorder?
        # Inorder follows Left Root Right. 2 corresponds to the middle which essentially is the root and thus goes into inorder.
    # and increment the num
    # and I'll push if there exists a right
    
# if num == 3, 
    # I'll take this node into my postorder list
    
from collections import deque
class Solution:
    def generate_pre_post_and_inorder(root):
        preorder = []
        postorder = []
        inorder = []
        
        # using a stack
        s = deque([(root,1)])   # (node, num) --> (root,1) is the initial configuration we start off with
        while s:
            node, num = s.pop()
            if num == 1:            # the node will be part of preorder
                preorder.append(node.val)
                s.append((node, num+1))     # increment num
                if node.left:               # if left exists, push that guy
                    s.append((node.left, 1))
            
            elif num == 2:  # the node will be part of inorder
                inorder.append(node.val)
                s.append((node, num + 1))   # increment num
                if node.right:              # if right exists, push that guy
                    s.append(node.right, 1)
                    
            elif num == 3:              # the node will be part of postorder
                postorder.append(node.val)
                
        
        print(inorder)
        print(postorder)
        print(preorder)
        
        
        # TC: O(3 * N) --> we will be visiting each node thrice
        # SC: O(3 * N)
        # Overall it's a linear solution which generates all 3 traversals in one single iteration
        