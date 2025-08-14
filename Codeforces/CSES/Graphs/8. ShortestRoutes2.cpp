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

// Floyd warshall algorithm -  Multi source shortest path
    // Minor changes to pass the cses test cases: Generally we have atmost one edge b/w any 2 nodes in a graph.
    // But here this isn't mentioned in the question and therefore we also need to take care of the scenario where we have multiple roads b/w 2 same cities
    // like [1,2,1] & [1,2,2]
    // This is an edge case : we have 2 roads b/w 1 and 2 with cost 1 and 2.


signed main() {
	initcode();
	int n,m,q;
	cin>>n>>m>>q;
	int mat[n+1][n+1];
    
    // Initialise the mat
    forn(i,n+1){
        forn(j,n+1)
            if(i == j) mat[i][j] = 0;
            else mat[i][j] = 1e18;
    }

    // NOTE: There can be multiple roads b/w 2 cities, hence we need to take the min cost of all the roads.
    // This is generally not the case in most of the problems, but here we need to take care of this edge case.
    forn(i,m){
        int u,v,wt;
        cin>>u>>v>>wt;
        mat[u][v] = min(mat[u][v], wt); // edge Case: there could be more than 1 direct roads b/w 2 cities. hence using the min condition to take the min cost all the roads
        mat[v][u] = min(mat[v][u], wt); 
    }

    vector<pii> queries;
    forn(i,q){
        int u,v; cin>>u>>v;
        queries.pb({u,v});
    }

    // Actual Processing
    for(int k=1;k<=n;k++){ // WHy the loop order is k -> u -> v where k is the intermediate node, u is the src and v is the dest
        
        for(int i=1;i<=n;i++){
        
            for(int j=1;j<=n;j++){
                
                if(i==j) continue; // it's cost is already known which is 0

                // cost of i to j via k
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }

    }

    forn(i,queries.size()){
        int u = queries[i].first ,v = queries[i].second;
        if(mat[u][v]==1e18) cout<<"-1"<<endl;
        else cout<<mat[u][v]<<endl;
    }
    

}

