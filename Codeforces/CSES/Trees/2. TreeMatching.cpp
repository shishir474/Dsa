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

vector<vector<int>> adj, dp;


// returns the final ans as max(dp[i][0],dp[i][1]) for ith vertex
int solve(int sv, int parent){

    // cout<<sv<<endl;

    // case1 : not selecting any edge from the sv i.e dp[sv][1]
        // solution : just call recusion on all the childrens
    int op1 = 0;

    if(dp[sv][1] != -1) op1 = dp[sv][1];  // if already computed, use it
    else{ // compute it
        for(auto nb: adj[sv]){
            if(nb != parent){
                op1 += solve(nb, sv);
            }
        }
        dp[sv][1] = op1;  // save it for future reference
    }

    
    // case 2: selecting a particular edge
    // choose the best child -->  we cannot select all the child nodes
    int best = 0;
    if(dp[sv][0] != -1){ // if already computed
        best = dp[sv][0];  // use it
    }
    else{   // compute it
        vector<int> children;
        for(auto nb: adj[sv]){
            if(nb != parent)
                children.push_back(nb);
        }

        int sz = children.size();

        // perform operation only if children.size() > 0
        if(sz == 0){        // dp is initialised with -1, indicating computation hasn't been performed yet
            dp[sv][0] = 0;
        }
        else{
            // used prefix and suffix arrays to optimise the calculation of sums from (0 to i-1) and (i+1 to n)
            vector<int> prefix(children.size(),0), suffix(children.size(),0);

            vector<int> temp(children.size());

            for(int j=0;j<children.size();j++){
                temp[j] = solve(children[j], sv);
            }

            prefix[0] = temp[0];
            for(int j=1;j<children.size();j++)
                prefix[j] = prefix[j-1] + temp[j];

            suffix[sz-1] = temp[sz-1];
            for(int i=sz-2;i>=0;i--){
                suffix[i] = suffix[i+1] + temp[i];
            }

            // optimised the summation of prefix and suffix by computing it beforehand --> thus reducing the complexity from O(n^2) to O(n)
            for(int i=0;i<children.size();i++){
                // if I select ith child children[i]
                int cnt = 0;
                // for(int j=0;j<i;j++){
                //     cnt+=solve(children[j], sv);
                // }
                if (i > 0)
                    cnt += prefix[i-1];
                // for(int j=i+1;j<children.size();j++){
                //     cnt+=solve(children[j], sv);
                // }
                if(i < children.size()-1)
                    cnt += suffix[i+1];

                for(auto nb: adj[children[i]]){
                    if(nb!=sv){
                        cnt+=solve(nb, children[i]);
                    }
                }

                best = max(best, cnt+1);
            }

            dp[sv][0] = best;

        }
        
            
    }
    
    
    return max(dp[sv][0], dp[sv][1]);

}


signed main() {
    initcode();
    
    // it is given in the problem statement that the input is a tree (connected and acyclic graph)
    int n; cin>>n;
    adj.resize(n+1);
    
    // n vertices and n-1 edges
    // assuming that 1 is the root of the tree;
    forn(i,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.resize(n+1, vector<int>(2,-1)); // dp[i][0] and dp[i][1]
    // -1 indicates that the dp value isnt' computed yet!

    // 2 states for each vertex
    // dp[i][0] --> include any edge with i as one of the endpoint
    // dp[i][1] --> dont include i 
    // final ans = dp[1][0] + dp[1][1] i.e summation of both the possiblilities for 1(assuming 1 is the root of the tree)

    solve(1,-1);
    
    cout<<max(dp[1][0], dp[1][1])<<endl;
    
    // fore(i,1,n){
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    // }

}






