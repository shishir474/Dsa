class Solution:
    def floyd_warshall(self, V, edges):
        # initialize distance matrix
        dist = [[float('inf')]*V for _ in range(V)]
        
        # dist matrix initialization
        for i in range(V):          # distance from a node to itself is 0
            dist[i][i] = 0
        
        for u,v,wt in edges:    
            dist[u][v] = wt
            dist[v][u] = wt   # for undirected graph
        
        
        # Floyd Warshall Algorithm
        for k in range(V):      # intermediate vertex
            for i in range(V):  # endpoint vertex 1
                for j in range(V):  # endpoint vertex 2
                    if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        
        return dist
    
    # TC: O(V^3) due to the three nested loops iterating over all pairs of vertices and the intermediate vertex.
    # SC: O(V^2) for the distance matrix that stores the shortest path between all pairs of vertices. 
    
# Why does Floyd Warshall work?
# The algorithm relies on the principle of optimal substructure, meaning:

# If the shortest path from i to j passes through some vertex k, then the path from i to k and the path from k to j must also be shortest paths.
# The iterative approach ensures that by the time vertex k is considered, all shortest paths using only vertices 0 to k-1 have already been computed.
# By the end of the algorithm, all shortest paths are computed optimally because each possible intermediate vertex has been considered.

