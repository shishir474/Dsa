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

// Here the intuition was to determine if we could acheive a target using the n elements.
// The questions ask is to figure out all the targets that could be acheived. targets would lie in range [0, sum(arr)].
// So we can leverage the DP array at the end to determine what all targets are acheivable using the n elements

// recursive solution: checks if we can acheive target 
int t[n+1][target+1]
solve(i, target){
    if(target == 0) return true
    if(i>=n) return false;
    if(t[i][target] != -1) return t[i][target]; // target would always be in range of 0 to sum(arr) both inclusive

    if(arr[i] <= target){
       return t[i][target] =  solve(i-1,target) or solve(i-1, target-arr[i]);
    }
    else{
        return t[i][target] =  solve(i-1, target);
    }
}

signed main(){
    initcode();
    int n; cin>>n;
    vector<int> arr(n);
    forn(i,n) cin>>arr[i];
    int s = 0;
    forn(i,n) s+=arr[i];
    bool t[n+1][s+1];
// first col will be true - we could always make sum 0 by not including any element
// first row will be false from col 1 to s
    for(int i=0;i<=n;i++) t[i][0] = true;
    for(int i=1;i<=s;i++) t[0][i] = false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            // we have to make sum j with i elements
            // now can we take the ith element and make sum j. The ith element can only be taken if we arr[i-1] <= j
            if(arr[i-1]<=j){ // 2options take it or leave it
                t[i][j] = t[i-1][j] or t[i-1][j-arr[i-1]];
            }
            else{ // only one option to leave 
                t[i][j] = t[i-1][j];
            }
        }
    }

    int cnt=0;
    for(int i=1;i<=s;i++){
        if(t[n][i]) cnt++;
    }

    cout<<cnt<<endl;
    for(int i=1;i<=s;i++){
        if(t[n][i]) cout<<i<<" ";
    }
    cout<<endl;
    
}

