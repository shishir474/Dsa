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

vector<vector<int>> adj, matrix;
vector<int> dist, depth;
int N;


// for lca, I need depth of root = 1, depth of root's child=2 and so on 
// This function can also be implemented via dfs()
void evalDepth(int sv, int parent){
   queue<pair<int,int>> q;
   q.push({1,-1});   // node,parent
   depth[1] = 1;
   while(!q.empty()){
       int node = q.front().first;
       int parent = q.front().second;
       matrix[0][node] = parent;                            // parent assignment. Filling the 1st row of parent matrix
       q.pop();
       for(auto nb: adj[node]){
           if(nb != parent){
               depth[nb] = 1 + depth[node];
               q.push({nb, node});
           }
       }
   }
}


void binaryLifting(){
    /// matrix[i][j] represents the 2^ith parent of node j
    // 2^ith parent of node j =>  2^i-1 parent of node j, let's call this parent x
                    // => 2^i-1 parent of node x
    
    // 2^i = 2^(i-1) + 2^(i-1) = 2 * (2^(i-1)) = 2^i

    for(int i=1;i<=20;i++){
        for(int j=1;j<=N;j++){
            int tempNode = matrix[i-1][j];
            if(tempNode != -1)
                matrix[i][j] = matrix[i-1][tempNode];
        }
    }
}

int liftNode(int u, int k){
    int curr = u;
    for(int i=20;i>=0;i--){
        if(k&(1<<i)){
            curr = matrix[i][curr];
            if(curr == -1) return -1;
        }
    }
    return curr;
}

// compute the lca of nodoes u and v
int getLca(int u, int v){
    // we'll assume that depth[u] >= depth[v]
    if(depth[u] < depth[v]){        
        swap(u,v);
    }

    // lift u to bring it to the same level of v
    int new_u = liftNode(u, depth[u]-depth[v]);
    if(new_u == v) return v;

    int pow = log2(depth[v]);       // log2(val) returns the max power of 2, such that 2^pow <= val.
                                    // if val = 10, then pow = 3, since 2^3 is the max power <= 10

    // use pow>=0 condition inside while loop, instead of pow--;
    // ex: if pow = 3, pow>=0 will run for 3,2,1,0
    // but pow-- will run for 2,1,0
    while(pow >= 0){                                // IMPORTANT
        int n1 = liftNode(new_u,1<<pow);
        int n2 = liftNode(v, 1<<pow);
        if(n1 != n2){
            new_u = n1;
            v = n2;
        }
        pow--;
    }

    // new_u and v are now 1 exactly one step below the lca 
    // return liftNode(new_u,1);
    return matrix[0][new_u];                // directly access the parent, instead of making function call
}

// We dont need this function now. We'll use prefix sums technique to evaluate the dist[] which is more efficient

// traverse from root to dest and increase the value of each node by x
// bool dfs(int sv, int parent, int dest, int x){
//     if(sv == dest){
//         dist[sv] += x;
//         return true;
//     }
    
//     // loop through all child's of sv. if for any child,  solve(child) return true, then it means the dest node exits in that child's subtree and that node lies in the path from root to dest
//     bool val = false;
//     for(auto nb: adj[sv]){
//         if(nb != parent){
//             if(dfs(nb, sv, dest, x)) {
//                 val = true; break;
//             }
//         }
//     }


//     if(val) {       // dest node exists on this path 
//         dist[sv] += x;
//         return true;
//     }
//     else return false;  /// if the dest node does not exist 

// }





// evaluates prefix sum 
// dist[i] is sum of node' values in its subtree, including itself
int dfs2(int sv, int parent){
    for(auto nb: adj[sv]){
        if(nb != parent){
            dist[sv] += dfs2(nb, sv);
        }
    }
    return dist[sv];
}


signed main() {
    initcode();
    int n,q; cin>>n>>q;
    N = n;
    adj.resize(n+1);
    matrix.resize(21, vector<int>(n+1, -1));
    depth.resize(n+1,0);
    dist.resize(n+1,0);
    
    forn(i,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // matrix[0][max(u,v)] = min(u,v);                  // this is not right. Instead of assigning parent this way, assign the paretn in evalDepth function 
    }

    // All the below operations assume that 1 is the root of the tree


    evalDepth(1,-1);        // O(n) -- evaluates depth of each node and fills the 1st row of parent matrix
    binaryLifting();        // O(n) -- precomputes 2^ith parent of each node 

    dist.resize(n+1,0);     // stores the count of paths passing through each node

    // Overall TC earlier" O(q*n) 
    // updated optimised TC O(qlogn)
    while(q--){
        int u,v; cin>>u>>v;
        int lca = getLca(u,v);              // O(logn)
        // dfs(1,-1,u,+1);         // root to u +1     // O(n) per dfs call
        // dfs(1,-1,v,+1);         // root to v +1
        // dfs(1,-1,lca,-1);       // root to lca -1
        // int lca_parent = matrix[0][lca];    // root to lca_parrent -1           (if lca is root, then lca's parent doesn't exist. hence the check)
        // if(lca_parent != -1){
        //     dfs(1,-1,lca_parent,-1);
        // }
        
        // for each query O(n) overall
        
        
        // I can reduce its complexity using prefix sums
        dist[u] += 1;                       // O(1)
        dist[v] += 1;                       // O(1)
        dist[lca] -= 1;                     // O(1)
        if(matrix[0][lca] != -1){           // O(1)
            dist[matrix[0][lca]] -= 1;
        }

        // Now overall complexity per query O(logN) for finding lca, rest all operations are O(1)
        
        /* debug
        
        cout<<u<<" "<<v<<" lca "<<lca<<" lca parent "<<lca_parent<<endl;
        for(int i=1;i<=N;i++) cout<<dist[i]<<" ";
        cout<<endl;
        
        */
        
    }



    // compute prefix sum using dfs2();
    dfs2(1,-1); // sv, parent   

    fore(i,1,N) cout<<dist[i]<<" ";
    cout<<endl;

    // final tc: O(q*logn) + O(n)
    

    return 0;
    
}





// finding lca, binary lifting, prefix sums, evaluate depth 



