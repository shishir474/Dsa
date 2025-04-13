/* Shishir Singh */
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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int modularBinaryExponentitation(int base, int exp) { return exp == 0 ? 1 : (modularBinaryExponentitation(base, exp / 2) * modularBinaryExponentitation(base, exp / 2) % mod * (exp % 2 ? base : 1)) % mod; }
int modinv(int b, int c){ return modularBinaryExponentitation(b, c-2);}
int log_a_with_base_b(int a, int b) { return log2(a) / log2(b); }
// int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// int mminvprime(int a, int b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void print_graph( vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};

vector<vector<int>> adj;
int N;
// map<pii,int> mp;

vector<vector<int>> dp;

//  n*2^n entries 
// int dfs(int sv, int mask){
//     if(sv == N){
//         if(mask == ((1<<N)-1) ) return 1;
//         else return 0;
//     }
//     if(mp.count({sv,mask})) return mp[{sv,mask}];

//     int ans = 0;
//     for(auto nb: adj[sv]){
//         if( (mask & (1<<(nb-1))) == 0){
//             ans = ( ans + dfs(nb, (mask | (1<<(nb-1))) ) )%mod;
//         }
//     }

//     return mp[{sv,mask}] = ans;
// }

int dfs(int sv, int mask){
    if(sv == N){
        if(mask == ((1<<N)-1) ) return 1;
        else return 0;
    }
    if(dp[sv][mask] != -1) return dp[sv][mask];

    int ans = 0;
    for(auto nb: adj[sv]){
        if( (mask & (1<<(nb-1))) == 0){
            ans = ( ans + dfs(nb, (mask | (1<<(nb-1))) ) )%mod;
        }
    }

    return dp[sv][mask] = ans;
}

signed main() {
    initcode();
    int n,m; cin>>n>>m;
    N = n;
    adj.resize(n+1);
    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }

    // starting node: 1, dest node: n
    // return the count of possible routes from 1 to n such that you visit each city exactly once basically count of unique hamiltonian paths
 
    // graph must be connected. i.e 1 and n must be part of the same connected component infact all the vertices must be part of one single connected component since we need to visit all nodes
    // so there should be 1 single connected component, no isolated vertices
 
    // how to check if a hamiltonian path exists in a graph 
    // start a simple dfs from a node and check if you are able to visit all the vertices. It is possible that the hamiltonian path doesn't start from the current vertex, 
    // so we might need to check all the nodes, considering them as the starting point for dfs
 
    // During each recursve call, in order to check if all the nodes are visited in constant time, we can use mask 
    // if mask == (1<<n)-1 --> it implies all the nodes have been viited and hamiltonian path exists. The same can be acheived using vis array as well, but that would require O(n) time to check 
    // using Bitmasks to track vis vertices and DP to memoise the results --> Bitmask + DP Problem

    dp.resize(n+1, vector<int>(1<<n, -1));       // state: dp[node][mask]
    // avoid using maps for memoisation -- they are highly inefficient as compared to vectors and can result in TLE 

    cout<<dfs(1,1)<<endl;
    
}








