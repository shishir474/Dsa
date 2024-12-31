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

struct cmp{
    bool operator()(const pii& p1, const pii& p2){
        return p1.first < p2.first;  // Compare by first element
    }
};

signed main(){
    initcode(); // without this the code is giveing TLE. Always add initcode function in the beggining, it optimises the input and output
    // Read more about initcode function. How does it work?

    int x,n; cin>>x>>n;
    set<int> s; // set will store the positions, positions will be unique hence using sets, differences might not be unique hence using multisets
    multiset<int> ms; // multiset set will store the lengths. ms.rbegin() will be our ans. 
    // Used multiset because the lengths are not guaranteed to be unique
    
    s.insert(0);
    s.insert(x);
    ms.insert(x);
    
    forn(i,n){
        int pos; cin>>pos;
        s.insert(pos);
        auto iter = s.find(pos);
        int prev_val = *prev(iter);
        int next_val = *next(iter);
        // ms.erase(next_val-prev_val); // this is incorrect,bcoz ms.erase(val) will erase all the occurence of val in the multiset. Instead find one of the occruences of the value and then erase that paricular occurence using ms.erase(it)
        
        ms.erase(ms.find(next_val-prev_val));
        ms.insert(pos - prev_val);
        ms.insert(next_val - pos);
        
        cout<<*ms.rbegin()<<" "; // multiset.begin() points to the smallest element, ms.rbegin() points to the largest element
    }
    
    
    
}