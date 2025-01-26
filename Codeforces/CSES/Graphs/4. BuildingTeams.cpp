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

// Bipartite using DFS
bool dfs(int sv, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &color, int curr_color){
    vis[sv] = true;
    color[sv] = curr_color; // color the vertex

    for(auto nb: adj[sv]){
        if(!vis[nb]){
            if(!dfs(nb, adj, vis, color, 1-curr_color)) // IMP: if this component returns false(which means its not bipartite, we can straight away return false), but if it returns true, we still need to check other components if they are bipartite or not. WE cannot make a decision solely based on this vertex
                return false;
        }
        else if(vis[nb]==true and color[nb] == curr_color){
            return false;
        }
    }

    return true;
}

// We need to check if the graph is bipartite or not and assign colors 
// Remeber: Graph can be disconnected as well
// NOTE: In order to be able to successfully solve problems, you must write correct code for base problems like (dfs,bfs,bipartite etc). You cannot afford mistakes here 

// Bipartite using BFS
bool bfs(int sv, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &color){
    queue<int> q;
    q.push(sv);
    color[sv] = 0;
    vis[sv] = true;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto nb: adj[f]){
            if(!vis[nb]){
                q.push(nb);
                vis[nb] = true;
                color[nb] = 1-color[f];
            }
            else if(vis[nb]==true and color[nb] == color[f]){
                return false;
            }
        }
    }

    return true;
}

signed main(){
    initcode();
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1); // 1 to n vertices
    forn(i,m){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n+1,-1);
    vector<bool> vis(n+1,false);

    bool ans = true;
// Using DFS
    // fore(i,1,n){
    //     if(!vis[i]){
    //         if(!dfs(i,adj,vis,color,0)){ // if this returns false-> means the graph is not bipartite
    //             ans = false; break;
    //         }
    //     }
    // }
    
// Using BFS
    fore(i,1,n){
        if(!vis[i]){
            if(!bfs(i,adj,vis,color)){ // if this returns false-> means the graph is not bipartite
                ans = false; break;
            }
        }
    }

    if(ans){
        // According to the problem statement, we have to color with 1 or 2. Hence replacing 0's with 2
        fore(i,1,n){
            if(color[i]==0)
                color[i] = 2;
        }
        
        fore(i,1,n) cout<<color[i]<<" ";
        cout<<endl;
    }
    else{
        // graph is not bipartite
        cout<<"IMPOSSIBLE"<<endl;
    }
    
}

