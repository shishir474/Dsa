# You will be given a binary tree.
# and you need to maintain children sum property.
# This property states that a node's value should be equivalent to left subtree node value sum + right subtree node value sum.
# and if it's not then we need to modify the node values so that the tree starts following this property.

# [node] = [left] + [right]
# you can increment any node by +1 any number of times.
# Also you cannot change the structure of the binary tree 

    #     2                                         
    #    / \
    #   35  10
    #  / \  / \
    # 2  3  5  2                        
     
    # can be converted to
    
    #     45                                        
    #    / \
    #   35  10
    #  / \  / \
    # 5 30  8  2    
    
    
    # now this is not as straightforward as you think. 
    # There are some edge cases
    
    #     50                                        
    #    / \
    #   7    2
    #  / \  / \
    # 5 3  1  30  
    
    # it's not simple as moving from bottom to top and updating the value.
    # 5 + 3 = 8, you update 7 to 8
    # similary 2 is updated to 31
    # now root shouuld be 31 + 8 = 39 which is < 50.
    # You cannot reduce a node's value. You can only increase its value in increments of 1 infinite no of times.
    
    # So there is no guarantee that if you move up, you will get a value > curr node's value. 
    # In which case the solution fails
    
    
    # We will see a O(N) solution.
    # Any binary Tree is accepted, as long as it follows the children sum property.
    # I have the liberty to increase node's value as many times as I like.
    # The question is not about ensuring minimal operations. 
    
class solution:
    def children_sum_property(self, root):
        
        def helper(root):
            if not root:                                # null node --> already balanced
                return
            if not root.left and not root.right:        # leaf node --> already balanced
                return
            
            sum = 0                         
            if root.left:
                sum += root.left.val
            if root.right:
                sum += root.right.val
                
            if sum < root.val:                      # checking if child sum < root.val
                if root.left: root.left.val = root.val  # if yes, then we need to set child value to root.val
                if root.right: root.right.val = root.val
                
            helper(root.left)                   
            helper(root.right)
            
            updated_root_val = 0                    # calculating child sum
            if root.left: updated_root_val += root.left.val
            if root.right: updated_root_val += root.right.val
            
            root.val = updated_root_val             # while coming back, set root.val as child sum


        # TC: O(n) -- post order traversal, we visit each node once.
        # SC: O(h) --> recursive stack space
        

    #     50                                        
    #    / \
    #   7    2
    #  / \  / \
    # 5 3  1  30  
    
    # Dry run
    # I'm standing at 50.
    # Get the children summation: 7 + 2 = 9
    # since 9 < 50, we update 7 with 50 (i.e root.val) and 2 with 50
    # call recursion on left i.e 50
    
    #     50                                        
    #    / \
    #   50    50
    #  / \  / \
    # 5 3  1  30  
    
    # again 50 child sum => 5 + 3 = 8 < 50
    # again I replace left and right child value with root.
    # and I recurse for left 50
    # It's a leaf node (already balanced, we return)
    # we recurse right (again a leaf node, we return)
    # while returning update the root.val with left child + right child sum
    # so 50 + 50 = 100, replcae 50 with 100
    
    #     50                                        
    #    / \
    #   50    50
    #  / \  / \
    # 50 50  1  30  
    
    #     50                                        
    #    / \
    #   100  50
    #  / \  / \
    # 50 50 1  30  
    
    # now left subtree is balanced.
    # left subtree is done, we recurse right.
    # again we check children sum: 1 + 31 = 31 < 50
    # The reason we update child's value with root.val is because if the child sum < root.val
    # then we can never make the tree balanced without reducing the value of root which is simply not allowed.
    # So the simplest way would be to just update the child val both left and right if they exist with root.val
    # and post recursion while coming back, we update the root.val
    
    
    #     50                                        
    #    / \
    #   100  50
    #  / \  / \
    # 50 50 50  50  
    
        
    #     50                                        
    #    / \
    #   100  100
    #  / \  / \
    # 50 50 50  50  
       
            
    #     200                                       
    #    / \
    #   100  100
    #  / \  / \
    # 50 50 50  50  
    
    
    
    # Psuedo Code
    
    # f(root):
    #     if not root: 
    #         return
    #     if not root.left and not root.right:
    #         return
            
    #     f(root.left)        # get left subtree balanced
    #     f(root.right)       # get right subtree balanced
        
    #     updated_val = 0
    #     if root.left: updated_val += root.left.val
    #     if root.right: updated_val += root.right.val
        
    #     root.val = updated_val      # while coming back, update root val
        
        
    # This solution just cares about setting a node's value to sum of its child nodes.
    # But in our question, we have to do this plus we also need to take care of one condition that we can only increase a particular node's value.
    # We cannot reduce it.
    # So if the child sum < root.val, then we can't set that sum directly as root.val because the questions clearly prohibits us from doing that.
    # What could be done in that case then?
    # if the child sum < root.val: we simply update the child value with root's current value. 
    # (both left and right child if they exists)
    # once we udpate them, call recursion on left subtree, right subtree 
    # and while coming back, set the root.val as child sum
        
        