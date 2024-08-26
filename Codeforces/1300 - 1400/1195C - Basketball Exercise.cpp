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

int32_t main()
{
    initcode();
    int n; cin>>n;
    int a[2][n];
    forn(i,2){
        forn(j,n) cin>>a[i][j];
    }

    int dp[3][n];
    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];
    dp[2][0] = 0;

    for(int i=1;i<n;i++){
        dp[0][i] = max({a[0][i]+dp[1][i-1], a[0][i]+dp[2][i-1], a[0][i]});
        dp[1][i] = max({a[1][i]+dp[0][i-1], a[1][i]+dp[2][i-1], a[1][i]});
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]);
    }

    cout<<max(dp[0][n-1], dp[1][n-1])<<endl;


}















