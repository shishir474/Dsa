class Solution:
    def bellman_ford(self, V, edges, src):
        dist = [float('inf')]*V
        dist[src] = 0
        
        for i in range(V-1):   # O(V)
            for u,v,wt in edges:    # O(E)
                if dist[u] != float('inf') and dist[u] + wt < dist[v]:
                    dist[v] = dist[u] + wt
        
        # check for negative weight cycle
        for u,v,wt in edges:    # O(E)
            if dist[u] != float('inf') and dist[u] + wt < dist[v]:
                return [-1]
        
        return dist