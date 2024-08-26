You are given a tree consisting of n nodes.

A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?

Input

The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.

Then there are n−1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output

Print one integer: the maximum number of pairs.

Constraints
1≤n≤2⋅105
1≤a,b≤n
Example

Input:
5
1 2
1 3
3 4
3 5

Output:
2

Explanation: One possible matching is (1,2) and (3,4).

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

int dp[200005][2];

void dfs(vector<int> adj[], int root,int parent){
    
    vector<int> prefix, suffix;
    dp[root][0] = dp[root][1] = 0;

// compute for child
    bool leaf=1;
    for(auto it: adj[root]){
        if(it!=parent){
            leaf = 0;
            dfs(adj,it,root);
        }
    }
    
    if(leaf) return;
    
    // Now compute ans for root
    for(auto it: adj[root]){
        if(it!=parent){
            prefix.pb(max(dp[it][0], dp[it][1]));
            suffix.pb(max(dp[it][0], dp[it][1]));
        }
    }
    
    for(int i=1;i<prefix.size();i++){
        prefix[i]+=prefix[i-1];
    }
    for(int i=suffix.size()-2;i>=0;i--){
        suffix[i]+=suffix[i+1];
    }
    
    // If we choose to excluding root
    dp[root][0] = suffix[0];
    
    // including root
    int c_no=0;
    for(auto it: adj[root]){
        
        if(it==parent) continue;
        
        int left = (c_no==0) ? 0 : prefix[c_no-1];
        int right = (c_no==suffix.size()-1) ? 0 : suffix[c_no+1];
        
        dp[root][1] = max(dp[root][1], 1+left+right+dp[it][0]);
        
        c_no++;
    }
    
}
int32_t main()
{
	FIO;
	int n; cin>>n;
    vector<int> adj[n];
    forn(i,n-1){
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].pb(x);
    }

    memset(dp,0,sizeof(dp));
    
    dfs(adj,0,-1);
    
    cout<<max(dp[0][0], dp[0][1])<<endl;
        
    
}


Logic:
dp[u,0] -> Max matching that we can get by excluding u
dp[u,1] -> Max matching that we can get by including u

Excluding root
op1 = (Ans[C1] + Ans[C2] + .... + Ans[Ck]) where C1, C2 are children of root
Ans[Ci] = max(dp[Ci,0], dp[Ci,1])

Including root

