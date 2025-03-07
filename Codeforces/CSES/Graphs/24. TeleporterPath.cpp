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
vector<bool> vis;
vector<int> outdeg;
vector<int> indeg;
stack<int> s;
int N;

// simple dfs: visit all the nodes you can that are part of sv component
void dfs(int sv){
    vis[sv]=true;
    for(auto nb: adj[sv]){
        if(!vis[nb]){
            dfs(nb);
        }
    }
}

// checks if all the edges are part of 1 single component
bool isConnected(){
    vis.resize(N+1,false);

    int starting_node;
    // find the first vertex that has some edges, that will be our starting node for dfs
    fore(i,1,N){
        if(adj[i].size() > 0){
            starting_node = i; break;
        }
    }
    if(starting_node == -1){ // graph contains no edges
        return false;
    }

    dfs(starting_node); // this will visit all the nodes that are connected to starting_node

    // check if there exists any node that is not visited yet and has some edges -- it means we have multi component graph
    fore(i,1,N){
        if(!vis[i] and adj[i].size()>0)
            return false;
    }

    // now it's confirmed that all the edges are part of 1 single component. There might exist single nodes outside this component, but they will not have any edges
    if(!vis[1] or !vis[N]) return false; // edge case

    return true;

}

void dfs_to_generate_euler_path(int sv){
    // check if there exists any nb for sv. If yes, then remove that edge and call dfs on nb. If no nb's exist, add the node into the stack and return
    while(!adj[sv].empty()){
        int nb = adj[sv].back();
        adj[sv].pop_back(); // remove the sv -> nb edge. since it's a directed graph only 1 edge needs to be removed
        
        dfs_to_generate_euler_path(nb);
    }

    s.push(sv);
}

// given a directed graph, we have to determine if there exists euler path which starts from 1 and ends at n
// Some necessary prerequisites for euler path:
// 1. all the edges should be part of one single component. There should not exists more than 1 components with edges
// 2. Exactly 2 nodes starting and ending node will have an odd degree, rest must have an even degree. In our case, ensure node 1 and n has odd degree and 1 and n should be part of the same connected component

signed main() {
    initcode();
    int n,m;
    cin>>n>>m;
    N = n;
    adj.resize(n+1);
    outdeg.resize(n+1,0);
    indeg.resize(n+1,0);
    
    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back(v); // u to v directed edge
        // deg[v]++;
        outdeg[u]++;
        indeg[v]++;
    }

    if(!isConnected()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    int cnt = 0;

    int v1=-1,v2=-1;
    fore(i,1,n){
        if(outdeg[i]!=indeg[i]){
            if(abs(outdeg[i]-indeg[i]) != 1){
                cout<<"IMPOSSIBLE"<<endl; return 0;
            }
            else cnt++;
        }
    }

    if(cnt > 2){ 
        cout<<"IMPOSSIBLE"<<endl; 
        return 0;
    }

    // if v1 == -1 -> then it means it is a euler circuit
    dfs_to_generate_euler_path(1);

    vector<int> res;
    while(!s.empty()){
        auto t = s.top();
        s.pop();
        res.push_back(t);
    }

    if(res.back() != n){ // edge case: the tour must start at 1 and end at n 
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    for(auto val: res) cout<<val<<" ";
    cout<<endl;

}

