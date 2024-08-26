// Subtree Queries
// segment tree 

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

int seg[4*100005];
int values[200008];
vector<int> adj[200008];
int start[200008];
int subtreeSize[200008];


int dfs(int src, int par, int& timer, vector<int>& dfspath){
    subtreeSize[src]++;
    dfspath.pb(values[src]);
    start[src] = timer;
    timer++;
    for(auto it: adj[src]){
        if(it!=par){
           subtreeSize[src]+= dfs(it, src, timer, dfspath);
        }
    }

    return subtreeSize[src];
}

void build(int ind, int lo, int hi, vector<int>& dfspath){
    if(lo==hi){
        seg[ind] = dfspath[lo];
        return;
    }
    int mid = lo+(hi-lo)/2;
    build(2*ind+1, lo, mid, dfspath);
    build(2*ind+2, mid+1, hi, dfspath);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int query(int ind, int lo, int hi, int l, int r){
    if(lo>=l and hi<=r){ // completely lies within the range
        return seg[ind];
    }
    else if(hi<l || lo>r) return 0; // does not lie in range
    else{
        int mid = lo+(hi-lo)/2;
        return query(2*ind+1, lo, mid, l, r) + query(2*ind+1, mid+1, hi, l, r);
    }
}

void update(int ind, int lo, int hi, int node, int value){
    if(lo>node || hi<node) return;
    if(lo==hi and lo==node){
        seg[ind]+=value;
        return;
    }
    int mid = lo+(hi-lo)/2;
    update(2*ind+1, lo, mid, node, value);
    update(2*ind+2, mid+1, hi, node, value);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];

}


int32_t main()
{
    initcode();
    int n,q; cin>>n>>q;
    forn(i,n) cin>>values[i];   
    forn(i,n-1){
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    memset(subtreeSize, 0, sizeof(subtreeSize));

    int timer=0;

    vector<int> dfspath;

    dfs(0,-1,timer,dfspath);

    // forn(i,dfspath.size()) cout<<dfspath[i]<<" ";
    // cout<<"\n";

    build(0, 0, dfspath.size()-1, dfspath);

    while(q--){
        int a,b,c; cin>>a;
        if(a==1){
            cin>>b>>c;
            update(0, 0,n-1,start[b], c-values[b]);
            values[b]=c;
        }
        else{
            cin>>b;
            cout<<query(0,0,n-1,start[b],start[b]+subtreeSize[b]-1);
        }
    }
    
}



