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
// int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// int mminvprime(int a, int b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void print_graph( vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }
struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};

vector<vector<int>> rev_adj, parent;
int N;

void binaryLifting(){
    for(int i=1;i<=20;i++){
        for(int j=0;j<N;j++){
            // 2^ith parent of j = 2^(i-1) parent of(2^(i-1) parent of j)
            int temp =  parent[j][i-1];
            if(temp != -1)
            parent[j][i] = parent[temp][i-1];
        }
    }

}

// return the kth parent of using binary lifting
int up(int node, int k){    
    int res = node;
    for(int i=20;i>=0;i--){
        if(k&(1<<i)){
            res =  parent[res][i];
            if(res == -1) return -1;
        }
    }

    return res;
}

signed main() {
    initcode();
    int n; cin>>n;
    N = n;
    rev_adj.resize(n+1);                             // need rev_adj for calculating the dist of each node from cycle 
    parent.resize(n, vector<int>(21,-1));
    vector<int> next(n);
    
    // Initialisation: populate next[], rev_adj list and 0th column of parent[][]
    forn(i,n){
        cin>>next[i];
        next[i]--;                                     // 0 based indexing 
        rev_adj[next[i]].push_back(i);
        parent[i][0] = next[i];
    }

    // PRECOMPUTATION
    // precomppute 2^ith parent of each node 
    binaryLifting();
    
    /* DEBUG STEP:
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<parent[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    // storing all cycles in the form of a map(node,index) in cycles 
    // cyclic_id stores the cycle id for each node. if(cyclic_id[p] == -1, it means p is not part of a cycle )

    // STEP 1:
    vector<map<int,int>> cycles;                                      
    vector<int> cycle_id(n,-2), cyclic_dist(n,0);                     // cycle_id innitialised with -2, indicating the vertices have not been processed yet 

    forn(i,n){
        if(cycle_id[i] != -2) continue;                               // node has already been processed 
        vector<int> path;                                             // path stores all nodes covered in the current iteration 
        int at = i;
        path.pb(at);
        while(cycle_id[next[at]] == -2){                              // while next node is not yet vis
            at = next[at];                                            // move to next node
            cycle_id[at] = -3;                                        // marking cycle_id -3 just to mark it vis
            path.push_back(at);
        }

        bool in_cycle = false;
        map<int,int> cycle;                                           // map used to store the cycle if any in the current path 

        for(auto i: path){
            if(i == next[at]){                                        // cycle found  
                in_cycle = true;
            }
            if(in_cycle){                                             // set the cycle_id and add node the cycle map      
                cycle_id[i] = cycles.size();                           
                cycle[i] = cycle.size();
            }
            else{
                cycle_id[i] = -1;                                     // since node is not part of cycle, set cycle_id -1
            }
        }
        cycles.push_back(cycle);                                      // push the cycle in cycles vector
    }

    /* Debug step:
    Printing all the cycles 
    cout<<cycles.size()<<endl;
    for(auto mp: cycles){
        for(auto i: mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
    forn(i,n){
        cout<<cycle_id[i]<<" ";
    }
    cout<<endl;
    */

    // compute the distance of each node from the cycle 
    // cyclic_dist[p] = 0 if p is a part of the cycle 

    // STEP 2:
    forn(i,n){
        // process only those which are at dist 1 from cycle which means ignore all nodes that part of cycle + nodes which are not at dist 1 from the cycle
        // node which is at dist 1 from cycle it's next node cycle_id will be >= 0
        if(cycle_id[i] != -1 or cycle_id[next[i]] == -1) continue;           
        cyclic_dist[i] = 1;                                 // perform bfs/level order traversal to calculate the depth of each node on reversed_graph
        queue<int> q;                                       // node, dist
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nb: rev_adj[node]){
                cyclic_dist[nb] = cyclic_dist[node] + 1;
                q.push(nb);
            }
        }
    }
    
    /* DEBUG STEP
    // forn(i,n) cout<<cyclic_dist[i]<<" ";
    // cout<<endl;
    */

    // STEP 3:
    forn(i,n){
        if(cycle_id[i] != -1){ // if node is part of any cycle 
            cout<<cycles[cycle_id[i]].size()<<" ";
        }
        else{   // node is not part of cycle 
            int node_on_cycle = up(i, cyclic_dist[i]);
            int cycle_len = cycles[cycle_id[node_on_cycle]].size();
            cout<<cyclic_dist[i]+cycle_len<<" ";
        }
    }

    
}

// The input is a functional graph(each node has exactly one outgoing edge liek here teleportation links)
// Notice that all functional graphs can be broken down into a bunch of "components". 
// Each of these components consists of many trees directed towards the root, and a single cycle composed of said roots and some other nodes.








