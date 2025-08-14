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

// Djkstra algorithm -  single source shortest path TC: O(ElogV)
// Bellman Ford is also a single source shortest path algo like djkstra but it's used in graphs that have -ve edge weights
// Minor changes to handle the edge cases
    // Initialised the Key vector with 1e18 instead of INT_MAX, the dist could cross 1e9 as per question's constraints
    // Edges are unidirectional 

signed main() {
	initcode();
	int n,m;
	cin>>n>>m;
	vector<vector<pii>> adj(n+1); // [1..n] vertices
    forn(i,m){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].pb({v,wt}); // it's a one way flight - i.e unidirectional edge
    }

    bool visited[n+1];
    int key[n+1];

    for(int i=0;i<=n;i++){
        key[i]=1e18;  // edge wt's are huge, could cross INT_MAX, hence initialised with 1e18 
        visited[i]=false;
    }


    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
    
    key[1]=0;
    pq.push({0,1}); // distance, vertex

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        // process the node only if it is not visited yet - dont need visited array. Please refer to the latest/updated code of djkstra
        if(!visited[u]){
            visited[u] = true;

            for(auto it: adj[u]){
                int v=it.first;
                int wt=it.second;
                if(!visited[v] and key[u]+wt<key[v]){
                    key[v]=key[u]+wt;
                    pq.push({key[v],v});
                }
            }
        }
        
    }


    for(int i=1;i<=n;i++){
        cout<<key[i]<<" ";
    }
    


}

