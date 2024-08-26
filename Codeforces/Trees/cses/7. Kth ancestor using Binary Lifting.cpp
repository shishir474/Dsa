#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

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
void SieveOfEratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2;i*i<=n;i++){
        if (sieve[i]){
             // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

bool compare(pair<int,int>& p1, pair<int,int>& p2){
    if (p1.first == p2.first)
    return p1.second < p2.second;
    return p1.first < p2.first;
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool isPalindrome(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if (s[i]!=s[n-1-i]){
            return false;
        }
    }
    
    return true;
}

void printGraph(vector<vector<int> >& adj, int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
        int size = adj[i].size();
        for(int j=0;j<size;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){
        return false;
    }else{
        return true;
    }
}

vector<int> adj[2000008];

void dfs(int src, int par, vector<vector<int> >& parent){
    parent[src][0] = par;
    for(auto child: adj[src]){
        if(child!=par){
            dfs(child,src,parent);
        }
    }
}

int solve(int u, int k, vector<vector<int> >& parent){
    while(k){
        int v = (int)log2(u); // v = 3->8
        u = parent[u][v];
        k-=(1<<v);
    }
    return u;
}

int32_t main()
{
	FIO;
	int n,q; cin>>n>>q;
    forn(i,n-1){
        int x; cin>>x;
        x--;
        adj[x].push_back(i+1);
        adj[i+1].pb(x);
    }


// precomputation
    int maxLevel = log2(n);
    
    // parent stores 2^ith parent of every node
    vector<vector<int> > parent(n, vector<int> (maxLevel+1, -1));
    
    // dfs call to compute 2^0th node i.e parent node 
    dfs(0,-1,parent);
    
    // for(int i=0;i<n;i++)cout<<parent[i][0]<<" ";
    
    for(int i=1;i<=maxLevel;i++){
        for(int node=0;node<n;node++){
            // to find 2^ith parent of node
            int v = parent[node][i-1];
            if(v!=-1){
                parent[node][i] = parent[v][i-1];
            }
        }
    }
    // Outer loop runs maxLevel times = Log2(n) times
    // inner loop runs n times
    // final complexity -> O(nlogn)
    
    // cout<<parent[1][0]<<endl;
    
    while(q--){
        int u,k; cin>>u>>k;
        u--;
        int ans = solve(u,k,parent);
        if(ans==-1) cout<<"-1"<<endl;
        else cout<<ans+1<<endl;
    }
 
    
    
}
