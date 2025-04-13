/* Shishir Singh */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>;  // policy based data structure
// ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// and set.order_by_key(k) -> returns the index of the key k
// ordered set data structure => adds indexing functionality to sets

#define int             long long int
#define ff              first
#define ss              second
#define pb              push_back
// #define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define INF             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(i,n)      for(int i=0;i<n;++i)
#define fore(i, l, r)   for(int i = l; i <= r; ++i)
#define all(v)          v.begin(), v.end()

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode() {
	FIO;
	// #ifndef ONLINE_JUDGE
	// freopen("cpp/input.txt", "r", stdin);
	// freopen("cpp/output.txt", "w", stdout);
	// #endif // ONLINE_JUDGE
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int modularBinaryExponentitation(int base, int exp) { return exp == 0 ? 1 : (modularBinaryExponentitation(base, exp / 2) * modularBinaryExponentitation(base, exp / 2) % mod * (exp % 2 ? base : 1)) % mod; }
int modinv(int b, int c){ return modularBinaryExponentitation(b, c-2);}
int log_a_with_base_b(int a, int b) { return log2(a) / log2(b); }
// ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void print_graph( vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};

// Solution1
signed main() {
    initcode();
    int n,q; cin>>n>>q;
    vector<int> arr(n);
    set<pii> s;     // salary, index
    forn(i,n){              // salary may not be unique, hence using set of pii
        cin>>arr[i];
        s.insert({arr[i],i});
    }


    while(q--){
        char ch; cin>>ch;
        if(ch == '!'){
            int k,x; cin>>k>>x;   
            k--;                      // change the salary of employee k to x, k is 1 based, changing it to 0 based 
            s.erase({arr[k],k});     // empplyee k's salary is arr[k]
            arr[k] = x;
            s.insert({arr[k],k});   // delete the older salary and insert the new salary 
        }
        else{   
            int x,y; cin>>x>>y;
            // # of employees whose salary is between [x,y]
            cout<<s.order_of_key({y,INF}) - s.order_of_key({x-1,INF})<<endl;
            // int a = s.lower_bound({x-1,INF}) - s.begin();
            int a = distance(s.begin(), s.lower_bound({x-1,INF}));
            // int b = s.lower_bound({y,INF})-s.begin();
            int b = distance(s.begin(), s.lower_bound({y,INF}));

            cout<<b - a<<endl;
        }
    }
   

}



// Solution 2: Using Segment Trees

/* Shishir Singh */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>;  // policy based data structure
// ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// and set.order_by_key(k) -> returns the index of the key k
// ordered set data structure => adds indexing functionality to sets

#define int             long long int
#define ff              first
#define ss              second
#define pb              push_back
// #define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define INF             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(i,n)      for(int i=0;i<n;++i)
#define fore(i, l, r)   for(int i = l; i <= r; ++i)
#define all(v)          v.begin(), v.end()

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode() {
	FIO;
	// #ifndef ONLINE_JUDGE
	// freopen("cpp/input.txt", "r", stdin);
	// freopen("cpp/output.txt", "w", stdout);
	// #endif // ONLINE_JUDGE
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int modularBinaryExponentitation(int base, int exp) { return exp == 0 ? 1 : (modularBinaryExponentitation(base, exp / 2) * modularBinaryExponentitation(base, exp / 2) % mod * (exp % 2 ? base : 1)) % mod; }
int modinv(int b, int c){ return modularBinaryExponentitation(b, c-2);}
int log_a_with_base_b(int a, int b) { return log2(a) / log2(b); }
// ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void print_graph( vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};


vector<int> segTree;

void buildTree(int index, int lo, int hi){
    if(lo == hi){
        segTree[index] = 0;
        return;
    }
    int mid = (lo + hi)/2;
    buildTree(2*index+1, lo,mid);
    buildTree(2*index+2, mid+1,hi);
    segTree[index] = segTree[2*index+1]+ segTree[2*index+2];
}

// index -> segTreee index
// lo, hi -> array boundary
// update the value of position x to val
void update(int index, int lo, int hi, int x, int val){
    if(lo == hi){
        segTree[index] += val;
        return;
    }
    int mid = (lo + hi)/2;
    if(x<=mid){
        update(2*index+1,lo,mid,x,val);
    }
    else{
        update(2*index+2,mid+1,hi,x,val);
    }
    segTree[index] = segTree[2*index+1]+ segTree[2*index+2];
}


int queryTree(int index, int lo, int hi, int l, int r){
    // case 1: complete overlap
    if(lo >= l and hi <= r) return segTree[index];
    // case 2: completely out of bound
    if(hi < l or lo > r) return 0;
    // partial overlap
    int mid = (lo + hi) / 2; 
    return queryTree(2*index+1,lo,mid,l,r) +
    queryTree(2*index+2,mid+1,hi,l,r);
}

// Solution1
signed main() {
    initcode();
    int n,q; cin>>n>>q;
    vector<int> arr;
    segTree.resize(4*n);
    forn(i,n){int x; cin>>x; arr.push_back(x);};      // arr stores all your salaries 
    vector<int> orig_salaries(arr.begin(),arr.end());
    vector<array<int,3>> res;
    while(q--){
        char t; cin>>t;
        if(t=='?'){
            int a,b; cin>>a>>b;    // # no of emp whose salary is between a and b
            res.push_back({0,a,b});
        }
        else{
            int k,x; cin>>k>>x;     // update the salary of emp k to x
            k--;                    // since k is 1 based 
            arr.push_back(x);       // track all the current + future update salaries in arr
            res.push_back({1,k,x});
        }
    }

    // arr contains all the salaries, current + future updates 

    // Coordinate Compression step
    // Remove duplicates from arr 
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());

    // Now all your salaries(current + future updates) are mapped to unique indices in arr 
    // mapped all the salaries to a unique index 

    map<int,int> compress;
    for(int i=0;i<arr.size();i++){
        compress[arr[i]] = i;       // mapped each salary to its unique index 
    }

    buildTree(0,0,arr.size()-1);    // segTree index, array boundary

    for(int i=0;i<arr.size();i++){
        update(0,0,arr.size()-1,compress[arr[i]],1);
    }
    for(int i=0;i<res.size();i++){
        if(res[i][0] == 0){
            int a = res[i][1], b = res[i][2];
            // # of emp whose salary is between a and b 
            int i1 = lower_bound(all(arr),a) - arr.begin();
            int i2 = upper_bound(all(arr),b) - arr.begin();
            cout<<queryTree(0,0,arr.size()-1,i1,i2)<<endl;

        }
        else{
            int k = res[i][1], x = res[i][2];
            // update emp k salary to x
            int old_salary = orig_salaries[k];
            update(0,0,arr.size()-1,compress[old_salary],-1);
            orig_salaries[k] = x;
            update(0,0,arr.size()-1,compress[x],1);
        
        }
    }


    return 0;



}

