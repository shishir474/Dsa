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

// this dfs captures the dist of each node from sv 
void dfs(int sv, int parent, int dist, vector<int> &d){
    d[sv] = dist;
    for(auto nb: adj[sv]){
        if(nb != parent){
            dfs(nb, sv, dist+1, d);
        }
    }
}

// In a tree longest distance between 2 nodes is called the diameter of the tree.
// For a node u, its maximum distance to any other node is either:
// 	•	Distance to one endpoint of the diameter
// 	•	Or distance to the other endpoint

// ✅ So basically:
// 	•	Find two farthest points in the tree (the two endpoints of the diameter).
// 	•	Then for each node, maximum distance = max(distance to endpoint1, distance to endpoint2)


signed main() {
    initcode();
    int n; cin>>n;
    adj.resize(n+1);
    forn(i,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // start dfs from 1 to find the farthest end point(lets call it u)
    // start 2nd dfs from u to find the farthest end point(lets call it v). u and v represents two different endpoints of the diameter
    // start 3rd dfs from v to find the distance of each node from v
    // final ans for each node would be max(dist_u[i], dist_v[i]), where dist_u[node] represents the distance of node i from u and dist_v[i] represents the dist of node i from v
    


    // find u(1st endpoint of the diameter)
    vector<int> d(n+1,-1);      
    dfs(1,-1,0,d);                            // 1st dfs()
    int maxDist = -1, u=-1, v=-1;           // u and v represents 2 endpoints of the diameter
    for(int i=1;i<=n;i++){
        if(d[i] > maxDist){
            maxDist = max(maxDist, d[i]);
            u = i;
        }
    }

    // find v(2nd endpoint of the diameter)
    vector<int> dist_u(n+1,-1);
    dfs(u,-1,0,dist_u);                        // 2nd dfs()
    maxDist = -1;      
    for(int i=1;i<=n;i++){
        if(dist_u[i] > maxDist){
            maxDist = max(maxDist, dist_u[i]);
            v = i;
        }
    }

    vector<int> dist_v(n+1, -1);
    dfs(v,-1,0,dist_v);                         // 3rd dfs()

    for(int i=1;i<=n;i++){
        cout<<max(dist_u[i], dist_v[i])<<" ";
    }
    cout<<endl;
    
    return 0;
}


//  we need to compute for each node the maximum distance (in terms of edges) to any other node in the tree.
// 🔍 Key Observations
// 	•	The farthest node from a node always lies on the diameter of the tree.
// 	•	If we find the two endpoints of the diameter (u and v), then:
// 	•	For any node x, the maximum distance to any other node is:
// max(dist(x, u), dist(x, v)).




