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

void printset(set<pii> s){
    for(auto it: s){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

// good question
// 1st: for a particular window, we always convert all the elements to that window's median value. This will be the most optimal approach
// 2nd: How we calculate ans for a particular window by keeping track of the sums of the left and right set
signed main(){
    initcode();
    int n,k; cin>>n>>k;
    vector<int> arr(n);
    forn(i,n) cin>>arr[i];

    // Handling edge cases k=1 and k=2
    if(k==1){
        for(int i=0;i<n;i++){
            cout<<"0"<<" ";
        }
        return 0;
    }
    if(k==2){
        for(int i=0;i<n-1;i++){
            cout<<abs(arr[i] - arr[i+1])<<" ";
        }
        return 0;
    }

    vector<pii> v;

    // process first k elements 
    forn(i,k){
        v.push_back({arr[i],i});
    }
    sort(all(v));

    set<pii> lset, rset;
    int lset_sum = 0, rset_sum = 0;

    // lets add k+2 + (k%2) elements in the lset, and the remaing in rset 
    for(int i=0;i < k/2 + (k%2); i++){
        lset.insert(v[i]);
        lset_sum += v[i].first;
    }
    for(int i = k/2 + (k%2); i<k; i++){
        rset.insert(v[i]);
        rset_sum += v[i].first;
    }

    // Initial configuration ready 
    int median = (*lset.rbegin()).first;  // first window median
    cout<< (lset.size() * median - lset_sum )       // first window cost 
        + (rset_sum - rset.size() * median) <<" ";

    // NOTE: while inserting and removing element, you have to update corresponding set's sum as well
    for(int j = 1; j < n - k + 1; j++){
        // remove arr[j-1] element 
        if(lset.count({arr[j-1],j-1})) {
            lset_sum -= arr[j-1];
            lset.erase({arr[j-1],j-1});
        }
        else{
            rset_sum -= arr[j-1];
            rset.erase({arr[j-1],j-1});
        }
        // insert arr[j+k-1] element 
        if(arr[j+k-1] > lset.rbegin()->first){ // insert in rset
            rset.insert({arr[j+k-1], j+k-1});
            rset_sum += arr[j+k-1];
        } else{
            lset.insert({arr[j+k-1], j+k-1});
            lset_sum += arr[j+k-1];
        }
        // transfer elements to ensure lset.size() is k/2 + (k%2) at the end 
        while(lset.size() < k/2 + (k%2)){ // insert elements from rset.begin() into lset
            pii p=  *(rset.begin());       // here we are trying to increase lset size
            rset_sum -= p.first;
            rset.erase(p);
            lset.insert(p);
            lset_sum += p.first;
        }
        // similary repeat the same activity if lset.size() > k/2 + (k%2)
        while(lset.size() > k/2 + (k%2)){ // insert elements from lset.rbegin() into rset
            pii p=  *(lset.rbegin());     // here we are trying to decrease lset size  
            lset_sum -= p.first;
            lset.erase(p);
            rset.insert(p);
            rset_sum += p.first;                             
        }
        // at this point lset size will guaranteed by k/2 + (k%2)
        // Performing operations and maintaining lset size this way ensures that the median value is always given by lset.rbegin()->first
        
        // debug
            // cout<<"printing lset "<<j<<endl;
            // printset(lset);
            // cout<<"lset sum "<<lset_sum<<endl;
            // cout<<"printing rset "<<j<<endl;
            // printset(rset);
            // cout<<"rset sum "<<rset_sum<<endl;
        
        median = (*lset.rbegin()).first; 
        cout<< (lset.size() * median - lset_sum )       
        + (rset_sum - rset.size() * median) <<" ";

    }


    return 0;
    
}