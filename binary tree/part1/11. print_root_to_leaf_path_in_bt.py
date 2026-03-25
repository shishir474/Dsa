    #     1
    #    / \
    #   2   3
    #  / \  /  
    # 4   6 5
    
    # print all possible root to leaf paths
    # 1->2->4, 1->2->6, 1->3->5
    # res = []
    # temp = [1,2,4]
    
# class Solution:
#     def print_root_to_leaf_paths_in_bt(self, root):
#         res = []
#         temp_res = []
        
#         def helper(root):
#             if not root: return
#             temp_res.append(root)
#             helper(root.left)
#             helper(root.right)
#             temp_res.pop(root)
        
#         helper(root)
#         return res
class Solution:   
    def root_to_node_path(self, root, node):
        # root --> node path
        def helper(root, path):
            if not root: 
                return False
            
            path.append(root.val)   # we always add root to path
            
            if root.val == node.val: # if root == node, we found the path
                return True
            
            # if either of left or right return True
            if helper(root.left, path) or helper(root.right, path):
                return True
        
            # I have to do the tedious task of removing the value
            path.pop()
            return False
        

        path = []
        if helper(root,path):
            return path
        return []

        
        
    # NOTE: 
    # 1. “Since path and res are defined in the outer function. The inner function would be able to access it. 
    # Also they are shared across recursive calls, 
    # I can either pass them(path & res) explicitly in function parameter or use closure(python detects them automatically since they are defined in outer scope).
    # Both are valid.”
    
    # 2. Will changes to path reflect in recursive calls?
    # Yes, because list is mutable and is passed by reference.
    # That's why backtracking pop() is essential.
    
    # 3. why do we use path[:]? 
    # because in python outer container store references of inner container objects. 
    # If you just do res.append(path) --> whatever changes that will happen in path will also reflect in res. 
    # Thus we create it's copy. 
    def root_to_leaf_path(root):
        res = []
        path = []
        
        def helper(root):
            if not root:
                return
            
            path.append(root.data)
            
            helper(root.left)
            helper(root.right)
            
            # once you're done with both left & right calls of 2
            # you will check if 2 is a leaf node. It's not. So nothing will be added to res
    
            # for one, left & right calls are done and it is also not a leaf node. So nothing will be added
            if not root.left and not root.right:
                res.append(path[:])
                
            # we remove 1 and then return
            path.pop()  # we'll pop 2 and then return
                
            
        helper(root) 
        return res  
            
    #     1
    #   /      
    #   2 
    #  / \
    # 3. 4 
    
    # with better ordering -- does the same thing as above
    # clean code
    def root_to_leaf_path(root):
        res = []
        path = []
        
        def helper(root):
            if not root:
                return
            
            path.append(root.data)
            
            if not root.left and not root.right:
                res.append(path[:])
            else:
                helper(root.left)
                helper(root.right)
            
            path.pop()  
                
            
        helper(root) 
        return res  
                
            

