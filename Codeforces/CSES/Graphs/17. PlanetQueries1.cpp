// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>;  // policy based data structure
// // ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// // and set.order_by_key(k) -> returns the index of the key k
// // ordered set data structure => adds indexing functionality to sets

// #define int             long long int
// #define ff              first
// #define ss              second
// #define pb              push_back
// // #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int> >
// #define setbits(x)      __builtin_popcountll(x)
// #define zrobits(x)      __builtin_ctzll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x; cin>>x; while(x--)
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define forn(i,n)      for(int i=0;i<n;++i)
// #define fore(i, l, r)   for(int i = l; i <= r; ++i)
// #define all(v)          v.begin(), v.end()

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// void initcode() {
// 	FIO;
// 	// #ifndef ONLINE_JUDGE
// 	// freopen("cpp/input.txt", "r", stdin);
// 	// freopen("cpp/output.txt", "w", stdout);
// 	// #endif // ONLINE_JUDGE
// }
// int gcd(int a, int b)
// {
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }
// int lcm(int a, int b) {
// 	return (a / gcd(a, b) * b);
// }
// int log_a_with_base_b(int a, int b){
//         return log2(a) / log2(b);
// }

// int modularBinaryExponentitation(int base, int exponent) {
// 	if(exponent==0) return 1;
// 	int val = modularBinaryExponentitation(base, exponent/2);
// 	if(exponent%2)
// 		return ((val*val)%mod*base)%mod;
// 	else
// 		return (val*val)%mod;
// }

// struct cmp {
// 	bool operator()(const pii& p1, const pii& p2) {
// 		return p1.second < p2.second;
// 	}
// };

// // 1e5 queries: for each query you have a starting point and you can take k steps -> determine which node you will reach
// vector<vector<int>> adj;

// signed main() {
//     initcode();
    
//     int n,q; cin>>n>>q;
//     // adj.resize(n+1); // nodes are [1..n] -> no need of adj array in this problem
    
//     // here we need to compute log n with base 2 
//     int col = floor(log2(n));  // assume n=8, log(8) base 2 = 3 -> so we need 4 columns in t

//     // cout<<"col "<<col<<endl;
//     int t[n+1][col+1]; // this matrix will store the 2^ith parent/child for each node
//     memset(t, -1, sizeof(t)); // initialised t with -1

//     forn(i,n){
//         cin>>t[i+1][0];
//     }

//     // fill the rest of the columns of t
//     // compute 2^i th child for each node
//         // t[i][1] = 2nd child of i, this will be firstChild(firstChild of i)
//         // t[i][1] = t[t[i][0]][0]
//         // t[i][2] = t[t[i][1]][1] => this will 4th child of i 
//     // 4th child of i is secondChild(secondChild(i)) 
//         // t[i][3] = 

//     // precomputation of 2^i th child for each node
//     for(int i=1;i<=col;i++){
//         for(int j=1;j<=n;j++)
//             t[j][i] = t[t[j][i-1]][i-1];
//     }
    
//     // for(int i=0;i<=col;i++){
//     //     for(int j=1;j<=n;j++){
//     //         cout<<t[j][i]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
    
//     while(q--){
//         int sv, k; cin>>sv>>k; // find kth child of the sv
        
        
//         for(int i=31;i>=0;i--){ // this way we will process the biggest factor of 2 by going in reverse direction 
//             // if ith bit is set in k
//             if(k&(1<<i)){
//                 sv = t[sv][i]; // update the sv to 2^i th child 
//             }
//         }

//         cout<<sv<<endl;

//     }
  
// }

// // log(n) computes log n base e
// // log2(n) computes log n with base 2. log2(n) is an inbuilt function in cpp to compute log with base 2
// // log a with base b 
//     // int log_a_with_base_b(int a, int b){
//     //     return log2(a) / log2(b);
//     // }




// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>;  // policy based data structure
// // ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// // and set.order_by_key(k) -> returns the index of the key k
// // ordered set data structure => adds indexing functionality to sets

// #define int             long long int
// #define ff              first
// #define ss              second
// #define pb              push_back
// // #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int> >
// #define setbits(x)      __builtin_popcountll(x)
// #define zrobits(x)      __builtin_ctzll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x; cin>>x; while(x--)
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define forn(i,n)      for(int i=0;i<n;++i)
// #define fore(i, l, r)   for(int i = l; i <= r; ++i)
// #define all(v)          v.begin(), v.end()

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// void initcode() {
// 	FIO;
// 	// #ifndef ONLINE_JUDGE
// 	// freopen("cpp/input.txt", "r", stdin);
// 	// freopen("cpp/output.txt", "w", stdout);
// 	// #endif // ONLINE_JUDGE
// }
// int gcd(int a, int b)
// {
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }
// int lcm(int a, int b) {
// 	return (a / gcd(a, b) * b);
// }

// int modularBinaryExponentitation(int base, int exponent) {
// 	if(exponent==0) return 1;
// 	int val = modularBinaryExponentitation(base, exponent/2);
// 	if(exponent%2)
// 		return ((val*val)%mod*base)%mod;
// 	else
// 		return (val*val)%mod;
// }

// struct cmp {
// 	bool operator()(const pii& p1, const pii& p2) {
// 		return p1.second < p2.second;
// 	}
// };

// // 1e5 queries: for each query you have a starting point and you can take k steps -> determine which node you will reach
// vector<vector<int>> adj;

// signed main() {
//     initcode();
    
//     int n,q; cin>>n>>q;
//     // adj.resize(n+1); // nodes are [1..n]
    
//     int col = floor(log2(n));  // assume n=8, log(8) base 2 = 3 -> so we need 4 columns in t
//     // cout<<"col "<<col<<endl;
//     int t[col+1][n+1]; // this matrix will store the 2^ith parent/child for each node
//     memset(t, -1, sizeof(t)); // initialised t with -1

//     forn(i,n){
//         cin>>t[0][i+1];
//     }

//     // fill the rest of the columns of t
//     // compute 2^i th child for each node
//         // t[i][1] = 2nd child of i, this will be firstChild(firstChild of i)
//         // t[i][1] = t[t[i][0]][0]
//         // t[i][2] = t[t[i][1]][1] => this will 4th child of i 
//     // 4th child of i is secondChild(secondChild(i)) 
//         // t[i][3] = 

//     // precomputation of 2^i th child for each node
//     for(int i=1;i<=col;i++){
//         for(int j=1;j<=n;j++)
//             t[i][j] = t[i-1][t[i-1][j]];
//     }
    
//     // for(int i=0;i<=col;i++){
//     //     for(int j=1;j<=n;j++){
//     //         cout<<t[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
    
//     while(q--){
//         int sv, k; cin>>sv>>k; // find kth child of the sv
        
        
//         for(int i=31;i>=0;i--){ // this way we will process the biggest factor of 2 by going in reverse direction 
//             // if ith bit is set in k
//             if(k&(1<<i)){
//                 sv = t[i][sv]; // update the sv to 2^i th child 
//             }
//         }

//         cout<<sv<<endl;

//     }
  
// }




#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define double long double
#define endl '\n'
 
const int MOD = 1000000007;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int n,q;
    cin>>n>>q;
    int m = 30;
 
    vector<vector<int>> sparseTable(m+1,vector<int> (n+1,-1));
    for (int i = 1; i <= n; i++) {
        cin>>sparseTable[0][i];
    }
 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
        }
    }
 
    while(q--) {
        int x,k;
        cin>>x>>k;
        int ans = x;
        for (int i = 0; i <=m; i++) {
            if (k&(1<<i)){
                ans = sparseTable[i][ans];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

// debug my code
// There is one more crucial part to this problem, the no of columns are always preffered to be more than no of rows in cpp. This is an optimisation techinque 
// Without this optimisation, my code is giving runtime error

