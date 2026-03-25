# Morris Inorder traversal 
# 1. uses the concept of Threaded Binary Tree 
  
    #     1
    #    / \   
    #   2   3 
    #  / \   
    # 4   5    
    #      \ 
    #        6
    
    # Benefit of Morris traversal is it uses no extra space. Unlike the recusive solution where we took O(n) time and O(n) recursive stack space,
    # morris traversal essentially iterate the binary tree in O(n) time and O(1) space.
    # So no extra space required.
    
    # Inorder follows: Left root Right
    # In the recursive approach, we move from 1 to 2 and then to 4. 
    # 4s left is null, we print 4 and then we move right which is also null
    # and then we come back to 2(since left part is done). We print 2 and then we move to the right subtree.
    # we were able to come back to 2 because of the backtracking. Recursion maintains that information.
    
    # How do we come back to 4. That's the main problem. There is no parent pointer, and thus there is no way you can come back to 2.
    # and We cannot have a parent pointer definitely, because a binary tree as we know only has 2 pointers left and right
    
    # One thing to observe is we always need to move from the last guy of the left subtree to the root.
    # so here the last guy is 4, so we need to move back to 2.
    # similarly if we talk about the left subtree of 1, the last guy (as in last guy in the inorder traversal of that subtree)
    # is 6, so we need to move back to 1 from 6.
    
    # We're not going to introduce any additional parent pointer. 
    # The pattern which exists here, from the last guy in the left subtree, we move to the root.
    
    # 1st case: left is null.
        # we start from 1 and straightaway move to right. once we move to right, we don't need to comeback to 1.
        #     1
        #    /  \  
        #   Null 2
        # so , I will just print(root) and then move right
        
    # 2nd case:
        # before moving left, we need to connect the rightmost guy in the left subtree with root.
        # because once we move left, there is no way you could come back to root, since we are using an iterative approach.
        # what is the rightmost guy on the left subtree?
            # rightmost_on_left = root.left
            # if rightmost_on_left:
            #     while rightmost_on_left.right:
            #         rightmost_on_left = rightmost_on_left.right
            
            # Now I'm at the rightmost guy in the left subtree. Connect it right pointer to root
            # rightmost_on_left.right = root    
            
        # so the conculusion is, if you are standing at root, first connect the rightmost guy on the left subtree to root, and then move left.
        # This way you will be able to come back to root.
        
        # But once you comeback, how do you determine that I have again came back to root & this time I need to move right?
        # This thread was created temporaily, until we reach back to root. Once I again come back to root and if the thread exists, 
        # then I will delete that thread(yes, we can't keep that thread permanently, it was just a hack so that we can move back to root).
        # so once we come back, we delete this thread and move right.
        
            #     1\
            #    / \ \
            #   2   3 /
            #  / \    /
            # 4   5  /  
            #     \ /
            #     6/
            
            # PS: that extra thread from 6 pointing to 1 is the one which we created temporarily
            
            
  # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        curr = root
        
        def get_rightmost_guy_on_left_subtree(root):
            left = root.left
            if left:            # if the left node exists
                # need to add this condition as well in order to avoid infinite loop: left.right != root
                while left.right and left.right != root:   # we keep on moving right until it exists
                    left = left.right
            return left     # Now I'm at the rightmost guy in the left subtree. Connect it right pointer to root
            


        while curr :
            rightmost_guy = get_rightmost_guy_on_left_subtree(curr)
            
            # case 1 : rightmost_guy exists and it's right is pointing to curr: 
            # this means we have already visited the left subtree and now we need to move right.
            # but before we move right, we need to delete that temp thread or link that we created. It was just a temporary thing
            if rightmost_guy and rightmost_guy.right == curr: 
                rightmost_guy.right = None                          # deleting the temp link
                curr = curr.right       
                
            # case2: rightmost guy exists, but it is not connected to curr.
            # This means, we haven't visited the left subtree yet. so we move left.
            # But before we do that, add that temp link between the rightmost guy and curr
            elif rightmost_guy:         # need to use elif here
                rightmost_guy.right = curr # creating the temporary thread
                res.append(curr.val)
                # and now I can move left
                curr = curr.left
            
            # case 3: rightmost guy doesn't exist (on the left subtree). we simply move right
            else:
                # if righmost guy doesn't exist, we simply print curr and move right
                res.append(curr.val)
                curr = curr.right
            
            
        
        return res

    
    # TC: O(n)
    # SC: O(1)
    # THis is the most efficient solution for preorder traversal.
    # Requires no extra space. We solved it iteratively

    
    # cls scorecard --> gets you shipped records
    # if the order is shipped it should be present in cls scorecard.
    # orders that are not shipped
    #     sales order (contains all shipped + unshipped)
    #     delivery where sales order is not in cls_scorecard
    #     shipment 

    # otherwise you get all the data from the 3 tables.
    # GBS has the capability to overwrite the 

    # kna scm is sap system
    # sc_planner field in matrl_mstr
    # Is this field tied to matrl?

    # where matrl_type_cd = 'FERT'
    # check with business if they need the planner name description using sc_planr_id