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
int log_a_with_base_b(int a, int b) { return log2(a) / log2(b); }
// int modularBinaryExponentitation(int base, int exp) { return exp == 0 ? 1 : (modularBinaryExponentitation(base, exp / 2) * modularBinaryExponentitation(base, exp / 2) % mod * (exp % 2 ? base : 1)) % mod; }
// ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void print_graph(vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};

vector<vector<int>> adj;
vector<int> subtree;
int N;

// TC: O(N)
// evaluates subtree size of each node
int evalSubtreeSize(int sv, int parent){
    int sz = 0;
    for(auto nb: adj[sv]){
        if(nb != parent){
            sz += evalSubtreeSize(nb,sv);
        }
    }
    subtree[sv] = 1+sz;
    return subtree[sv];
}

int findCentroid(int sv, int parent){

    // find the max child subtree size for the current sv. If it's <= [n/2], then sv is your centroid
    int mx = 0, node;
    for(auto nb: adj[sv]){
        if(nb != parent){
            if(subtree[nb] > mx){
                mx = subtree[nb];
                node = nb;
            }
        }
    }
    
    // cout<<sv<<" "<<parent<<" "<<mx<<" "<<node<<endl;

    if(mx <= N/2) return sv;
    else return findCentroid(node, sv);
}

// We'll need to 2 DFS calls
// 1t dfs() to find the subtree size rooted at each node --> this will take O(n) 
// 2nd dfs() to find centroid --> this will take O(logn) time 
        // Why logn?
            // I will first check the size of root's child subtrees. and if the max size of its child;s subtrees <= N/2. Root is your centroid
            // if not, we will recurse to the child whose subtree size > N/2 & we can only have at most 1 subtree whose size is > N/2
            // bcoz if we have 2 subtrees with size > N/2, then the total no of nodes will become > N which is not possible.
            // So essentially, during each recursive call, tree size is getting reduced by half. FIrst N, then N/2, then N/4 and so on
            // Hence Logn
// Overall Time Complexity : O(n + logn) = O(n)

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
    subtree.resize(n+1,0);

// 🔍 Can you use the Rerooting technique to find the centroid?

// No — rerooting is not the best or natural choice for centroid finding.
// Here’s why:

// ⸻

// 🧠 Rerooting Technique:

// Used when you want to:
// 	•	Calculate a value for each node as if it’s the root (e.g., distance sum, subtree size, DP, etc.).
// 	•	It’s useful when you want to compute values for all nodes after computing it for one node efficiently.

// 📌 But centroid is:
// 	•	A single node with a specific structural property.
// 	•	You don’t need per-node DP or rerooting — you just want the one node whose largest child subtree is ≤ N/2.


// Your Current Centroid Logic:
//     Start from the root, check the size of the child's subtree and find the max size
// If maxSize <= N/2
// 	Root is your centroid
// If not, then you can recurse to the child which has the largest subtree size 

// If the largest subtree size was <= N/2, then sv would have been your centroid, but since this is not true
// I.e the largest subtree size was > N/2, our centroid will lie in this subtree

// Total nodes: N
// Size of largest child subtree > N/2
// Hence, Size of the remaining subtree excluding the largest child subtree will be < N/2. 
// This part is fine, we don’t need to worry about it.
// We just have to focus on the subtree whose size > N/2




    // We;ll perform 2 DFS
    // 1st to calculate subtree sizes O(N)
    evalSubtreeSize(1,0); // root, parent
    
    // 2nd to Find Centroid O(N)
    cout<<findCentroid(1,0)<<endl;


    // Overall complexity: O(N) + O(N) = O(N)
}






