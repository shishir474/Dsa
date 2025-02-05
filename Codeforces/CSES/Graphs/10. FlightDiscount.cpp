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

// Djkstra algo + also maintain a map that will track the parent 
// finding the shortest path and then reducing max weight edge on that path to half wont work --> fails 
// ex: [1,2,200], [2,4,200], [1,3,20] [3,4,400]
// according to djkstra {1,2,4} will be the shortest path with cost = 400 and cost according to question's constraints 300
// But ans is 220 {1,3,4} Although this path has higher cost but based on the constraints mentioned in the problem statement, this proves to be a better path

// m edges and m is in range of 1e5
// so we need O(m) solution
// we try by reducing each edge wt to half and then calculating the score
// src to all other vertices shortest path -> will be given by djkstra
// all vertices to destination shortest path -> will also be given by djkstra but first we have to reverse the edges of the graph and then perform djkstra
// let's say processing edge u which connects a to b
// ans = d[a] + wt(u)/2 + d1[b]
// d[a] = shortest path from 1(src) to a
// d1[b] = shortest path from b to destination 

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

    // implement later
    


}

