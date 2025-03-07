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


vector<vector<int>> adj;
// vector<int> dp;
map<pair<int,int>, int> mp;
int N;

// DP with bitmasking + Graphs
int dfs(int sv, int mask){
    if(sv == N || mask == (1<<N)-1){
        // if we have reached the dest
        if(sv == N and mask == (1<<N)-1){
            // if all the nodes have been visited
            return 1;
        }
        else return 0;
    }

    // 2D dp array -- we need to store ans corresponding to (sv,mask) combination
    if(mp.count({sv,mask})) return mp[{sv,mask}]; 

    int ans = 0;

    // analyse all neighbour
    for(auto nb: adj[sv]){
        // if the nb is unvisited
        if( (mask&(1<<(nb-1))) == 0){  // mask&(1<<(nb-1)) == 0 applying () around mask&(1<<(nb-1)) is necesary here in order to ensure correct computation and compariso  
            // call dfs on nb and mark the nb visited
            ans = (ans + dfs(nb, mask|(1<<(nb-1))))%mod;
        }
    }


    return mp[{sv,mask}] = ans;

}

// every no has a unique binary representatoin and we will use this fact to represent each possible subsets
// bitmasking --> you use bits to represent a subset ex: [1011], [1100], [1001] 
signed main() {
    initcode();
    int n,m; cin>>n>>m;
    N = n;
    adj.resize(n+1);
    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    mp.clear(); // reset the dp array

    // starting node: 1, dest node: n
    // return the count of possible routes from 1 to n such that you visit each city exactly once basically count of unique hamiltonian paths

    // graph must be connected. i.e 1 and n must be part of the same connected component infact all the vertices must be part of one single connected component since we need to visit all nodes
    // so there should be 1 single connected component, no isolated vertices

    // how to check if a hamiltonian path exists in a graph 
    // start a simple dfs from a node and check if you are able to visit all the vertices. It is possible that the hamiltonian path doesn't start from the current vertex, 
    // so we might need to check all the nodes, considering them as the starting point for dfs

    // During each recursve call, in order to check if all the nodes are visited in constant time, we can use mask 
    // if mask == (1<<n)-1 --> it implies all the nodes have been viited and hamiltonian path exists. The same can be acheived using vis array as well, but that would require O(n) time to check 
    // Using mask we can check this in O(1) time


    int ans = dfs(1,1);
    cout<<ans<<endl;
    
}






