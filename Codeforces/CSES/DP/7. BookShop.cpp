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

// int t[1002][100002];
// int solve(int i, int x, vector<int>& prices, vector<int>& pages){
//     int n = prices.size();
//     if(i+1 >= n) return 0; // no books available
//     if(x <= 0) return 0; // no money, can't buy any book
//     if(t[i][x] != -1) return t[i][x];

//     int op1=0,op2=0;
//     op1 = solve(i+1,x,prices,pages);
    
//     if(prices[i] <= x){
//         op2 = max(pages[i] + solve(i+1,x-prices[i],prices,pages), solve(i+1,x,prices,pages));
//     }

//     return t[i][x] =  max(op1,op2);

// }


signed main(){
    initcode();
    int n,x; cin>>n>>x;
    vector<int> prices(n), pages(n);
    
    forn(i,n) cin>>prices[i];
    forn(i,n) cin>>pages[i];
    
    // memset(t,-1,sizeof(t));

    // cout<<solve(0,x,prices,pages)<<endl;

    // int t[n+1][x+1]; // stores the max no of pages
    int t[2][x+1];
    memset(t,0,sizeof(t)); // base case: when no books available -> return 0 (reason: In event of no availability of books the max no of pages that could be taken is 0)
    // 2nd base case: When no money -> return 0 (In case of absense of money, you can't buy any book, hence the max no of pages that could be returned is 0)
    
    int flag = 1;

    fore(i,1,n){
        fore(j,1,x){
            t[flag][j] = t[flag^1][j];
            if(prices[i-1] <= j){
                t[flag][j] = max(pages[i-1] + t[flag^1][j-prices[i-1]] , t[flag^1][j]);
            }
        }
        flag =  flag^1;
    }

    flag = flag^1;

    cout<<t[flag][x]<<endl;
}

// Step 1: recursive solution
// In recursive solution you will notice that ith row only depends on i-1th and the current ith row only.
// Hence space can be optimised here from O(n*m) to O(m)

// Step 2: Convert the recursive solution to iterative solution

// Step 3: Apply Space optimisation technique using flag