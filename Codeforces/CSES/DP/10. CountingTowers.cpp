#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update>; // policy based data structure
// ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// and set.order_by_key(k) -> returns the index of the key k
// ordered set data structure => adds indexing functionality to sets

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
        return p1.second < p2.second;  
    }
};

// Solution:
// Instead of computing the same answer several times for different n's. Just do the precomputation for all values of n and then in the test case, directly return the result of n 

// int solve(int n){
//     int t[n+1][2];
//     t[1][0] = 1;
//     t[1][1] = 1;
//     for(int i=2;i<=n;i++){
//         // case when i-1 was not linked:
//             // 1. dont extend either of them 
//             // 2. extend either of them 
//             // 3. extend both of them 
//         // t[i][0] = (t[i-1][0] + t[i-1][1])+ 2*t[i-1][0] + t[i-1][0];
//         t[i][0] = ((t[i-1][0] + t[i-1][1])%mod + (3*t[i-1][0])%mod)%mod;
        
        
//         // case when i-1 was linked
//         // 1. If I choose not to extend it -- fresh start
//         // 2. If I extend them both(there is no option to extend either of them. Either you do both or none)
//         // t[i][1] = (t[i-1][0] + t[i-1][1]) + t[i-1][1];
//         t[i][1] = ((t[i-1][0] + t[i-1][1])%mod + t[i-1][1])%mod;
//     }
//     return (t[n][0] + t[n][1])%mod;
// }

// create a global array
int t[1000002][2];

signed main(){
    initcode();

    // Precompute the ans for all n 
    // n can go upto 1e6. Creating an array of that size inside main was causing runtime error. So created the array globally and precomputed the results for all possible n's
    t[1][0] = 1;
    t[1][1] = 1;
    for(int i=2;i<=1000001;i++){
        // case when i-1 was not linked:
            // 1. dont extend either of them 
            // 2. extend either of them 
            // 3. extend both of them 
        // t[i][0] = (t[i-1][0] + t[i-1][1])+ 2*t[i-1][0] + t[i-1][0];
        t[i][0] = ((t[i-1][0] + t[i-1][1])%mod + (3*t[i-1][0])%mod)%mod;
        
        
        // case when i-1 was linked
        // 1. If I choose not to extend it -- fresh start
        // 2. If I extend them both(there is no option to extend either of them. Either you do both or none)
        // t[i][1] = (t[i-1][0] + t[i-1][1]) + t[i-1][1];
        t[i][1] = ((t[i-1][0] + t[i-1][1])%mod + t[i-1][1])%mod;
    }

    int test;
    cin>>test;
    while(test--){
        int n; cin>>n;
        cout<<(t[n][0] + t[n][1])%mod<<endl;
    }

}

