class Solution:
    def get_all_bridges(self, V, edges):
        from collections import defaultdict
        adj = defaultdict(list)
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        
        # low[] is used to keep track of the lowest possible time by which we can reach that node (except parent)
        # so that if the edge from parent is removed, can that node be reached by any other path?
        # low[node] = min(low[all it's adjacent nodes except parent])
        
        # tin[] is the time of insertion of the node. It is the first time we have reached that node.
        
        # track parent
        
        # I have 3 possible cases:
        # nb == parent --> skip that nb
        
        # nb is not visited --> call dfs on that nb and once dfs call completes, update low[node] as min(low[node], low[nb]) and check if the edge (node -> nb) is a bridge
        # condition to check bridge: if low[nb] > tin[node] --> it's a bridge
        # bridge simply means -- it is the only route thru which I can reach the nb & thus if we remove that edge, the no of components is going to increase.
        
        # nb is visited:
            # update low[node] as min(low[node], tin[nb]) -- because nb is already visited, so we can reach nb in tin[nb] time.
        
    
        self.timer = 0
        tin = [-1]*V
        low = [-1]*V    
        vis = [False]*V
        bridges = []
        
        def dfs(node, parent):
            vis[node] = True
            tin[node] = low[node] = self.timer
            self.timer += 1
            
            for nb in adj[node]:
                if not vis[nb]:
                    dfs(nb, node)       # dfs call
                    low[node] = min(low[node], low[nb]) # once dfs call completes, update low[node] as min(low[node], low[nb])
                    if low[nb] > tin[node]:   # bridge detection
                        bridges.append((node, nb))
                else:
                    if nb != parent:
                        low[node] = min(low[node], tin[nb])
                
        
        # for all the components
        for i in range(V):
            if not vis[i]:
                dfs(i, -1)
        
        return bridges
    
    # TC: O(V + 2*E) -- which is the tc of standard dfs traversal.
    # SC: O(V) for tin[], low[], vis[] + O(V) for recursion stack in worst case (skewed tree) = O(V)