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

vector<vector<int>> adj,mat;
vector<int> level;
int N;

void populateMatrix(){
    //0th column ie 2^0 i.e 1st parent is already populated
    // populate rest of the columns 
    for(int j=1;j<=20;j++){
        for(int i=1;i<=N;i++){
            // To compute 2^jth parent of node i
                // first get 2^(j-1) parent of node i and then again get 2^(j-1)th parent of node obtained in the prev step
            int t = mat[i][j-1];
            if(t != -1) // only compute if 2^(j-1) th parent exists
                mat[i][j] = mat[t][j-1];
        }
    }
}

// returns the node id of the kth ancestor of u-- uses binary lifting logic to determine the kth ancestor
// binary lifting => k(the dist) can also be expressed as sums of powers of 2 
int liftNode(int u, int k){
    // mat dimension is n+1 X 21 i.e it is assumed that max depth of the tree wont exceed 2^20
    int curr = u;
    for(int i=20;i>=0;i--){
        // if the ith bit is set in K
        if(k&(1<<i)){
            curr = mat[curr][i];
            if(curr == -1) return -1;
        }
    }
    return curr;
}

// computes lca of 2 nodes u and v and returns that node id
int computeLCA(int u, int v){
    // assuming level[v] <= level[u]
    if(level[u] < level[v]) swap(u,v);
    // lift u to bring it to the same level as v
    // how much to lift = level[u]-level[v]
    int new_u = liftNode(u,level[u]-level[v]);
    // now both new_u and v are at the same level;
    // edge case : if v is the ancestor of u 
    if(new_u == v){
        return v;
    }
    
    int pow = log2(level[v]);
    // largest pow such that 2^pow <= level[v];
    // take as much jumps as you can such that you land on node 1 step below the lca node
    // start with the largest power of 2 -- this strategy works bcoz, we can express any no in sums of powers of 2
    // assume level[v] = 10, level[lca] = 5, so we need to reach level = 6 pow=3
    // 2^3 = 8 ==> same n1 and n2 
    // 2^2 = 4 ==> diff n1 and n2 , lift new_u and v
    // 2^1, 2^0 => not possible
    while(pow--){
        int n1 = liftNode(new_u,1<<pow);
        int n2 = liftNode(v,1<<pow);
        if(n1 != n2){
            // take this jump and update new_u and v to n1 and n2 respectively
            new_u = n1;
            v = n2;
        }
    }

    // now it's guranteed that new_u and v are exactly 1 step below the lca
    return liftNode(new_u,1);
}

// computes distance between 2 nodes u and v
int computeDist(int u, int v){
    if(u == v) return 0;
    int lca = computeLCA(u,v);
    int dist = level[u] + level[v] - 2*level[lca];
    return dist;
}

void computeLevels(){
    queue<pii> q;
    q.push({1,-1}); // node,parent
    level[1] = 0;
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        // checking nb's of node
        for(auto nb: adj[node]){
            if(nb != parent){
                level[nb]=  level[node] + 1;
                q.push({nb,node});
            }
        }
    }
}

// dist(u,v) =  lvl(u) + lvl(v) - 2*lvl(lca(u,v))
signed main() {
    initcode();
    int n,q; cin>>n>>q;
    N = n;
    adj.resize(n+1);
    level.resize(n+1,-1);
    mat.resize(n+1, vector<int>(21,-1)); // mat stores 2^i th parent of each node from [1,n] where 0<=i<=20
    // assuming 2^20 is the max depth of the tree. Tree depth will not be more than this
    forn(i,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // assuming v is greater than u ex: 1 2
        if(v < u) swap(u,v);
        mat[v][0] = u; // 2^0 i.e 1st parent of v is u
    }

    computeLevels();
    populateMatrix();
    
    // fore(i,1,N) cout<<level[i]<<" ";
    // cout<<endl;
    
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=2;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    while(q--){
        int u,v; cin>>u>>v;
        int dist = computeDist(u,v);
        cout<<dist<<endl;
    }
    
    // cout<<computeLCA(4,5)<<endl;
    // cout<<computeLCA(4,2)<<endl;
}






