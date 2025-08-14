from collections import deque

def bfs(sv, adj, vis, color) -> bool:
    q = deque()
    q.append(sv)
    color[sv] = 0
    vis[sv] = True
    while q:
        f = q.popleft()
        for nb in adj[f]:
            if not vis[nb]:
                q.append(nb)
                vis[nb] = True
                color[nb] = 1 - color[f]
            elif vis[nb] == True and color[nb] == color[f]:
                return False
            
    return True
            
    

def main():
    n, m = map(int,input().split())
    adj =  [[] for _ in range(n+1)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
        
    color = [-1] * (n+1)
    vis = [-1] * (n+1)
    ans = True
    
    for i in range(1,n+1):
        if not vis[i]:
            if not bfs(i,adj,vis,color):
                ans = False
                break
            
    if ans:
        for i in range(1, n + 1):
            if color[i] == 0:
                color[i] = 2

        for i in range(1, n + 1):
            print(color[i], end=' ')
    else:
        print("IMPOSSIBLE")
            
if __name__ == "__main__":
    main()