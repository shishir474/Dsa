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

struct edges{
    int f,s,wt;
    // edges(int _f,int _s, int _wt){
    //     f = _f;
    //     s = _s;
    //     wt = _wt;
    // }
};
struct node{
    int parent, rank;
};
vector<node> dsuf;

// returns absolute parent of u
// also applies path compression, meaning it directly connects all nodes in the path to their root, flattening the structure.
// The amortized time complexity of findPar is O(α(N)), where α(N) (inverse Ackermann function) grows very slowly and is nearly constant for practical values of N.
int find(int v){
    if(dsuf[v].parent==-1){
        return v;
    }
    return dsuf[v].parent = find(dsuf[v].parent);
}

// O(1) 
// The smaller tree is always merged under the larger tree, keeping the depth small.
// The total complexity of N union and find operations is O(N * α(N)), which is nearly O(N) in practice.
void union_op(int fromP, int toP){
    
  if (dsuf[fromP].rank > dsuf[toP].rank){
      dsuf[toP].parent=  fromP;
  } 
  else if(dsuf[fromP].rank < dsuf[toP].rank){
      dsuf[fromP].parent=  toP;
  }
  else{
       dsuf[fromP].parent=  toP;
       dsuf[toP].rank+=1;
  }
  
}


bool compare(edges a, edges b){
    return a.wt < b.wt;
}
int kruskal(edges edge_list[],int e, int v){
  vector<edges> output;
  dsuf.resize(v);
  for (int i=0;i<v;i++){
      dsuf[i].parent = -1;
      dsuf[i].rank = 0;
  }
  
  sort(edge_list, edge_list+e, compare);
  
  int count = 0;
  for (int i=0;i<e;i++){
      if (count==v-1) break;
      edges e = edge_list[i];
      int from = e.f, to = e.s, wt = e.wt;
      int fromP = find(from);
      int toP = find(to);
      if(fromP!=toP){
          count++;
          output.push_back(e);
          union_op(fromP, toP);
      }
  }
  
  if(count != v-1) return -1; 
    
  int ans = 0;
  for (int i=0;i<output.size();i++){
    ans += output[i].wt;
    // cout<<output[i].f<<" "<<output[i].s<<" "<<output[i].wt<<endl;
  } 

  return ans;
   
}

// We have a grpah with n nodes which is disconnected. In order to connect this graph, I need a min of n-1 edges.
// Each edge has certain cost associated with it. Sort the edges based on the weights.
// Before adding any edge(u,v), check if those vertices are already connected. This can be efficiently checked using disjoint sets(union and find functions). If the absolute parent of both nodes are same, then it means they are already connected.
// If they have different absolute parents, then this nodes are not connected yet. So we add this edge and update their absolute parents via union operation
// Both findAbsoluteParent(int node) and unionOperation(int absoluteParU, int absoluteParV) are amortised O(1). 
// amortised means - ...
// Actual complexity of both union() and find() functions is O(alpha(n)), α(n) is the inverse Ackermann function, which grows extremely slowly and is considered nearly constant for all practical input sizes.
// findAbsolutePar() flattens the tree structure which effectively makes the future find() opeartions much efficient.

signed main() {
	initcode();
    int v,e;
    cin>>v>>e;
    edges edge_list[e];
    for (int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges e;
        e.f = f;
        e.s = s;
        e.wt = w;
        edge_list[i] = e;
        
    }
    
    int ans = kruskal(edge_list,e,v);
    if(ans == -1) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
}

// Direct Kruskal's implementation - use union find algo 
// TIME COMPLEXITY: The time complexity of this Kruskal's algorithm implementation is:
// Sorting edges: O(E log E)
// Union-Find operations: Each union/find is O(α(V)), so for all edges: O(E * α(V)) (α(V) is nearly constant)
// Total time complexity:
// O(E log E + E * α(V))
// For practical purposes, this is usually written as O(E log E) since α(V) is very small.