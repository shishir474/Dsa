// 1400 Rated: div3-D
// Nice maths problem
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
void SieveOfEratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2;i<=sqrt(n);i++){
        if (sieve[i]){
             // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }
}
int gcd(int a, int b)
{ // Time Complexity: O(Log min(a, b)) Auxiliary Space: O(Log (min(a,b))
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
    return p1.first > p2.first;
    // if (p1.first == p2.first)
    // return p1.second < p2.second;
    // return p1.first < p2.first;
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
    if ((n&(1<<i)) != 0){// bit is set
        return false;
    }else{
        return true;
    }
}

vector<int> adj[3000];
vector<bool> vis(2600, false);

// cycle detection
bool dfs(int sv, int par){
    vis[sv]=true;
    for(int nb: adj[sv]){
        if(!vis[nb]){
            if(dfs(nb,sv)) return true;
        }
        else if(vis[nb]==true and nb!=par) return true;
    }

    return false;
}

int32_t main()
{
    initcode();
    w(t){
        int n; cin>>n;
        int a[n];
        forn(i,n) cin>>a[i];
        int hi=INT_MAX, lo=0;
        forn(i,n){
            if(a[i]==a[i+1]) continue;
            if(a[i] < a[i+1]){
                if((a[i]+a[i+1])/2 < hi) hi = (a[i]+a[i+1])/2;
            }   
            else{
                if(ceil((a[i]+a[i+1])/2.0) > lo) lo = ceil((a[i]+a[i+1])/2.0);
            }
        }

        if(lo > hi){
            cout<<"-1"<<endl;
        }
        else{
            cout<<lo<<endl;
        }
        

    }
    return 0;
}



// ultimately we have to determine if there exists any valid range of x or not
// |a[i]-x| < |a[i+1]-x|    -  eqn 1
// IF a[i]==a[i+1] , then any value of x will satisfy eqn1
// If a[i] < a[i+1], then x<=a[i] and x<=(a[i]+a[i+1])/2. Taking union x<=(a[i]+a[i+1])/2
// similarly, if a[i] > a[i+1], then x>=(a[i]+a[i+1])/2 satisfies the eqn1
// Get the range lo to hi and all the values in this range will be valid
