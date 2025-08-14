from collections import deque

def bfs(start, dest, vis, adj):
    n = dest
    q = deque()
    q.append(start) 
    vis[start] = True
    parent = [-1] * (n + 1)
    
    while(q):
        f  = q.popleft()
        if f == dest:
            path = []
            while f != -1:
                path.append(f)
                f = parent[f]
            return True, path[::-1]
        
        for nb in adj[f]:
            if not vis[nb]:
                vis[nb] = True
                parent[nb] = f
                q.append(nb)
    return False, []
    

def main():
    n, m = map(int,input().split())
    adj = [[] for _ in range(n+1)]
    vis = [False] * (n + 1)
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    found, path = bfs(1, n, vis, adj)
    if found:
        print(len(path))
        print(*path)
    else:
        print("Impossible")
        
if __name__ == "__main__":
    main()