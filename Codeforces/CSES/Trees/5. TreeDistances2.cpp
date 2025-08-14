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
#define INF             1e18
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
vector<int> subtreeSize, dp, ans;
int N;


// first DFS (Postorder Traversal):
// calculate:
    // subtreeSize[u] stores the no of nodes in the subtree rooted at node u, including u
    // dp[u] stores the sum of distances from u to all the nodes, it its subtree 
void dfs(int sv, int parent){
    subtreeSize[sv] = 1;
    for(auto nb: adj[sv]){
        if(nb!=parent){
            dfs(nb,sv);
            subtreeSize[sv] += subtreeSize[nb];
            dp[sv] += (dp[nb] + subtreeSize[nb]);
        }
    }
}

// Rerooting technique
// moving root from a node to its child, and updating the distance sums smartly
// When you move root from parent to child, the distances to nodes in the child's subtree decreases by 1, and distances to all the other nodes outside child's subtree increases by 1 
// net change: (-1 * num_of_nodes_child_subtree) + (n - num_of_nodes_child_subtree)*1
// Since subtreeSize[child] = num_of_nodes_child_subtree 
// hence , net change n - subtreeSize[child] - subtreeSize[child]
// n - 2*subtreeSize[child]
void dfs2(int sv, int parent){
    for(auto nb: adj[sv]){
        if(nb != parent){
            ans[nb] = ans[sv] + (N - 2*subtreeSize[nb]);
            dfs2(nb, sv);
        }
    }
}

signed main() {
    initcode();
    int n; cin>>n;
    N = n;
    adj.resize(n+1);
    forn(i,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    subtreeSize.resize(n+1,1);      // subtreeSize(node) represents the size of the subtree rooted at node, including node 
    
    dp.resize(n+1,0);           // dp[node] stores the sum of distances from node to all other nodes, in its subtree.
    //  Initialising it with 0 --> Imp

    dfs(1,-1);      // node,parent              1st dfs call to compute subtreeSize[node] & dp[node]

    ans.resize(n+1, -1);                        // ans[node] stores the sum of distances from node to all nodes in tree

    ans[1]= dp[1];                              
    dfs2(1,-1);
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
    
}

// intutioin:
// lets start by finding the sum of distances of all nodes from root, in its subtree
// Then we can use this and rerooting technique to get the answers for all nodes by calculating the net change 

// calculating the sum of distances from all nodes for root 
    // this will need subtree size + dp val of the child node 






