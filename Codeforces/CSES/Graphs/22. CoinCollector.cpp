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

void print_graph(vector<vector<int>> adj){
	forn(i,adj.size()){
		cout<<i<<": ";
		forn(j,adj[i].size()){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

// Find the strongly connected components
// Create a condensed graph using the above info
// This condensed graph will always be acyclic in nature. Why --> bccoz if it was cyclic then the nodes would have been part of the same component and we did not have got 2 different nodes

vector<vector<int>> adj; 	 // original graph
vector<vector<int>> rev_adj; // reverse graph
vector<vector<int>> red_adj; // reduced graph formed using SCCs
vector<bool> vis;
stack<int> s;
vector<int> coins;
unordered_map<int,int> component_ids;  // node -> component_id
vector<int> component_coins; 	// stores the total coins for each component
vector<int> indegree;
vector<int> dp;
int N;

// this dfs() captures the nodes in the descending order of their finish times in stack s
void dfs(int sv){
	vis[sv] = true;
	for(auto nb: adj[sv]){
		if(!vis[nb]){
			dfs(nb);
		}
	}
	s.push(sv);	
}

void rev_dfs(int sv, int comp_id){
	vis[sv] = true;
	component_ids[sv] = comp_id;
	for(auto nb: rev_adj[sv]){		// traversing on reversed_adj 
		if(!vis[nb]){
			rev_dfs(nb, comp_id);
		}
	}
}

// computes the max amount of coins that can be obtained, given that we start from sv
// recurrence: component_coins[sv] + max amount of coins that can be obtained amongst all its neighbours
// we will be iterating over the reduced graph 
int obt(int sv){
	// if already precomputed
	if(dp[sv] != -1) return dp[sv];

	int ans = component_coins[sv];
	int val = 0;
	for(auto nb: red_adj[sv]){
		val = max(val, obt(nb));
	}

	return dp[sv] = ans + val;

}

int kosaraju(){
	// sort the nodes based on their end timings
	vis.resize(N+1),false;
	fore(i,1,N){
		if(!vis[i]) dfs(i);
	}

	// reset vis array
	forn(i,N+1) vis[i] = false;

	// stack contains vertices in the order of their end times i.e the vertex at the top is the last to finish in the dfs 
	int comp_id = 0;
	while(!s.empty()){
		int t = s.top();
		s.pop();
		if(!vis[t]){
			rev_dfs(t,++comp_id); // perform dfs on the reversed graph to get the SCCs
		}
	}

	// create the condensed_graph using the compoenent_id information
	red_adj.resize(comp_id+1);
	component_coins.resize(comp_id+1);
	indegree.resize(comp_id+1,0);

	// check all the vertices
	fore(i,1,N){
		// check all its edges
		for(auto nb: adj[i]){
			// if i and nb are part of different components -> create an edge
			if(component_ids[i] != component_ids[nb]){
				red_adj[component_ids[i]].push_back(component_ids[nb]);
				indegree[component_ids[nb]]++;
			}
		}
		component_coins[component_ids[i]]+=coins[i];
	}

	// for(auto it: component_ids){
	// 	cout<<it.first<<" "<<it.second<<endl;
	// }
	// print_graph(red_adj);
	// fore(i,1,comp_id) cout<<component_coins[i]<<" ";


	// dp[i] stores the max amount of coins that can be obtained given that we start from ith vertex
	// in the question it is stated that we can start from any node 
	// hence ans would be max(all dp[i]) 
	// initialising dp array with -1 indicating that ans is not computed 
	dp.resize(comp_id+1, -1);

	// obt() would calculate the max no of coins that we could have obtained given that our starting point is ith vertex

	// obt(1);  
	fore(i,1,comp_id){ // the reduced graph could be disconnected as well, hence computing the value by iterating over each node which is not yet computed
		// if(dp[i] == -1) obt(i);
		if(indegree[i] == 0){
			// i could be the potential starting point 
			obt(i);
		}
	}

	// we dont actually need to compute obt(i) for all the vertices in the reduced graph
	// The way we will be able to make max coins is only if we start from vertices that has an indegree 0. Starting from a vertex in the middle wont make much sense bcoz then we would be loosing out the coins of the previoous components
	// so instead of computing obt(i) for all vertices, compute it only for those that have indegree 0. 
	// This can reduce the overall tc  



	int ans = 0;
	fore(i,1,comp_id){
		// cout<<dp[i]<<endl;
		ans = max(ans, dp[i]);  // taking the max of all dp[i]
	}

	return ans;

}

// Reduce the input graph into scc's graph
	// Find all the sccs. Each component will be treated as a node in the shrinked graph 
// For first step, use kosaraju() to find all the sccs. Now we need to add edges between each scc node.
// each edge will either connnect 2 vertices that are part of the same scc or those that are part of different components.
// We only need to consider those edges that connect vertices across 2 different components. (For this we'll map each node to its component_id)
// map<int, vector<int>> mp 		-- component_id -> vector of nodes in this component
// Now we have a graph of scc's. We can use DP on this to find the optimal path(the path which gives us the max no of coins)
// dp is the go to solution when you need to find optimal solutions.


signed main() {
    initcode();
	int n,m; cin>>n>>m;
	N = n;
	coins.resize(n+1);
	adj.resize(n+1);
	rev_adj.resize(n+1);
	fore(i,1,n) cin>>coins[i];
	forn(i,m){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		rev_adj[v].push_back(u);
	}

	cout<<kosaraju()<<endl;
	
	return 0;
}






