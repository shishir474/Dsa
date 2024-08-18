class Solution:
    def __init__(self):
        self.vis = set()
        self.rec = set()

    def detectCycleDG(self, node, adj):
        self.vis.add(node)
        self.rec.add(node)
        for i in adj[node]:
            if i not in self.vis:
                if self.detectCycleDG(i,adj):
                    return True
            elif i in self.rec:
                return True
        
        self.rec.remove(node)
        return False

    # graph should be a DAG
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # construct the graph
        adj = {i: [] for i in range(numCourses)}

        # for lst in prerequisites:
        for lst in prerequisites:
            u,v = lst[0], lst[1] # v->u edge
            adj[v].append(u)
        
        print(adj)

        # check if it is dag
        for i in range(numCourses):
            if i not in self.vis:
                if self.detectCycleDG(i,adj):
                    return False
        
        return True
        