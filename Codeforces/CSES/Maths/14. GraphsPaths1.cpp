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
int log_a_with_base_b(int a, int b){
        return log2(a) / log2(b);
}
void print_graph(vector<vector<int>> adj){
	forn(i,adj.size()){
		cout<<i<<": ";
		forn(j,adj[i].size()){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}
int modularBinaryExponentitation(int base, int exponent) { // compute (a^b)%mod efficiently using binary exponentiation
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
int modinv(int b, int c){
    return modularBinaryExponentitation(b, c-2);
}

// matrix multiplication function -- multiplies matrices a(n X m) and b(m X k) and returns the output
vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b){
    int n = a.size(), m = a[0].size(), k = b[0].size();
    
    vector<vector<int>> res(n, vector<int>(k));

    for(int row=0;row<n;row++){
        for(int col=0;col<k;col++){
            int val = 0;
            for(int i=0;i<m;i++){
                val = (val + (a[row][i] * b[i][col])%mod)%mod;
            }
            res[row][col] = val;
        }
    }

    return res;
}

// base will be n X n square matrix
vector<vector<int>> matrixExponentiation(vector<vector<int>> &base, int pow){
    int n = base.size();
    if(pow == 0){   // return identity matrix of size n
        vector<vector<int>> res(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            res[i][i] = 1;
        }
        return res;
    }

    vector<vector<int>> temp = matrixExponentiation(base, pow/2);
    vector<vector<int>> res = multiply(temp,temp);
    if(pow%2){
        return multiply(res,base);
    }
    return res;

}

signed main() {
    initcode();
    int n,m,k; cin>>n>>m>>k;
    // reading graph as adj matrix
    vector<vector<int>> adj(n, vector<int>(n));
    forn(i,m){
        int u,v; cin>>u>>v;
        u--; v--; 
        adj[u][v]++
    }
// Solution 1: using recursion + memoisatoin --> will TLE since K can go upto 1e18
//  TC of this sol would be O(n * k)

// Solution 2: using matrix exponentiation: O(n^3logK)
    // compute the # of ways from node 1 to n with exactly k edges:
        // compute M^k and return value of cell (0,n-1)
    vector<vector<int>> res = matrixExponentiation(adj, k);
    cout<<res[0][n-1]<<endl;


    return 0;
}



