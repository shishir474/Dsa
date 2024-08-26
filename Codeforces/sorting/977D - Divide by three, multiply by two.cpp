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


vector<pair<int,int> > v;

// returns highest power of 3 s.t n%(3^y) = 0;
int calc_degree(int n){
    int c=0;
    while(n%3 == 0){
        c++;
        n/=3;
    }
    return c;
}

int32_t main()
{
    initcode();
    int n; cin>>n;
    v.resize(n);
    forn(i,n){
        cin>>v[i].second;
        v[i].first = -calc_degree(v[i].second);
    }

// sorting logic: sort on the basis of degree. I.e highest degree first and if two nos have same degreee than smaller one comes first
    sort(all(v));

    forn(i,n)cout<<v[i].second<<" ";
    
    return 0;
}


