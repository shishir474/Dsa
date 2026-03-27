# maximum path sum can be between any 2 nodes
# it might not pass also pass thru root

# What could be the brute force solution here
# checking the distance between every possible pairs. 
# if the tree has n nodes, then we'll have n^2 pairs and then it will take a bit more time 
# to compute the path sum between a pair. The solution has already crossed n^2. Not worth wile.

# lmrps - left max root path sum.
#     meaning: in the left subtree, what is the max root path sum.
#     root path sum is the sum of node values in a straight path which might or might not end at leaf.
#     node values can be -ve. Hence going till leaf node might not always be the best choice
    
# rmrps - right max root path sum
#     in the right subtree, what is the max root path sum. 
#     root path sum means sum of node values in a straight path. No V shape.
    
# ans_for_curr_root - signifies the best value possible at this curr node. 
# now of course, we take root.val into consideration.
# adding lmrps makes sense only if it's +ve.
# same with rmrps        

# Idea is we compute max path sum at each node and then track the global maximum
# ans_for_curr_root stores the ans for current root

# self.ans = max(self.ans, ans_for_curr_root)
# comparing the ans for curr root with global max and updating accordingly.

# what value to return?
# best_path_sum_for_curr_root - This simply signifies what is the best possible from the curr root, 
# extending in only one direction (left or right).
# It is also possible that path may not extend beyond root, if max(lmrps, rmrps) < 0

# We're trying to form the inverted V structure across each node -- to get the max path sum at each node
# and then compare that with global ans
# Now this path will always contain root. But it's not necessary that left and right branches both are added to root.
# It might happen that neither of them are added or only one of them is added
# only add if they are positive.

# key takeaway:
#     we're standing at root, what is the max path sum thru this root.
#     in order to compute this, lets first get the lmrps and rmprs i.e left_max_root_path_sum & right_max_root_path_sum
#     ans_for_curr_root definitely includes root.data. Add lmrps & rmrps only if they are +ve
#     got the best ans for curr node. Compare it with global max and update ans.
#     Now what to return? best_path_sum_for_curr_root
#     best_path_sum_for_curr_root definitely includes root.data.
#     Extend in either left or right direction depending on whichever side has larger value. 
#     We basically need a straight path. Now it migth also be possible that both left & right are contributing -ve values.
#     in that case only take root.data and ignore both left and right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = float('-inf')        # -inf because mps might be negative
        
        def dfs(root):
            if not root:
                return 0
            
            lmrps = dfs(root.left)
            rmps = dfs(root.right)
            
            # calculating the mps thru this root
            ans_for_curr_root = root.val                # take root    
            if lmrps >=0:                                # add lmrps only iff it's +ve
                ans_for_curr_root += lmrps
            if rmps >= 0:                               # add rmps only iff it's +ve
                ans_for_curr_root += rmps
            
            self.ans = max(self.ans, ans_for_curr_root) # tracking max path sum across all roots

            # value to return
            best_path_sum_for_curr_root = root.val          # could be only root
            if max(lmrps, rmps) >= 0:                        # extending makes sense only if max(left,right) is >= 0
                best_path_sum_for_curr_root += max(lmrps, rmps)  # otherwise it reduces the root's value
                
            return best_path_sum_for_curr_root
        
        dfs(root)

        return self.ans