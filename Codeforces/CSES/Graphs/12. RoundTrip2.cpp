#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update>; // policy based data structure
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
void initcode(){
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
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
 
int modularBinaryExponentitation(int base, int exponent){
    if(exponent==0) return 1;
    int val = modularBinaryExponentitation(base, exponent/2);
    if(exponent%2)
        return ((val*val)%mod*base)%mod;
    else    
        return (val*val)%mod;
}
 
struct cmp{
    bool operator()(const pii& p1, const pii& p2){
        return p1.second < p2.second;  
    }
};

// Move all the declarations to global scope
vector<vector<int>> adj;
vector<bool> vis, pathVis;
vector<int> path; 		// this vector will contain the cycle
map<int,int> mp; 		// this mp will be used to construct the cycle
int sp = -1, ep = -1;
 
void constructPath(){
    path.push_back(sp);
    int curr = mp[sp];
    while(curr != ep){
        path.push_back(curr);
        curr = mp[curr];
    }
    path.push_back(curr);
    path.push_back(sp);
}
 

// detect cycle using DFS
// sp and ep denotes the starting and ending point of the cycle
// mp is used to construct the cycle
// need parent to track the path
bool dfs(int sv, int parent){
    vis[sv] = true;
    pathVis[sv] = true;
    mp[parent] = sv;  				// using map -> just for purpose of cycle construction so that we know from which vertex we landed at the curr vertex 
 
    for(auto nb: adj[sv]){
        if(!vis[nb]){
            if(dfs(nb,sv)) return true;
        }
        else if(vis[nb]==true and pathVis[nb]==true){
            sp = nb; ep = sv;  		// got the starting and ending point of our cycle
            constructPath();		// constructs the cycle and stores it in path
            return true;
        }
    }
 
    pathVis[sv] = false;			// not part of a cycle, thus removing the node from the current path
    return false;
}
 

// We just need to detect if there is any cycle in the graph or not and then return the cycle -- this only will not work
// we only need to include nodes that are part of the cycle not all the nodes i.e we have to find the starting & ending point of the cycle;
// We need to detect the starting and ending point of the cycle and then construct the cycle 
signed main(){
    initcode();
    int n,m; cin>>n>>m;
    adj.resize(n+1); // 1 to n vertices
    
    // We have to start a node and check if we can reach the same node again or not. No compulsion to cover all the nodes or all edges. and all the edges are unidirectional.
    // So we just need to check if there is a cycle in the directed graph or not. 
    // Use parent[] to construct the cycle
    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back(v); // it's a one way edge
    }
 
	vis.resize(n+1,false);
	pathVis.resize(n+1,false);
 
    bool ans = false;
 
    fore(i,1,n){
        if(!vis[i]){
            if(dfs(i,-1)){ 
                ans = true; break;
            }
        }
    }
    
    if(ans){
        cout<<path.size()<<endl;
        forn(i,path.size()) cout<<path[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    
}