// https://www.youtube.com/watch?v=JqWiWJQOQyU&list=PLTIakIxRr2Qs0xyizdoK5Bq1idVJkPS6k&index=6&ab_channel=NeatlyStructured
// https://cses.fi/problemset/task/1082

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
#define mod             1000000007
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

int modularBinaryExponentitation(int base, int exponent){
    if(exponent==0) return 1;
    int val = modularBinaryExponentitation(base, exponent/2);
    if(exponent%2)
        return ((val*val)%mod*base)%mod;
    else    
        return (val*val)%mod;
}

signed main(){
    int n; cin>>n;
    
    int ans = 0;
    
     // iterating over the buckets(unique values of n/i) and in worst case we'll have 2*sqrt(n) unique values 
    // so effectively this loop runs 2*sqrt(n) times in worst case 
    for(int i=1,j; i<=n; i = j){
        int q = n/i;
        j = (n/q) + 1;
        //  (a/b) % mod  = (a * b_inv) % mod where b_inv = modularBinaryExponentitation(b,mod-2)
        // (j * (j+1))/2;
        int sumUptoJMinusOne = ((((j-1)%mod) * (j%mod))%mod * modularBinaryExponentitation(2, mod-2))%mod;
        // ((i-1) * i)/2;
        int sumUptoIMinusOne = ((((i-1)%mod) * (i%mod))%mod * modularBinaryExponentitation(2, mod-2))%mod;
        int rangeSum = (sumUptoJMinusOne - sumUptoIMinusOne + mod)%mod;
        ans = (ans + (rangeSum*q)%mod)%mod;
    }
    
    cout<<ans<<endl;
    
    
}