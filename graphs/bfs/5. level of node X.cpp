//Function to find the level of node X.x`
Given a Undirected Graph with V vertices and E edges, Find the level of node X. if X does not exist in the graph then print -1.
Note: Traverse the graph starting from vertex 0.
 

Example 1:

Input:

X = 4
0-1
0-2
1-3
1-4
2-5
4-5

Output:
2
Explanation:

We can clearly see that Node 4 lies at Level 2.

SOLUTION:
TO determine level of node only BFS CAN BE USED.
NOTE: DFS CANNOT BE USED HERE. ex; Take the above graph and apply dfs, will get WA. 

int nodeLevel(int V, vector<int> adj[], int X) 
{
    // code here
    vector<int> vis(V, false);

    queue<pair<int,int>> q;

    q.push({0,0}); // vertex, level

    vis[0]=true;
    
    while(!q.empty())
    {
        auto f=q.front();

        q.pop();

        int v=f.first, level=f.second;

        if(v==X) return level;
        
        for(int i: adj[v])
        {
            if(!vis[i])
            {
                vis[i]=true;
                q.push({i,level+1});
            }
        }
    }
    
    return -1;
    
}