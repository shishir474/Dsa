// Compute distance between 2 nodes 


#include<bits/stdc++.h>
using namespace std;

#define int             long long int
#define endl            "\n"
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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

vector<int> adj[200008];
vector<int> level(200008);
vector<vector<int> > parent(200008, vector<int> (22, -1));

void getDepth(int src, int par, vector<vector<int> >& parent,int depth){
    parent[src][0] = par;
    level[src] = depth;
    for(auto child: adj[src]){
        if(child!=par){
            getDepth(child,src,parent,depth+1);
        }
    }
}

// returns kth ancestor of u 
int kthancestor(int u, int k, vector<vector<int> >& parent){
    while(k){
        int i = log2(k);
        u = parent[u][i];
        if(u==-1) return -1;
        k-=(1<<i);
    }
    return u;
}

int solve2(int a, int b, vector<vector<int> >& parent){
    int diff = abs(level[a]-level[b]);
    if(level[b] > level[a]) swap(a,b);        
    // lift a
    a = kthancestor(a,diff,parent);
    
    // now a and b are at same level
    if(a==b){
        return b;
    }

    for(int i=19;i>=0;i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    
    return kthancestor(a,1,parent);
}

int32_t main()
{
    initcode();
    int n,q; cin>>n>>q;
    forn(i,n-1){
        int x,y; cin>>x>>y;
        adj[y].pb(x);
        adj[x].pb(y);
    }

// calculate 2^0th parent and depth
    getDepth(1,-1,parent,0);

    for(int i=1;i<=19;i++){
        for(int node = 1;node<=n; node++){
            // calc 2^i th parent of node
            int v = parent[node][i-1];
            if(v!=-1){
                parent[node][i] = parent[v][i-1];
            }
        }
    }


    while(q--){
        int a,b; cin>>a>>b;
        int lca = solve2(a,b,parent);
        // cout<<"lca"<<" "<<lca<<endl;
        int ans = level[a]+level[b] - (2*level[lca]);

        cout<<ans<<endl;
    }

    
}



