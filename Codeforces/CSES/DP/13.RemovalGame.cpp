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

int t[5002][5002];
int solve(int i, int j, vector<int>& arr){
    if(i==j) return arr[i]; // this would be the max difference when there is a single element
    if(t[i][j] != -1) return t[i][j];
    //2 options
    return t[i][j] = max(arr[i] - solve(i+1,j,arr), arr[j] - solve(i,j-1,arr));
}

// Key points
// t[i][j] stores the max diff in scores of p1 and p2 in array from i to j
// Once we have the max diff for the entire array we could leverage this diff to find the max score of p1
// we are using 2pointer here: Now p1 can choose to go with arr[i] or arr[j]
// Now if he chooses arr[i], the max diff in (i,j) would be arr[i] - dp[i+1][j]
// and similarly if he chooses arr[j] the max diff in (i,j) would be arr[j] - dp[i][j-1]
// dp[i][j] gives the max diff in interval of i to j, so for the subproblem dp(i+1,j) & dp(i,j-1) it also gives the max diff from the p1 perspective, but in order to maximise the value for interval (i,j) we would need to subtract the max value of subproblem from i or j 

signed main(){
    initcode();
    int n; cin>>n;
    vector<int> arr(n);
    int sum = 0;
    forn(i,n){
        cin>>arr[i];
        sum+=arr[i];
    }
    memset(t, -1, sizeof(t));
    int diff = solve(0,n-1,arr); // computes the max diff (i.e max value of p1-p2 in the whole array) p1 reps player1 score and p2 represents player2 score
    // diff is the max value of P1-P2
    // and we also know P1+P2 which is sum(arr)
    // Hence P1 would be (sum(arr) + diff)/2

    cout<<(sum+diff)/2<<endl;

    
}

// Trying to convert the above recursive sol into iterative solution
// (0,0), (0,1), (0,2), ....... (0,n-1)
//         (1,1), (1,2), (1,2)..(1,n-1)
//                 (2,2),(2,3)..(2,n)
//                 and so on 
//                              (n,n)

dp[i][j] depends on dp[i+1,j] and dp[i,j-1]

for(int i=n-1;i>=0;i--){  // moving from bottom to top
    for(int j=i;j<n;j++){ // and in each row from j=i to j=n-1
        if (i==j){
            t[i][j]=a[i];
        }
        else{
            t[i][j] = max(a[i]-t[i+1][j], a[j]-t[i][j-1]);
        }
    }
}
