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

// recursive solution
//         0
// - - - - -
//         nth position

// assume nth position in the array is 0. and we have to find the no of arrays that matches the description
// If I replace it with 1 then at n-1 we could only have 1 or 2 then only the adj elements difference will be 1
// similarly if I try to replace it with x, the i-1th element could be either x-1, x, or x+1


// int solve()(

// )

signed main(){
    initcode();
    int n,m; cin>>n>>m;
    int arr[n];
    forn(i,n) cin>>arr[i];

    int t[n+1][m+2]; // n+1 sized array for indexes from 1 to n
    //  m+2 cols - since we are checking x-1, x and x+1 when x = m, we will also be acessing m+1 th col. Hence m+2 cols in the array
    
    // first row and first col -> 0
    memset(t,0,sizeof(t)); 
    
    // Filling i=1 row
    for(int j=1;j<=m;j++){
        if(arr[0]==0) t[1][j] = 1; // If the 1st element is 0, we could replace it with any element b/w 1 and m
        else{
            if(arr[0] == j) t[1][j] = 1; // If the 1st element is non zero, then only cell where arr[0] == j would be set as 1, rest all will be 0
        }
    }

    // filling 2nd row onwards
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1] == 0){ // If the ith value is 0, then the no of ways to replace it with j is no of ways the prev position ends with j-1, j and j+1
                t[i][j] = ((t[i-1][j-1] + t[i-1][j])%mod + t[i-1][j+1])%mod;
            }
            else{ // if the ith value is non zero, then cells where arr[i-1] != j will be set as 0 and the no of ways this pos ends with j is summatoin of no of ways the prev position ends with j-1, j, and j+1
                if(arr[i-1] == j){
                    t[i][j] = ((t[i-1][j-1] + t[i-1][j])%mod + t[i-1][j+1])%mod;
                }
            }
        }
    }

    // check the last row and compute the ans
    int ans = 0;
    for(int j=1;j<=m;j++){
        ans = (ans + t[n][j])%mod;
    }

    cout<<ans<<endl;

    

}

