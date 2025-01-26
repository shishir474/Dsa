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

void solve(vector<int> &v){
    // forn(i,v.size()) cout<<v[i]<<" ";
    // cout<<endl;
    
    for(int i=1;i<v.size();i+=2)
        cout<<v[i]<<" ";
    
    if(v.size()==1){
        cout<<v[0];
        return;
    }
    
    vector<int> newv;
    if(v.size()%2 == 0){ // even size vector, 
        for(int i=0;i<v.size();i+=2)
            newv.pb(v[i]);
        
    }
    else{
        newv.pb(v[v.size()-1]);
        for(int i=0;i<v.size()-1;i+=2)
            newv.pb(v[i]);
    }
    
    solve(newv);
}

// count of subarrays with sum = x
// NOTE: the array can contain -ve values as well: only map solution will work
// sliding window will not work
signed main(){
    // initcode();
    int n,x; cin>>n>>x;
    int arr[n];
    forn(i,n) cin>>arr[i];
    // we will use the concept of prefix sums
    // at a particular index i, if the curr prefix sum is s, I will check if we have encoutered s - x before
    // Now we could leverage sets for this, but knowing if this value is present or not is not enough
    // the values could repeat as well, so instead of using sets we will use map to store the prefix sum and its freq
    // check in the map if we have found s-x before and how many occurences do we have
    // those many occurences will all contribute to target sum of x
    
    int cnt = 0;
    mii mp;
    mp[0] = 1; // empty subarray: initail config
    // lets say we have a prefix subarray with sum = x. Now we will check if we have encoutered 0 earlier
    
    int sum = 0;
    forn(i,n){
        sum+=arr[i];
        if(mp.count(sum - x)){
            cnt+=mp[sum-x];
        }
        mp[sum]++;
    }
    
    
    cout<<cnt<<endl;
    
    

    
    
    
}