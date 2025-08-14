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
    mii mp;
    forn(i,n){
        cin>>arr[i];    // values
        mp[arr[i]] = i; // values -> positions
    }
    
    int val = 2, pos = mp[1], rounds = 1;
    while(val <= n){
        while(val<=n and mp[val] > pos){
            pos = mp[val];
            val++;
        }
        if(val > n) break; // break out to avoid incrementing the rounds for val > n
        
        rounds++;
        pos = mp[val];
        val++;
    }
    
    cout<<rounds<<endl;
    
    
    
}


// logic
// initially set the pos to mp[1] 
// now we want 2 to be towards right of this pos. If this is true, we increment the val to 3 and check continuing the same condition
// if 2 is not towards the right of the pos of 1. It means, it will be part of another round 
// so we increment the rounds from 1 to 2(marking the beginning of the 2nd round, update the pos to mp[2] and update val to 3 since we now want to check is 3 towards the right of 2)

//Findings
// There is a correlation between the no of rounds and inversion count
// What is an inversion?
// 2 numbers a[i] and a[j] are considered inversion if a[i] > a[j] but pos[i] < pos[j]
// total no of rounds is equivalent to the inversion count + 1 

