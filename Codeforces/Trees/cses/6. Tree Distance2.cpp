
Solution Link:
https://usaco.guide/problems/cses-1133-tree-distances-ii/solution


It's easy to find the sum of distances from a single node - just root the tree
at that node, do a DFS, and add the depths of each other node to the answer.
Unfortunately, $n$ can go up to $2 \cdot 10^5$, so we can't just do this for
each node.

If we have the answer for some node (let's say node 1), how can we quickly find
the answer for its neighbours?

The key observation is that if we reroot the tree at node 1's neighbour (let's
say node 2), then

The depths of all nodes in node 2's subtree decrease by 1.
The depths of all nodes outside of its subtree increase by 1.


This gives us a nice way to transition from node 1's answer to node 2's answer
using only $n$ and the size of node 2's subtree! Observe that the change in the
answer is exactly $n - 2(\text{node 2's subtree size})$.

We can use DFS to find both the answer for node 1 and the size of each node's
subtree when rooted at node 1, and then DFS again to compute all the answers.



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


// sbtree[i] = No. of nodes in tree rooted at i;
vector<int> sbtree(200005, 0), ans(200005, 0);

int dfs(int src, int parent, vector<int> adj[], int depth){
    ans[0]+=depth;
    for(auto it: adj[src]){
        if(it!=parent){
           sbtree[src]+=dfs(it,src,adj,depth+1);
        }
    }
    sbtree[src]+=1;
    return sbtree[src];
}

void solve(vector<int> adj[], int src, int parent, int n){
      for(auto it: adj[src]){
          if(it!=parent){
            ans[it] = ans[src] + n - (2*sbtree[it]);
            solve(adj,it,src,n);
          }
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
    
  
    dfs(0,-1,adj,0);  
    
    solve(adj,0,-1,n);
    
    forn(i,n){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    
}
