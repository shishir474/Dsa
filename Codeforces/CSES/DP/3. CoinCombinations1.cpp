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
    vector<int> arr(n);
    forn(i,n) cin>>arr[i];

    // The problem with this approach is it doesn't consider permutations of a sequence
    // like for example [2,2,3] and [2,3,2] both of them makes a target of 7, but the below sol will treat it as one combo
    // In this problem, we also need to consider permuations 

//     int t[2][target+1]; // stores the no of ways
// )   forn(i,2) t[i][0]= 1;
//     fore(i,1,target) t[0][i] = 0;

//     int flag = 1;
    
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=target;j++){
//             t[flag][j] = t[flag^1][j];
//             if(arr[i-1] <= j){
//                 t[flag][j] = (t[flag][j] + t[flag][j-arr[i-1]])%mod;
//             }
//         }
//         flag = flag^1;
//     }

//     flag = flag^1;

//     cout<<t[flag][target]<<endl;
   



   // correct solution:

   int t[target+1]; // no of ways to make a target 
   
   memset(t,0,sizeof(t)); 
   
   t[0] = 1; // no of ways to make target 0 - pick no coins (one way)
   
   for(int i=1;i<=target;i++){
       
        // no of ways to make a target i;
        
        for(int j=0;j<n;j++){ 
        
            // can pick jth coin to make target i only iff arr[j] <= i
        
            if(arr[j] <= i){ // 2 choices : pick jth coin or drop it. pick only iff the if condition satisfies
        
                // # of ways to make target i = picking jth coin so # of ways to make (i-arr[j]) t[i-arr[j]] + 
                // # If I dont pick jth coin, target remains unchanges so t[i]

                // since no of ways could be huge apply mod
                t[i] = (t[i] + t[i-arr[j]])%mod;
            }

        }
   }

   cout<<t[target]<<endl;

    
    
}