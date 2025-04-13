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

vector<int> arr, seg_arr;

// index represents the index of the seg_tree
// lo and hi represents the range that seg_arr[index] is managing
void buildTree(int index, int lo, int hi){
    if(lo == hi){ // base case 
        seg_arr[index] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(2*index+1, lo, mid);
    buildTree(2*index+2, mid+1, hi);
    // backtrack
    seg_arr[index] = min(seg_arr[2*index+1], seg_arr[2*index+2]);
}

// index represents the index of the seg_tree
// lo and hi represents the range the seg_arr[index] is managing
// l and r represens the range for which we want to compute the max for 
int queryTree(int index, int lo, int hi, int l, int r){
    // 3 cases: complete overlap, out of range, partial overlap 
    // complete overlap:  range of the curr index(lo,hi) lies completely within the query range l and r
    // l <= lo <= hi <= r
    if(lo>=l and hi<=r){
        return seg_arr[index];
    }
    // case 2: out of bounds : query range is either completeley behind the seg_arr index range or ahead of the seg-arr index
    // lo & hi seg tree index range whereas l and r query range
    //  lo <= hi <=  l  <= r  or l <= r <= lo <= hi 
    if(hi < l or lo  > r) return INT_MAX;   // returning INT_MAX, since we need to determine min element in range [l,r]

    // if neither of the above 2 if statements are true, then it means, we have a partial overlap 
    // Here we will move in both the directionss
    int mid = lo + (hi-lo)/2;
    // compute left ans: (index,lo,mid) --> segTree parameters and (l to r) our parameters
    int left = queryTree(2*index+1, lo, mid, l, r);
    // compute right ans
    int right = queryTree(2*index+2, mid+1, hi, l, r);

    // ans at root is max of left and right
    return min(left,right);

}

// given an array, your task is to find min in the range of l to r. You are given q queries
// We'll use segment tree
signed main() {
    initcode();
    int n,q; cin>>n>>q;
    arr.resize(n);
    seg_arr.resize(4*n); // the max size of the seg_arr will be 4 times the array size
    forn(i,n) cin>>arr[i];

    // This function builds the segment tree & takes O(n) time, where n is the array size
    // Each index of the segment tree stores the result of a particular range
    // root's index is 0 and it manages range 0 to n-1
    // left child index is 2*index_of_parent + 1 & manages range low to mid
    // right child index is 2*index_of_parent + 2 & manages range mid+1 to hi
    buildTree(0,0,n-1); // seg_tree index, array boundary 0 , n-1

    // TC: O(QlogN)
    // queryTree is O(logN)
    while(q--){
        int l,r; cin>>l>>r;
        l--; r--;
        cout<<queryTree(0,0,n-1,l,r)<<endl; // index, seg_arr index range (0 to n-1), query range(l to r)
    }
    
    return 0;
    
}






