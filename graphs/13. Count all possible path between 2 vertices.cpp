Given a Directed Graph having V nodes numbered from 1 to V, and E directed edges. Given two nodes, source and destination, count the number of ways or paths between these two vertices in the directed graph. These paths should not contain any cycle.
Note: Graph doesnt contain multiple edges, self-loop, and cycles.


Example 1:

Input:
V = 5, E = 7
Edges of Graph = 
{0, 1}
{0, 2}
{0, 4}
{1, 3}
{1, 4}
{2, 4}
{3, 2}
source = 0 
destination = 4

Output: 4



SOlUTION:
Base case; if(source==destination) -> return 1;
mark visited sv=true;
explore all unvisited neighbours and get the count of paths from all neighbours
count+=solve(nb,dest,adj,vis);
unvisit sv // TO explore all paths we have to unvisit the vert4x otherwise we wont be able to explore all the paths
return cnt;


    
    // Function to count paths between two vertices in a directed graph.
    int dfs(int sv,int dest, vector<int> adj[], vector<int>& vis){
        if(sv==dest) return 1;
        
        int cnt=0;
        
        vis[sv]=1;
        
        for(int i: adj[sv]){
            if(!vis[i]){
                cnt+=dfs(i,dest,adj,vis);
            }
        }
        
        vis[sv]=0; // backtrack then only we can explore all paths
        
        return cnt;
    }


    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<int> vis(V,0);
        return dfs(source,destination,adj,vis);
    }