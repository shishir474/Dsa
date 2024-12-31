// https://www.youtube.com/watch?v=UGs_kQxJNPk&ab_channel=NeatlyStructured

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update>;

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
    // #ifndef ONLINE_JUDGE
    // freopen("cpp/input.txt", "r", stdin);
    // freopen("cpp/output.txt", "w", stdout);
    // #endif // ONLINE_JUDGE
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

struct cmp{
    bool operator()(const pii& p1, const pii& p2){
        return p1.first < p2.first;  // Compare by first element
    }
};


signed main(){
    initcode();
    int n,k; cin>>n>>k;
    vi arr(n);
    forn(i,n)
        cin>>arr[i];
    
    ordered_set<pii> os; // ordered_set of pair <int,int> to handle duplicate values
    // normal ordered_set of integers won't work, because the input can contain duplicates as well which ordered_set will not handle
    
    // hence storing {ele,index} in ordered set
    int i=0,j=0;
    while(j<k){
        os.insert({arr[j], j}); // very good technique to handle duplicates in sets
        j++;
    }

    int idx;
    
    while(j <= n){ // j <= n to handle the ans for last window 
        if(k%2) idx = k/2;  // ans for both even and odd will be (k-1)/2
        else idx = (k-1)/2;
        
        auto it = os.find_by_order(idx);
        cout<< it->first << endl;
        
        if(j==n) break; // exit after the last window
        
        os.erase({arr[i],i});
        i++;
        os.insert({arr[j],j});
        j++;
    }
   

    return 0;
    
    
}

