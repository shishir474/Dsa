from collections import defaultdict

# Intuition:
# if you have a neigbour which is already visited then that nb should be your parent because
# that is where you came from. If the nb node is not your parent, then you have a cycle in your graph.


class Solution:    
    def helper(self, sv, parent, vis, adj):
        vis[sv] = True                          # marking node visited

        for nb in adj[sv]:                      # checking all neighbours
            if not vis[nb]:
                if self.helper(nb, sv, vis, adj):   # IMP: if recursion returns true - we return true, cycle found
                    return True       
            elif nb != parent:      # base condition
                return True
                        
        
        return False                            # didn't find any cycle
    
        
        
    def isCycle(self, V, edges):
        adj = defaultdict(list)
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        vis = [False]*V
        
        # IMP: check for all the components
        for i in range(V):
            if not vis[i]:
                if self.helper(i, -1, vis, adj): return True       # found cycle in this component


        return False                        # checked all components, didn't find any cycle
    
    
    
    # SC: O(n) for recursive stack space + O(n) for vis []. 
    # not taking into account the space required for adj list
    
    # TC: O(N + 2*E) + O(N) for dfs traversal
    # we're performing a dfs traversal of the graph. Each vertex is visited once,
    # and each edge is explored at most twice (once from each endpoint, since it's an undirected graph).
    # each node is visited once --> O(V)
    # each edge is explored atmost twice (undirected graph) --> O(2 * E) = O(E)
    # DFS is only called once per component
    