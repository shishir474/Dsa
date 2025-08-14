import sys

# python's default recursion limit is 1000, we need to increase it for large graphs
# especially for deep recursion in DFS
# this is a common practice in competitive programming to avoid recursion limit errors
# but be careful with very large graphs as it can lead to memory issues
sys.setrecursionlimit(10**6)

def dfs(node, vis, adj):
    vis[node] = True
    for nb in adj[node]:
        if not vis[nb]:
            dfs(nb, vis, adj)
        

def main():
    n, m = map(int, input().split())
    # create an adjacency list for n nodes 1-based indexing
    adj = [[] for _ in range(1,n+1)]
    for _ in range(m):
        u,v = map(int,input().split())
        adj[u].append(v)
        adj[v].append(u)    
    
    vis = [False] * (n + 1)
    newRoads = []
    count = 0
    for i in range(1, n + 1):
        if not vis[i]:
            dfs(i, vis, adj)
            newRoads.append(i)
            count += 1
            
    print(count - 1)
    for i in range(1, len(newRoads)):
        print(newRoads[0], newRoads[i])
        
if __name__ == "__main__":
    main()
