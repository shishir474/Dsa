// For each node,we have 2 options either we save the first child and call recursino on the second child or vice versa
// we have to delete some nodes such that the number of saved nodes can be maximised -> using dp(inclusion/exclusion)
// 1600 rating




#include<bits/stdc++.h>
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
void initcode(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
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
int subtreeSize[300008];

int dfs(int src, int par, vector<int> adj[]){
    subtreeSize[src]++;
    for(auto it: adj[src]){
        if(it!=par){
           subtreeSize[src]+= dfs(it, src, adj);
        }
    }

    return subtreeSize[src];
}

int solve(int src, int par, vector<int> adj[], vector<int>& dp){
    if(dp[src]!=-1) return dp[src];
    vector<int> children;
    for(auto it: adj[src]){
        if(it!=par) children.pb(it);
    }

    int op1=-1, op2=-1;
    if(children.size()==0){
        return dp[src] = 0;
    }
    else if(children.size()==1){
        op1 = subtreeSize[children[0]]-1;
        return dp[src] = op1;
    }
    else{
        op1=  subtreeSize[children[0]]-1 + solve(children[1], src,adj, dp);
        op2 = subtreeSize[children[1]]-1 + solve(children[0], src, adj, dp);
        return dp[src] = max(op1, op2);
    }

}

int32_t main()
{
    initcode();
    w(t){
        int n; cin>>n;
        vector<int> adj[n];
    
        forn(i,n-1){
            int x,y; cin>>x>>y;
            x--; y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        memset(subtreeSize, 0, sizeof(subtreeSize));

// // evaluates subtree size
            dfs(0,-1,adj);
//         forn(i,n) cout<<subtreeSize[i]<<" ";
//         cout<<endl;
        vector<int> dp(n, -1);
        cout<<solve(0, -1, adj, dp)<<endl;
   
    }
      
    return 0;
}


