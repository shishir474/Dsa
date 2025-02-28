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
vector<bool> vis;
map<int,int> mp;
vector<int> path;
int N;

void constructPath(){
    int curr = 1;
    while(curr != N){
        path.push_back(curr);
        curr = mp[curr];
    }
    path.push_back(curr);
}

int dfs(int sv){
    if(sv == N){ // destination
        return 1;
    }
    if(dp[sv] != -1) return dp[sv];

    int ans = 0;
    
    //  analysed all the neighbours and picked the one that has best value
    for(auto nb: adj[sv]){
        int val = dfs(nb);
        if(val > ans){
            ans = val;
            mp[sv] = nb;
        }
        // ans = max(ans, dfs(nb));
    }

    // If the ans is still 0 it means we have reached a dead end
    // and there exists no path from this sv to N

    if(ans == 0) return dp[sv] = -1; // cannot reach dest from this sv (edge case)
    else return dp[sv] = 1 + ans; 
}

void isConnected(int sv){
    vis[sv]=true;
    for(auto nb: adj[sv]){
        if(!vis[nb]){
            isConnected(nb);
        }
    }
}

// observation points
// 1. node 1 and n must be connected. If not connected return impossible
// 2. Once it is guaranteed that the nodes 1 and n are connected, we have to find the longest path from 1 to n
// 3. For finding longest path:
//     a. considering a sv, we will check all its neighbours and get the longest path from them. Now here is 1 edge case where you can''t reach destination from the nb. If no path exists return -1
//     b. Out of all the nb's we pick the nb that gives us the longest path and also save the path in map 
//     c. we didn't used vis array in the dfs function-> reason is in the first dfs call the node would be marked vis but there might exist a different path that is the longest and passes through this node.
//     d. Used dp array to store the length of the longest path


signed main() {
	initcode();
	int n,m;
	cin>>n>>m;
	N = n;
    adj.resize(n+1);
    dp.resize(n+1, -1);
    vis.resize(n+1,false);

    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    
    isConnected(1);

    if(vis[n]==true){
        cout<<dfs(1)<<endl;
        constructPath();
        forn(i,path.size()) 
            cout<<path[i]<<" ";
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }


    
	

}

