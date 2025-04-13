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

vector<vector<int>> adj;
vector<int> values,startTime,endTime,arr,segTree;
int timer = 0;

// call from main as dfs(0,-1);
void dfs(int sv, int parent){
	startTime[sv] = timer++;
	for(auto nb: adj[sv]){
		if(nb != parent){
			dfs(nb, sv);
		}
	}
	endTime[sv] = timer++;
}

// sum segment Tree
// TC: O(N)
void buildTree(int index, int lo, int hi){
	if(lo == hi){
		segTree[index] = arr[lo];
		return;
	}
	int mid = (lo + hi) >> 1;
	buildTree(2*index+1,lo,mid);
	buildTree(2*index+2,mid+1,hi);
	segTree[index] = segTree[2*index+1] + segTree[2*index+2];
}

// update pos position with val
// TC: O(logN)
void updateTree(int index, int lo, int hi, int pos, int val){
	if(lo == hi){
	    // cout<<"inside updateTree"<<endl;
	    // cout<<lo<<" "<<hi<<" "<<pos<<endl;
	    // cout<<"before "<<segTree[index]<<endl;
		segTree[index] = val;
		// cout<<"after "<<segTree[index]<<endl;
		return;
	}
	int mid = (lo + hi) >> 1;
	if(pos<=mid){
		updateTree(2*index+1,lo,mid,pos,val);
	}
	else{
		updateTree(2*index+2,mid+1,hi,pos,val);
	}
	segTree[index] = segTree[2*index+1] + segTree[2*index+2];
}

// evaluate the sum of the segment l to r 
// lo and hi is the range boundary of the segTree node whose index is also represented using index 
int queryTree(int index, int lo, int hi, int l, int r){
	// 3 cases:
	// case 1: complete overlap - seg tree range lies completely inside l to r
	if(lo>=l and hi<=r) return segTree[index];
	// case 2: complete outside the boundary
	if(hi<l or lo>r) return 0;
	// 3rd case: partial overlap - move in both the directions
	int mid = (lo + hi) >> 1;
	int left = queryTree(2*index+1,lo,mid,l,r);
	int right = queryTree(2*index+2,mid+1,hi,l,r);
	return left + right;
}	

signed main() {
    initcode();
	int n,q; cin>>n>>q;
	
	adj.resize(n);
	values.resize(n);
	startTime.resize(n);
	endTime.resize(n);

	forn(i,n) cin>>values[i];
	forn(i,n-1){
		int u,v; cin>>u>>v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// perform euler tour to compute the start and end times for each node
	dfs(0,-1);  // O(N)
	
	// cout<<timer<<endl;

	arr.resize(timer);
	// iterate over startTime array and fill arr with +ve values
	forn(i,n){
		// ith node -> startTime[i]
		arr[startTime[i]] = values[i];
	}
	// iterate over endTime array and fill arr with -ve values
	forn(i,n){
		arr[endTime[i]] =  -1*values[i];
	}

	int sz = arr.size();
	segTree.resize(4*sz);
	buildTree(0,0,sz-1); // build seg Tree on arr

	// forn(i,n) cout<<startTime[i]<<" "; // node - time relation
	// cout<<endl;
	// forn(i,n) cout<<endTime[i]<<" ";
	// cout<<endl;
	// forn(i,n) cout<<values[i]<<" "; // node - values relation
	// cout<<endl;
	// forn(i,arr.size()) cout<<arr[i]<<" "; // time-values relation
	// cout<<endl;

	while(q--){
		int t; cin>>t;
		// Both update and query are log(N) functions
		if(t==1){
			int s,x; cin>>s>>x; s--;
			// cout<<"node s start time and end time "<<startTime[s]<<" "<<endTime[s]<<endl;
			// Update the value of node s to x 
			// arr[startTime[s]] = x and arr[endTime[s]] = -x
			updateTree(0,0,sz-1,startTime[s],x); // index, lo, hi, pos, val  
			updateTree(0,0,sz-1,endTime[s],-1*x); // index, lo, hi, pos, val
		}
		else{
			int s; cin>>s; s--;
			// calculate the sum of values from root to node s which is equivalent to finding sum of the segment startTime[1], endTime[s]-1
			// cout<<"ans "<<queryTree(0,0,sz-1,startTime[0],endTime[s]-1)<<endl;
			cout<<queryTree(0,0,sz-1,startTime[0],endTime[s]-1)<<endl;

		}
	}

	// Final Time ComplexityL: O(N + QlogN)
    
}

// key things to ensure
// we'll need to execute 2 update operation to update arr[startTime[s]] = x and arr[endTime[s]] = -x
// In the updateTree function's base condition, assign segTree[index] = val, instead of arr[lo] which we usually do in buildTree 








