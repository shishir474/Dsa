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
#define mp              make_pair
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

vector<vector<int>> adj;
vector<bool> vis;
int N;


// Perform simple BFS and find the shortest path from 1 to n
// We also need to construct the path - use map to track from which vertex we reached a certain vertex

void bfs(int src, int dest){
    queue<int> q;
    q.push(src);
    vis[src]=true;

    bool found = false;
    vector<int> path;

    // parent[] to track the parent of each node. initialised with -1 initally indicating the parents are not defined yet. 
    // src parent does not exist, hence parent[src] = -2
    vector<int> parent(N+1,-1); 
    parent[src] = -2; // -2 indicates src does'nt have a parent

    // standard bfs while loop
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int f = q.front();
            q.pop();
            if(f == dest){
                found=true; break;
            }
            for(auto nb: adj[f]){
                if(!vis[nb]){
                    parent[nb] = f;
                    vis[nb]=true;
                    q.push(nb);
                }
            }
        }
    }

    // if destination is reachable
    if(parent[dest] != -1){
        int curr = dest;
        while(curr != src){
            path.push_back(curr);
            int par = parent[curr];
            curr = par;
        }
        path.push_back(src);
        reverse(all(path));
        
        cout<<path.size()<<endl;
        for(auto i: path) cout<<i<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}
signed main(){
    initcode();
    int n,m; cin>>n>>m;
    N = n;
    adj.resize(n+1);
    vis.resize(n+1,false);
    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(1,n);
}

