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

const int MAXN = 200001;

vector<int> adj[MAXN];  // vector of vector

set<int> color[MAXN]; // vector/array of sets - each index contains a set 
                    // array of maps, array of pairs

int ans[MAXN];

// The reason why we merge smaller set into larger one is because, if we merge larger set, then more no of elements needs to be transferred which is clearly not efficient
void dfs(int sv, int parent){
    for(auto nb: adj[sv]){
        if(nb != parent){
            dfs(nb, sv);
            // swapping to ensure that smaller set is merged into larger one
            if(color[sv].size() < color[nb].size()){
                swap(color[sv],color[nb]);  // O(1) OPERATION
            }
            for(auto i: color[nb]){ // INSERT ELEMENTS FROM THE SMALLER SET TO THE LARGER SET 
                color[sv].insert(i);
            }
        }
    }
    ans[sv] = color[sv].size();
}

// https://www.youtube.com/watch?v=5JpaXAnrkIU&ab_channel=Senior

// ONE THING TO NOTE HERE IS IN THE ABOVE SOLUTION, WE DONT CREATE A NEW SET AND MERGE ALL THE CHILD SETS IN THE NEW ONE(THIS IS REALLY INEFFICIENT)
// TC; MERGING OF 2 SETS OF SIZE M AND N INTO A NEW SET WOULD BE O(MLOG(M+N))
// INSTEAD IF THE CHILD SET HAS A SIZE LARGER THAN THE PARNENT SET AND WE WANT TO MERGE CHILD SET INTO THE PARENT SET, SWAP CHILD AND PARENT SET(SO CHILD WILL HAVE FEW ELEMENTS) AND NOW MERGE ELEMENTS FROM CHILD TO PARENT 


// the child node will return a set of colors(obviously distinct)
// each node will be having their own sets for their own subtree 
// set for a particular node, would insert all the colors from their child nodes 

// set<int> dfs(int sv, int parent){
//     // cout<<sv<<endl;
    
//     set<int> final_s;
//     for(auto nb: adj[sv]){
//         if(nb != parent){
//             set<int> temp_s = dfs(nb,sv);
//             final_s.insert(all(temp_s));
//         }
//     }
//     final_s.insert(color[sv]);
//     ans[sv] = final_s.size();
//     return final_s;
// }



signed main() {
    initcode();
    int n; cin>>n;
    forn(i,n){
        int a; cin>>a;
        color[i].insert(a);
    }
    forn(i,n-1){
        int u,v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0,-1); // 0 is the root
    forn(i,n) cout<<ans[i]<<" ";
    cout<<endl;

    
}



// NOTE: Merging a small set of size M into a large Set of size N takes O(MlogN)
// inserting would take O(logN) and there are M elements. hence O(MlogN)

// Problem with the above solution is it doesnt consider the factor of which set is being is merged into which one. This is a bit inefficient
// We must always merge smaller set into larger set and not the other way around 
// Merge smaller to Larger, not Larger to smaller 




