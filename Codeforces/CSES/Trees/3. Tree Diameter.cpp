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

vector<vector<int>> adj;
vector<int> dp; // added Dp to overcome TLE for testcases

// can optimise by adding memoisatoin so that repeated subproblems aren't computed again
int getHeight(int sv, int parent){

    if(dp[sv] != -1) return dp[sv]; // check if the depth is already computed

    int best = 0;
    bool childFound = false;
    for(auto nb: adj[sv]){
        if(nb != parent){
            best = max(best, getHeight(nb,sv));
            childFound = true;
        }
    }
    
    if(!childFound) return dp[sv] = 0; // leaf node
    return dp[sv] = best + 1;

}

// solve function returns the diameter(in terms of no of edges)
int solve(int sv, int parent){

    // 2 options --> return the max of them 
    // Either the diameter passes through the root
    // Or is part of any of the subtree

    // 1st case if the diameter does not pass through the root
        // for each subtree calculate the diameter & pick hte max once
    int best = 0;
    for(auto nb: adj[sv]){
        if(nb != parent){
            best = max(best, solve(nb,sv));
        }
    }

    // 2nd case if the diameter passes through root
        // get the depth of the 2 deepest subtree or there is a possiblity that there is just 1 subtree or no subtree at all
    vector<int> heights;
    for(auto nb: adj[sv]){
        if(nb != parent){ // compute the height of each subtree
            int depth = getHeight(nb, sv);
            heights.push_back(depth);
        }
    }

    // sort the heights vector, to pick the max 2 height
    sort(all(heights));
    int ans = 0;
    if(heights.size() >= 2){
        int sz = heights.size();
        ans =heights[sz-1] + heights[sz-2] + 2; // this is your diameter
    }
    else if(heights.size() == 1){
        ans = heights[0]+1;
    }

    return max(ans, best);

}
signed main() {
    initcode();
    int n; cin>>n;
    adj.resize(n+1);
    forn(i,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.resize(n+1,-1); // initialising with -1 indicating the height isn't computed yet 
    // dp[i] denotes the height of the subtree at i node

    // n nodes (1 to n). OUt of this you can pick any value which is in range [1,n] and consider it your root
    // assuming 1 is the root of the tree. (You can pick any node among (1 to N) both inclusive as your root)
    // but since our will run on multiple hidden test cases, we dont know the actual value of N against which our code will be executed. N is gauranteed to be >= 1. Hence choosing 1 as your root makes sense
    int diameter = solve(1,-1);
    cout<<diameter<<endl;

    return 0;

}






