# why does the parent logic of UG fails in DG?

# 0 -> 1
# 1 -> 2
# 1 -> 3
# 3 -> 2

# Reason: 
#     From a node, we can have a path which when we explore will mark all the nodes 
#     visited in that path.
#     Now there can be an additional path (say in anticlockwise direction) which when we start 
#     exploring will lead us to those visited vertices. 
#     Now the visited vertex is not equivalent to the parent -- so our algo concludes that there is a cycle.
#     BUt that's NOT true. Why because we're talking about DG.
#     The edges need to be in one direction (either clockwise or anti clockwise) to form a cycle in DG.
    
    
# So now how can we detect a cycle in DG?
# we use rec_stack. 
# rec_stack keeps track of the vertices that we have considered in our current path
# when we land on a vertex, we mark it as visited and also add it to rec_stack.
# we check its neigbours.
# if the nb is not visited -- simple call recursion on that nb
# if the nb is visited and it is also part of rec_stack --> voila we have a cycle.
# why, because the node was visited and it is also part of rec_stack which simply means
# the node was already a part of our current path that we explored and we're are again coming back to it.
# which is basically the definition of a cycle.

# NOTE: while we backtrack, it is important to remove the node from rec_stack because it 
# is now no longer part of our path. 

# rec_stack could simply be a list of booleans where if it's true, the node is part of stack else not.

from collections import defaultdict
class Solution:
    def isCyclic(self, V, edges):
        adj = defaultdict(list)
        for u,v in edges:
            adj[u].append(v)        # it's a directed graph
            
        vis = [False] * V
        rec_stack = [False] * V
        
        def helper(sv):
            vis[sv] = True
            rec_stack[sv] = True
            
            for nb in adj[sv]:
                if not vis[nb]:         # if nb not visited, call recursion on that nb
                    if helper(nb):
                        return True
                        
                elif rec_stack[nb]:     # nb is visited, is it also part of rec_stack?
                    return True         # if Yes, it means we have a cycle
            
            rec_stack[sv] = False       # backtrack
            return False
                
        
        for i in range(V):      # check all the componennts
            if not vis[i]:
                if helper(i):
                    return True
                
        return False
    
    # TC: helper/dfs function will called once per component.
    # at a given node, we're exploring all it's neighbours
    # each node is processed once --> O(V)
    # each edge is processed exactly once --> O(E)
    # Overall, O(V + E)
    
    # SC: O(V) for vis[] + O(V) for rec_stack[] + O(V) recursive stack space 
    # Overall, O(V)
    
    