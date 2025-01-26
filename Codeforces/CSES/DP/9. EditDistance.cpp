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

signed main(){
    initcode();
    string s1, s2;
    cin>>s1>>s2;

    // If the nth and mth char matches:
        // then the problem reduces to trying matching n-1 and m-1 characters
    // If the nth and mth char mismatch we have 3possibilities:
    //  a. Add: If we add a new char such that n+1th char matches with mth char, then problemn reduces to matching n with m-1
    // b. Replace: If we replace nth char with mth char, then problem reduces to matching n-1 char with m-1 char
    // c. Delete: If we delete nth char, then problem reduces to matching n-1th char with mth char

    // Out of this 3 pick the min + 1

    int n = s1.length(), m = s2.length();
    int t[n+1][m+1];
    
    t[0][0] = 0;

    // fill 1st row
    for(int i=1;i<=m;i++){
        t[0][i] = i;
    }

    // fill 1st col
    for(int i=1;i<=n;i++){
        t[i][0] = i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // compare ith and jth char
            if(s1[i-1]==s2[j-1]){
                // If the ith char matches with jth char, then problem reduces to comparing i-1 and j-1 characters
                t[i][j] = t[i-1][j-1];
            }
            else{  // we could perform either of the 3 operations 
                t[i][j] = 1 + min({t[i-1][j], t[i-1][j-1], t[i][j-1]});
            }
        }
    }

    cout<<t[n][m]<<endl;


    

}

