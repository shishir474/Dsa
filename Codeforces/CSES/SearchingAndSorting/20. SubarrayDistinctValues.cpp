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

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    // initcode();
    int n,k; cin>>n>>k;
    int arr[n];
    forn(i,n) cin>>arr[i];
    int ans = 0;
    
    int i=0,j=0;
    mii mp; 
    // count of subarrays with at most k distinct values
    // build the map until you have more than k distinct elements
    while(j < n){
        mp[arr[j]]++;
        while(mp.size() > k){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) // remove the element once its freq is 0 to reduce the size of the mp
                mp.erase(arr[i]);
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    
    cout<<ans<<endl;
    
    
}

// atmost k distinct values -> build the map until you have <=k distinct values. The moment when the size of the mp.size() > k, start moving the left pointer
// jab tak k distinct values nhi mil jati, keep on adding the elements. Jaise hi map size > k i.e you've more that k distinct start removing elements from left
// after coming out of the loop you will have <= k distinct elements between i and j. 

// atmost k distinct -- calculation done above
// atleast k distinct -- total subarrays - atmost(k-1)
// exactly k distinct = atmostKDistinct(k) - atmostKDistinct(k-1) basically atmost(k) - atmost(k-1) will give us exactly k distinct
                 