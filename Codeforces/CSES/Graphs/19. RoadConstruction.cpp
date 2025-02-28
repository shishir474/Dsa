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
#define inf             1e18
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

// Union Find Algo
struct node{
    int parent, rank;
};
vector<node> dsuf;

// union by rank and path compression
int find(int v){
    if(dsuf[v].parent==-1){
        return v;
    }
    return dsuf[v].parent = find(dsuf[v].parent);
}

int union_op(int fromP, int toP){
    // modifying the union_op little bit to return the size of the component - initialised rank with 1 for all nodes 
    // here the rank indicates the size of the component
    if(dsuf[fromP].rank < dsuf[toP].rank) swap(fromP, toP);

    dsuf[toP].parent=  fromP;
    dsuf[fromP].rank += dsuf[toP].rank;

   return dsuf[fromP].rank;

}

signed main() {
    initcode();
    int n,m; cin>>n>>m;
    vector<pii> edges;
    forn(i,m){
        int u,v; cin>>u>>v;
        // making nodes 0 based indexed, since dsuf is 0 based 
        edges.push_back({u-1,v-1});
    }
    
    dsuf.resize(n);
    for(int i=0;i<n;i++){
        dsuf[i].parent = -1;
        dsuf[i].rank = 1;  // twisted the meaning of rank in this problem. Hence intialising with 1 indicating the size of the component
    } 

    int components = n;
    int size = 1;

    forn(i,edges.size()){
        int u = edges[i].first, v = edges[i].second;
        int u_par = find(u);
        int v_par = find(v);
        // if the parents are same, then no point of addding that edge. The no of components and the size of the component remains the same
        if(u_par != v_par){
            // union_op performs union and returns the size of the component
            size = max(size, union_op(u_par, v_par));
            components--;
        }

        cout<<components<<" "<<size<<endl;

    }
}


// We cannot use the below logic to compute the no of components and the size of the component. It will cause TLE 
// tc becomes O(v*e) and both v and e are of 1e5 order


// count the no of nodes whose parent is -1 -> we have that many components
        // mp logic for computing size of the components work only bcoz we are using path compression in union find 
        // int cnt = 0, size = 1; // reps count of components
        // map<int,int> mp;
        // forn(j,n){
        //     if(dsuf[j].parent == -1) cnt++;
        //     else {
        //         mp[dsuf[j].parent]++;
        //         size = max(size, mp[dsuf[j].parent]);
        //     }
        // }

        // cout<<cnt<<" "<<size+1<<endl;


