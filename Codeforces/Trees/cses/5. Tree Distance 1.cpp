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
 
 
 
vector<int> depth(200005, -1), ans(200005, -1);
 
void solve(vector<int> adj[], int src, int parent, int par_ans){
   
   vector<int> prefixMax, suffixMax;
   
   for(auto child: adj[src]){
       if(child!=parent){
           prefixMax.pb(depth[child]);
           suffixMax.pb(depth[child]);
       }
   }
  
//   cout<<src<<": "<<"\n";
//   forn(i,prefixMax.size())cout<<prefixMax[i]<<" ";
//   forn(i,suffixMax.size())cout<<suffixMax[i]<<" "; 
   
//   cout<<endl;
   
   
   for(int i=1;i<prefixMax.size();i++){
       prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
   }
   for(int i=suffixMax.size()-2;i>=0;i--){
       suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
   }
   
   // evaluate ans for child
   int c_no=0;
   for(auto child: adj[src]){
       if(child!=parent){
           int op1 = (c_no==0) ? INT_MIN : prefixMax[c_no-1];
           int op2 = (c_no==suffixMax.size()-1) ? INT_MIN : suffixMax[c_no+1];
           int partial_ans = 1+max({op1,op2,par_ans});
           
           solve(adj,child,src,partial_ans);
           c_no++;
       }
   }
   
   
   ans[src] = max(depth[src], 1+par_ans);
   
}
 
int evalDepth(int root, int parent, vector<int> adj[]){
    
    if(depth[root]!=-1) return depth[root];
    
    int leaf=1;
    int mx=0;
    for(auto it: adj[root]){
        if(it!=parent){
            leaf = 0;
            mx = max(mx, evalDepth(it,root,adj));
        }
    }
    
    if(leaf){
        return depth[root] = 0;
    }
    
    return depth[root]=1+mx;
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
    
    evalDepth(0,-1,adj);
    
    // for(int i=0;i<n;i++){
    //     cout<<depth[i]<<" ";
    // }
    
    
    solve(adj,0,-1,-1);
    
    forn(i,n){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    
}