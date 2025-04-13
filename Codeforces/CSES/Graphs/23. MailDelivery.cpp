#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>;  // policy based data structure
// ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// and set.order_by_key(k) -> returns the index of the key k
// ordered set data structure => adds indexing functionality to sets
 
#define int             long long int
#define ff              first
#define ss              second
#define pb              push_back
// #define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(i,n)      for(int i=0;i<n;++i)
#define fore(i, l, r)   for(int i = l; i <= r; ++i)
#define all(v)          v.begin(), v.end()
 
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode() {
	FIO;
	// #ifndef ONLINE_JUDGE
	// freopen("cpp/input.txt", "r", stdin);
	// freopen("cpp/output.txt", "w", stdout);
	// #endif // ONLINE_JUDGE
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a / gcd(a, b) * b);
}
int log_a_with_base_b(int a, int b){
        return log2(a) / log2(b);
}
void print_graph(vector<vector<int>> adj){
	forn(i,adj.size()){
		cout<<i<<": ";
		forn(j,adj[i].size()){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}
int modularBinaryExponentitation(int base, int exponent) {
	if(exponent==0) return 1;
	int val = modularBinaryExponentitation(base, exponent/2);
	if(exponent%2)
		return ((val*val)%mod*base)%mod;
	else
		return (val*val)%mod;
}
 
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};
 
 
vector<vector<pii>> adj;
vector<int> degree;
vector<bool> vis, seen;
stack<int> s;
int N;
 
void dfs(int sv){
    vis[sv] = true;
    for(auto it: adj[sv]){
        int nb = it.first;
        if(!vis[nb]) dfs(nb);
    }
}
 
// this function ensures that all the edges are part of the 1 single component
// i.e there exists no multi edged components 
// There could be more than 1 component, but only 1 component will have all the edges and the rest of them will be 1 single node
bool isConnected(){
    vis.resize(N+1,false);
    dfs(1);
    for(int i=1;i<=N;i++){
        if(!vis[i] and degree[i] > 0) return false;
    }
    return true;
}
 
 
void dfs_to_generate_euler_circuit(int sv){
    // METHOD 1: RUNTIME ERROR
    // for(int i=1;i<=N;i++){
    //     if(adj[sv][i]){
    //         adj[sv][i]--;
    //         adj[i][sv]--;
    //         dfs_to_generate_euler_circuit(i);
    //     }
    // }
    // s.push(sv);


    // we have to process all the edges of sv
    // for(int i=0;i<adj[sv].size();i++){       // erasing element this way could cause problems
    //     int nb = adj[sv][i];
    //     adj[sv].erase()
    // }


// METHOD 3: TLE for 1 test case   
// we dont actually need to delete the nb vertex from adj[sv], seen[] will ensure that we process only a unvisited edge
// but after a certain point, all the edges for a vertex will be seen and we will unnecesarily loop on them. So if we remove the vertex nb from adj[sv] and mark the edge seen, this will reduce the size of adj[sv] and later we wont have to iterate over all the unnecessary edges 
    // for(auto i: adj[sv]){
    //     int nb = i.first;                                // this is the nb we will process 
    //     int id = i.second; 
        
    //     if(seen[id]) continue;
    //     seen[id] = true;
 
    //     dfs_to_generate_euler_circuit(nb);
        
    // }

// METHOD 4:
     while(!adj[sv].empty()){
        int nb = adj[sv].back().first;                                // this is the nb we will process 
        int id = adj[sv].back().second; 
        adj[sv].pop_back();                                          // delete the sv-> nb edge - remove nb from adj[sv]
                                        // NOTE that deletion of this edge is not necessary, just doing it for the optimisation purpose
        if(seen[id]) continue;
        seen[id] = true;
 
        dfs_to_generate_euler_circuit(nb);
    }
 
    
    // METHOD 2: TLE for 1 test case    
    // This is the best way to erase -- erase from the last 
    // // Intead of modifying the adj lit while iterating, we always process the last element (similar to stack behaviour)
    
    // while(!adj[sv].empty()){
    //     int nb = adj[sv].back().first;                                // this is the nb we will process 
    //     int id = adj[sv].back().second; 
    
    //     adj[sv].pop_back();                                          // delete the sv-> nb edge - remove nb from adj[sv]
    
    //      vector erase accepts only iterator (single element / range of eleemnts)    
    // Below line is O(degree of nb) because find is linear in a vector, and erase is also linear because it has to shift the elements.
    // •	In the worst case (dense graph), you’re repeatedly searching and erasing, making the complexity worse than expected.
    // •	If each node has a high degree, you’re paying that penalty every time — leading to Time Limit Exceeded.

    //     adj[nb].erase(find(all(adj[nb]),sv));                        // delete the nb-> sv edge  - remove sv from adj[nb]

    //     if(seen[id]) continue;
    //     seen[id] = true;
 
    //     dfs_to_generate_euler_circuit(nb);
    // }
    
    s.push(sv);
 
}
 
 
// Code is giving TLE on 1 case: 
    // Try using adj matrix instead of adj list as used in cp algo's code
signed main() {
    initcode();
    int n,m; cin>>n>>m;
    N = n;
    // adj.resize(n+1, vector<int>(n+1,0)); // 1 to N nodes are given in the problem statement 
    adj.resize(n+1);
    degree.resize(n+1,0);
    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back({v ,i});           // nb node, edge_id
        adj[v].push_back({u, i});
        // adj[u][v]++; 
        // adj[v][u]++;
        degree[u]++;
        degree[v]++;
    }
 
    if(!isConnected()){ // all the edges should be a part of one single component and (1 should be part of this component) -> this reason is in accordance to problem requirements
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
 
    // for euler circuit, all degree must be even
    fore(i,1,n){
        if(degree[i]%2){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    
    // Now it is confirmed that all the nodes have even degree
    // Now the task is to find a euler circuit
    // In euler circuit, we need to ensure that each edge is traversed exactly once and we cover all the edges and return back to the starting point. During this, we could visit a vertex more than once
 
 
    // starting point is given as 1 in the problem statement
    seen.resize(m, false);                                              // used to track edges that have been processed
    dfs_to_generate_euler_circuit(1);
    
    vector<int> res;
    
    while(!s.empty()){
        int t=  s.top();
        s.pop();
        res.push_back(t);
    }
 
    forn(i,res.size()) cout<<res[i]<<" ";
 
 
}


NOTES regarding implementation optimisations:
Why I was getting TLE on removing the element from the adj list 
using pop_back() is O(1)
But adj[nb].erase(find(all(adj[nb]),sv));
	This line is O(degree of nb) because find is linear in a vector, and erase is also linear because it has to shift the elements.
	•	In the worst case (dense graph), you’re repeatedly searching and erasing, making the complexity worse than expected.
	•	If each node has a high degree, you’re paying that penalty every time — leading to Time Limit Exceeded.

Instead maintain seen array for edges, and don’t erase edges at all, which means:
    	Adjacency list stays intact
	•	Every edge is only visited once
	•	No O(N) erasures → only constant time operations
	•	Efficient even for dense graphs

To fix your code:
	•	Represent edges with an index   (0 to m-1)
	•	Store edge IDs in the adjacency list
	•	Use a seen[] array to avoid re-visiting edges


🔑 What’s the difference between pop_back() vs erase(find(...))?

Operation               Time Complexity                     Notes
pop_back()                 O(1)                             Removes the last element in a vector â€” constant time, very fast.
erase(find(...))           O(N)                             Searches for the element and then shifts all elements â€” slow for large vectors.

Even removing the 1 edge is also not necessary, but this is causing TLE for 1 test case. To optimise, we will remove that one edge
    you don’t even need to pop_back() just to “remove” the edge — the seen[] array already handles whether an edge has been used or not, so the edge can safely remain in the adjacency list.

    🔁 So why does USACO still do pop_back()?

    It’s just for efficiency — not correctness.

    By always processing and removing the last edge from the adjacency list with pop_back():
        •	You don’t reprocess the same unused edges again.
        •	You save time by not scanning over edges that are already used (seen[] == true).
        •	Think of it like: “only consider each edge once” — and pop_back() helps clean up as you go.

    🧠 But it’s still safe not to remove the edge at all

    You could keep all edges and just do this:

    for (auto [nb, idx] : adj[sv]) {
        if (!seen[idx]) {
            seen[idx] = true;
            dfs(nb);
        }
    }

    …but the runtime will suffer if you don’t pop_back() or filter used edges, because you’re repeatedly scanning over already-used ones.

✅ Best of both worlds

Use pop_back() to process each edge once, and use seen[] to skip already-used edges when you encounter them again from the other side. This gives you:
	•	Fast edge access
	•	No expensive find() or erase()
	•	Efficient memory usage
	•	TLE-proof Euler circuit DFS 🚀


✅ Fix: Either use pop_back() with a while loop OR iterate with for loop properly.

Option 1: Use while loop with pop_back() like USACO
    
    while (!adj[sv].empty()) {
        auto [nb, id] = adj[sv].back();
        adj[sv].pop_back();

        if (seen[id]) continue;
        seen[id] = true;

        dfs_to_generate_euler_circuit(nb);
    }

Option 2: Proper for loop

    for (auto [nb, id] : adj[sv]) {
        if (seen[id]) continue;
        seen[id] = true;

        dfs_to_generate_euler_circuit(nb);
    }






// // {https://www.youtube.com/watch?v=eQL_LLvAdtY&ab_channel=Codenzyme}
// // https://www.youtube.com/watch?v=8MpoO2zA2l4&ab_channel=WilliamFiset

// Necessary Conditions for Euler Tour:
// Every node should have an even degree except 2 nodes(start and end node)
// Whole graph should be a single connected component
// Node which has 1 extra outgoing edge is the starting point and the node which has 1 extra incoming edge is the ending node for the eulerian tour
// exactly 2 nodes have abs(indegree-outdegree) = 1, rest will have equal indegree and outdegree. Those 2 nodes will form your starting and ending point

// Necessary Conditions for Euler Circuit/Cycle:
// It''s an eulerian tour that starts and ends at the same node
// Indegree is equal to outdegree for every node and you can choose to start from any node 

// Once I assign the directed edges, the graph that is formed is 1 single Strongly Component
// So if someone gives u an undirected graph and tells you to assign edges in such a way that the graph becomes 1 single strongly connected component -> eulerian Circuit
// The way you assign directions to the edges - eulerian oriented graph. It is a directed graph and it represents a single strongly connected component 


// // Directed graph implementation

// Let''s see what happens if we do a naive dfs, trying to traverse as many edges as possible until we get stuck 
// By Randomly selecting edges during the DFS, we made it from the start node to the end node. However, we did not find an eulerian path because we didn''t traverse all the edges in our graph
// Good news is we can modify our DFS to handle forcing the traversal of all edges :)
//       2
//       ||  
// 0 --> 1 ---> 3 ---> 4

// To illustrate this, consider starting at node 0 and trying to find an Eulerian path 
// Whoops.. we skipped the edges going to node 2 and back which need to be part of the solution 

// Solution:
// Once we get stuck (meaning the current node has no unvisited outgoing edges), we backtrack and add the current node to the solution
// Basically here we need to track if a certain edge has been visited or not. Generally we just use the visited array for keeping track of visited vertices, but here we need to track the edges which are visited 

// we reach 4, and we are stuck since we have no outgoing edge. add 4 to stack and backtrack [4]
// we reach back to 3, stuck since we have no outgoing edge. add 3 to stack and backtrack [3,4]
// 1 has an outgoing edge which is unvisited, visit that edge. We reach 2 which has an outgoing edge not yet visited. We reach 1
// 1 has no unvisited outgoing edge, push it into the stack and backtrack [1,3,4]
// Now we are at 2, which also does not have any outgoing edge. Push it into the stack and backtrack [2,1,3,4]
// Now at 1, no outgoing unvisited edge, Push it into the stack and backtrack [1,2,1,3,4]
// Now at 0, no outgoing unvisited edge, Push it into the stack and backtrack [0,1,2,1,3,4]


// The time complexity to find an eulerian path with this algorithn is O(E). The two calculations we are doing: computing in/out degrees + DFS are both linear in the number of edges 

// https://cp-algorithms.com/graph/euler_path.html

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin>>n>>m;
    vector<vector<int>> g(n, vector<int>(n));
    // reading the graph in the adjacency matrix
    
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        u--; v--;
        g[u][v]++;
        g[v][u]++;
    }
    

    vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            deg[i] += g[i][j];
    }

    int first = 0;  // get the first non zero degree vertex
    while (first < n && !deg[first])
        ++first;
    if (first == n) {
        cout << -1;
        return 0;
    }

    int v1 = -1, v2 = -1;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        if (deg[i] & 1) {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                bad = true;
        }
    }

    // if there are 2 vertices with odd degree(i.e the euler path exists)
    //  we will add a fictious edge b/w v1 and v2 and now the graph would contain a euler cycle 
    // if v1 is still -1 it means the graph consists of euler cycle
    // if v1 is not -1 it means the graph consists euler path, but in order to derive that euler path we will have to add an extra edge b/w v1 and v2
    // addition of this edge will ensure that the graph now contains euler cycle 
    // now we can apply the dfs logic   
        // for the sv, start deleting its edges with nb 
        // for all the edges that sv has : delete sv to nb edge and nb to sv edge  and call recursion on the nb node
        // if the sv has no nb left push it into the stack and return
    // the stack will contain the nodes for your euler cycle
    // Now if v1 was -1 it means the graph originally consists of euler cycle you can return the res from the stack 
    // but if v1 was not -1 which means the graph originally didn't have euler cycle, it only consists of euler path so you will have to remove that extra fitious edge that you added earlier to convert the euler path into euler cycle
    // you will first transfer the elements from the stack into a vector and then iterate over it and see if (v[i]==v1 and v[i+1]==v2) or (v[i]==v2 and v[i+1]==v1)
    // you will copy the elemnent from v[i+1 to end] and then v[1 to i]
    if (v1 != -1)
        ++g[v1][v2], ++g[v2][v1];

    // check for the euler cycle 
    stack<int> st;
    st.push(first);
    vector<int> res;
    while (!st.empty()) {
        int v = st.top();
        int i;
        for (i = 0; i < n; ++i)
            if (g[v][i])
                break;
        if (i == n) {
            res.push_back(v);
            st.pop();
        } else {
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }

    // removing that one extra fictious edge that we added earlier knowing the graph only consists of euler path
    // we added this edge in order to convert that euler path into a euler cycle
    if (v1 != -1) {
        for (size_t i = 0; i + 1 < res.size(); ++i) {
            if ((res[i] == v1 && res[i + 1] == v2) ||
                (res[i] == v2 && res[i + 1] == v1)) {
                vector<int> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j])
                bad = true;
        }
    }

    if (bad) {
        cout << -1;
    } else {
        for (int x : res)
            cout << x << " ";
    }
}