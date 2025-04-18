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


// Stronly Connected Components - Kosaraju Algo
vector<vector<int>> adj;
vector<vector<int>> rev_adj;
vector<bool> vis;
int n;

void dfs(int v, stack<int> &s){
    vis[v] = true;
    for(auto nb: adj[v]){
        if(!vis[nb]){
            dfs(nb, s);
        }
    }
    s.push(v);
}

void dfs2(int v, vector<int> &scc){
    vis[v] = true;
    scc.push_back(v);
    // traverse on the reversed graph
    for(auto nb: rev_adj[v]){
        if(!vis[nb]){
            dfs2(nb, scc);
        }
    }
}

void kosaraju(){
    // step1: sort the nodes based on their end time 
    stack<int> s;
    vis.resize(n+1, false);
    fore(i,1,n){
        if(!vis[i]){
            dfs(i,s);
        }
    }
    
    // node at the stack's top is the one which finished the last in the dfs. Use that node to perform dfs on the reversed graph

    // step 3:  perform dfs on the reversed graph;
    forn(i,n+1) vis[i] = false;  
    
    vector<vector<int>> sccs; // maintains a list of all the scc's
    int cnt = 0; // represent the no of scc's
    while(!s.empty()){
        int t = s.top();
        s.pop();
        if(!vis[t]){
            vector<int> scc;
            dfs2(t,scc);
            sccs.push_back(scc);
            cnt++;
        }
    }

    // No of kingdoms is equivalent to no of scc's
    cout<<sccs.size()<<endl;

    // mp stores which node is part of which scc
    unordered_map<int,int> mp;
    forn(i,sccs.size()){
        forn(j,sccs[i].size()){
            mp[sccs[i][j]] = i+1;
        }
    }

    fore(i,1,n){
        cout<<mp[i]<<" ";
    }

    

}

signed main() {
    initcode();
    int N,M; cin>>N>>M;
    n = N;
    adj.resize(n+1);
    rev_adj.resize(n+1);
    forn(i,M){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u); // storing reverse graph
    }

    kosaraju();

    return 0;
}






