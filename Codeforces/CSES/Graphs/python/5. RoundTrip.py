def construct_path(sp, ep, mp, path) -> None:
    path.append(sp)
    path.append(ep)
    curr = mp[ep]
    while curr != sp:
        path.append(sp)
        curr = mp[curr]
    path.append(curr)
    

def dfs(node, parent, adj, vis, path, sp, ep, mp) -> bool:
    vis[node] = True
    mp[node]  = parent
    for nb in adj[node]:
        if not vis[nb]:
            if dfs(nb, node, adj, vis, path, sp, ep, mp):
                return True
        elif vis[nb] == True and nb != parent:
            sp = nb
            ep = sv
            construct_path(sp, ep, mp, path)
            return True
        
    return False

    
     

def main():
    n,m = map(int,input().split())
    adj = [[] for _ in range(n+1)]
    for _ in range(m):
        u,v = map(int,input().split())
        adj[u].append(v)
        adj[v].append(u)
        
    vis = [False] * (n + 1)
    path = []
    mp = {}
    sp, ep = -1, -1
    
    for i in range(1, n + 1):
        if not vis[i]:
            if dfs(i, -1, adj, vis, path, sp, ep, mp):
                ans = True
                break
    
            