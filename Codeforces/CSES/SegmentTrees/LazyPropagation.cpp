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
// ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void print_graph( vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};

vector<int> arr, segTree, lazy;

// constructs the segTree in O(N) time
// call from main as  buildTree(0,0,n-1);
// index reps the index of the segtree node, lo and hi reps the array range for which the segNode stores the ans
void buildTree(int index, int lo, int hi){
    if(lo ==  hi){
        segTree[index] = arr[lo];
        return;
    }
    int mid = (lo+  hi)/2; 
    buildTree(2*index + 1, lo, mid);
    buildTree(2*index + 2, mid+1, hi);
    segTree[index] = segTree[2*index + 1] + segTree[2*index + 2];
}

// increment the value of the range l to r by x 
// call from main as rangeUpdate(0,0,n-1,l,r,x);
// O(logN)
void rangeUpdate(int index, int lo, int hi, int l, int r, int x){
    if(lazy[index] != 0){           // check for pending updates 
        segTree[index] += (hi-lo+1) * lazy[index];          // update the curr node
        if(lo != hi){       // push the changes to the child nodes
            lazy[2*index + 1] += lazy[index];
            lazy[2*index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }

    // case 1: if the curr range of segTree node's lie completely within l and r
    if(lo >= l and hi <= r){
        segTree[index] += (hi-lo+1) * x; 
        if(lo != hi){       // push the changes to the child nodes if it exists
            lazy[2*index + 1] += x;
            lazy[2*index + 2] += x;
        }
        return;
    }

    // case 2: lies completely outside - simply get back
    if(hi < l or lo > r) return ;

    // case3: partial overlap   -- recurse in both directions 
    int mid = (lo + hi) >> 1;
    rangeUpdate(2*index+1, lo, mid, l, r, x);
    rangeUpdate(2*index+2, mid+1, hi, l, r, x);
    // while backtracking - update the curr node 
    segTree[index] = segTree[2*index + 1] + segTree[2*index + 2];

}


// evaluates the sum of range l to r lazily 
// call from main as querySumLazy(0,0,n-1,l,r)
// O(logN)
int querySumLazy(int index, int lo, int hi, int l, int r){
    if(lazy[index] != 0){           // check for pending updates 
        segTree[index] += (hi-lo+1) * lazy[index];          // update the curr node
        if(lo != hi){       // push the changes to the child nodes
            lazy[2*index + 1] += lazy[index];
            lazy[2*index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }

    if(lo >= l and hi <= r) return segTree[index];
    if(hi < l or lo > r) return 0;
    int mid = (lo + hi) >> 1;
    return querySumLazy(2*index+1, lo, mid, l, r) + 
            querySumLazy(2*index+2, mid+1, hi, l, r);

}

// Lazy actually stops the update unless and until you need it and whenever you need it, it takes care of it

signed main() {
    initcode();
    int n,q; cin>>n>>q;
    arr.resize(n);
    segTree.resize(4*n);
    lazy.resize(4*n,0);         // lazyTree is initalised with 0 --> indicating no pending updates initally

    forn(i,n) cin>>arr[i];

    buildTree(0,0,n-1);

    while(q--){
        int t,l,r; cin>>t>>l>>r;
        l--; r--;       // 0 - based indexing
        if(t==1){
            int x; cin>>x;
            rangeUpdate(0,0,n-1,l,r,x);
        }
        else{
            cout<<querySumLazy(0,0,n-1,l,r)<<endl;
        }
    }
    
    
}






