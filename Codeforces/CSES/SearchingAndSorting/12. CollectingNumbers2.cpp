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
    int n,m; cin>>n>>m;
    int arr[n];
    vector<int> pos(n+1);
    forn(i,n){
        cin>>arr[i];
        pos[arr[i]] = i+1;
    }
    
    int inversionCount = 0;
    for(int i=1;i<n;i++){
        if(pos[i+1] < pos[i]) {
            // cout<<i<<" "<<i+1<<endl;
            inversionCount++;
            
        }
    }
    
    // cout<<"arr"<<endl;
    // forn(i,n) cout<<arr[i]<<" ";
    // cout<<endl;
    // cout<<"pos"<<endl;
    // fore(i,1,n) cout<<pos[i]<<" ";
    // cout<<endl;
    
    // cout<<"intial inversion"<<endl;
    // cout<<inversionCount<<endl;
    
    while(m--){
        int f,s; cin>>f>>s; // 1 based positions
        set<pii> affectedPairs;
        int val_f = arr[f-1], val_s = arr[s-1];
        
        // cout<<f<<" "<<s<<" "<<val_f<<" "<<val_s<<endl;
        
        if(val_f > 1) affectedPairs.insert({val_f-1, val_f});
        if(val_f < n) affectedPairs.insert({val_f, val_f+1});
        if(val_s > 1) affectedPairs.insert({val_s-1, val_s});
        if(val_s < n) affectedPairs.insert({val_s, val_s+1});
        
        for(auto it: affectedPairs){
            int a = it.first, b = it.second;  // a is always less than b
            if(pos[a] > pos[b]) inversionCount--;
        }
        
        // cout<<"before swapping"<<endl;  
        // cout<<"arr"<<endl;
        // forn(i,n) cout<<arr[i]<<" ";
        // cout<<endl;
        // cout<<"pos"<<endl;
        // fore(i,1,n) cout<<pos[i]<<" ";
        // cout<<endl;
        
        // swap
        swap(arr[f-1], arr[s-1]);
        pos[arr[f-1]] = f;
        pos[arr[s-1]] = s;
    
        // cout<<"after swapping"<<endl;        
        // cout<<"arr"<<endl;
        // forn(i,n) cout<<arr[i]<<" ";
        // cout<<endl;
        // cout<<"pos"<<endl;
        // fore(i,1,n) cout<<pos[i]<<" ";
        // cout<<endl;
    
        
        
        for(auto it: affectedPairs){
            int a = it.first, b = it.second;  // a is always less than b
            if(pos[a] > pos[b]) inversionCount++;
        }
        
        // cout<<"ans"<<endl;
        cout<<inversionCount+1<<endl;

    }
    
    
    
    
}


// this problem uses the concept of inversions count
// ans of the easy versoin of this problem is inversions Count + 1

// Interesting part is how do we calculate this for each round of swapping
