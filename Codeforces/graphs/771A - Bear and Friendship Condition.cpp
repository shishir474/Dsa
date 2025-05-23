/* simple DFS*/


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

vector<int> adj[150003];
vector<bool> vis(150003, false);

void dfs(int sv, int& count_vertices, int& count_edges){
    vis[sv]=1;
    
    count_vertices++;
    count_edges+=adj[sv].size();

    for(auto nb: adj[sv]){
        if(!vis[nb])
            dfs(nb, count_vertices, count_edges);
    }
}
// each connected component should be fully connected then only print yes
int32_t main()
{
    initcode();
        int n,m; cin>>n>>m;
        forn(i,m){
            int x,y; cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        bool notpossible = false;

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int count_vertices=0,count_edges=0;
                dfs(i,count_vertices, count_edges);
                if(count_edges != (count_vertices-1)*count_vertices){
                    notpossible = true;  break;
                }
            }
        }

        if(notpossible){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }


    

    return 0;
}



