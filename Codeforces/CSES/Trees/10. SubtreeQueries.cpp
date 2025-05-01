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
// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
// int log_a_with_base_b(int a, int b) { return log2(a) / log2(b); }
// int modularBinaryExponentitation(int base, int exp) { return exp == 0 ? 1 : (modularBinaryExponentitation(base, exp / 2) * modularBinaryExponentitation(base, exp / 2) % mod * (exp % 2 ? base : 1)) % mod; }
// // mod in the below function parameter is conflicting with constant defined above 
// // int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// int mminvprime(int a, int b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// void print_graph(vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};


vector<vector<int>> adj;
vector<int> values, segTree, startTime, endTime, arr;
int N, timer=0;

// index -> indexing for Seg Tree (1based), leftChild = 2*parent_index, rightChild = 2*parentIndex+1
// We are following 1 based indexing in Seg Tree 
void buildTree(int index, int lo, int hi){
    if(lo == hi){ // base case
        segTree[index] = arr[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    buildTree(2*index+1, lo, mid);
    buildTree(2*index+2, mid+1, hi);
    segTree[index]  = segTree[2*index+1] + segTree[2*index+2];

}

// Update node s value to x
void updateTree(int s, int x, int index=0, int lo=0, int hi=N-1){
    if(lo == hi){
        segTree[index] = x;
        return;
    }
    int mid = (lo + hi) >> 1;
    if(s <= mid){ // update left side 
        updateTree(s,x,2*index+1,lo,mid);
    }
    else{
        updateTree(s,x,2*index+2,mid+1,hi);
    }
    segTree[index]  = segTree[2*index+1] + segTree[2*index+2];
}

// index -> segTree index
// lo and hi -> range of segTree[index]
// l and r --> our range for which we want to compute
int queryTree(int index, int lo, int hi, int l, int r){
    // if lo and hi completely lies within our range (l to r)
    if(lo>=l and hi<=r) return segTree[index];
    if(hi<l or lo>r) return 0;
    // overlap case: move in both the directions
    int mid = (lo+hi) >> 1;
    int left = queryTree(2*index+1,lo,mid,l,r);
    int right = queryTree(2*index+2,mid+1,hi,l,r);
    return left+right;

}

// evaluates the startTime and endTime for each node in the DFS Traversal
// the way start time and end time is designated to a node is for the leaf node, start time = end time 
// but in certain problems, we don't assign same start and end time to a node. There is atleast a difference of 1 b/w them
void dfs(int node, int parent){
    startTime[node] = timer; // node - time
    arr[timer] = values[node]; // time - values -- building correlation between startTime and values. This will help us in answering the queries in O(logN) by computing the sum of the segment which is represneted by node s
    timer++;
    for(auto nb: adj[node]){
        if(nb != parent){
            dfs(nb, node);
        }
    }
    endTime[node] = timer-1;
}


// Important: The way start time and end time is assigned in euler tour especially to the leaf nodes, depends on the problem statement.
// Here in this problem, we assigned same time as the start and end time for leaf nodes. In some problems, start and end time differs by 1 
signed main() {
    initcode();
    int n,q; cin>>n>>q;
    N = n;

    values.resize(n); // n nodes 1 to n
    startTime.resize(n);
    endTime.resize(n);
    segTree.resize(4*n);
    arr.resize(n);
    adj.resize(n);
    
    forn(i,n) cin>>values[i]; // node - values
    // finding sum of values in the subtree of node s is equivalent to finding sum of values in the segment start[s] and end[s] in the array arr
    // but for this we need correlation between start time and values of each node. arr contains that correlation

    forn(i,n-1){
        int u,v; cin>>u>>v;
        u--; v--;   // converting to 0 based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // euler tour
    // 0 is the root
    // evaluates the startTime and endTime time for each node in the dfs traversal
    dfs(0,-1); // node,parent O(N), where N is the no of nodes 

    // forn(i,n) cout<<startTime[i]<<" ";  // node-startTime
    // cout<<endl;
    // forn(i,n) cout<<endTime[i]<<" ";
    // cout<<endl;
    // forn(i,n) cout<<values[i]<<" ";  // node - values
    // cout<<endl;
    // forn(i,n) cout<<arr[i]<<" "; // starttimer - values
    // cout<<endl;

    // constructs sum segTree on the array arr
    buildTree(0,0,n-1);    // index, range of the array for which segTree[index] stores the answer


    // O(q*logN)
    while(q--){
        int t; cin>>t;
        if(t==1){
            int s,x; cin>>s>>x;
            s--;
            // update node s value to x, this means we'll also have to make change in arr as well. Update arr[startTime[s]] to x 
            // here we're sending startTime[s] in the parameter --> understanding this is the heart of the problem 
            // changing arr[startTime[s]] = x
            updateTree(startTime[s], x); // O(logn)
        }
        else{
            int s; cin>>s; 
            s--;
            // evaluting ans for subtree rooted at node s is equivalent to computing the answer for the segment startTime[s] to endTime[s]
            cout<<queryTree(0,0,N-1,startTime[s],endTime[s])<<endl; // O(logn)
        }
    }


    return 0;


    
}
// FINAL TC: O(N + QlogN)
