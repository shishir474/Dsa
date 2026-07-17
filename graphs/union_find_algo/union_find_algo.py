class Solution:
    def find(self, x):      # O(α(V)) for find with path compression
        if self.parent[x] == -1:
            return x
        self.parent[x] = self.find(self.parent[x])     # path compression
        return self.parent[x]
    
    def union(self, px, py):  # O(1) for union by rank      
        # union by rank
        if self.rank[px] > self.rank[py]:
            self.parent[py] = px
        elif self.rank[px] < self.rank[py]:
            self.parent[px] = py
        else:
            self.parent[py] = px
            self.rank[px] += 1
    
    def detect_cycle(self, edges, V):
        self.parent = [-1]*V
        self.rank = [0]*V

        for u,v in edges:
            u_par = self.find(u)
            v_par = self.find(v)
            if u_par == v_par:
                return True
            self.union(u_par, v_par)
        return False
# TC: O(E * α(V)) where α is the inverse Ackermann function, which grows very slowly and is practically constant for all reasonable values of V.
# SC: O(V) for parent[] and rank[] arrays.
# NOTE: Union Find Algo is used to detect cycle in undirected graph. It can also be used to find connected components in a graph, and to check if two vertices are in the same component.
# It is not used for cycle detection in directed graphs, because the concept of "parent" is not well-defined in directed graphs. For cycle detection in directed graphs, we typically use DFS with a recursion stack or Kahn's algorithm for topological sorting.

# function initialization vs constructor initialization:
# #NOTE: in function initialization, we are initializing the parent[] and rank[] arrays inside 
# the detect_cycle function. This means that every time we call detect_cycle, we will be re-initializing these arrays.
# This is fine if we are only calling detect_cycle once, but if we need to call it multiple times, 
# it would be more efficient to initialize these arrays in the constructor of the class, so that they are only
# initialized once when the object is created, and can be reused across multiple calls to detect_cycle.

# NOTE: Union Find algo is not applicable to directed graphs. It is fundamentally designed for UGs as it relies on the
# concept of bidirectinality. Union operation inherently treats connections as a two way, symmetric relationship 
# (i.e if A is connected to B, B is connected to A)
# In a DG, the edge A->B is different from the edge B->A. Union find cannot distinguish this directionaliy within 
# its disjoint set data structure.
# Appplying Union Find for cycle detection in DG can lead to False Positives.
# THe algo might group the nodes into the same set based on reachability but without respecting the edge direction,
# which is crucial for DG.