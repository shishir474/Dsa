# same problem -- just using bfs

# bfs --> level order traversal
# we'll need to use deque / queue

# idea is whenever we push any node to deque we mark it as visited.
# we will start with root
# and we will track node and its parent both. Just like we did in recursive dfs solution.
# same approach

# and ofcourse, we need to check for all the components


from collections import deque, defaultdict
class Solution:
    def isCycle(self, V, edges):
        adj = defaultdict(list)
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        vis = [False]*V
        
        def helper(sv):
            dq = deque([(sv, -1)])       # node, parent
            vis[sv] = True
            
            while dq:
                node, parent = dq.popleft()
                
                for nb in adj[node]:
                    if not vis[nb]:
                        vis[nb] = True
                        dq.append((nb, node))
                    elif nb != parent:
                        return True
            
            return False
        
        # check for all the components
        for i in range(V):
            if not vis[i]:
                if helper(i): 
                    return True
                
        return False
    
    # TC: O(V + E)
    # we will visit each node once --> O(V)
    # we will process each edge atmost twice 
    # (once from each endpoint, since it's an undirected graph -> O(2 * E)
    # Overall O(v + 2*E)
    
    # SC: O(V) for vis[] + O(V) for queue. In worst case, queue might have V elements
    # I'm ignoring the space required for adj list.