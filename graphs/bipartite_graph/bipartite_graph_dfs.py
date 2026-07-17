# definition of bipartite graph:

# A graph is called bipartite if you're able to color it using 2 colors in a way that no 2 adj nodes are assigned the same color.
# Then it's called bipartite.

# if you have an odd length cycle --> graph is not bipartite.

# essentially you will be able to create 2 sets (u and v) of vertices, and all the edges of 
# the graph would be between u &v and not within the same set.

from collections import defaultdict
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        adj = defaultdict(list)
        for i, sublist in enumerate(graph):
            for j in sublist:
                adj[i].append(j)
        
        n = len(graph)

        vis = [False]*n
        color = [-1]*n 

        def dfs(node, nc):       # node, node_color
            vis[node] = True
            color[node] = nc

            for nb in adj[node]:
                if not vis[nb]:
                    if not dfs(nb, 1 - nc):
                        return False
                elif color[nb] == nc:
                    return False
            
            return True


        # check for all components
        for i in range(n):
            if not vis[i]:
                if not dfs(i, 0):      # this component is not bipartite
                    return False

        return True             # all components must be bipartite