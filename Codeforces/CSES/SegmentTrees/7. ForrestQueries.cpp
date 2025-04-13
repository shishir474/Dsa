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


// 2-D Prefix Sum 
// No use of Seg Tree here

signed main() {
    initcode();
    int n,q; cin>>n>>q;
    vector<vector<int>> mat(n,vector<int>(n,0));
    vector<vector<char>> a(n, vector<char>(n));
    forn(i,n){
        forn(j,n)
            cin>>a[i][j];
    }

    if(a[n-1][n-1] == '*') mat[n-1][n-1] = 1;
    // last row
    for(int i=n-2;i>=0;i--){
        mat[n-1][i] = mat[n-1][i+1];
        if(a[n-1][i] == '*') mat[n-1][i]++;
    }
    // last col
    for(int i=n-2;i>=0;i--){
        mat[i][n-1] = mat[i+1][n-1];
        if(a[i][n-1] == '*') mat[i][n-1]++;
    }
    // rest of the matrix
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            mat[i][j] = mat[i][j+1] + mat[i+1][j] - mat[i+1][j+1];
            if(a[i][j] == '*') mat[i][j]++;
        }
    }
    
    // forn(i,n){
    //     forn(j,n){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    while(q--){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        x1--; x2--; y1--; y2--;
        
        int ans= mat[x1][y1];
        if(x2+1 < n) ans -=  mat[x2+1][y1];
        if(y2+1 < n) ans -=  mat[x1][y2+1];
        if(x2+1 < n and y2+1 < n) ans += mat[x2+1][y2+1];

        cout<<ans<<endl;
    }

    
}






