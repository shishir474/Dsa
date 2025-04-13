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
    bool operator()(const pair<pii,int>& p1, const pair<pii,int>& p2){
        if(p1.first.first == p2.first.first) // if start time is same, arrange in descending order of end times 
        return p1.first.second > p2.first.second;  // Compare by end time 

        return p1.first.first < p2.first.first; // arrange in ascending order of start times 

    }
};


signed main(){
    initcode();
    int n; cin>>n;
    vector<pair<pii,int>> ranges; // <<start,end>,index>
    forn(i,n){
        int start, end; cin>>start>>end;
        ranges.pb({{start,end},i});
    }
    // sort on basis of start time
    // if start time's are same, sort the intervals in descending order of end times  --- IMPORTANT 
    sort(all(ranges), cmp());     
    // ex: (1,4) (1,5)

    // ex: (1,5), (1,4)
    //contains 1   0             

    vector<bool> contains(n,false), contained(n,false);

    // ith interval will contain jth interval only when jth interval starts after ith one and ends before ith one
    // a[i].start <= a[j].start and a[j].end <= a[i].end
    // tracking min end time for all the possible j intervals
    // out of all the j intervals if we are able to found any one interval that ends before the ith one - ans for the ith interval becomes true. Hence tracking the minimum of all end times
    int mn = 1e18;
    for(int i=n-1;i>=0;i--){ 
        int start = ranges[i].first.first;
        int end = ranges[i].first.second;
        int idx = ranges[i].second;

        if(mn <= end)  // found one interval which ends before the current i
            contains[idx] = true;
        mn = min(mn, end); // updating the min end time
    }

    // ith interval will be contained by jth interval only when there is any j interval that starts before the ith one and ends after the ith one
    // a[j].start <= a[i].start && a[i].end <= a[j].end
    // so even if we have one interval that ends after the ith one, contained[i] = true -- hence tracking the max end time here

    int mx = -1;
    for(int i=0;i<n;i++){
        int start = ranges[i].first.first;
        int end = ranges[i].first.second;
        int idx = ranges[i].second;

        if(mx >= end)
            contained[idx] = true;
        mx = max(mx, end); // updating the max end time
    }

    forn(i,n) cout<<contains[i]<<" ";
    cout<<endl;
    forn(i,n) cout<<contained[i]<<" ";

    return 0;
    
    
}

