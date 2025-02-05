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
#define mp              make_pair
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

// Variation of Djkstra algo (Excellent Problem)
// Djkstra was about Single Source (One) shortest path whereas this problem is about Single Source (K) Shortest Path(S)
// In Djkstra, we store the lengths in a vector. We initialise all the lengths to INF
// In this problem we can store K lengths for each vertex in a vector of vectors. All K lengths are initialised to INF
// In Djkstra, we overwrite when we find a shorter path
// In this problem, if the given path is better than the worst current path, we overwrite into the worst current path and sort as per path lengths

// This is how dist array will look initially in this problem, assuming we have 3 vertices and we have to find 4 shortest paths
// dist = <<inf, inf, inf, inf>, <inf, inf, inf, inf>, <inf, inf, inf, inf>>
// basically n*k size for dist array

// Constraints
// n vertices and m edges in range of 1e5, 
// cost of an edge in range of 1e9
// 1 <= K <= 10

signed main() {
	initcode();
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<pii>> adj(n+1); // [1..n] vertices
    forn(i,m){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].pb({v,wt}); // it's a one way flight - i.e unidirectional edge
    }

    // implementation (https://www.youtube.com/watch?v=009PBKHXtyA&ab_channel=Dardev)
    vector<vector<int>> dist(n+1, vector<int>(k,1e18)); // modified dist array of size n*k for this problem since we have to find k shortest paths
    dist[1][0] = 0;
    
    // We will not use visited array in this problem
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap(dist, node)
    pq.push({0,1}); // 1 is the src node and its dist is 0

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

//dist[u][k-1] denotes the kth best path to reach u. If d is greater than this cost: then no need to process this path
        if(dist[u][k-1] < d) continue;

        for(auto e: adj[u]){
            int v = e.first;
            int c = e.second;
            if(dist[v][k-1] > c+d){
                dist[v][k-1] =  c+d;
                pq.push({dist[v][k-1], v});
                sort(dist[v].begin(), dist[v].end()); // sorting so that the kth path becomes the worst 
            }
        }


    }

    forn(i,k){
        cout<<dist[n][i]<<" ";
    }
    cout<<endl;





}

