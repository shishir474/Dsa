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
    int n; cin>>n;
    vector<int> arr(n);
    forn(i,n) cin>>arr[i];
    
    sort(all(arr));
    
    // 1<= arr[i] <= 10^9
    int val = 1, sum = 0;
    forn(i,n){
        if(arr[i] > val) break;
        sum+=arr[i];
        val = sum+1;
    }
    
    cout<<val<<endl;
    
    
}

// LOGIC
// at pos i lets say the value is a[i] and we have a prefix that gives sum between 1 and k
// Now we have to check if we can construct sum k+1. 
// Now there are 3 cases
// 1. a[i] > k+1 , not possible => we have a prefix that gives sum between 1 and k and we need to add something to this prefix sum to get k+1, but we surely cant add a[i] since a[i] > k+1. SO this will cause the entire value to exceed k+1
// 2. a[i] = k+1 , yes possible => a[i] itself alone can be choosen
// 3. a[i] < k+1 , yes possible => a[i] + x = k+1 we want this condition to hold true. This holds only when we prove x lies between [1,k]
// x = (k+1) - a[i]
// Now the min value of a[i] could be 1 , this gives us x = k which surely lies in range [1,k]
// and the max values of a[i] is gonna be k(since a[i] is surely less than k+1), this gives x = 1 which lies in range of [1,k]
// Either way we prove that x will always lie between range [1,k]

// Hence the only condition is a[i] <= val that we are trying to construct. If this is true, then we construct val and all the numbers till prefixSum[i]
// and the next value that we need to check is prefixSum[i] + 1