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

vector<vector<int>> adj, mat;
vector<int> value,level;
int N,limit;

// precompute 2^ith parent for each node
void binaryLifting(){
	for(int j=1;j<=limit;j++){
		for(int i=1;i<=N;i++){
			int temp_node = mat[i][j-1];
			if(temp_node != -1)
			mat[i][j] = mat[temp_node][j-1];
		}
	}
}

// returns the node id of the kth parent of u
int liftNode(int u, int k){
	int curr = u;
	// it's assumed that max depth of the tree possible is 1<<20 in the beginning of the problem that's why the mat dimension is like that
	// I want to take a jump of length k 
	// so see if the ith bit is set in k -- take that jump and update curr to 1<<i th parent
	for(int i=limit;i>=0;i--){
		if(k&(1<<i)){
			curr = mat[curr][i];
		}
	}
	return curr;
}

// precomputes level/depth & populates the parent info for each node
void evalLevels(){
	// its assumed that 1 is the root of the tree
	// Level order traversal 
	queue<pii> q;
	q.push({1,-1}); // node,parent
	level[1]= 0;
	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		mat[node][0] = parent;
		q.pop();

		for(auto nb: adj[node]){
			if(nb != parent){
				level[nb] = level[node] + 1;
				q.push({nb,node});
			}
		}
	}
}

int computeLCA(int u, int v){
	if(level[u] < level[v]) swap(u,v);
	// level[v] is always <= level[u] 
	// lift u to bring it to the same level as v
	int new_u = liftNode(u,level[u]-level[v]);
	// edgecase: if v was an ancestor of u, then v is the lca
	if(new_u == v) return v;
	// both u and v are at the same levels
	// max depth possible level[v]
	// compute largest powers of 2 such that you make a jump of 2^pow from both new_u and v and land on different nodes
	int pow = log2(level[v]);
	while(pow>=0){
		int n1 = liftNode(new_u,1<<pow);
		int n2 = liftNode(v,1<<pow);
		if(n1 != n2){
			// you make that jump and update your positions
			new_u = n1;
			v = n2;
		}
		pow--;
	}
	// at this point you are just 1 step below the lca 
	return liftNode(new_u,1);
}

// stores the sum of count for each node at it's subtree's root
int dfs_for_ans_eval(int sv, int parent){
	int val = 0;
	for(auto nb: adj[sv]){
		if(nb!=parent){ // considering all the child nodes 
		    val+=dfs_for_ans_eval(nb,sv);
		}
	}
	value[sv] = value[sv] + val;
	return value[sv];

}

signed main() {
    initcode();
    int n,q; cin>>n>>q;
	N = n;
    adj.resize(n+1);
	// max depth of the tree possible is n
	// 2^i <= n
	// taking log on both sides 
	// i = log2(n)
	limit = log2(n) + 1; 
	mat.resize(n+1,vector<int>(limit+1,-1));
	value.resize(n+1,0);
	level.resize(n+1,-1);
    forn(i,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
		// mat[v][0] = u; /// 1-2, 1-3  // you dont know whether u or v is the parent --> hence better to fill this info whiile evaluating levels 
    }

	// precomputes level/depth for each node
	// While evaluating the levels, you also populate the 0th column of mat i.e parent of each nodes 
	evalLevels();
	// precompute 2^ith parent for each node
	binaryLifting();
    
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=limit;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
   

	// TC: for each query, we need O(logn) time to compute the lca, rest operations are O(1)
	// Total tc: O(qlogn) which is way better than the brute force approach of perfming dfs for each query which will take O(q*n)
    while(q--){
        int u,v; cin>>u>>v;
		int lca = computeLCA(u,v);
		int lca_parent = liftNode(lca,1);
        // int lca_parent = mat[lca][0];
        // cout<<lca<<" "<<lca_parent<<endl;
		// we'll use difference array technique + prefix sum to update the value for each node 
		value[u]+=1;
		value[v]+=1;
		value[lca]-=1;
		if(lca_parent != -1)
			value[lca_parent]-=1;

    }

	// at last one simple dfs traversal to compute the answer.
	//  Each node will store the sum of value for the subtree rooted at that node 
	dfs_for_ans_eval(1,-1);

    fore(i,1,n)
        cout<<value[i]<<" ";
    cout<<endl;

    return 0;
    
}


// Key Pointers
// First identify the limit for the mat dimension 
// evaluate levels and also fill the 0th column of the matrix mat while evaluating levels
// binaryLifting --> to populate the rest of the columns of the matrix mat
// liftNode(i, k) --> return kth parent of ith node 
// process queries
	// compute lca --> uses level info computed above and lift node to bring u and v at the same levels assuming level[u] > =level[v]
	// 




