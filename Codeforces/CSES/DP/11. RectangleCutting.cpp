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

// returns the min no of moves required to cut these rectangles into squares
// a>0 and b>0 always

int t[502][502];

int solve(int a, int b){
    if(a==b) return 0; // already a square, no move required
    if(t[a][b]!=-1) return t[a][b];

    // we have 2 possiblities, either we can make a horizontal cut or a vertical cut
    // Hence we will try all the possibilities and then take the min of them all

    int ans = INT_MAX;
    // cutting horizontally
    for(int i=1;i<a;i++){ // exactly a-1 cuts can be made
        ans = min(ans, 1 + solve(i,b) + solve(a-i, b)); // width will remain same
    }
    // cutting vertically
    for(int i=1;i<b;i++){ // exactly b-1 cuts can be made
        ans = min(ans, 1 + solve(a,i) + solve(a,b-i)); // length will remain same
    }

    return t[a][b] = ans;
}


// Intuition:

// ---------
// |        |  
// |        | b
// ---------
// <---- a -->
// We are tasked with cutting the rectangle (a X b) into squares
// Now we can cut them horizontally and vertically
// If we cut them horizontally (------) I can make cut at points from 1 to b-1 and now the problem will reduce to finding min no no moves for rectangele
// solve(a,i) & solve(a,b-i) & we have already made 1 move

// Similary if we cut vertically, I can make cuts at points ranging from 1 to a-1 & now problem reduces to solve(i,b) & solve(a-i,b)

// Out of both the options, we will choose the one with min no of moves

signed main(){
    initcode();
    int a,b; cin>>a>>b;
    memset(t,-1,sizeof(t));
    cout<<solve(a,b)<<endl;
    
}

