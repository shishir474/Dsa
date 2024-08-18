# https://www.geeksforgeeks.org/problems/alien-dictionary/1

# chr(97) = 'a'
# ord('a') = 97


class Solution:
    def __init__(self):
        self.vis = set()
        
    def dfs(self, node, adj, s):
        self.vis.add(node)
        for i in adj[node]:
            if i not in self.vis:
                self.dfs(i,adj,s)
        s.append(node)
        
    def findOrder(self,alien_dict, N, K):
    # construct graph
        adj = {i:[] for i in range(K)}
        
        for i in range(N-1):
            s1, s2 = alien_dict[i], alien_dict[i+1]
            for j in range(min(len(s1),len(s2))):
                if s1[j] != s2[j]:
                    adj[ord(s1[j])-97].append(ord(s2[j])-97)
                    break
        
    # Perform Topo sort
        s = []
        for i in range(K):
            if i not in self.vis:
                self.dfs(i,adj,s)
        s = list(reversed(s))            
        # print(s)
        
        ans=""
        for i in s:
            ans+=chr(i+97)
            
        return ans


