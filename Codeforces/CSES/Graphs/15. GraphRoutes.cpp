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
#define inf             1e18
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
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a / gcd(a, b) * b);
}

int modularBinaryExponentitation(int base, int exponent) {
	if(exponent==0) return 1;
	int val = modularBinaryExponentitation(base, exponent/2);
	if(exponent%2)
		return ((val*val)%mod*base)%mod;
	else
		return (val*val)%mod;
}

struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};

vector<vector<int>> adj;
vector<int> dp;
int N;


// dp[sv] = -1 means ans is not computed for this sv yet
// Initlly dp will be -1 for all sv
// dp[sv] >= 0, 0 in case if there exists no path

int dfs(int sv){
    if(sv == N) return 1;
    if(dp[sv] != -1) return dp[sv];

    int ans = 0;
    for(auto nb: adj[sv]){
        int val = dfs(nb);
        ans = (ans + val)%mod;   
    }

    // if(ans == 0) return dp[sv] = -1; // dp[sv] = -1 means there is no path from sv to dest n
    // else return dp[sv] = ans;

    // ans 0 means there is no path from sv to dest
    return dp[sv] = ans;
}



// In this problem, we have to count the no of paths from src to dest.
// If there exists no path return 0

signed main() {
	initcode();
    int n,m; cin>>n>>m;
    N = n;
    adj.resize(n+1);
    dp.resize(n+1, -1);
    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }

    cout<<dfs(1)<<endl;
}


