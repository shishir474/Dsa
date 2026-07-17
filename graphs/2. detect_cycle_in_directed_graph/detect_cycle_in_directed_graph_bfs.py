# This is the famous Kahn's algorithm used to find the topological sort
# It also tells us whether the graph contains cycle or not.

# topological sort only exists if the graph is a DAG
# which means it should be directed, it should be acyclic (no cycles)

# topological sort concept is only applicable to DG. 
# finding a topo sort for UG doesn't makes sense.

# what is a topo sort?
# in a dag it allows us to generate a sequence such that,
# if there is an edge from vertex u --> v, then vertex u appears before vertex v in that sequence.

# now in this algo, we are using indegrees. Idea is all the nodes which have indegree = 0
# will serve as potential starting points.

# now as we process each node's nb, we reduce their indegree by 1 which simply means that we have processed that edge.
# and if the indegree of nb becomes 0 at any instance, we simply insert that nb in the queue.

# now if the graph doesn't contain any cycle, so in that case we should be able to visit all nodes.
# but if it has a cycle, we'll terminate early in this process.  

from collections import deque, defaultdict
class Solution:
    def isCyclic(self, V, edges):
        # building graph
        adj = defaultdict(list)
        
        indegree = [0] * V
        for u,v in edges:
            indegree[v] += 1
            adj[u].append(v)
        
        dq = deque()
        for i in range(V):
            if indegree[i] == 0:    # by considering all nodes with indegree = 0, we have covered all the components
                dq.append(i)        # all these nodes that have indegree = 0, my starting points
                
        res = []
        while dq:
            node = dq.popleft()
            res.append(node)
            
            for nb in adj[node]:
                indegree[nb] -= 1               
                if indegree[nb] == 0:
                    dq.append(nb)
                    
        # if we are not able to visit all nodes / terminated early --> we have a cycle and thus topo sort is also not applicable here
        if len(res) != V:       # which simply means, we were not able to visit all the nodes, we have a cycle
            return True
              
        # we don't have any cycles. res[] represents the topo sort
        return False    # Ideally, I should be able to visit all the nodes. If yes then there is no cycle
                        # no need of vis[], only indegree[] is required
                        
        
                        
