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

signed main(){
    initcode();
    int n,target; cin>>n>>target;
    vector<int> v;
    forn(i,n){
        int x; cin>>x;
        v.pb(x); 
    } 
    if(n<4){ // we need atleast 4 elements 
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        unordered_map<int, pii> mp; // sum -> indices of the values that constitues this sum
        
        mp[v[0]+v[1]] = {0,1};

        // start from 2nd index onwards: i and j will track the pair and we will use map to check whether we've encoutered target-v[i]-v[j] value before
        for(int i=2;i<n;i++){

            for(int j=i+1;j<n;j++){

                // check if target-v[i]-v[j] exists in the mp, found the solution
                if(mp.count(target-v[i]-v[j])){
                    cout<<mp[target-v[i]-v[j]].first+1<<" "<<mp[target-v[i]-v[j]].second+1<<" "<<i+1<<" "<<j+1<<endl;
                    return 0;
                }

            }

            // update the map: add entries for the pairs ending at index i
            for(int j=0;j<i;j++){
                mp[v[j]+v[i]] = {j,i};
            }

        }

        cout<<"IMPOSSIBLE"<<endl;
        return 0;

    
    }
    
 

    
}