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


vector<int> arr, segarr;

// max segment tree
void buildTree(int index, int lo, int hi){
    if(lo == hi){
        segarr[index] = arr[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    buildTree(2*index+1, lo, mid);
    buildTree(2*index+2, mid+1, hi);
    segarr[index] = max(segarr[2*index+1], segarr[2*index+2]);
}

// this function  prints the answer and updates the tree as well  
void queryupdate(int index,int lo, int hi, int val){
    if(lo == hi){
        segarr[index] -= val;
        cout<<lo+1<<" ";
        return;
    }    
    
    int mid = (lo + hi) >> 1;
    
    // assuming that you know that ans is in range [l,r]
    // if max(al,...,amid) >= xthen we know that the ans is in the range [l,mid].
    // Otherwise the ans is in range [mid+1,r]
    if(segarr[2*index+1] >= val) queryupdate(2*index+1,lo,mid,val);
    else queryupdate(2*index+2,mid+1,hi,val);
    
    segarr[index] = max(segarr[2*index+1], segarr[2*index+2]);
}

// Solution Explaination:  https://usaco.guide/plat/segtree-ext?lang=cpp
signed main() {
    initcode();
    int n,m; cin>>n>>m;
    arr.resize(n);
    segarr.resize(4*n);
    forn(i,n) cin>>arr[i];
    buildTree(0,0,n-1); // stores max for each segment

    // instead of binary searching and querying the max segment tree separately, let's do them teogeher! 
    // This reduces the complexity from O(log^2N) to O(logN)
    // That's why we've clubbed both the query and update part in 1 single function 
 

    forn(i,m){
        int x; cin>>x;
        // if the root's value isn't enough
        if(segarr[0] < x) cout<<"0 ";
        else queryupdate(0,0,n-1,x);
    }

    // TC: O(N + QlogN)



// Multiset approach wont work since it sorts the rooms in increasing order and we might find an index that is lower than the index found by the lower bound  

    // multiset<pair<int,int>> s;
    // forn(i,n){
    //     int x; cin>>x;
    //     s.insert({x,i+1}); // capacity,hotel_id [1,N]
    // }
    
    // printMultiset(s);

    // vector<int> res(m);
    // forn(i,m){
    //     int req; cin>>req;
    //     auto it = s.lower_bound({req,0});
    //     if(it == s.end()) res[i] = 0;
    //     else{
    //         int val = (*it).first;
    //         int hotel_id = (*it).second;
    //         s.erase(it);
    //         if(val - req > 0){
    //             s.insert({val-req,hotel_id});
    //         }
    //         res[i] = hotel_id;
    //     }
    // }

    // forn(i,n) cout<<res[i]<<" ";
    // cout<<endl;
    
}




