// https://www.youtube.com/watch?v=s8e3Gy7H9iw&t=144s&ab_channel=NeatlyStructured

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
        return p1.first > p2.first;  // Compare by first element
    }
};

bool isPossible(int mid, vector<int>& arr, int t){
    // t is the desired no of products that we need to make, arr contains time required to making 1 product across different machines
    // calculate the number of products that can be made within mid minutes
    int cnt=0;
    forn(i,arr.size()){ // 1e9 machines -- loop size, max value of t could be 1e9
    // loop runs 1e9 times in the worst case and in worst case mid could be 1e18 and arr[i]=1 which means If I sum 1e18, 1e9 times, it will exceed the max of long long
        cnt+=(mid/arr[i]);  // this cnt can overflow, hence add break condition
        if(cnt>=t) break; // cnt can overflow out of long long and hence this break condition
    }
    return cnt>=t; // if we are able to make t products we return true
}

signed main(){
    initcode();
    int n,t,ans; cin>>n>>t;
    vector<int> arr(n);
    forn(i,n) cin>>arr[i];
    int lo = 0, hi = 1e18;
    // hi = *max_element(all(arr))*t; // min and the max time required to make t products
    while(lo <= hi){
        int mid = (lo + (hi-lo)/2);
        if(isPossible(mid,arr,t)){ // checks if t products can be made in mid minutes
            ans = mid; // if yes, then obviously we can make them in more than mid minutes as well -- monotonic nature 
            hi = mid-1;
        }
        else{ // t products can't be made in mid minutes, so obvioulsy then can't be made in less than mid minutes as well
            lo = mid+1;
        }
    }

    cout<<ans<<endl;

    return 0;
    
    
}

