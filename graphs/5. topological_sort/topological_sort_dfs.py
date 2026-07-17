# Better approach
# asymptotically this is an optimal solution.
# But we are doing 2 full dfs traversals which is really not required
class Solution:
    def detect_cycle(self, adj, V):
        vis = [False]*V
        rec_stack = [False]*V
        
        def helper(sv):
            vis[sv] = True
            rec_stack[sv] = True

            for nb in adj[sv]:
                if not vis[nb]:
                    if helper(nb):
                        return True
                elif rec_stack[nb]:
                    return True

            rec_stack[sv] = False
            return False
            
        
        # cover all the components
        for i in range(V):
            if not vis[i]:
                if helper(i):
                    return True         # detected a cycle

        return False                    # no cycle found


    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # topo sort is only applicable to DG
        # and in order to find topo_sort of a DG, it should be acyclic.
        adj = defaultdict(list)
        for u,v in prerequisites:
            adj[v].append(u)
        
        if self.detect_cycle(adj, numCourses):      # cycle detected, topo sort doesn't exist
            return []

        
        vis = [False]*numCourses
        s = []          # stack
        
        def helper(sv):
            vis[sv] = True
            for nb in adj[sv]:
                if not vis[nb]:
                    helper(nb)
            s.append(sv)                # once we reach deadend, push sv into stack
            
        
        # cover all the components
        for i in range(numCourses):
            if not vis[i]:
                helper(i)
                
        res = []
        while s:
            res.append(s.pop())
            
        return res
    


    
# Optimal approach

# in one single dfs traversal, we are checking for cycles
# and we are also building topo sort.

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # topo sort is only applicable to DG
        # and in order to find topo_sort of a DG, it should be acyclic.
        adj = defaultdict(list)
        for u,v in prerequisites:
            adj[v].append(u)
        
        vis = [False]*numCourses
        rec_stack = [False]*numCourses
        s = []          # stack
        
        # combined both steps: cycle detection in dfs and topo sort generatoin
        def helper(sv):
            vis[sv] = True
            rec_stack[sv] = True
            for nb in adj[sv]:
                if not vis[nb]:
                    if helper(nb):
                        return True
                elif rec_stack[nb]:         # nb visited, is it also part of rec_stack?
                    return True             # if yes, cycle detected

            s.append(sv)                # once we reach deadend, push sv into stack
            rec_stack[sv] = False       # backtrack
            return False                # cycle not found
        
        # cover all the components
        for i in range(numCourses):
            if not vis[i]:
                if helper(i):           # if helper() --> True, cycle detected
                    return []           # topo sort not possible
                    
            
        res = []
        while s:
            res.append(s.pop())
            
        return res
    
    
    # TC: O(V + E) -- one full dfs traversal
    # SC: O(V) for vis + O(V) for rec_stack + O(V) for res + O(V) for recursion_stack space
    # overall O(V)