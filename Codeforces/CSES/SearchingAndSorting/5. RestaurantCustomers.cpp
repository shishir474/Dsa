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
        if(p1.first == p2.first){
            return p1.second < p2.second; // Compare by second element if the first ones are equal
        }
        return p1.first < p2.first;  // Compare by first element
    }
};

signed main(){
    int n; cin>>n;
    vector<pii> v;
    forn(i,n){
        int start, end; cin>>start>>end;
        v.pb({start, 1}); // {start,1} indicates a customer has arrived
        v.pb({end, -1}); // {end,-1} indicates a customer has left
    }

    // sort(all(v));
    sort(all(v), cmp());

    int x = 0;
    int ans = 0;
    for(auto p: v){
        x+=p.second;
        ans = max(ans, x);
    }

    cout<<ans<<endl;
    
    
   
    
}






// (2,4) (3,5) (7,9) (1,10)  --> The below approach fails on this test case:
// Whenever there is a conflict we increase the count by 1 else we reset the count.
// But there is a possibility that after resetting the count we might find a pair that spans across the previous pairs.

// WRONG SOLUTION
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
        if(p1.second == p2.second){
            return p1.first < p2.first; // Compare by second element if the first ones are equal
        }
        return p1.second < p2.second;  // sort on the basis of second element
    }
};

signed main(){
    int n; cin>>n;
    vector<pii> v;
    forn(i,n){
        int start, end; cin>>start>>end;
        v.pb({start,end});
    }

    sort(all(v), cmp()); // sort it on the basis of end time
    int ans=1, cnt=1;
    int prev_end = v[0].second;
    fore(i,1,n-1){
        if(v[i].first < prev_end){
            cnt++; 
            ans = max(ans, cnt);
            prev_end = v[i].second;
        }
        else{
            cnt = 1; // reset the count value to 1
            prev_end = v[i].second;
        }
    }

    cout<<ans<<endl;


    
   
    
}
