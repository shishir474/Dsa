
// 1. Creating graph via adj list
vector<int> adj[n+1]
vector<vector<int>> adj(n+1); // SC: will be O(2*E) each edge belongs to 2 vertices 
// for directed graph SC: O(E) 

for(int i=1;i<=n;i++){ // 1 based nodes indexing 
    int u,v;  cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// ------------------------------------------------

// 2. Weighted graph
vector<pair<int,int>> adj[n+1];
vector<vector<pair<int,int>>> adj(n+1)

// ------------------------------------------------

// 3. BFS
// initial configuration
// Create a queue and push the src vertex
// Create a vis array and mark the src visited
vector<int> vis(n+1, false);
queue<int> q;
q.push(src);
vis[src] = true;

// Actual BFS starts: Keep taking out from the queue until its empty
while(!q.empty()){
    int f = q.front(); 
    q.pop();
    cout<<f<<endl;

    // explore all the neighbours of f
    for(auto itr: adj[f]){
        if(!vis[itr]){ 
            vis[itr] = true;
            q.push(itr);
        }
    }
}


// calling bfs on all the components 
for(int i=1;i<=n;i++){
    if(!vis[i]){
        bfs(src)
    }
}

// SC for BFS: 
// O(N) for vis array 

// TC for BFS
// while loop will run N times, each node will be processed exaclty once and the inside for loop run for total of all its degrees which is 2*E
// Total Deg = 2*E
// TC; O(N)+O(2*E)



// ----------------------------------------------------------------------


// 4. DFS
void dfs(int src){
    vis[src]=true;
    for(auto itr: adj[src]){
        if(!vis[itr]){
            dfs(itr)
        }
    }
}

vector<int> vis(n,0);
for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i);
    }
}

// Let's talk about the space complexity: How many nodes are we visiting. We will be visiting all the n nodes exaclty ones
// O(n) for vis + O(n) rec stack space(skewed graph) =  approx O(N)
// Time Complexity
// the dfs function is called exaclty ones for all n nodes. Inside dfs, we are exploring all the neighbours of the current node, which is basically equivalent to its degree. 
// So for all nodes, it will be summation of degree of all the node which is nothing but 2*E for undirected graph
// FOr undirected graph, sum of degree for whole graph = 2*E
// O(N) + (2*E)
// For directed graph the second component will change depending on the number of edges


// ----------------------------------------------------------------------


// Q.1 Number of Provinces
void dfs(){

}

vector<int> vis(n+1, false);
for(int i=1;i<=n;i++){
    if!vis[i]){
        dfs(i,adj, vis);
    }
}

// Time and space complexity analysis
// SC: O(n) for vis + O(n)+ rec stack space
// TC: O(n) + O(V+2E): THis for loop will run n times. The dfs calls are not made for all the vertices. Each call will have a tc of O(V+2E)
// so it is approximately O(n)+O(v+2e)


// --------------------X--------------------X-----------------------X------------------



// Q.2 Number of Islands : 
// Create a vis matrix of size n*m. Call dfs on the first unvisited cell which is marked 1. The number of traversal dfs has been done is equivalent to the number of islanda
// One optimisation that we could do is instead of marking the cell visted in the vis matrix, I can replace 1 with some different character which is not present in the matrix

// PSUEDO code
void dfs(int i, int j, mat){
    mat[i][j]='$';
    for(int k=0;k<4;k++){
        int newi = i+X[k], newj = j+Y[k];
        if(newi>=0 and newi<n and newj>=0 and newj<m and mat[newi][newj]==1){
            dfs(newi,newj,mat);
        }
    }
    // no need to backtrack/revert the change, we need this change to exist for keeping track of visited cells
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(mat[i][j]==1){
            dfs(i,j,mat);
        }
    }
}

// By changing the char we are modifying the input which is actually not desired, but we are saving O(n*m) space for vis matrix
// Appparently the number of times dfs/bfs is called will determine the number of islands. 

// TC: O(n*m) 
// SC: O(n*m) recursive stack space  

// --------------------X--------------------X-----------------------X------------------

// Q.3 Flood Fill
// Can do both DFS or BFS to perform flood fill on the matrix. Given initial row and col, you can move in 4 directions, convert all the cells to the given value int he input. But only those cells can be converted that has same initial color\
// Best practise: Create a copy of the input and perform flood fill on that. Do not alter/tamper the input

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& image, vector<vector<int>>& ans, int oc, int newColor){
        ans[i][j] = newColor;
        for(int k=0;k<4;k++){
            int newi = i+X[k], newj=j+Y[k]; // cell within boundaries and input matrix new coord has original color and ans matrix new cord is not colored yet
            if(newi>=0 and newi<N and newj>=0 and newj<M and image[newi][newj]==oc and ans[newi][newj]!=newColor)
                dfs(newi,newj,image,ans,oc,newColor);
        }
    }
public:    
    int N,M;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // if the input negibour contains the original color and in the ans matrix if it is not colored with newColor, then call dfs
        vector<vector<int>> ans = image; // not tampering the input matrix, instead create a copy
        int n=image.size(),m=image[0].size();
        N=n;
        M=m;
        int oc = image[sr][sc];
        dfs(sr,sc,image,ans,oc,color);
        return ans;
    }
};

// TC: O(n*m): In the worst case, the entire matrix needs to be colored with the new color, and since each cell is processed exaclty once
// SC: O(n*m) for ans matrix, we will not tamper the input data/matrix + O(n*m) rec stack space which can take n*m space if all the cells are covered with Original Color

// Doubt: if we in case change the input, why do we need vis matriz? DONE: We dont need vis matrix. By changing the input in place we are making sure that we are not going back to the already visited cell.
// we changed the source cell to new color. Now we look for its neighbours, basically those that has same original color. we call dfs on them. 
// now when you're standing at neighbour, the cell from which you came was already marked with newcolor, so this will automatically not considered
// Condition that we need to check:
    // if the cell is within boundary of matrix and matrix[newi][newj]==oc
// On edge case while using this approach is if the newcolor is same as the original color, then we don't do anythin and straight away return the image
// Not handling this edge case will cause dfs to stuck in cycle and will give TLE, which was happening till now

int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int oc, int nc){
        int n=image.size(), m = image[0].size();
        image[i][j] = nc;

        for(int k=0;k<4;k++){
            int newi=i+X[k], newj=j+Y[k];
            if(newi>=0 and newi<n and newj>=0 and newj<m and image[newi][newj]==oc){
                dfs(newi,newj,image,oc,nc);
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(), m = image[0].size();
        int oc=image[sr][sc];
        if(oc!=color)
            dfs(sr,sc,image,oc,color);
        return image;
    }
};



// --------------------X--------------------X-----------------------X------------------


// Q.4 Rotten Oranges
// BFS Usecase: WHen we want to explore all the neighbours simaltaneously, then we use bfs traversal

class Solution {
public:
// edge cases: rotten present but fresh are absent -- handled by code
// rotten absent but fresh present -- handled by code
// rotten absent and fresh absent 
// both rotten and fresh present. -- handled by code
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m = grid[0].size();

        queue<pair<int,int>> q;

        bool ones_found=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    ones_found=true;
            }
        }

    // edge case;rotten absent and fresh absent 
        if(q.empty() and ones_found==false) return 0;

        set<pair<int,int>> vis;

        int X[]={-1,0,1,0};
        int Y[]={0,1,0,-1};

        int timer=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newi = i+X[k];
                    int newj = j+Y[k];
                    if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==1 and vis.count({newi,newj})==0){
                        vis.insert({newi,newj});
                        q.push({newi,newj});
                    }
                }
            }
            timer++;
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis.count({i,j})) return -1;
            }
        }

        return timer-1;
    }
};

// TC: O(n*m) In worst case we might have to call bfs from each cell if all the cells have value=2
// SC:O(n*m) in worst case vis set might have to store all the elements of the matrix

// Solution 2: using distance

int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m = grid[0].size();

        queue<pair<int,pair<int,int>>> q;

        bool ones_found=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,{j,0}});
                }
                else if(grid[i][j]==1)
                    ones_found=true;
            }
        }

    // edge case;rotten absent and fresh absent 
        if(q.empty() and ones_found==false) return 0;

        set<pair<int,int>> vis;

        int X[]={-1,0,1,0};
        int Y[]={0,1,0,-1};

        int ans=0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();

            ans = max(ans, dist);

            for(int k=0;k<4;k++){
                int newi = i+X[k];
                int newj = j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==1 and vis.count({newi,newj})==0){
                    vis.insert({newi,newj});
                    q.push({newi,{newj,dist+1}});
                }
            }

        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis.count({i,j})) return -1;
            }
        }

        return ans;
}




// --------------------X--------------------X-----------------------X------------------


// Q.5 Detect cycle in an undirected Graph using BFS

// NOTE: ALways remember if the connectivity info is not mentioned, alwasy assume the graph to be disconnected.

bool checkCycleUsingBfs(int src, vector<int> adj[], int n, vector<bool>& vis){
    // I will start a bfs from this src and check if this component has cycle
    queue<pair<int,int>> q; // {parent, node}
    q.push({-1,src});
    vis[src]=true;

    while(!q.empty()){
        int parent = q.front().first;
        int node = q.front().second;
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]]){ // if the nb is not visited, mark it vis and push it into the queue
                vis[adj[node][i]] = true;
                q.push({node, adj[node][i]});
            }
            else if(vis[adj[node][i]]==true and adj[node][i]!=parent) // if the mneoghbour is already visited then it shold be it's parent, then only we dont have a cycle. If it's some other node, then we have a cycle
                return true;
        }
    }

    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(int i=0;i<edges.size();i++){
        int a=edges[i][0], b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    for(int i=1;i<=n;i++){ // assuming the graph is disconnected
        if(!vis[i]){
            if(checkCycleUsingBfs(i,adj,n,vis)) return "Yes";
        }
    }

    return "No";
}


// TC: O(V+2*E) + O(N) tc for simple bfs traversal. 
// Why 2*E, bcoz for every node you are traversing for all its adjacent nodes and adj nodes is nothing but degree.
// Summation of all adj nodes is equivalent to summation of degree which is 2*E in undirected graph
// O(N) factor for covering all components. It will not be multiplied bcoz the call will not be made for all the nodes 

// SC:O(V) for vis array




// Q.10 Detect Cycle using DFS in an Undirected graph
// The parent logic to detect cycle only works in case of undirected graph. In UG, a neighbour can be visited and not equal to its parent and still may not for the Cycle



class Solution {
  private:
    // Function to detect cycle in an undirected graph.
    bool detectCycleUsingDFS(int src, int parent, vector<int> adj[], int V, vector<bool>& vis){
        vis[src] = true;
        for(auto nb: adj[src]){
            if(!vis[nb]){
                if(detectCycleUsingDFS(nb,src,adj,V,vis)) return true;
            }
            else if(nb!=parent)
                return true;
        }
        
        return false;
    }
    
  public:
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                // if this component has a cycle
                if(detectCycleUsingDFS(i,-1,adj,V,vis)) return true;
            }
        }
        
        // if none of the components have cycle 
        return false;
    }
};


// TC: Processed all nodes and edges which is O(V+E)
// SC: O(V) for color + O(V) for recursive stack space which is approx O(V)


// --------------------X--------------------X-----------------------X------------------


// Q.6 Distance of nearest cell having 1

// Given a binary grid, you have to compute the shortest distance from 1 for each cell

// Solution 1: uses visited array: This is the recommended solution as it gives more clarity
vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        
        vector<vector<int>> ans(n, vector<int>(m,0)); // stores the shortest dist from 1
        vector<vector<bool>> vis(n,vector<bool>(m,false)); // keeps track of vis vertex
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,{j,0}});
                    vis[i][j]=true;
                }
            }
        }
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
    
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second.first;
            int dist=q.front().second.second;
            
            ans[i][j]=dist;
            
            q.pop();
            
            for(int k=0;k<4;k++){
                int newi=i+X[k];
                int newj=j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m and !vis[newi][newj]){
                    vis[newi][newj] = true;
                    q.push({newi,{newj,dist+1}});
                }
            }
            
        }
        
        return ans;
        
        
        
    }

// SOlution 2:
// without using vis array: Basically intialiase the ans matrix with 1e9 for each cell
// Insert all the cells with cell value=1 in queue and mark their values in ans cell as 0
// Now start processing elements from queue. Element will be of form (i,j) coordinates
// explore its neighbours(valid ones which are within the boundary of the matrix) and check if the 1+cost_curr < cost_nb
// If the condition is true: update the cost_of_nb and push the cell into the queue
// if(valid cell + ans[i][j]+1 < ans[newi][newj]){
    // ans[newi][newj] =  ans[i][j] + 1;
    // q.push({i,j});
// }
// This condition prevents us from revisiting the already vis vertex: why let's see an example: Assume your are coming from cell A to B. Now while standing at B, you wont go back to A. THe new cost for A isn't better than its prev cost and hence we will not go back to already visited vertex

// SOlution 2 : without visited vertex
    
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        
        vector<vector<int>> ans(n, vector<int>(m,1e9)); // stores the shortest dist from 1

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
    
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int newi=i+X[k];
                int newj=j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m and ans[i][j]+1 < ans[newi][newj]){ // ans[i][j]+1 < ans[newi][newj] THis condition will help us prevent visit the already visited vertex
                    ans[newi][newj] = 1 + ans[i][j];
                    q.push({newi,newj});
                }
            }
            
        }
        
        return ans;
                
    }

// TC: of both approaches is O(n*m)
// SC: of both approaches is O(n*m)


// --------------------X--------------------X-----------------------X------------------

// Q.7 Replace O's with X's
// Given a matrix that contains O's and X's. Replace all the O's that are surropunded by X's in all 4 directions;

// SOlution: 
// Call dfs from all the cells that contains O's and are at boundary. This way you will mark all the O's connected with boundary as visited
// Now whichever O's were not visited, are not connected to boundary and are surrounded by X. Replace all these O's
// The set of O's which are not connected to boundary are bound to be surrounded by X

int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

class Solution{
private:
    void dfs(int i, int j, vector<vector<char>>& mat, vector<vector<bool>>& vis){
        int n = mat.size(), m =mat[0].size();
        
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int newi = i+X[k];
            int newj = j+Y[k];
            if(newi>=0 and newi<n and newj>=0 and newj<m and mat[newi][newj]=='O' and !vis[newi][newj])
                dfs(newi,newj,mat,vis);
        }
    }
    
public:
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> input)
    {
        // code here
        vector<vector<char>> mat = input; // operate on the copy, do not alter the input
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' and !vis[i][0])
                dfs(i,0,mat,vis);
            if(mat[i][m-1]=='O' and !vis[i][m-1])
                dfs(i,m-1,mat,vis);
        }
        
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' and !vis[0][i])
                dfs(0,i,mat,vis);
            if(mat[n-1][i]=='O' and !vis[n-1][i])
                dfs(n-1,i,mat,vis);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' and !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
            
    }
};

// TC: O(n*m)
// SC: O(n*m)


// --------------------X--------------------X-----------------------X------------------

// Q.8 Number of enclaves
// Given a binary matrix where 1 represents land and 0 represents water
// You have to count the number of land cells which are not connected to boundary

// SOlution
// Call dfs from all the 4 boundaries, cells which contains 1's and mark all those cells as visited
// Now whichever cells that has 1 and is not visited, it means they are not connected to boundary, otherwise they would have been visited
// Count those 1 which are not visited and return the count

// BFS based solution: similar logic. For BFS we need to identify the starting points and push them into queue. Our starting points are cells that are at boundary with vlaue 1

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        vector<vector<bool>> vis(n, vector<bool>(m,false));

        for(int i=0;i<n;i++){
            // left col
            if(grid[i][0]==1 and !vis[i][0]){
                vis[i][0] = true;
                q.push({i,0});
            }
            // right col
            if(grid[i][m-1]==1 and !vis[i][m-1]){
                vis[i][m-1] = true;
                q.push({i,m-1});
            }
        }

        for(int i=0;i<m;i++){
            // top row
            if(grid[0][i]==1 and !vis[0][i]){
                vis[0][i] = true;
                q.push({0,i});
            }
            // bottom row
            if(grid[n-1][i]==1 and !vis[n-1][i]){
                vis[n-1][i] = true;
                q.push({n-1,i});
            }
        }

        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int newi = i+X[k];
                int newj = j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==1 and !vis[newi][newj]){
                    vis[newi][newj]=true;
                    q.push({newi,newj});
                }
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j])
                    cnt++;
            }
        }

        return cnt;

    }   
};

// TC: O(n*m)
// SC: O(n*m)


// --------------------X--------------------X-----------------------X------------------


// Q.9 Number of distint islands
// Given a boolean grid which contains 0's and 1's you have to count the distinct number of islands
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Output:
// 1
// Explanation:
// grid[][] = {{1, 1, 0, 0, 0}, 
//             {1, 1, 0, 0, 0}, 
//             {0, 0, 0, 1, 1}, 
//             {0, 0, 0, 1, 1}}
// Same colored islands are equal.
// We have 2 equal islands, so we 
// have only 1 distinct island.

// Example 2:

// Input:
// grid[][] = {{1, 1, 0, 1, 1},
//             {1, 0, 0, 0, 0},
//             {0, 0, 0, 0, 1},
//             {1, 1, 0, 1, 1}}
// Output:
// 3
// Explanation:
// grid[][] = {{1, 1, 0, 1, 1}, 
//             {1, 0, 0, 0, 0}, 
//             {0, 0, 0, 0, 1}, 
//             {1, 1, 0, 1, 1}}
// Same colored islands are equal.
// We have 4 islands, but 2 of them
// are equal, So we have 3 distinct islands.

// If we are able to store the shape of islands in set, then our set size will be our ans. but how to figure out the shape.  

// The challenge is how do we store the shape of an island, so that if we get the same island in the future, we won't include that in the count

// For an island, subtract the base coordinate from all the coordinates and perform dfs. Also store the dfs traversals in a path vector.
// Maintain a set, which will keep track of unique paths

// Base coordinate is the starting point of our dfs traversal 

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
        
class Solution {
  private:
    int n,m;
    void dfs(vector<vector<int>>& grid,int start_x, int start_y, int i, int j, vector<vector<int>>& vis, vector<pair<int,int>>& path){
        vis[i][j]=true;
        path.push_back({i-start_x, j-start_y}); // main step: subtract the base coordinate from all the coordinates 
        
        for(int k=0;k<4;k++){
            int newi = i+X[k];
            int newj = j+Y[k];
            if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==1 and !vis[newi][newj])
                dfs(grid,start_x,start_y,newi,newj,vis,path);
        }
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        n = N;
        m = M;
        
        vector<vector<int>> vis(n,vector<int>(m,false));
        
        set<vector<pair<int,int>>> unique_paths;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    vector<pair<int,int>> path;
                    dfs(grid,i,j,i,j,vis,path);
                    unique_paths.insert(path);
                }
            }
        }
        return unique_paths.size();
        
        
    }
};


// TC: O(n*m*log(n*m)) + O(n*m*4)
//  (n*m*log(n*m)) -> for the for loop and set insertion
//  and dfs would be O(n*m*4)

// SC: O(n*m) for vis + o(n*m) for set
// set will store all the elements of the grid in the worst case



// --------------------X--------------------X-----------------------X------------------



// Q.10 Bipartite graphs using BFS

// Cover the graph with 2 colors such that none of the adjacent nodes have the same color
// The graph can be disconnected; In that case all the components should be bipartite to call the entire graph bipartite
// We dont need vis array. Color array will be sufficient.
// Color array tracks if a vertex is colored and it would be if and only if it is visited. Unvisited vertex cannot be colored

// NOTE:
// Graphs with no cycle are always bipartite, we can always color
// Graphs that contains odd length cycle are not bipartite
// even cycle length graph is also bipartite



class Solution {
private:
    bool isBipartiteUtil(int src, vector<int>& color, vector<vector<int>>& adj){
        // will use BFS to check if bipartite, color - (0,1)
        queue<int> q;
        color[src]=0;
        q.push(src);

        while(!q.empty()){
            int f = q.front();
            int curr_color = color[f];
            q.pop();
            for(auto nb: adj[f]){
                if(color[nb]==-1){ // if neighbour not colored, color it with different color
                    color[nb]=1-curr_color;
                    q.push(nb);
                }
                else if(color[nb] == curr_color){ // if neighbour is colored and is of the same color as adj node, the graph is not bipartite
                    return false;
                }
            }
        }

        return true;

    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }

        
        // graph may not be connected: all the componnents must be bipartite to call the entire graph bipartite
        vector<int> color(n,-1); 

        // Don't need vis array, color array will compensate the need of vis.
        // if a node is not colored, it means it is not visited. Else it would have been colored
    
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!isBipartiteUtil(i,color,adj))   
                    return false;
            }
        }

        // checked all the components and all are bipartite
        return true;

    }
};

// TC: BFS Traversal --> O(V+E). The code will process all the nodes and edges 
// SC: O(V) for color array + O(V) for queue => Overall O(V)



// --------------------X--------------------X-----------------------X------------------



// Q.10 Bipartite graphs using DFS
// If not stated, assume the graph to be disconneted and you will have to call the dfs/bfs for each component
// No need of vis array, we are using color vector which will indirectly help us keep track of visited vertices
// Vertices not colored, means they are not visited, and colored means visited


// Recursive part is interesting: 
// I have 2 options: if the recursion return true -> then return true 
// else if recursion return false --> then return false
// Which one to pick?
// Now if you pick 1st option even assume a case where your node has 2 neighbours a and b: a was colored with opposite color, but b was uncolored. So you called recursion on b
// Now the recursion call from b return false, even though your child recursive call returned false, you would eventually return true. The for loop will process all the neighbours, and since the if condition(1st one recursion call wali) failed, at the end you will end up returning false

// Now if you choose to pick 2nd option: which is if recursion return false we will return false.
// The last point will be you are standing at a node where all your negibours are colored and even if one of them is wrongly colored you will return false.
// You will check all the neighbours and if all are rightly colored you will return true at the end of the for loop

// Take example:
// A pentagon graph with 5 vertices and 5 edges which is not bipartite, remove one edge and you will have another graph which is bipartite


class Solution {
private:
    bool isBipartiteUtil(int src, int curr_node_color, vector<int>& color, vector<vector<int>>& adj){
        // will use DFS to check if bipartite, color - assign curr_color to src node in the color array
        color[src]= curr_node_color;

        for(auto nb: adj[src]){
            if(color[nb] == -1){// neighbouring node is not colored, color it
                if(!isBipartiteUtil(nb, 1-curr_node_color, color, adj)) return false;
            }
            else if(color[nb] == curr_node_color) // neighbouring node has the same color as the curr node
                return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }

        
        // graph may not be connected: all the componnents must be bipartite to call the entire graph bipartite
        vector<int> color(n,-1); 

        // Don't need vis array, color array will compensate the need of vis.
        // if a node is not colored, it means it is not visited. Else it would have been colored
    
        // if the node is not colored, call dfs on that component
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!isBipartiteUtil(i,0,color,adj))   
                    return false;
            }
        }

        // checked all the components and all are bipartite
        return true;

    }
};

// TC: Processed all nodes and edges which is O(V+E)
// SC: O(V) for color + O(V) for recursive stack space which is approx O(V)





// --------------------X--------------------X-----------------------X------------------

// Q.11 Detect cycle in a directed graph

// used sets to keep track of vis: reason -> requirement is to check if an element is present or not -> set is the best ds, remove the element -> set suits best
// normal set was giving TLE, so used unordered_set.
// We can use vectors as well in place of set. Intially both vis and recstack vector will be initialised with false.

// Intuition:
// insert the node in vis and recstack which means marking it as visited and it is now part of the current path
// Generally your nb will be unvisited, so you will call recursion on that
// but if the nb is visited and is part of the recstack as well -> then it means we have a cycle
// If we reach a dead end, we remove the node from recstack indicating that it is no longer part part of the path, and return false. Not removing from vis, bcoz the vertex will remain visited, no matter what. It's just that since it is no longer a priority for us, we are removing it from the recstack 


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclicUtil(int src, unordered_set<int>& vis, unordered_set<int>& recstack, vector<int> adj[], int V){
        vis.insert(src);
        recstack.insert(src);
        for(auto nb: adj[src]){
            if(vis.count(nb)==0){
                // if nb not visited, call recursion
                if(isCyclicUtil(nb,vis,recstack,adj,V)) return true;
            }
            else if(recstack.count(nb)==1)
            // if nb is visited and nb is part of recstack as well, return true
                return true;
        }
        
        // remove the src node, it is no longer a part 
        recstack.erase(src);
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_set<int> vis, recstack;
        for(int i=0;i<V;i++){
            if(vis.count(i)==0){
                // if this component has a cycle return true
                if(isCyclicUtil(i,vis,recstack,adj,V)) return true;
            }
        }
        
        // No components have cycle
        return false;

    }
};

// TC: Processed all nodes and edges which is O(V+E)
// SC: O(V) for color + O(V) for recursive stack space which is approx O(V)



// --------------------X--------------------X-----------------------X------------------

// Q.12 Eventual Safe states: Using DFS

// Given an disconnected directed graph, You have to return a list of all the safe node
// A node is called a safe node if all possible paths starting from that node ends at a terminal node
// A node is a terminal node if it has an outdegree of 0 i.e no outgoing edges

// Observation
// A node which is a part of a cycle or is leading to a cycle is not a safe node

// Intuition
// Similar to detecting cycle in a directed graph
// Start from a node, mark it visited, and mark it pathVisited. Explore its neighbours. 2 possiblilies: Node not visited or is visited
// If node is not visited, call recursion 
// If visited, check if it also part of pathVisited. if yes, then there is a cycle & this node can never be a safe node. So without adding it to the ans vector return true
// If we have explored all the neighbours and not returned true yet, then it means we don't have a cycle and this is a safe node
// Save the node in the ans vector and remove it from the pathVisited & then return false



class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& recstack, vector<int> adj[], int V, vector<int>& ans){
        vis[node]=true;
        recstack[node]=true;
        
        for(auto nb: adj[node]){
            // when the node has not been visited
            if(!vis[nb]){
                if(dfs(nb,vis,recstack,adj,V,ans)) return true;
            }
            // if the node has been visited and is part of recstack as well -> found a cycle
            else if(recstack[nb]==true)
                return true;
        }
        
        // node is a safe node. All safe nodes are stored in ans
        ans.push_back(node); 
        recstack[node]=false;
        return false;
    }
  public:
  // every node which is a part of a cycle and is connected(leading) to the cycle are not safe nodes
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,false), recstack(V,false);
        
        // ans will store all the safe nodes
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,recstack,adj,V,ans);
            }
        }
        
        // return all safe nodes in sorted fashion
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// TC: Processed all nodes and edges which is O(V+E)
// SC: O(V) for vis + O(V) for recursive stack space + O(V) for ans array which is approx O(V)




// --------------------X--------------------X-----------------------X------------------

// Q.13 Topological sorting Using DFS

// The concept of Topo sort Is only valid for Directed Acyclic Graph
// Topo sort: is a logical arrangement of vertices such that if there is a edge from u to v, u must appear before v in the topological sort

// Why directed graph: well the statement says if there is a edge from u to v, u must appear before v in the topological sort.
// Now if the graph would have been undirected, then it wouldn't have made much sense

// Why Acyclic graph: If the graph consists of a cycle, then this type of arrangement of vertices is practically not possible

// Hence Directed Acyclic Graph

// Intuition: 
// Once I reach a dead end, I store this vertex in the stack

class Solution
{
    private:
        void dfs(int src, vector<int>& vis, vector<int> adj[], int V, stack<int>& s){
            vis[src]=true;
            for(auto nb: adj[src]){
                if(!vis[nb]){
                    dfs(nb,vis,adj,V,s);
                }
            }
            s.push(src);
        }
        
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, false);
	    
	    // stack will store the topo sort
	    stack<int> s;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,adj,V,s);
	        }
	    }
	    
	    vector<int> res;
	    while(!s.empty()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    
	    return res;
	}
};


// TC: O(V+E) simple dfs call where we are processing all the nodes and edges of the graph. Edge node is processed exaclty once
// SC: O(V) for vis + O(V) for storing the topo sort + O(V) recursion stack space. Overall it is approximatley O(V)



// --------------------X--------------------X-----------------------X------------------

// Q.13 Topological sorting Using BFS: Kahn's Algorithm


// Key points
// BFS starts from nodes whose indegree is 0. So first calculate the indegree of each vertex and then push vertices whose indegree is 0 into the queue
// Now for each node in the queue, explore it's neighbours and reduce their indegree by 1.
// If neighbours indegree becomes 0, then push it into the queue

// Why start from vertices with 0 indegree?
// Assumme you start from a vertex that has an incomeing edge. But according to topo sort definition, the vertex from which the edge is incomeing should be placed first, which is contradicting our assumption
// Hence we always start from vertex that has no incoming edge

// This algo handles disconnected graph as well. No need to add for loop for handling disconnected components. 
// How does it handle that? Basically we check all the vertices of the graph and push those that has 0 indegree. So by covering all the vertices in this step, we are automatically covering all the components as well

// No need of vis array: Basically we start eliminating edges between vertices hypothetically, and when a vertex has no incoming edge left then we push that into the queue

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    // populate the indegree array
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            // i -> adj[i][j] directed edge
	            indegree[adj[i][j]]++;
	        }
	    }
	    
	    queue<int> q;
	
	    // there will be atleast 1 vertex with 0 indegree, if the graph is DAG
	    // No need of vis, This loop covers all the vertices which means all the disconnected components.
	    // Whichever node has 0 indegree, doesn't matter which component it belongs to is added to the queue
	    for(int i=0;i<V;i++){ // covers all the vertices of the entire graph
	        if(indegree[i]==0)
	            q.push(i);
	    }

        // someone will always have an indegree 0, since it is a DAG

        vector<int> res;   
	    // starting point for bfs is the node whose indegree is 0
	    while(!q.empty()){
	        int f=q.front();
	        q.pop();
	        res.push_back(f);
	        for(auto nb: adj[f]){
	            indegree[nb]--;
	            if(indegree[nb]==0)
	                q.push(nb);
	        }
	    }
	    
	    return res;
	}
};

// TC: O(V+E) simple BFS call where we are processing all the nodes and edges of the graph. Edge node is processed exaclty once, coz we are eliminating the edges once it is processed
// SC: O(V) for indegreee + O(V) for storing the topo sort. Overall it is approximatley O(V)



// --------------------X--------------------X-----------------------X------------------

// Q.14 Cycle Detection in a directed graph: Using BFS

// Variation: Cycle detection in undirected Graph using DFS -> simple dfs with parent
// Variation: Cycle detection in undirected Graph using BFS -> simple bfs with parent
// Variation: Cycle detection in directed Graph using DFS -> using vis and recstack vectors
// Variation: Cycle detection in directed Graph using BFS -> using Topo sort 

// We will use the concepts of Topo Sort: If we are able to generate a topo sort for the given graph, then it is a DAG which means no cycle, else we have a cycle

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> cycleDetectionInDirectedGraphUsingBFS(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    // populate the indegree array
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            // i -> adj[i][j] directed edge
	            indegree[adj[i][j]]++;
	        }
	    }
	    
	    queue<int> q;
	
	    // there will be atleast 1 vertex with 0 indegree, if the graph is DAG
	    // No need of vis, This loop covers all the vertices which means all the disconnected components.
	    // Whichever node has 0 indegree, doesn't matter which component it belongs to is added to the queue
	    for(int i=0;i<V;i++){ // covers all the vertices of the entire graph
	        if(indegree[i]==0)
	            q.push(i);
	    }

        // someone will always have an indegree 0, since it is a DAG

        vector<int> res;   
	    // starting point for bfs is the node whose indegree is 0
	    while(!q.empty()){
	        int f=q.front();
	        q.pop();
	        res.push_back(f);
	        for(auto nb: adj[f]){
	            indegree[nb]--;
	            if(indegree[nb]==0)
	                q.push(nb);
	        }
	    }

        // we were able to generate the topo sort: and hence the graph is acyclic
        if(res.size()==V) 
            return false;
        
        return true;
	    
	}
};

// TC: O(V+E) simple BFS call where we are processing all the nodes and edges of the graph. Edge node is processed exaclty once, coz we are eliminating the edges once it is processed
// SC: O(V) for indegreee + O(V) for storing the topo sort. Overall it is approximatley O(V)



// --------------------X--------------------X-----------------------X------------------

// Q.14 Preqrequisites task -- checking whether if we can fulfill all the prerequisites

// 2nd variation: return the possible sequence of tasks basically return the topological sort

// We can either use DFS or BFS to do this. Detect a cycle using DFS or BFS(Topo sort)

// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

class Solution {
private:
    bool dfs(int src, vector<int>& vis, vector<int>& pathVisited, vector<int> adj[], int N){
        vis[src]=true;
        pathVisited[src]=true;
        for(auto nb: adj[src]){
            if(!vis[nb]){
                if(dfs(nb,vis,pathVisited,adj,N)) return true;
            }
            else if(pathVisited[nb]==true)
                return true;
        }
        
        pathVisited[src] = false;
        return false;
    }
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    
	    // construct graph
	    for(int i=0;i<prerequisites.size();i++){
	        int a = prerequisites[i].first;
	        int b = prerequisites[i].second;
	        adj[b].push_back(a);
	    }
	    
	        
	   // check if we are able to produce a Topo sort, which means we need to check if the graph is acyclic
	   
	   // detecy cycle in directed graph using DFS
	   vector<int> vis(N,false), pathVisited(N,false);
	   for(int i=0;i<N;i++){
	       if(!vis[i]){
	           // if found cycle 
	           if(dfs(i,vis,pathVisited,adj,N)) return false;
	           
	       }
	   }
	   
	   // None of the components has a cycle, which means the topo sort is possible
	   return true;
	    
	}
};




// --------------------X--------------------X-----------------------X------------------

// Q.15 Eventual safe states using BFS

// A safe node is a node, from where all possible paths lead to a  terminal node
// A terminal node is a node, that has no outgoing edges

// Directed graph and using BFS --> think of kahn's algorithm
// If you apply kahn's on the given graph and insert all indegree 0 nodes into the queue as starting configuration, you will not be able to cover the entire graph --> take an example and see
// Instead reverse all the edges of the given graph, and then apply kahn's algo. Whatever nodes you were able to cover, are all safe nodes

// The idea of reversing the edges of the graph comes from the fact that, in your original graph, the terminal nodes(which has no outgoing edges) are your starting points, but in order to start from that point, you will have to reverse the edges of the graph
// Hence reverse the graph and then apply Kahn's algo

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int> indegree(V,0);
        
        // construct reverse graph
        vector<int> adj_rev[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                int u = i, v = adj[i][j];  // u to v edge
                // i to adj[i][j] edge
                adj_rev[v].push_back(u); // In reverse graph, v to u edge
                indegree[u]++;
                
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> ans;

        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            
            // apply logic on reversed graph
            for(auto nb: adj_rev[f]){
                indegree[nb]--;
                if(indegree[nb]==0)
                    q.push(nb);
            }
        }
        
        
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};

// TC is Similar to topo sort
// TC: O(V+E)
// Extra overhead of storign the reverse graph 
// SC: O(V+E) for storing rev graph + O(V) for indegree + O(V) for ans, which overall comes to O(V+E)



// --------------------X--------------------X-----------------------X------------------

// Q.16. Alien Dictionary - Topological Sort

// Given a list of sorted strings which is made using the first k characters in normal alphabets, you have to return the order of characters in the alien language.

// Input: 
// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}

// Here order of characters is 
// 'b', 'd', 'a', 'c' 

// Intuition:
// The questions says something before something (b->a, d->a, a->c, b->d)--> which leads us to topological sort algorithm
// If we are able to figure out between every pair, who is appearing before whom, who is the differentiating factor  why "baa" is placed before "abcd", that's because b < a.
// and if you create the DG, then the question boils down to finding the topo sort 
// In order to find out the first differentiating factor between i and i+1, you will run a loop till N-1 and compare each pair of words

// Solution:
// 1st step: Construct the graph -- Compare dict[i] and dict[i+1], & find the first different characters, say c1 and c2. Edge will be from c1 to c2 indicating c1 appears before c2 in the alien dictionary
// 2nd step: Perform topological sort to generate the ordering of characters which can be done using simple dfs or bfs

// The question states that order is always possible, but what if the order is not possible
// 2 cases
// First case: s1="abcd", s2="abc". If the larger string is appearing before the shorter and you found no differentiating factor then the order is not possible.
// Second case: Cyclic dependency - dict=["abc","bat","acd"] which means a<b and b<a
// These are the 2 checks that you have to integrate if the order is not guranteed and the solution will work absolutely fine


// NOTE:
// Use the DFS method for Topo sort, only when it is guranteed that the graph is acyclic. Bcoz, dfs works only when the graph is dag
// If not guranteed, use BFS approach. This way if at the end you are not ending up with all the vertices in your topo sort, it means you have a cyclic dependency and order is not possible

class Solution{
    private:
    void dfs(int src, vector<int> adj[], vector<bool>& vis, stack<int>& s){
        vis[src]=true;
        for(auto nb: adj[src]){
            if(!vis[nb]){
                dfs(nb, adj, vis, s);
            }
        }
        
        s.push(src);
    }
    public:
    string findOrder(string dict[], int N, int K) {
        
        // the question explicityly states that we will be dealing with only the first K characters
        vector<int> adj[K];

        // construct the graph
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int min_len = min(s1.length(),s2.length());
            
            for(int j=0;j<min_len;j++){
                // find the first non equivalent character
                if(s1[j]!=s2[j]){
                    // edge from s1[j] to s2[j]
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
            
        }
        
        // print graph
        // for(int i=0;i<K;i++){
        //     for(auto it: adj[i]){
        //         cout<<i<<" "<<it<<endl;
        //     }
        // }
        
        
        // Step 2: return the topo sort 
        
        // only first k characters will be there
        vector<bool> vis(K,false);
        stack<int> s;
        
        for(int i=0;i<K;i++){
            if(!vis[i])
                dfs(i,adj,vis,s);
        }
 
       
        string ans="";
        while(!s.empty()){
            // cout<<s.top()<<endl;
            ans+='a'+s.top();
            s.pop();
        }
        
        return ans;
        
    }
};

// TC: O(N*lenth_word) for constructing graph + O(K+N) for topo sort, K is the no of vertices and N is the number of edges that will be added in the worst case 
// SC: O(K) for vis + O(K) for stack + O(K) for recursive stack space, which overall is O(K)


// SOL2: Alien Dictionary Using BFS

class Solution{
    private:
    // works for multiple components and single vertices
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indegree(V,0);
        
        for(int i=0;i<V;i++){
            for(auto it: adj[i])
                indegree[it]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            ans.push_back(f);            

            for(auto nb: adj[f]){
                indegree[nb]--;
                if(indegree[nb]==0)
                    q.push(nb);
            }
        }
        
        return ans;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        // K is the number of characters, N is the number of words in dict list
        vector<int> adj[K];
        // construct the graph
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int min_len = min(s1.length(),s2.length());
            
            for(int j=0;j<min_len;j++){
                // find the first different character
                if(s1[j]!=s2[j]){
                    // edge from s1[j] to s2[j]
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
            
        }
        // Step 2: return the topo sort 

        vector<int> topo = topoSort(K,adj);
       
        string ans="";
        for(auto i: topo){
            ans+=i+'a';
        }
        
        return ans;
        
    }
};


// TC: O(N*lenth_word) for constructing graph + O(K+N) for topo sort, K is the no of vertices and N is the number of edges that will be added in the worst case 
// SC: O(K) for indegree + O(K) for storing topo sort in ans vector, which overall is O(K)




// --------------------X--------------------X-----------------------X------------------

// Q.17. Shortest Path in Directed acyclic Graph 

// Given a directed acyclic graph and a src node, find the shortest distance from the src to all nodes. If the node is not reachable, then print -1 for that node

// Solution
// 1st step: Find the topological sort
// 2nd step: Do the distance thing, basically relax the edges
    // create a dist array of N size, initialise the dist[src]=0 and for other nodes as INT_MAX or 1e9;
    // Now start processing nodes in fashion in which they are present in topo sort. By processing node, I mean for a given node,
    // if (dist[f]+wt < dist[nb]) 
    //      dist[nb] = dist[f] + wt;


// Intuition
// WHy topo sort? -- Striver
// Processing the nodes in topological order ensures that by the time you get to a vertex, you have already processed all the vertices that precedes it.
// Djkstra algo is necessary for graphs that contains cycles, because they can't be topologically sorted

// the first node of your topo sort should be your src? Is this true --> No it is not necessary. If this is the case then the worst that can happen is you will not be able to reach all the nodes, and their distance from the source will be infinity. Refer example 2
// The src can be any vertex, it doesn't matter. It's just that we will always start from the first vertex in topo sort, bcoz this is the vertex that has no incoming edges which means no one is present before it and by the time we reach a vertex, we would have already processed all the vertices preciding it

// We have processed the nodes sequentially based on their reachability. The nodes which are reachable first, I processed them first. This helped us to minimise the number of steps to O(V+E) - while loop part. This is much less than any standard algo. Djkstra takes more time than this
// The only reason it works is because we are processing nodes in topological fashion. So if I reach a node all its previous nodes, have been computed.

// The intution is if I'm reaching a node, all it's previous nodes has it answers computed


// NOTE:
// Since the qeustion stated, that the graph is a DAG, topological order is possible and we processed the nodes in that fashion
// If the DAG property wasn't mentionted better to use Djkstra to find the shortest path



// Example1  node -> <(nb,wt)>
// 0 -> <(1,2), (4,1)>
// 1 -> <(2,3)>
// 2 -> <(3,6)>
// 3 -> <>
// 4 -> <(2,2), (5,4)>
// 5 -> <(3,1)>


// Example2
// 0 -> <(1,2)>
// 1 -> <(3,1)>
// 2 -> <(3,3)>
// 3 -> <>
// 4 -> <(0,3),(2,1)>
// 5 -> <(4,1)>
// 6 -> <(4,2),(5,3)>



class Solution {
  private: 
  void topoSort(int node, vector<int>& vis, vector<pair<int,int>> adj[], stack<int>& s){
      vis[node] = true;
      
      for(auto it: adj[node]){
          int nb = it.first;
          if(!vis[nb])
            topoSort(nb, vis, adj, s);
      }
      
      s.push(node);
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // construct graph
        
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        stack<int> s;
        vector<int> vis(N,false);
        
        // call for each component
        // Simple DFS: O(N+M)
        for(int i=0;i<N;i++){
            if(!vis[i])
                topoSort(i,vis,adj,s);    
        }
        
        // Do the distance thing: basically start relaxing the edges
        vector<int> dist(N,1e9);
        //  0 is the source vertex: mentioned in the problem statement
        int src = 0;
        dist[src] = 0;
        
        // O(N + M)
        while(!s.empty()){  // the stack will contain N nodes
            int node = s.top();
            s.pop();
            for(auto it: adj[f]){ /// THis loop processess all the edges of each node, total of E edges processes across all N nodes, hence Total complexity becomes : O(N+M)
                int nb = it.first;
                int wt = it.second;
                if(dist[node]+wt < dist[nb])
                    dist[nb] = dist[node]+wt;
            }
        }
          
        for(int i=0;i<N;i++){
            // i was unreachable from src, hence it's distance was INT_MAX
            if(dist[i]==1e9)
                dist[i]=-1;
        }
        
        return dist;
        
        
        
    }
};

// TC: O(N+M) for topo sort + O(N+M) for distance thing. Overall it is O(N+M)
// O(N) for vis + O(N) for dist + O(N) for stack + O(N) for recusive stack space. Overall it is O(N)

// Can do the same using BFS as well




// --------------------X--------------------X-----------------------X------------------

// Q.18.Shortest path in Undirected Graph

// given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

// EX:
// edges = [(0,1),(0,3),(1,2),(3,4),(4,5),(5,6),(6,7),(7,8),(6,8),(2,6)]

// Simple BFS algo + edge relaxation

// Most Optimised solution
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        // will do simple bfs
        vector<int> dist(N,INT_MAX);
        
        dist[src]=0;
        
        // No multi component thing. Given just a single src, so whatever vertices could be visited, will be visited, rest will be marked infinity
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nb: adj[node]){
                // checking the distace condition is enought, no need of visited array. The condition automatically fails for visited vertices, hence not allowing us to go back to visited vertices 
                if(dist[node] + 1 < dist[nb]){
                    dist[nb] = dist[node]+1;
                    q.push(nb);
                }
            }
        }
        
        // dist for unreachable nodes would have been INF. mark dist for unreachable nodes as -1
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        
        return dist;
        
    }
};
// TC: simple BFS O(V+E) + O(V) + O(E). OVerall O(V+E)
// SC: O(V) for dist array + O(V) for queue. Overall O(V)

// Okay Solution: utilises extra visited array.
// Distance array is sufficient, no need of extra visited array. By using the dist array itself, we can prevent visiting the already visited vertices
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        // will do simple bfs
        vector<int> dist(N,INT_MAX), vis(N,false);
        
        
        dist[src]=0;
        
        queue<int> q;
        q.push(src);
        vis[src]=true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nb: adj[node]){
                if(!vis[nb]){ 
     // if the nb is not visited, we can straightaway update the dist[nb] as dist[node]+1. No need to check the distance conditino bcoz, we are following bfs and it is always guranteed to provide the shortest path. So if the nb is not vis, mark it visited, dist of nb will be dist of node + 1 and push the nb into the queue
     // extra overhead of maintaining vis array. We can handle not visiting the already visited vertices by using dist array only using condition (dist[node]+1 < dist[nb]). No need of extra vis array. This dist condition will always fail for visited vertices, hence prevents us from visiting the already visited vertices.
                    dist[nb] = dist[node]+1;
                    vis[nb]=true;
                    q.push(nb);
                }
            }
        }
        
        // dist for unreachable nodes would have been INF. mark dist for unreachable nodes as -1
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        
        return dist;
        
    }
};

// TC: simple BFS O(V+E) + O(V) For for loop  + O(E) For constructing graph. OVerall O(V+E)
// SC: O(V) for dist array + O(V) for vis array + O(V) for queue. Overall O(V)



// --------------------X--------------------X-----------------------X------------------

// Q.19. Word Ladder I - BFS

// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
// Keep the following conditions in mind:

// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList

// Note: If no possible way to transform sequence from startWord to targetWord return 0



// Start replacing char from a to z for each position and check if the word exists in the wordList. Set is the best ds to check if an element exists or not in O(1)
// Level by level traversal --> which algo? BFS
// Doesn't make much sense to go back to word that we have already visited earlier. This will only elongate the sequence. Hence used visited set to ensure that we never go back to already visited word.
// The use of visited can be avoided with the help of s. Just remove the word from s indicating that it has been visited, and it is no longer available in the future
// BFS guarantees the shortest path to each word that we are reaching. 

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        set<string> s(wordList.begin(),wordList.end());
        
        set<string> vis;
        
        queue<string> q;
        q.push(startWord);
        vis.insert(startWord);
        
        int steps=0;
        
        // O(wordList): the queue will store all the words in the wordList in worst case of direct neighbour
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string f = q.front();
                q.pop();
                
                if(f == targetWord) // This is the first time we have seen this word, and steps stores the min transformations required
                    return steps+1;
                
                // check it's all neigbhours: For each position, start replacing char from a to z
                // wordLength*26*log(n) -> log factor is for set. If used unoredered_set it will be O(1)
                for(int i=0;i<f.length();i++){
                    string prefix = f.substr(0,i);
                    string suffix = f.substr(i+1);
                    
                    for(char c='a';c<='z';c++){
                        if(f[i] == c) continue;
                        string new_f = prefix+c+suffix;
                        // if new_f is a neighbour and is not visited
                        if(s.count(new_f)==1 and vis.count(new_f)==0){ 
                            vis.insert(new_f);
                            q.push(new_f);
                        }
                    }
                    
                }
                
                
            }
            steps++;
        }
        
        
        // cannot reach targetWord, hence returning 0. 
        return 0;
        
              
    }
};


// TC: O(wordList * wordLength * 26 * log(n)) Logarithmic factor is for set. If used unordered_set, this factor will be reduced to 1
// SC: O(wordList) for queue + O(wordlist) for set + O(wordList) for vis. Overall O(wordList)

// Slightly different implmentation: Complexity remains the same.
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        set<string> s(wordList.begin(),wordList.end());
        
        set<string> vis;
        
        // Along with the word, also storing its transformationo steps side by side
        queue<pair<string,int>> q; // word, steps
        q.push({startWord,1});
       
        vis.insert(startWord);
       
        while(!q.empty()){
            string f = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(f == targetWord)
                return steps;
            
            // check it's all neigbhours: For each position, start replacing char from a to z
            for(int i=0;i<f.length();i++){
                string prefix = f.substr(0,i);
                string suffix = f.substr(i+1);
                
                for(char c='a';c<='z';c++){
                    if(f[i] == c) continue;
                    string new_f = prefix+c+suffix;
                    // if new_f is a neighbour and is not visited
                    if(s.count(new_f)==1 and vis.count(new_f)==0){ 
                        vis.insert(new_f);
                        q.push({new_f,steps+1});
                    }
                }
                
            }
        
        }
        
        
        // cannot reach targetWord, hence returning 0. 
        return 0;
        
    }
};




// --------------------X--------------------X-----------------------X------------------

// Q. 20. Word Ladder 2 - BFS MOST DIFFICULT PROBLEM OF BFS
// instead of returning the length of the shortest transformation seq from startWord to targetWord, you have to return all possible shortest transformation sequences of min length

// Key points
// Used a queue of type vector<string>. We will be storing sequences in the queue
// Will have to process the elements in a level wise manner.
// At a particular level, let's say I have m elements. Now for each elemnent's last word, I will find eligible neighbours, all this will create a new seq and push them into the queue
// Do not mark the eligible neighbours as visited, coz, they can also be an eligible neighbour for elements in the queue. mark the neighbours as visited only after processing all the elements at the current level
// ex startWord="bat", endWOrd="coz"
// wordList = <"pat","bot","pot","poz","coz">
// bat -> pat,bot
// pat -> pot
// bot -> pot

// bat -> pat -> pot -> poz -> coz
// bat -> bot -> pot -> poz -> coz

// vis => bat
// Now during the first iteration: <bat> was in the queue, and it pushed 2 new seqs <bat,pat> & <bat,bot>. While pushing I tracked the neighbours and once the entire level was I marked the tracked neighbours as visited

// vis => bat,pat,bot
// Level2: 2 elements in the queue <bat,pat> & <bat,bot>. pat has a neighbour pot which is not visited and is an eligible neigbour as well. Created a new seq <bat,pat,pot> & pushed it into the queue. Stored pot to be marked as visited later at the end of this level
// bot also has pot as an eligible neighbour. So created a new seq <bat,bot,pot> and pushed it into the queue. If we would have marked pot visited in the earlier iteration, we could have lost this seq. Hence it is necesaay to store all the neighbours and then mark them visited later after the level is processed



class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<vector<string>> ans;
        
        set<string> s(wordList.begin(),wordList.end());
        set<string> vis;
        
        queue<vector<string>> q;
        q.push({beginWord});
        vis.insert(beginWord);
        
        bool found=false;
        
        while(!q.empty()){
            int sz =q.size();

            vector<string> to_mark_vis; // tracks vertices that needs to be marked visited
            // THis vector needs to be maintained at a level wise fashion
              
            while(sz--){
                vector<string> f = q.front();
                q.pop();
                string lastWord = f[f.size()-1];
                
                if(lastWord==endWord){ // we have to return the no of seq at the current level which ends with endWord. WHy current level? bcoz this level will only produce the shortest seq. Sequences found at level higher than this are not eligible coz they are not shortest seq
                    ans.push_back(f); // found first seq
                    while(sz--){ // check other seq at the current level
                        if(q.front()[q.front().size()-1] == endWord)
                            ans.push_back(q.front());
                        q.pop();
                    }
                    found=true;
                    break;
                }
                    
                
                // possible transformations on lastWord
                for(int i=0;i<lastWord.size();i++){
                    // for each position, replace char from a to z
                    for(char c='a';c<='z';c++){
                        string prefix=lastWord.substr(0,i);
                        string suffix=lastWord.substr(i+1);
                        string new_word = prefix+c+suffix;
                        // if a possible neighbour word and is not visited yet: create a new seq and push it into the queue. Do not mark it visited yet. This could be used by some other sequence as well. Marking it visited, will cause in loosing that other seq
                        if(s.count(new_word) and vis.count(new_word)==0){
                            to_mark_vis.push_back(new_word);
                            vector<string> new_seq = f;
                            new_seq.push_back(new_word);
                            q.push(new_seq);
                        }
                    }
                    
                }
                
            }
            
            if(found) break;
            
            for(auto s: to_mark_vis)
                    vis.insert(s);
        }
        
        
     
        return ans;
        
    }
};


// --------------------X--------------------X-----------------------X------------------


// Q. 21 Djkstra Algorithm -- returns the shortest dist path from the source to all nodes in the graph(connected, weighted and undirected)
// Single Source Shortest Path Algorithm
// Assumptions
// a. Graph is undirected, weighted, & connected
// Graph must not contain negative weight. bcoz in that case, it will fall in infinite loop
// ex: 0 -> <{1,-2}> 

// adj list
// 0 -> <{1,4}, {2,4}>
// 1 -> <{0,4}, {2,2}>
// 2 -> <{0,4}, {1,2}, {3,3}, {5,6}, {4,1}>
// 3 -> <{2,3}, {5,2}>
// 4 -> <{2,1}, {5,3}>
// 5 -> <{3,2}, {2,6}, {4,3}>

// 2 ways to implement djkstra:
// 1. Using Priority Queue & 2. Using Sets(most optimised)
struct compare{
    bool operator()(pair<int,int>& p1, pair<int,int>& p2){
        if(p1.first==p2.first){
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    { // Using prirority queue

        // initial configuration: create a dist vector, initialise it with INF, mark the dist of the Src 0. Create a min heap of {dist,node} & push the src node with 0 dist in the heap
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq; // min heap {dist, node}
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> pq;  // Min heap can also be declared this way

        dist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if(dis+edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis+edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
        
        
    }
};


// TC: O(ELogV) where E is the total no of edges and V is total no of vertices
// Why a pq is used specifically? Why not a queue. Queues also works fine
// WHy pq? bcoz we want min dist node to be processed first


// Djkstra Implementation Using SET
// Advantage of using Set is you can erase already existing path.
// Does set improves the tc? Not very much. Depends on the graph
//  The erase operation is Logn in set. You are probably saving up iterations in the future, which might not be the case always, but you are also erasing which ends up taking a logarithmic factor
 // You are investing Logn and you probably are gonna save some iterations in the future. So you cannnot explicitly say if using set is a better idea, depends on the size of the graph, edges etc
//  Both of them can be used. There will be hardly minor difference
// Is set better in terms of tc from pq. There is not much of a difference


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
    { // Using prirority queue
        vector<int> dist(V, INT_MAX);
        set<pair<int,int>> s; // min heap {dist, node}
        
        dist[src] = 0;
        s.insert({0,src}); // set stores the elements in the ascending fashion with the smallest element at the top and values increases downwards
        
        while(!s.empty()){
            auto it = *(s.begin());
            int node = it.second;
            int dis = it.first;
            s.erase(it);
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if(dis+edgeWeight < dist[adjNode]) {
                    if(dist[adjNode] != INT_MAX)
                        s.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = dis+edgeWeight;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
        
        
    }
};


// Why priority queue. Normal queue also works
// Time complexity : ELogV derivation
// Intuition of djkstra algo
The advanatage of using a priority queue in djkstra over a normal queue is you will not process unwanted paths, which will effectively be much more efficient and fast. You will save on a lot of iterations
Queue causes us to process all paths which is kind of brute force, and then figuring out the minimal. With priority queue, we are following a greedy approach at each step to explore the paths
Queue will definitely give you an ans, but you will end up exploring lots of paths. With pq we were able to save up unnecessary iterations and paths

EX : graph
0 -> <{1,3}, {2,1}>
1 -> <{0,3}, {3,4}>
2 -> <{0,1}, {3,2}>
3 -> <{1,4}, {2,2}, {4,2}, {5,1}>
4 -> <{3,2}>
5 -> <{3,1}>

1. In Dijkstra's algorithm, a priority queue is preferred over a normal queue due to its efficiency in handling the vertex selection process. 
2. Purpose of Dijkstra's Algorithm
        Dijkstra's algorithm finds the shortest path from a source vertex to all other vertices in a graph with non-negative edge weights. The main steps involve:

        Initialization: Set the distance to the source vertex as zero and all other vertices to infinity.
        Vertex Selection: At each step, select the vertex with the smallest known distance that hasn't been processed yet.
        Distance Update: Update the distances to its neighboring vertices based on the edge weights.

3. Why Use a Priority Queue?
Efficient Vertex Selection:
    Priority Queue: It allows you to efficiently retrieve and remove the vertex with the smallest distance. Operations like insertion and extraction of the minimum element are logarithmic in complexity (O(log V)), where V is the number of vertices.
    Normal Queue: It does not support efficient retrieval of the smallest element. In a normal queue, you'd have to scan through all elements to find the one with the smallest distance, which is inefficient and has a linear time complexity (O(V)).

Reduction in Time Complexity:
    Using a priority queue (typically implemented as a binary heap), Dijkstra’s algorithm can be optimized to run in O((E + V) log V) time, where E is the number of edges and V is the number of vertices.
    Without a priority queue, the time complexity would be O(V^2), as finding the minimum distance vertex in a normal queue requires scanning all vertices.


/// Time complexity analysis - Refer strivers video G 34 graph series
Each vertex will go into the pq 
for each vertex, popping operation in pq which is O(heap_size) + processing the edges (which in worst case could be V-1 for densely connnected graph) and then inserting the new element in pq which is O(heap_size)

TC: =  O(V * (pop vertex from min heap + (no of edges in each vertex*push into priority queue)))
    => O(V * (log(heap_size) + (V-1)*log(heap_size)) )
    => O(V * (log(heap_size)(1 + V - 1)))
    => O(V * V * (log(heap_size)))

    Now what is heap size: Assume you started processsing, the starting vertex had 3 neigbhours and all of them were minimal, so pushed all its neighbours. Then came the next element, it also has 3 neighbours all minimal pushed all of them and so orangesRotting
    heap size in worst case is nothing but (V-1) + (V-1) + (V-1) + (V-1) + (V-1) +....V times   which is approx V^2. This is the hypothetically the absolute worst case that could happen
    =>  O(V^2 * log(V^2))
    =>  What is V^2 ==> It is equivalent to E. How? In a denseley connected graph where all vertices are connected to each other total no of edges will be 
        E = (V-1) + (V-1) + (V-1) + ... V times which is basically V*(V-1) = approximately V^2
    => O(E * 2logV)
    => O(ElogV)






// --------------------X--------------------X-----------------------X------------------

Q. 22 Shortest Path in Weighted undirected graph
// Given an undirected, weighted graph consisting of n vertices from 1 to n and m edges. you have to return the cost and the shortes path of from 1 to n
// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Constructing Graph
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        // main part: Djkstra 
        vector<int> dist(n+1,INT_MAX);
        vector<int> parent(n+1);
        dist[1] = 0; // dist of src will be 0
        parent[1] = -1; // parent of src vertex will be -1
        
        // min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1}); // {dist,node}
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(dis+edgeWt < dist[adjNode]){
                    dist[adjNode] = dis+edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
            
        }
        
        // Ans vector construction
        // have to return {cost, nodes in path}
        vector<int> ans;
        if(dist[n]==INT_MAX) // were unable to reach the target destination
            return {-1}; 
        
        ans.push_back(dist[n]); // adding cost of the path
        
        // lets construct the path
        vector<int> path;
        
        int curr = n;
        while(parent[curr]!=-1){
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        
        ans.insert(ans.begin()+1, path.begin(), path.end()); // adding nodes of the shortest path from src to n
        
        return ans;
    
    }
};

// TC: O(ElogV) for djkstra + O(V) for path constructioo




// --------------------X--------------------X-----------------------X------------------

Q. 23 Shortest distance in a binary maze {Refer Striver Video for any clarification}
https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

// Tags: [djkstra]

Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.

// for shortest path: we have BFS, Djkstra 
        
        // Do we need a priroity queue or a normal queue would suffice.
        // In the problem the edge weight is 1 for all the edges. Thus a normal queue would work, no need of priority queue. 
        // By taking a normal queue you would be saving the logn factor
        
        // But in djkstra we used pq because, there the edge weights was different.Thus a priority queue was needed to figure out the minimal edge wt
        // Here it doesn't matter coz all the edges has a edgewt of 1
        
        // SO rule of thumb is : If the egde weight is different for all the edges, using a pq makes sense because it will help us in finding the minimal wt node in O(1) time
        // But if the edge weight is same, normal queue is good enough. In fact by using the normal queue you will save logn factor which occurs in pq
        
        // Thus this problem can be solved via djkstra but using a queeu
        

// DP won't work as the value on any cell is path-dependent, so it won't work. It works in the maze which has two direction movements in the right and bottom, and the future cells would never be visited. Think about it by taking some examples. 

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n=grid.size();
        int m = grid[0].size();
        
        if(grid[destination.first][destination.second]==0) return -1;
        if(source.first==destination.first and source.second==destination.second) return 0;
        
        queue<pair<int,int>> q; // q or pq: since the edge weight is 1 for all the edges, q will be a better option. pq would have been a good option in case the edge weights were different. Also the advantage of using a q is you will save the logn factor which occurs in pq
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int sr = source.first;
        int sc = source.second;
        dist[sr][sc]= 0;
        q.push({sr,sc});
        
        int X[]={-1,0,1,0};
        int Y[]={0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            if(r==destination.first && c==destination.second) 
                return dist[r][c];
            q.pop();
            for(int k=0;k<4;k++){
                int newr = r+X[k];
                int newc = c+Y[k];
                // is it a valid neighbour
                if(newr>=0 and newr<n and newc>=0 and newc<m and grid[newr][newc]==1){
                    // is this a valid path
                    if(dist[r][c] + 1 < dist[newr][newc]){
                        dist[newr][newc] = dist[r][c] + 1;
                        q.push({newr,newc});
                    }
                }
            }
            
            
        }
        
        return -1;

}



// --------------------X--------------------X-----------------------X------------------

Q. 24 Path with minimum effort - [https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1]

You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the rout

// Tags: [Djkstra]

class MyTuple{
public:
    int diff;
    int i;
    int j;
    MyTuple(int d, int r, int c){
        diff = d;
        i = r;
        j = c;
    }
};

struct compare{
    bool operator()(MyTuple a, MyTuple b){
        return a.diff > b.diff;
    }
};

// Using custom class 
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<MyTuple, vector<MyTuple>, compare> pq;
        vector<vector<int>> dist(n, vector<int> (m,INT_MAX));
        dist[0][0] = 0;
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
        
        pq.push(MyTuple(0,0,0)); // mytuple{diff, i, j}
        while(!pq.empty()){
            int d = pq.top().diff;
            int r = pq.top().i;
            int c = pq.top().j;
            pq.pop();
            
            for(int k=0;k<4;k++){
                int newr = r+X[k];
                int newc = c+Y[k];
                if(newr>=0 and newr<n and newc>=0 and newc<m){
                    
                    int max_diff = max(abs(heights[newr][newc] - heights[r][c]), d);
                    
                    if(max_diff < dist[newr][newc]){
                        dist[newr][newc] = max_diff;
                        pq.push(MyTuple(max_diff, newr, newc));
                    }
                }
            }
            
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)
        //         cout<<dist[i][j]<<" ";
        //     cout<<endl;
        // }
        return dist[n-1][m-1];
        
    }
};

/// TC: of dkstra is ElogV. this is a grid. How many edges do we have in a grid. We have n*m cells and from each cell we can move in 4 directions. so n*m*4
V is the total num of vertices, which is in our case total num of cells that is n*m

so TC: n*m*4log(n*m)

// SC: O(n*m) for dist array + o(n*m) for pq.
// The pq will contain all the cells in the worst case



// Solution 2: Just a different way of implementation

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
       
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        
        pq.push({0,{0,0}}); // {diff,{i,j}}
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int d = it.first;
            int i = it.second.first;
            int j = it.second.second;
            
            if(i==n-1 and j==m-1) return d; // the first time we process this , we can return ans from here itself
            
            for(int k=0;k<4;k++){
                int newi = i+X[k];
                int newj = j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m){
                    int max_diff = max(abs(heights[newi][newj] - heights[i][j]), d);
                    if(max_diff < dist[newi][newj]){
                        dist[newi][newj] = max_diff;
                        pq.push({max_diff,{newi,newj}});
                    }
                }
            }
        }
        
        return 0;
    }
};




// --------------------X--------------------X-----------------------X------------------

Q. 25 Cheapest flights within K Stops 
// Tags: [djkstra]
https://www.youtube.com/watch?v=9XybHVqTHcQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=38

Djkstra problem with small modification -> cannot use djkstra directly because there can exist a path with a lower cost but it can't be taken bcoz it doesn't satisfy the stops requirements
There can exist a higher cost path which can lead us to the destination in <= K stops

hence distance cannot be our source of judgement. Here stops will be the deciding factor 

ex; [[0,1,5], [0,3,2], [3,1,2], [1,4,1], [1,2,5], [4,2,1]]  -- > {u,v,cost} u to v directed edge with edge weight of cost 
this is the sample graph, run simple djkstra on this and you will see why it fails
The cheaper cost path to 4 is 5 which is {0,3,1,4}. But when we see a path from {0,1,4} we are not able to use this path bcoz it costs us 6 bucks. Djkstra is discarding this path

// NOTE: Why Normal queue would work
// We dont need a pq bcoz we will store it in terms of {stops,{city,dist}}. Stops will always increase by 1. The increase is constant.
// If dist would have been the deciding factor and the edgeWt is not 1 for all the edges, pq would have been a better choice
// Here we are giving more weightage to stops & since the increase in stops is constant, no need of pq. normal queue would suffice
// by doing this we will be saving the logarithmic factor of pq
// problems where you can use queue for djkstra, you could also use pq. But the reverse isn't true. 
// In djkstra, if the edge wt is constant, use q, else use pq 

// Whenever you reach a dest do not stop. We could reach the dest in future with a better price.
// This is a valid question that should we stop at the first encounter of dest or should we continue processing the vertices.
// In some problems we stopped at the very first encouter of dst, whereas in this problem we will have to continue processing coz there is a possibility that in fuutre we could reacch at a better price

// If the dist[dst] == 1e9, it means it was unreachable and you could return -1
// else return dist[dst]
 

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].push_back({v,cost});
        }
        
        queue<pair<int,pair<int,int>>> q;
            
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        q.push({0,{src,0}}); // {stops,{city,cost}} stops will be our deciding factor
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int city = it.second.first;
            int d = it.second.second;
            
            if(stops > K) continue; // I have exhausted all the stops, doesn't matter if I'm at dst or not. If at dst, we will explore neighbours of dst and the stops will be K surely gretaer than K, which will automatically be dropped in the next iteratoin
            // If not at dst and the stops > K, we definately cannot take this path
            
            // I cannot return at the very first encounter of dst, bcoz we can get a better path at a later stage
            
            for(auto it: adj[city]){
                int nb = it.first, edgeWt = it.second;
                if(d+edgeWt < dist[nb]){ 
                    dist[nb] = d+edgeWt;
                    q.push({stops+1,{nb,d+edgeWt}});
                }
            }
            
        }
        
        if(dist[dst]==1e9)
        return -1;
        
        return dist[dst];
        
    }
};
 

// TC: for djkstra implemented using pq is ElogV. But since we are using q for implementing djkstra, the log factor will not be there. So time complexity is O(E)
// E is the total no of edges which is nothing but flights.size()
Hence TC: O(flights.size())

// SC: O(V+E) for adj list + O(V) for dist array + O(V) for queue
// V is n 
// E is flights.size()



// --------------------X--------------------X-----------------------X------------------

Q.26 Minimum Multiplications to reach End [https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0]
// Tags: [djkstra]

Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

// you have a src node and you want to reach a destination. 
// Now from a given node, you can reach nb nodes by multipleying array numbers. But the crux is multiplication operation is always followed by mod
// which means the value will always be in the range of [0,9999]
// So you have a fixed set of nodes. Initially from src, it took 0 steps
// Then nb from src takes +1 steps
// Then nb from those src nb takes +2 steps and so on

// The problme can be solved using a simple bfs, but we will use an additional dist array to avoid processing the same states again
// No need of vis, dist array will take care of it. Obviously if the node was visited earlier and now we are visiting it again, deifinitley we would take more steps as comapred to last time and it will not be added into the queue


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int src, int end) {
        // you have a src node and all your nodes will lie in range from [0,9999]
        // It means you have a finite set of nodes and you have a starting point
        // Djkstra would work
        // (0,3) - starting point (steps, node)
        // (1,6), (1,15), (1,21) is the next level
        // create a dist array initialsied with inf, initalise src with 0;
        // no need of pq, simple q will work because the increase in steps is constant. 
        
        const int mod = 1e5;
        queue<pair<int,int>> q;
        vector<int> dist(100000, 1e9); 
        dist[src] = 0;
        q.push({0,src});
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            int steps = f.first;
            int node = f.second;
            
            if(node == end) return steps;
            
               for(auto it: arr){
                if(steps+1 < dist[(node*it)%mod]){ // with this condition we avoid adding the same nodes that we have reached earlier with the same steps. So if the same nb is encoutered again, then it better should be reached in less steps as compared to last time, then only it will be added to the queue
                // hence dist array is imp to track the number of steps, so that in future if we again reach the same node with same steps, we won't add that pair into the queue
                // So its a simple bfs with an adiitional dist array to avoid processing the same states again -- Using this dist array, it makes the algo similar to djkstra
                    dist[(node*it)%mod] = steps+1;
                    q.push({steps+1, (node*it)%mod});
                }
            }
        }
        
        return -1;
        
        
    }
};

TC: O(E) log v factor is not there because we are using a queue 





// --------------------X--------------------X-----------------------X------------------

Q.27 number-of-ways-to-arrive-at-destination  [djkstra]

https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.


// Instead of finding the shortest path, we have to return the count of number of shortest path 

// In addition to dist array, also kept a ways array to track the number of shortest paths that leads us to a certain node


typedef long long ll;
class Solution {
  public:
  // djkstra 
  // we have to count the number of shortest path with the minimal cost
  // In addition to dist array, I'll also keep ways[] array that tracks the number of ways I can reach a particular node
  
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[n];
        for(auto it: roads){ // bidirectional edges 
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        const int mod = 1e9+7;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; // {dist,node}
        pq.push({0,0});
        vector<ll> dist(n,1e18);
        dist[0] = 0;
        vector<ll> ways(n,0); // no of ways of reaching a node at this point is taken as 0
        ways[0] = 1;
        
        while(!pq.empty()){
            ll d = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
        
            for(auto it: adj[node]){
                ll nb = it.first, edgeWt = it.second;
                // This is the first time I'm arriving at this node with this short distance
                if(d + edgeWt < dist[nb]){
                    dist[nb] = d+edgeWt;
                    pq.push({d+edgeWt, nb});
                    ways[nb] = ways[node];
                }
                else if(d + edgeWt == dist[nb]){ // not the first time, 
                    ways[nb] = (ways[nb] + ways[node])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};

// TC: O(ElogV) simple djkstra complexity
// SC: djkstra sc + extra O(n) for ways array 


// --------------------X--------------------X-----------------------X------------------

Q.28 Bellman ford algorithm

This algo will also help us to find the shortest path from src to all other Vertices

Then how is it different from djkstra
Dkstra algo will fail if the graph has negative edges. If there is a negative cycle, djkstra algo goes for a TLE. It will keep on minimising the distance  
Djkstra doesnt help you to detect negative Cycle
Bellman ford helps you to detect negative cycles as well
Bellman ford works only on a DG(directed graph). So if you are given an undirected graph, change it to DG by having 2 side edges with the same edgeWt

The only difference between djkstra and bellmand ford is bellman helps you to detect negative cycles
If the path weight is < 0, then the graph has negative cycle

Both djkstra and bellmand ford are single source shortest path algorithm
Bellman only works on DG, if an undirected graph is given you will have to convert it into a DG
For Djkstra, it doesn't matter [Check it once]


Similarity between Djkstra and Bellmand
1. Both are single source shortest path algorithms which means you have a predefined src and you have to compute the shortest dist of all the nodes from that src
2. Both will use dist array initially marked as inf and src as 0

Differnce between Djkstra and Bellman
1. Djkstra fails in case of negative weight cycles. It will keep on updating the dist value and will stuck in an infinite cycle causing TLE
2. Bellman only works on DG, djkstra can work on both undirectged and DG
3. In bellman we will relax all the edges n-1 times, whereas in djkstra we start with pushing the (dist,node) pair for src in the pq and then process all the neighbours 
4. Bellmans TC is kinda quadratic O(V*E), wheares Djkstras TC is O(ElogV), so it's bit more expensive, but it is very useful if the grpah has -ve edge wts or -ve wt cycle, bcoz djkstra doesn't work in those cases


// DOUBT
Does djkstra work in case of -ve edge wt (NO). What about -ve edge wt cycle(NO, will cause TLE)
Does Bellman work in case of -ve edge wt(Yes). What about -ve edge wt cycle(you will be able to detect -ve wt cycle using bellman)
and if the graph has -ve wt cycle, the dist array doesnt make much sense, bcoz the dist will keep on getting reduced




**Bellman implementation** 

Relax all the edges (N-1) times, where N is the number of vertices,
Dist array with all elements marked as inf and src as 0
By relaxing an edge[u,v,wt] I mean if(dist[u] + wt < dist[v]) then update dist[v] = dist[u] + wt;

Edge wise processing is done, doesn't matter the order of edges. and this processing needs to be done (n-1) times
 
WHy (N-1) iterations ? Refer Striver's Video
0 -> 1 -> 2 -> 3 -> 4  

edges: 
[3,4,1]
[2,3,1]
[1,2,1]
[0,1,1]

dist ->  0, inf, inf, inf, inf

1st iteratoin
dist[0] + 1 < dist[1]
     0, 1, inf, inf, inf


In the first iteration you will get value for 1
in second iteration, since you got value of 1 in last iteration, you will be able to calculate value of 2
in third iteration, since you got value of 2 in last iteration, you will get value of 3
in fourth iteration, you will get value of 4 using value of 3

In a grpah of N nodes, in the worst case you will take N-1 edges to reach from first to last, thereby we iterate for N-1 iterations
Try drawing for graph with more than N-1 edges, you won't need to wait for all iterations to be covered
In order to handle worst case scenarios, you iterate for N-1 times


Q. How To detect Negative cycles?
At max we will need N-1 iterations, so we will do 1 extra iteration and try relaxing the edges one more time. If the dist array gets updated, then it means you have a negative weights Cycle

In essence, if during the Nth iteration, relaxation causes updation of dist array, it means you have a negative weights cycle.
Since we already proved that we need only N-1 iteratoins in the worst case


Intution: Assume these are the edges of DG [0,1,-1], [1,2,-2], [2,0,2]
Perform relaxatoin N-1 times, the wt of cycle is -1, so each time weights will keep on reducing by -1
Now perform relaxatoin one more time, the dist array will get updated indicating -ve wt cycle.



Does bellman works in case of -ve weight cycles.
    Yes it does work in case of -ve weight cycles. It can help you to detect -ve wt cycle. If the graph contains -ve wt cycle, then calculating the shortest dist deosnt make any sense, bcoz in each iteration, the distance will keep on minimising

Does bellman works in case of -ve edge.
    Yes, it works

Does Djkstra works in case of -ve weight cycles.   
    No, stucks in TLE. It keeps on reducing the weights

Does Djkstra works in case of -ve edges.
    No





class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    // the problem asks us to check if the graph contains -ve cycle, means will have to use bellman
    // if the edge wts are -ve, use bellman
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V,1e8);
        dist[S] = 0;
        
        // Relax all the edges N-1 times
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int edgeWt = it[2];
                if(dist[u]!=1e8 and dist[u] + edgeWt < dist[v]){ // adding the first condition is a good practise
                    dist[v] = dist[u] + edgeWt;
                }
            }
        }
        
        // Relax 1 more time
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int edgeWt = it[2];
            if(dist[u]!=1e8 and dist[u] + edgeWt < dist[v]){ // if the dist array is getting updated, which it should not in ideal case, it means we have a -ve wt cycle. Return -1
                return {-1};
            }
        }
        
        
        return dist;
        
    }
};


// TC: O(V*E)
// SC: O(V)



// --------------------X--------------------X-----------------------X------------------

Q.28 Floyd Warshall algorithm

It is a multi source shortest path algo. It helps you to find the shortest path from all the nodes to every other node.
It helps you detect -ve cycles as well
It works for both DG and UG. If the graph is UG, then split the edge into 2 edges with the same weights
From the ultimate matrix that is generated, you will be able to figure out the shortest path between any 2 nodes


Differene between Floyd Warshall and Djkstra and Bellman is
    All of them are shortest path algrithms, Floyd Warshall is a multi source whereas the djkstra and bellman are single source 


How to detect -ve wt cycle?
    cost[i][i] should be 0, but if the graph has a -ve wt cycle, cost[i][i] < 0.
    Apparently the cost of any node from itself should be 0. traverse throught the cost matrix and check if the cost for any i is less than 0. It means we have -ve wt cycle 
    for(int i=0;i<n;i++){
        if(cost[i][i] < 0)
            cout<<"negative weight cycle exists"
    }
    If the graph has a negative cycle, it doesnt make sense to find the shortest path

    In most of the cases, if the graph contains -ve cycle, they would have stated it in the problem statement

Can we use Djkstra?
    Djkstra wont work in case of -ve weight cycles. It will stuck in a TLE loop.
    But yes we can definitely apply djkstra considering all the vertices as the src vertex. TC of this would be V*ElogV which is still less than Floyd warshall which takes V3



The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. 
Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Note : Modify the distances for every pair in-place.


// Have used 1e9 instead of INT_MAX. 1e9 < INT_MAX
// Using INT_MAX, values flows out of bound
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	         if(matrix[i][j]==-1)   // indicates there is no edge between i and j
	            matrix[i][j] = 1e9;
	         if(i==j) 
	            matrix[i][j] = 0;
	        }    
	    }
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(i==j) continue;
	                matrix[i][j]= min(matrix[i][j], 
	                                  matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }

        for(int i=0;i<n;i++){
            if(matrix[i][i] < 0){
                cout<<"negative cycle exists"
                return;
            }
        }
	    
	    for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	         if(matrix[i][j]==1e9)   
	            matrix[i][j] = -1;
	        }    
	    }
	        
	}
};

// TC: O(n^3)
// SC: O(n^2) to store the cost matrix

Floyd Warshall based problem
1. https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/



// --------------------X--------------------X-----------------------X------------------

Q.29 Minimum Spanning Tree

First lets understand what is a Spanning Tree?
    You will be given an undirected weighted graph contianing N Vertices and M Edges.
    The minimum no of edges required to connect this N vertices is N-1.  
    A tree in which we have N Nodes and N-1 edges and all nodes are reachable from each other , is a spanning tree. Out of all the possible spanning trees, the tree which has the minimum weight of all, is the MST(Minimum Spanning Tree)
    Every node is connected and has total of N-1 Edges  

    A graph can have more than 1 spanning tree. The spanning tree with the least sum is the MST 

Applications of MST 
Prims Algo
Kruskals Algo
    Disjoint Sets



// --------------------X--------------------X-----------------------X------------------

Q. 29 Prims ALgo
https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=45&ab_channel=takeUforward

Sample graph [[0,1,2], [0,2,1], [1,2,1], [2,3,2], [2,4,2], [3,4,1]] Undirected graph (u,v,wt)

It helps you to find the MST as well as the MSTs weight of a given graph.  

MST -> THe graph that contains N-1 edges and all the nodes are connected and the sum of all the edges is minimal

intuition:
Greedy approach is taken to choose the edges. 

Implementation

Initial configuration:
sum = 0 tracks the MSTs weight
vector<int> vis(n) initially marked false for all nodes
priority queue pq (wt, node, parent) min heap
MST List [] -> which will store all the edges that are part of MST

you can start of with any node. We will start from 0 
INsert(0,0,-1)  

// If you only want the sum of edges in MST, then you need to store the wt, and node in pq
// This will get you the MST value
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,0}); // (wt, node)
        int sum = 0;
        
        // this while loop will process each edge, so it runs for approximately E times
        // E
        while(!pq.empty()){
            // logE
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if(!vis[node]){
                vis[node] = true;
                sum+=wt;
                // ElogE
                for(auto i: adj[node]){
                    int adjNode = i[0], edWt = i[1];
                    if(!vis[adjNode]){
                        pq.push({edWt,adjNode}); // logE
                    }
                }
            }
            
        }
        
        return sum;
        
        
    }
};

// In the worst case, the src node pushes all the edges in the pq in the worst case
TC: ElogE for iteration in the Pq plus fetching the top pair + ElogE for iteration over the neigbhours and pushing it into the pq Overall ElogE 
SC: O(V) for vis + O(E) for Pq



// If you want the edge info as well, you will have to maintain parent information as well.
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V, false);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}}); // (wt, node, parent)
        int sum = 0;
        vector<pair<int,int>> mst; // (node1, node2) stores the edges involved in MST
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            
            if(!vis[node]){
                vis[node] = true;
                sum+=wt;
                if(parent!=-1) mst.push_back({node,parent});
                
                for(auto i: adj[node]){
                    int adjNode = i[0], edWt = i[1];
                    if(!vis[adjNode]){
                        pq.push({edWt,{adjNode,node}});
                    }
                }
            }
            
        }
        
        return sum;
        
        
    }
};




// --------------------X--------------------X-----------------------X------------------

Q. 30 Disjoint Sets (Union Find Algo) [Very IMP] Asked in lots of interviews and OA
https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46&ab_channel=takeUforward

What is a disjoint set Data structure?
Lets say you are given a graph that has multiple components & someone asks if 2 nodes are part of the same component
The brute force would be to start a dfs from one node and see if we can reach the other node. TC of dfs is O(V+E) which is kind of a linear complexity 
With Disjoint Sets, you can figure out this information in O(1) i.e constant time

Dijoint sets gives you 2 functionalities
a. findParent()
b. UnionByRank()
c. UnionBySize()

Initially all nodes are disconnected. Union will help you to connect 2 nodes
The nature of the graph is dynamic, it is changing at every step as and when we are adding new edges using Union 


We will need 2 arrays, rank and parent array and this is their inital config 
vector<int> rank(V, 0)
vector<int> parent(V)
for(int i=0;i<V;i++) parent[i] = i;


Union(u,v)
1. find ultimate parent of u and v, represented by pu and pv
2. Find ranks of pu and pv i.e rank of ultimate parents
3. connect smaller rank to larger rank always, in case of equality you can connect anyone to anyone
 

findParent()
does a and b belong to same component? Find ultimate parent of a and b. if pa!=pb it means they are part of different component

Normally findParent() is a log(n) opearation

This is where we introduce, path compression technique
Since we are only concerned with the ultimate parent at every stage, while figuring out the parent, we will store the parent for each node, so that next time if someone asks you who is the ultimate parent of a node, you can directly lookup in the parents array and tell
So now instead of storing the actual parent, we will be storing the ultimate parent for each node in the parents array
This is a very good technique, imagine your tree having a great depth, finding the ultimate parent would take logn. But using this, we will be able to find the ultimate parent in O(1)

While finding the ultimate parent, you will end up doing a path compression. 
Rank cannot be reduced during path compression, coz its possible that you still have another section of the tree which causes the rank to still remain the same.
If we could have reduced, we would have called it as a height. But rank is not the same as height. Rank just indicates that one component is bigger than the other component(in terms of prioriy)
{21 mins}

TC: of union operation is O(4alpha) which is as good as a constant. The alpha value very close to 1
findParent is also O(4alpha) where alpha is very close to 1.
SO overall both the findParent() and UnionByRank() takes O(1) time

SC: O(V) for parent array + O(V) for rank array

WHy connnect smaller rank to larger?
    Becoz this way we keep the height of the tree short. If we would have connected larger to shorter, the overall height of the tree would have increased, it will take a longer time evern though we are doing a path compression
    The travel times for all the nodes will be smaller if we connect lower rank guy to higher rank guy.
    This helps us to ensure that time taken for finding the ultimate parent is as minimal as possible


Union operation could be implemented both by rank as well as size. Size one is more intuitive.
Initially size of all the nodes is 1 and we always connect smaller size component to larger size 
while connecting dont forget to update the parent as well as the size


Psuedo code

int findParent(int u){
    if(u == parent[u])
        return u;
    return parent[u] =  findParent(parent[u]); // path compression, while returning save the parent
}
// ALl the links will be path compresssed during the recursion 


Sample UG graph 
[0,1]
[1,2]
[3,4]
[5,6]
[4,5]
[2,6]




class DisjointSet{
    vector<int> parent, rank, size;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }

};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // if 3 and 7 same or not
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"same\n";
    }
    else cout<<"Not Same\n"

    ds.unionByRank(3,7);


    DisjointSet ds1(7);
    ds1.unionBySize(1,2);
    ds1.unionBySize(2,3);
    ds1.unionBySize(4,5);
    ds1.unionBySize(6,7);
    ds1.unionBySize(5,6);
    // if 3 and 7 same or not
    if(ds1.findUPar(3) == ds1.findUPar(7)){
        cout<<"same\n";
    }
    else cout<<"Not Same\n"

    ds1.unionBySize(3,7);

}

// With comments
class DisjointSet{
    vector<int> parent, rank;
    public:
    DisjointSet(int n){ // n vertices
        rank.resize(n+1, 0); // n+1 sized array handles 1 based nodes as well. Initlaise rank with 0 for all and parents to themselves
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

//TC: O(4alpha) where alpha is near about 1
    int findUPar(int node){ // finds the Ultimate parent in O(1) time
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // path compression step which converts the logn logic to O(1)
    }

//TC: O(4alpha) where alpha is near about 1
    void unionByRank(int u, int v){ // adds 2 nodes belonging to different component to the same component in O(1) time
        int ulp_u = findUPar(u); // findUPar of both u anv
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return; // both already belong to same component, nothing needs to be done
        if(rank[ulp_u] < rank[ulp_v]){ // connect lower rank to higher rank always, the rank for the higher one remains unchanged
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v; // connect any one to any one, increase the rank of new Ultimate par by 1
            rank[ulp_v]++;
        }
    }

//TC: O(4alpha) where alpha is near about 1
     void unionBySize(int u, int v){ 
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }

};




// --------------------X--------------------X-----------------------X------------------

Q 31 Kruskal Algorithm

It helps us to find the MST
Earlier we did the same using Prims algo

What is a MST?
n nodes, n-1 edges and all the nodes are connected to each other and the overall weight of the tree is minimal

1. Sort all the edges according to weight edge;(wt, u, v)
2. We will use DisjointSet data structure. It gives us two things: findUPar() and unionByRank()
    and if 2 nodes belongs to the same component, they will always have the same ultimate parent
3.  Start adding edges, initially all the nodes will be disconnected and each will be its own parent
    Disjoing set will help us in finding the ultimate parent. If the 2 nodes of an edge belong to different component, add that edge in your MST




Doubt': While doing union should we take union of ultimate parents or union of nodes is good enough?
Do a dry run ' Line 3471


https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class DisjointSet{
    vector<int> parent, rank;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        // 2 -> (4,5)
        // 4 -> (2,5) the Edge will be added twice, but it doesnt matter, bcoz disjoint set will take care of it
        
        // 5 2 4
        // 5 4 2. the edges will be stored twice in the edges since its a bidretional edge, but Disjoint set will take care of it
        // V+E
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt,node,adjNode});
            }
        }
        
        // MlogM - M edges
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        
        int mstWt = 0, cnt=0;

        // M*4*alpha*2 -- This will be executed very less no of times
        for(auto it: edges){
            int wt = it[0];
            int u = it[1];
            int v = it[2];
            int pu = ds.findUPar(u); // ultimate parent of u
            int pv = ds.findUPar(v); // ultimate parent of v
            if(pu != pv){
                // add this edge in the mst
                mstWt+=wt;
                ds.unionByRank(pu,pv); // union the ultimate parents not the nodes
                cnt++;
            }
            if(cnt==V-1) break;
        }
        
        
        return mstWt;
        
        
    }


// TC: ElogE + V+E + E*4*alpha*2
// SC: V(parent) + V(rank) + E(edges)




// --------------------X--------------------X-----------------------X------------------

Q 31 Number of Provinces

Sol1 using simple DFS traversal

Sol2 Using Disjoint set
https://www.geeksforgeeks.org/problems/number-of-provinces/1

class DisjointSet{
    vector<int> parent, rank;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
};


class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V+1);
        
        // V*V*4*aplha*2
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i == j) continue;
                if(adj[i][j]){
                    int ulp_i = ds.findUPar(i+1);
                    int ulp_j = ds.findUPar(j+1);
                    if(ulp_i == ulp_j) continue;
                    ds.unionByRank(ulp_i,ulp_j);
                }
            }
        }
        
        // cnt the number of unique ultimate parent
        int cnt=0; // V*4*alpha
        for(int i=1;i<=V;i++){ // nodes for which there ultimate parent are they themselves, or I can say nodes which are components boss
           if(ds.findUPar(i) == i) cnt++;
        }
        
        return cnt;
        
        
    }
};

TC: O(V*V)
SC; V(parent) + V(rank)




// --------------------X--------------------X-----------------------X------------------

Q 32 Connecting the graph

// Tags: [Disjoint set] cnt the number of redundent edges and cnt the number of components 

class DisjointSet{
    vector<int> parent, rank;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edges) {
        // cnt the number of connected components C. 
        // Do we need to perform dfs for this. No we can count the number of components from DisjointSets itself
        // find no of redundent edges
        // C-1 <= no of redundent edges 
        // return C-1 else return -1

        DisjointSet ds(n);
        
        int redundent_edge=0;
        
        for(auto it: edges){ // figure out the extra edges
            int u = it[0];
            int v = it[1];
            int pu = ds.findUPar(u);
            int pv = ds.findUPar(v);
            if(pu == pv){
                redundent_edge++;
                continue;
            }
            ds.unionByRank(pu, pv);
        }
        
        int c=0;
        for(int i=0;i<n;i++){ // cnt the no of components
            if(ds.findUPar(i) == i){ // count unique ultimate parents or counts the no of components
                c++;
            }
        }
        
        if(c-1 <= redundent_edge) // to connnect c components we need c-1 edges
            return c-1;
        
        return -1;
         
    }
};




// --------------------X--------------------X-----------------------X------------------

Q 32 

I want to learn about all the key concepts related to spark structered Streaming. 
I want to understand its architecture, how does it actually work, how data processing takes place in a distributed environment

