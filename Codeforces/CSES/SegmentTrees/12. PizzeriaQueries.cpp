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

// Need 2 segTrees in this problem up and down.
vector<int> up, down; // up tracks min value of p[j] + j, whearas down tracks min value of P[j] - j
vector<int> arr;

// tracks min value of P[j] - j
void buildDownSegTree(int index, int lo, int hi){
    if(lo == hi){
        down[index] = arr[lo] - lo;
        return;
    }
    int mid = (lo + hi)/2;
    buildDownSegTree(2*index+1, lo,mid);
    buildDownSegTree(2*index+2, mid+1,hi);
    down[index] = min(down[2*index + 1], down[2*index + 2]);
}
// tracks min value of P[j] + j
void buildUpSegTree(int index, int lo, int hi){
    if(lo == hi){
        up[index] = arr[lo] + lo;
        return;
    }
    int mid = (lo + hi)/2;
    buildUpSegTree(2*index+1, lo,mid);
    buildUpSegTree(2*index+2, mid+1,hi);
    up[index] = min(up[2*index + 1], up[2*index + 2]);
}

// index -> segTreee index
// lo, hi -> array boundary
// update the value of position x to val
void updateDownSegTree(int index, int lo, int hi, int x, int val){
    if(lo == hi){
        down[index] = val - x;
        return;
    }
    int mid = (lo + hi)/2;
    if(x<=mid){
        updateDownSegTree(2*index+1,lo,mid,x,val);
    }
    else{
        updateDownSegTree(2*index+2,mid+1,hi,x,val);
    }
    down[index] = min(down[2*index + 1], down[2*index + 2]);
}
void updateUpSegTree(int index, int lo, int hi, int x, int val){
    if(lo == hi){
        up[index] = val + x;
        return;
    }
    int mid = (lo + hi)/2;
    if(x<=mid){
        updateUpSegTree(2*index+1,lo,mid,x,val);
    }
    else{
        updateUpSegTree(2*index+2,mid+1,hi,x,val);
    }
    up[index] = min(up[2*index + 1], up[2*index + 2]);
}

int queryDownSegTree(int index, int lo, int hi, int l, int r){
    // case 1: complete overlap
    if(lo >= l and hi <= r) return down[index];
    // case 2: completely out of bound
    if(hi < l or lo > r) return INF;    // since we need min value, hence returning INF for out of bounds
    // partial overlap
    int mid = (lo + hi) / 2; 
    return min(queryDownSegTree(2*index+1,lo,mid,l,r),
                queryDownSegTree(2*index+2,mid+1,hi,l,r));
}
int queryUpSegTree(int index, int lo, int hi, int l, int r){
    // case 1: complete overlap
    if(lo >= l and hi <= r) return up[index];
    // case 2: completely out of bound
    if(hi < l or lo > r) return INF;    // since we need min value, hence returning INF for out of bounds
    // partial overlap
    int mid = (lo + hi) / 2; 
    return min(queryUpSegTree(2*index+1,lo,mid,l,r),
                queryUpSegTree(2*index+2,mid+1,hi,l,r));
}
// Solution1
signed main() {
    initcode();
    int n,q; cin>>n>>q;
    arr.resize(n);
    down.resize(4*n);
    up.resize(4*n);
    forn(i,n) cin>>arr[i];

    buildDownSegTree(0,0,arr.size()-1); // O(N)     // tracks min value of P[j] - j
    buildUpSegTree(0,0,arr.size()-1);   //O(N)    // tracks min value of P[j] + j


    // Overall complexity: O(qlogN)
    while(q--){
        int t; cin>>t;
        if(t==1){
            int k,x; cin>>k>>x;
            k--;                    // update value of pos k to x
            arr[k] = x;
            updateDownSegTree(0,0,arr.size()-1,k,x);    // O(logN)
            updateUpSegTree(0,0,arr.size()-1,k,x);      // O(logN)
        }
        else{
            int k; cin>>k; k--;
            // downstream
            int d = queryDownSegTree(0,0,arr.size()-1,0,k-1) + k;  // O(logN)
            int u = queryUpSegTree(0,0,arr.size()-1,k+1,n-1) - k;   // O(logN)
            int curr = arr[k];

            cout<<min({d,u,curr})<<endl;

        }
    }
    
    return 0;

}