 suppose you want to do a special operation to a node x. What nodes from subtree of x will be flipped? Obviously, x will be first, being located at level L. Sons of x, located at level L + 1 will not be flipped. Sons of sons, located at level L + 2, will be flipped again. So, nodes from subtree of x located at levels L, L + 2, L + 4, ... will be flipped, and nodes located at levels L + 1, L + 3, L + 5 won’t be flipped. Let’s take those values of L modulo 2. All nodes having remainder L modulo 2 will be flipped, and nodes having reminder (L + 1) modulo 2 will not. In other words, for a fixed x, at a level L, let y a node from subtree of x, at level L2. If L and L2 have same parity, y will be flipped, otherwise it won’t.
 let’s think what should be our first operation. Let’s consider some nodes {x1, x2, ..., xk} with property that x1 is son of x2, x2 is son of x3, ... xk-1 is son of xk and parity of levels of these nodes is the same. Suppose by now we fixed {x1, x2, ..., xk-1} (their current value is equal to their goal value), but xk is still not fixed. After some time, we’ll have to fix xk. Now, by doing this, all nodes {x1, x2, ..., xk-1} will get flipped and hence unfixed. We’ve done some useless operations, so our used strategy is not the one that gives minimal number of operations.

What we learn from this example? Suppose I want to currently fix a node X. There is no point to fix it now, unless all ancestors Y of X with property level(Y) = level(X) (mod 2) are fixed. But what if an ancestor Y of X is not fixed yet and level(Y) != level(X) (mod 2)? Can I fix node X now? The answer is yes, as future operations done on Y won’t affect X. But, by same logic, I can firstly fix Y and then fix X, because again operations done on Y won’t affect X. We get a nice property: there is no point to make an operation on a node X unless all ancestors of X are fixed.


So if we want to fix node x , then we need to ensure that all its ancestors at alternate levels are already fixed. bcoz if the ancestors are not fixed , then later when we try to fix the ancestor, the node which we fixed earlier will unfix
So we''ll move from top to bottom. For root all its ancestors are fixed(since it doesnt have any )

[IMPORTANT EDITORIAL] VERY GOOD Problem of DFS



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
vector<int> intial(100003,-1), final(100003,-1), res;

void dfs(int src, int par, int eventimes, int oddtimes, int level, int& ans){
    // updating value of src vertex from the opereations that were performed on its ancestors. Now if u are at currently even level, then only the eventimes operation will affect its value
    if(level%2 == 0){
        intial[src] = (intial[src]+eventimes)%2;
    }
    else{
        intial[src] = (intial[src]+oddtimes)%2;        
    }

    if(intial[src]!=final[src]){
        res.pb(src);
        ans++;
        for(auto it: adj[src]){
            if(it!=par){
                if(level%2 == 0)
                dfs(it, src, eventimes+1, oddtimes, level+1, ans);
                else
                dfs(it, src, eventimes, oddtimes+1, level+1, ans);
            }
        }
    }
    else{
         for(auto it: adj[src]){
            if(it!=par){
                dfs(it, src, eventimes, oddtimes, level+1, ans);
              }
           }
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
    for(int i=1;i<=n;i++) cin>>intial[i];
    for(int i=1;i<=n;i++) cin>>final[i];

int ans=0;
    dfs(1,-1,0,0,0,ans);
    cout<<ans<<endl;
    forn(i,res.size())cout<<res[i]<<endl;





    return 0;
}


