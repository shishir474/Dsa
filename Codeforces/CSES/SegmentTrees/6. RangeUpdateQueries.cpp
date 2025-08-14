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
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a / gcd(a, b) * b);
}
int log_a_with_base_b(int a, int b){
        return log2(a) / log2(b);
}
void print_graph(vector<vector<int>> adj){
	forn(i,adj.size()){
		cout<<i<<": ";
		forn(j,adj[i].size()){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}
int modularBinaryExponentitation(int base, int exponent) {
	if(exponent==0) return 1;
	int val = modularBinaryExponentitation(base, exponent/2);
	if(exponent%2)
		return ((val*val)%mod*base)%mod;
	else
		return (val*val)%mod;
}

struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};

vector<int> arr,segTree;

// update pos k's value to u
// index -> denotes the index of the segTree node, lo and hi denotes the range of array arr for which it stores the ans
void update(int index, int lo, int hi, int k, int u){
    if(lo == hi){
        segTree[index] += u;
        return;
    }
    int mid = (lo + hi) >> 1;
    if(k <= mid){
        update(2*index + 1, lo, mid, k, u);
    }
    else{
        update(2*index + 2, mid+1, hi, k, u);
    }

    segTree[index]= segTree[2*index + 1] + segTree[2*index + 2];

}

int queryTree(int index, int lo, int hi, int l, int r){
    if(lo >= l and hi <= r) return segTree[index];
    else if(hi < l or lo >  r) return 0;
    int mid = (lo + hi) >> 1;
    int left = queryTree(2*index+1, lo, mid, l, r);
    int right = queryTree(2*index+2, mid+1, hi, l, r);
    return left + right;
}

// Instead of the point update, this questions asks us to do range updates 
// range update are pretty simple. We can use Difference array technique + prefix sums to efficiently update and evaluate the updated array 
// suppose you want to update [l,r] by +x. then all you have to do is increase arr[l]  by x and decrease arr[r+1] by x (only iff r+1 exists)
// and then take a prefix sum 
// If there are multiple queries, this is an O(1) operation and after all queries you can evalute the prefix sum to get the actual arr
signed main() {
    initcode();
    int n,q; cin>>n>>q;
    arr.resize(n);
    segTree.resize(4*n);
    forn(i,n) cin>>arr[i];

    while(q--){
        int t; cin>>t;
        if(t==1){
            int a,b,u; cin>>a>>b>>u;
            a--; b--;                   // convert to 0 based indexing

            // increase the value of the range [a,b] by u
            update(0,0,n-1,a,u);        // diff[a] += u
            if(b+1 < n){
                update(0,0,n-1,b+1,-1*u);       // diff[b+1] -= u (array difference technique) --> ofcourse do this only if b+1 < n
            }
        }
        else{
            int k; cin>>k;
            k--;                       // convert to 0 based indexing
            // get the value at index k -- essentially equal to finding the prefix sum[0,k] of the difference array 
            int netChange = queryTree(0,0,n-1,0,k);
            cout<<arr[k] + netChange<<endl;
        }
    }

    return 0;    
}





