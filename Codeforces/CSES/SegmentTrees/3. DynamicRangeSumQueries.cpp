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
// int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
// int log_a_with_base_b(int a, int b) { return log2(a) / log2(b); }
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


vector<int> arr, segarr;

// this particular node of the seg tree has an index -> index and stores the ans for the range lo to hi 
void buildTree(int index, int lo, int hi){
    if(lo == hi){
        segarr[index] = arr[lo];
        return;
    }
    int mid = (lo + hi)>>1;
    buildTree(2*index+1,lo,mid);
    buildTree(2*index+2,mid+1,hi);
    segarr[index]=  segarr[2*index+1] + segarr[2*index+2];
}

// update the value of the index u to v
// (index,lo,hi) --> segment tree parameters
void updateTree(int u, int v, int index, int lo, int hi){
    if(lo == hi){
        // segarr[index] = arr[lo];
        segarr[index] = v;
        return;
    }
    int mid = (lo + hi) >> 1;
    if(u <= mid){
        updateTree(u,v,2*index+1,lo,mid);
    }
    else {
        updateTree(u,v,2*index+2,mid+1,hi);
    }
    segarr[index] = segarr[2*index+1] + segarr[2*index+2];
}

// this particular node of the seg tree has an index -> index and stores the answer for the range lo to hi
// and we are looking for evaluating answer for the range l to r
int queryTree(int index, int lo, int hi, int l, int r){
    // 3 cases: 
    // case1: Complete overlap: Nodd's range lies completely within the range l to r
    if(lo>=l and hi<=r) return segarr[index];
    // case 2: Complete outside: Node's range lies outside the range l to r
    if(hi < l or lo > r) return 0; // since we have to return the sum, for range outside our range we 'll return 0
    int mid = (lo + hi) >> 1;
    int left = queryTree(2*index+1,lo,mid,l,r);
    int right = queryTree(2*index+2,mid+1,hi,l,r);
    return left+right;
}

signed main() {
    initcode();
    int n,q; cin>>n>>q;
    arr.resize(n);
    segarr.resize(4*n);
    forn(i,n) cin>>arr[i];
    buildTree(0,0,n-1);
    
    // TC: O(QlogN) where N is the array size 
    // both updateTree() and queryTree() are log(N) operations
    while(q--){
        int t,u,v; cin>>t>>u>>v;
        if(t==1){
            // update the position u's value to v
            u--; // u is 1 based in prblem steatement
            updateTree(u,v,0,0,n-1); // u,v,index,0,n-1
        }
        else{ 
            // get the ans for the range u to v, decremented both by 1 since we are following 0 based indexing
            u--; v--;
            cout<<queryTree(0,0,n-1,u,v)<<endl;
        }
       
    }

    return 0;
    
}






