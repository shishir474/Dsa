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
vector<int> height,ans;

// depth calculation is based on no of edges
int evalDepth(int sv, int parent){
    int best = 0;
    bool childFound = false;
    for(auto nb: adj[sv]){
        if(nb != parent){
            best = max(best, evalDepth(nb, sv)); // compute the max depth amongst all child subtrees
            childFound = true;
        }
    }

    // if leaf node
    if(!childFound) return height[sv] = 0; 
    return height[sv] = 1+best;
}


void evalDistance(int sv, int parent, int partial_ans){

    vector<int> prefixMax, suffixMax;
    for(auto nb: adj[sv]){
        if(nb != parent){
            prefixMax.push_back(height[nb]);
            suffixMax.push_back(height[nb]);
        }
    }

    for(int i=1;i<prefixMax.size();i++){
        prefixMax[i] = max(prefixMax[i-1], prefixMax[i]);
    }
    for(int i=suffixMax.size()-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i+1], suffixMax[i]);
    }

    int childno = 0, numChild = prefixMax.size();
    for(auto nb: adj[sv]){
        if(nb!=parent){
            // if first child, prefixMax[i-1] won't exist
            int leftmax = (childno == 0) ? INT_MIN : prefixMax[childno-1];
            // if last child, suffixMax[i+1] wont exist
            int rightmax = (childno == numChild-1) ? INT_MIN : suffixMax[childno+1];
            
            // cout<<nb<<" "<<leftmax<<" "<<rightmax<<" "<<partial_ans<<endl;
            // partial_ans wrt this child
            int next_partial_ans = 1 + max({leftmax, rightmax, partial_ans}); // having all 3 parameters is important 
            
            // recursion call
            evalDistance(nb, sv, next_partial_ans);

            childno++;
        }
    }

    // for root node, there will be no siblings, hence partial_ans is not applicable to it and thus we''ll consider the height as the ans for that node
    // 1+partial_ans ==> 1 for distance of the node from its parent. partial_ans is computed from the parent
    // cout<<sv<<" "<<partial_ans<<endl;
    ans[sv] = max(height[sv], 1+partial_ans);

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
    
    height.resize(n+1, -1); // -1 indicates height[i] isn't computed yet
    
    // height[i] stores height of the subtree rooted at node i
    ans.resize(n+1,-1);
    // ans[i] stores the max distance to another node for node i
    // ans[i] = max(1+partial_ans(i), depth(i))
    // where partial_ans(i) denotes the max depth of its parent considering the fact that ith node subtree is not considered 
    // partial_ans(i) ==> partial_ans for ith node is max(prefixMax[i-1], suffixMax[i+1])
    // considering n siblings and we are currently analysing ith sibling, prefixMax[i] gives the max depth amongst the first i siblings(0 to i-1)
    // and suffixMax[i] gives the max depth amonst the siblings on the right (i+1 to n-1)
    // This will help us get the max depth amongst the left and right siblings in O(1) time
    // so partial_ans(i) = 1 + max(prefixMax[i-1],suffixMax[i+1])
    // added 1 in order to consider the distance from parent

    // Assuming the tree is rooted at 1
    evalDepth(1,-1);
    // fore(i,1,n) cout<<height[i]<<" ";
    // cout<<endl;
    
    evalDistance(1,-1,-1); // sv, parent, partial_ans
    // we're propagating partial_ans for each node downwards --> THis is the heart of the problem --understanding why propagating partial_ans is important and why cant wejust compute it at each node 

    fore(i,1,n) cout<<ans[i]<<" ";
    cout<<endl;


}






