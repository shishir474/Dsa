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

vector<int> blocks;
vector<int> arr;

// computes the sum of the range l to r 
int query(int l, int r, int block_size) {
    int ans = 0;

    while (l <= r && l % block_size != 0) {
        ans += arr[l];
        l++;
    }

    while (l <= r && l % block_size == 0 && l + block_size - 1 <= r) {
        ans += blocks[l / block_size];
        l += block_size;
    }

    while (l <= r) {
        ans += arr[l];
        l++;
    }

    return ans;
}

// update the value of index i to val
void update(int i, int val, int block_size){
    // index i is at (i%block_size) index in the blocks array
    blocks[(i%block_size)] += (val - arr[i]);       // adding the difference (new_val - orig_value)
    arr[i] = val;
}

signed main() {
    initcode();
    arr = {1,3,5,2,7,6,3,1,4,8};  
    int n = arr.size();
    int block_size = sqrt(n);
    blocks.resize(block_size + 1);
    
    int block_id = -1;
    for (int i = 0; i < n; i++) {
        if (i % block_size == 0) {
            block_id++;
        }
        blocks[block_id] += arr[i];
    }
    
    int l = 6, r = 9;
    cout << query(l, r, block_size) << endl;
}

// We are divding out input array into chunks of size sqrt
// Each chunk will be of size sqrt i.e 3 and will store the sum of elements of that range 
// .     .     .     .
// 0 1 2 3 4 5 6 7 8 9
// 1,3,5,2,7,6,3,1,4,8

// 0       1       2       3
// 1+3+5   2+7+6   3+1+4   8+0+0
// 9       15      8       8

// 15 + (8-7)
// 15 + (6-7)

// [2,7]  --> [2-2] + [3-5] + [6-7]
// [l,r] chunk is broken down into 3 chunks 
// Time required to process each chunk would be O(sqrt(n)) in the worst case. Hence the ans for the range [l,r] can be evaluated in O(sqrt(n))
// instead of O(n)
// Using Segment Tree, we can do the same in O(logn) time  

// sqrt(10) = 3







