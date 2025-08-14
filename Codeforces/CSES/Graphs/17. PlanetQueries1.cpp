#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define double long double
#define endl '\n'
 
const int MOD = 1000000007;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int n,q;
    cin>>n>>q;
    int m = 30;
 
    vector<vector<int>> sparseTable(m+1,vector<int> (n+1,-1));
    for (int i = 1; i <= n; i++) {
        cin>>sparseTable[0][i];
    }
 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
        }
    }
 
    while(q--) {
        int x,k;
        cin>>x>>k;
        int ans = x;
        for (int i = 0; i <=m; i++) {
            if (k&(1<<i)){
                ans = sparseTable[i][ans];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

// debug my code
// There is one more crucial part to this problem, the no of columns are always preffered to be more than no of rows in cpp. This is an optimisation techinque 
// Without this optimisation, my code is giving runtime error



// Interesting part of this problem is either we can matrix mat of dimensions (n+1 X 31) or (31 X n+1) 
// n <= 1e5
// 2nd option (31 X n+1) is more optimised. This is because c++ stores the values of a row in a contigous manner and this makes the access much faster 
// mat[i][j] denotes the 2^i th parent of node j 
// Populate the 0th row since we already know the parent of each node
// Now as part of the for loop populate the rest of the rows (mat will be filled in a row wise fashion)

// The benefit of having 2^ith parent pre computed is we can efficiently find the kth parent of a node in log(k) time as compared to O(k) 
// This works because every whole no can be reprensented in the powers of 2.



// Similar implementation --> Just made code more modular

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

vector<vector<int>> adj, mat;
int N;

void populate(){
    for(int i=1;i<=30;i++){  // 2^i th parent
        for(int j=1;j<=N;j++){ // jth node where j belongs to [1,N]
            // mat[i][j] ==> jth node 2^ith parent
            // 2^i = 2^(i-1) + 2^(i-1) or 2^i = 2*(2^(i-1))
            int node =  mat[i-1][j]; 
            mat[i][j] = mat[i-1][node];
        }
    }
}

void compute(int sv, int k){
    // compute the k th parent of sv
    // we already know 2^i th parent of each vertex --> precomputed 
    int curr = sv;
    for(int i=30;i>=0;i--){
        if(k&(1<<i)){
            curr = mat[i][curr];
        }
    }

  
    cout<<curr<<endl;

}

// Doubt: Why did we choose 31 as the limit, shouldn't it be log2(n) + 1
signed main() {
    initcode();
    int n,q; cin>>n>>q; // n vertices and q queries
    
    // 21*1e5 sized matrix
    // why vertices along the columnwise --> In cpp, multidimension arrays are stored in row major order which means eleemnts in the same row are stored contigously in the memory
    // now depending on our access patterns, storing the values this way is more efficient
    // NOTE: if we store the matrix in the other other --> code is giving runtime error.

    // one thing is clear -> we always give more preference to more no of columns rather than more no of rows 
    mat.resize(31, vector<int>(n+1,-1)); // n vertices along the column side & 2^ith parent along the row side 
    N = n;

    fore(i,1,n) cin>>mat[0][i]; // ith vertex => 2^0 i.e 1st parent
    
    populate();

    while(q--){
        int x,k; cin>>x>>k;  // x is the starting node,  k is the distance
        compute(x,k);
    }
    
}






