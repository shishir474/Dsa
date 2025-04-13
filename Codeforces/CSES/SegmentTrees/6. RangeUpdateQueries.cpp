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
int log_a_with_base_b(int a, int b) { return log2(a) / log2(b); }
// int modularBinaryExponentitation(int base, int exp) { return exp == 0 ? 1 : (modularBinaryExponentitation(base, exp / 2) * modularBinaryExponentitation(base, exp / 2) % mod * (exp % 2 ? base : 1)) % mod; }
// ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void print_graph(vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};


// difference array techinue:
// You are given  q queries of the form l,r,x. You have to add x to all the positions from l to r and finally print the array after all the queries
// Add x to arr[l] and -x to arr[r+1]
// arr[l]+=x
// arr[r+1]-=x;
// Take prefix sum --> this will give you your final array 
// TC for each query O(1)
// Total time complexity: O(Q) + O(N) : O(Q) for processing all queries + O(N) for prefix sum
// Brute force tc; O(Q*N)

// Simlary if asked to do xor from l to r with x 
// arr[l] ^= x;
// arr[r+1] ^= x;
// Take prefix xor --> this will give you the final array 

vector<int> arr,diff,segTree;

// we are storing sum for a particular range at each node
void buildTree(int index, int lo, int hi){
    if(lo == hi){
        segTree[index] = diff[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    buildTree(2*index+1, lo, mid);
    buildTree(2*index+2, mid+1, hi);
    segTree[index] = segTree[2*index+1] + segTree[2*index+2];
}

// lo, hi represents the range of the segTree node] whose index is index
void updateTree(int index,int lo, int hi, int pos, int val){
    // cout<<"lo "<<lo<<" "<<"hi "<<hi<<" "<<"pos "<<pos<<endl;
    if(lo == hi){
        segTree[index]+=val;
        return;
    }
    int mid = (lo + hi) >> 1;
    if(pos<=mid){
        updateTree(2*index+1, lo, mid, pos, val);
    }
    else{
        updateTree(2*index+2, mid+1, hi, pos, val);
    }
    segTree[index] = segTree[2*index+1] + segTree[2*index+2];
}

// compute the sum of the seg l to r
// lo and hi represents the range of curr segtree node's
int queryTree(int index, int lo, int hi, int l, int r){
    // case 1:complete overlap -> if the segTree's range lies completely within l to r 
    if(lo >= l and hi <= r) return segTree[index];
    // case 2: completely outside 
    // lo hi l r or l r lo hi
    if(hi < l or lo > r) return 0;
    // case 3: partial overlap, move in both directions
    int mid = (lo + hi) >> 1;
    int left = queryTree(2*index+1, lo, mid, l, r);
    int right = queryTree(2*index+2, mid+1, hi, l, r);
    return left + right;

}

// In this problem: you are given q queries : 1st increase each element from index l to r by x 
// 2nd : Print the value at a particular index 
// first thought that came is using array difference technique 
// For each query of 1st type we do arr[l] += x and arr[r+1] -= x
// and for 2nd query take the prefix sum of the array to get the actual state of the array  --> O(N)
// TC: in the worst case could be O(Q * N) if all the queries are of 2nd type 
// Instead of computing the prefix sum via traditional route which take O(N) time, we will use Seg Tree to compute this value in O(logN);
signed main() {
    initcode();
    int n,q; cin>>n>>q;
    arr.resize(n);
    diff.resize(n);
    segTree.resize(4*n);
    forn(i,n) cin>>arr[i];
    diff[0] = arr[0];
    fore(i,1,n-1)
        diff[i] = arr[i] - arr[i-1];

    // built on diff array 
    buildTree(0,0,n-1);  // index, lo, hi
    // buildTree is O(N), whereas updateTree and queryTree() both are O(logN)
    
    
// TC: O(Q * logN)
    while(q--){
        int t; cin>>t;
        if(t==1){
            int a,b,val; cin>>a>>b>>val;
            a--; b--; // converting the 1based indexing to 0 based indexing

            // using difference array concept 
            updateTree(0,0,n-1,a,val); // increase position a's value by u
            if(b+1 < n)
                updateTree(0,0,n-1,b+1,-1*val); // increase position b+1's value by -u
        }
        else{
            int k; cin>>k; // compute the sum/prefixSsum of segment [0,k] using segTree 
            // computing the prefix sum from [0,k] will give you the element at position k 
            k--;
            cout<<queryTree(0,0,n-1,0,k)<<endl;  // O(logN)
        }

    }

    
}






