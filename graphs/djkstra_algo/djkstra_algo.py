from heapq import heappush, heappop
from collections import defaultdict
class Solution:
    # SSSP Algorithm -- single source shortest path
    # Returns shortest distances from src to all other vertices
    def dijkstra(self, V, edges, src):
        # build graph
        adj = defaultdict(list)
        for u,v,wt in edges:    # O(E)
            adj[u].append((v,wt))
            adj[v].append((u,wt))
            
        dist = [float('inf')]*V     # array initializatoin: O(V)
        pq = []                     # min heap based on first element of tuple
        heappush(pq, (0,src))       # O(logV)  storing (dist,node)        
        dist[src] = 0               # source / starting point
        
        while pq:
            d, node = heappop(pq)   # O(logV)  d --> is the dist/cost with which we have reachhed the node
            if d > dist[node]:      # d should be <= dist[node]
                continue
            for nb,wt in adj[node]:     # O(E)
                if d + wt < dist[nb]:
                    dist[nb] = d + wt
                    heappush(pq, (dist[nb], nb))    
                    
        return dist
                    
        #TC: Each edge can cause atmost one relaxation --> one push
        # So total E pushes and E pops
        # Time per push / per pop = O(logV)
        # Overall tc for the while loop becomes O(ElogV)
        # For dense graphs, E = V^2, making the complexity O(V^2logV). 
        # For sparse graphs, E < V, making the complexity O(ElogV)
        
        # SC: O(V) for dist[] + O(V) for pq
        # Overall SC: O(V)

        # The worst-case scenario often arises in fully connected graphs 
        # or graphs with many edges between each pair of vertices.



# NOTE: Djkstra's algo connection with directed and undirected graphs:
# Dijkstra's algorithm works for both directed and undirected graphs,
# provided all edge weights are non-negative.
        
# The core logic of Dijkstra's algorithm relies on exploring neighbors
# from the current node and updating distances if a shorter path is found. 
# This process is agnostic to the graph's directionality, as the algorithm 
# only needs to know which nodes are reachable from a given node. 
        
#NOTE: Key Requirement: Non-Negative Edge Weights 
# The crucial condition for Dijkstra's algorithm to work correctly is that 
# all edge weights must be non-negative. The algorithm's assumption that once
# a node is marked as "visited", its shortest path is finalized, holds true 
# only if there are no negative weights that could later lead to a shorter path
# If a graph contains negative edge weights or negative cycles, 
# Dijkstra's algorithm will fail to produce the correct shortest paths. 
# In such cases, the Bellman-Ford algorithm should be used instead