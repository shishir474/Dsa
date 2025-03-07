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
vector<vector<int>> cap;
vector<int> parent;
vector<vector<pair<int,int>>> G;
vector<int> ans;
vector<bool> vis;
int N;

int bfs(int s=1, int t=N){
    fill(all(parent),-1);
    parent[s]=-2;

    queue<pair<int,int>> q;
    q.push({s,INF});
    while(!q.empty()){
        int curr = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(auto nb: adj[curr]){
            if(parent[nb]==-1 and cap[curr][nb] > 0){
                parent[nb] = curr;
                int new_flow = min(flow, cap[curr][nb]);
                if(nb == t)
                    return new_flow;
                q.push({nb,new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s=1, int t=N){
    int flow=0;
    int aug;

    while(aug = bfs()){
        flow += aug;
        int curr = t;
        // vector<int> path;

        while(curr != s){
            // path.push_back(curr);
            int par = parent[curr];
            cap[par][curr]-=aug;  // Reduce forward capacity
            cap[curr][par]+=aug;  // Reduce backward capacity
            curr = par;
        }
        
        // This is not the correct path
        
        // path.push_back(s);
        // reverse(all(path));
        // for(auto i: path) cout<<i<<" ";
        // cout<<endl;
    }

    return flow;
}

void dfs(int sv=1){
    ans.push_back(sv);
    if(sv == N) return;
    for(auto i: G[sv]){
        int nb = i.first;
        int id = i.second;
        if(cap[sv][nb] == 0 and !vis[id]){ // if the capacity of that edge is 0 and edge is not visited
            vis[id]=true; // marking the edge vis 
            dfs(nb);
            return;
        }
    }
}

signed main() {
    initcode();
    int n,m; cin>>n>>m;
    N = n;
    adj.resize(n+1);
    G.resize(n+1);
    parent.resize(n+1); 
    vis.resize(m+1,false);  // vis is used to track the unused edges
    cap.assign(n+1,vector<int>(n+1,0));

    forn(i,m){
        int u,v; cin>>u>>v;
        G[u].push_back({v,i});
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v]+=1;
    }

    int K = maxflow();
    cout<<K<<endl;
    
    // for(int i=1;i<n+1;i++){
    //     for(int j=1;j<n+1;j++){
    //         cout<<cap[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // cout<<"yes"<<endl;
    
    // separate dfs() call to find out the paths 
    // choose only those edges that are fully utilised and not vis
    // used vis to ensure each edge is only used once in DFS
    for(int k=0;k<K;k++){
        ans.clear();
        
        dfs();
        cout<<ans.size()<<endl;
        for(auto i: ans) cout<<i<<" ";
        cout<<endl;
    }
    
}






