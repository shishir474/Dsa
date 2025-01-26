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
#define INF             1e9 // Large value to prevent overflow

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



signed main(){
    initcode();
    int n,target; cin>>n>>target;
    vector<int> coins(n);
    forn(i,n) cin>>coins[i];
    
    int t[2][target+1];

    forn(i,2)  // minimum no of coins required to make 0 is 0
        t[i][0] = 0; 
    fore(i,1,target)
        t[0][i] = INF;

    // SPACE optimised solution O(2*target)
    int flag = 1;
    fore(i,1,n){
        fore(j,1,target){
            if(coins[i-1] <= j){
                // I have 2 options: can take this coin or can discard it
                // NOTE: I have an infinite supply of each denomination
                t[flag][j] = min(1+t[flag][j-coins[i-1]], t[flag^1][j]);
            }
            else{
                // I have no other option other than discarding it
                t[flag][j] = t[flag^1][j];
            }
        }
        flag = flag^1;
    }
    
    // fore(i,1,n){
    //     fore(j,1,target){
    //         if(coins[i-1] <= j){
    //             // I have 2 options: can take this coin or can discard it
    //             // NOTE: I have an infinite supply of each denomination
    //             t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);
    //         }
    //         else{
    //             // I have no other option other than discarding it
    //             t[i][j] = t[i-1][j];
    //         }
    //     }
    // }

    flag = flag^1; // flip flag one more time
    
    if(t[flag][target] == INF) cout<<"-1"<<endl; // if solution not possible print -1
    else cout<<t[flag][target]<<endl;
    
    
}

// Simple knapsack problem
// TC: O(n*target)
// SC: O(n*target) - was getting runtime error on this

// possible causes for the runtime error

// 1. Constraints of the t array
// You have defined t[101][1000005], which means you’re allocating memory for 101 * 1000005 integers. This requires approximately 404 MB of memory, which may exceed the memory limit in certain environments.

// 2.  INT_MAX and Overflow
// Replace INT_MAX with a large number that won’t cause overflow when adding 1, e.g., 1e9.

// 3. Space Optimization
// Instead of using a 2D DP array t, you can reduce space complexity to O(target) using a 1D DP array. Since the current row depends only on the previous row or itself, we can reuse the same array.


// Learnings: 
// Instead of using INT_MAX, initialise the values with 1e9 or such large values so that when 1 is added it doesn't cause an overflow
// Since the ith row only depends on the ith and i-1 th row, we can do space optimisations which can help us overcome TLE
