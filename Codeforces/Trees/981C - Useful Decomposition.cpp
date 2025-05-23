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
    return p1.second > p2.second;
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

bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){
        return false;
    }else{
        return true;
    }
}


vector<int> adj[100003];
vector<int> leaf;

void dfs(int src, int par){
    int child=0;
    for(auto it: adj[src]){
        if(it!=par){
            child++;
            dfs(it,src);
        }
    }
    if(child==0){
        leaf.pb(src);
    }
}

int32_t main()
{
    initcode();
    int n; cin>>n;
    forn(i,n-1){
        int f,s; cin>>f>>s;
        adj[f].pb(s);
        adj[s].pb(f);
    }

// by default lets take root=1
    int root=1, c=0;
    for(int i=1;i<=n;i++){
        if(adj[i].size() > 2){
            c++;
            root = i;
        }
    }

// no. of vertex with degree > 2 can be atmost 1. If there are more that 1vertex, tehn decompostion is not possible
    if(c>1){
        cout<<"No"<<endl;
        return 0;
    }

    dfs(root, -1);
    cout<<"Yes"<<endl;
    cout<<leaf.size()<<endl;
    for(int i=0;i<leaf.size();i++){
        cout<<root<<" "<<leaf[i]<<endl;
    }


    return 0;
}


