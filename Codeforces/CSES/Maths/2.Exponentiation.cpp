// https://cses.fi/problemset/task/1712/

// Notes taken -> uses concepts of Euler Function, fermat's little theorem and modular exponentiation

#include <bits/stdc++.h>
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
// #define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(i,n)      for(int i=0;i<n;++i)
#define fore(i, l, r)   for(int i = l; i <= r; ++i)
#define all(v)          v.begin(), v.end()

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("cpp/input.txt", "r", stdin);
    freopen("cpp/output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }


// computes (a^b)%mod -> modular exponentiation
int solve(int a, int b, int mod){
    if(b==0) return 1;
    int val = solve(a,b/2,mod);
    if(b%2 == 0){
        return (val*val)%mod;
    }
    else{
        int t = (val*val)%mod;
        int ans = (t*a)%mod;
        return ans;
    }
    
}

signed main(){
    w(t){
        int a,b,c; cin>>a>>b>>c;
        int mod = 1e9+7;
        int power_bc = solve(b,c,mod-1);
        cout<<solve(a,power_bc,mod)<<endl;
    }
}