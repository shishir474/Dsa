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

vector<vector<pair<int,int>>> adj;

int N,M;

void take_input_graph(){
    int n,m; cin>>n>>m;
    N = n; M = m; // n vertices and M edges 
    adj.resize(n+1);
    forn(i,m){
        int u,v,wt; cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
}

// computes the shortest path from single source to all other nodes
void djkstra(int src = 1){
    vector<int> dist(N+1,INF);
    dist[src] = 0;

    // (dist,node) tuple in pq min heap 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // if the distance is outdated skip processing
        if(d > dist[u]) continue;  // ideally d should be <= dist[u]. If its not we can dicard that pair

        for(auto i: adj[u]){
            int v = i.first, edWt = i.second;
            if(d + edWt < dist[v]){
                dist[v] = d + edWt;
                pq.push({dist[v],v});
            }
        }
        
    }

    fore(i,1,N) cout<<dist[i]<<" ";
    cout<<endl;

}


signed main() {
    initcode();
    take_input_graph();
    djkstra();

    return 0;
    
}


No, the vis array is not strictly necessary in Dijkstra’s algorithm if you are using a priority queue (min-heap) and correctly implementing the relaxation condition. The dist[] array alone is enough to track the shortest distances.

Why vis[] is Not Needed?
	1.	Priority Queue Ensures Processing in Increasing Order of Distance
        •	In a min-heap-based Dijkstra, we always process the node with the smallest distance first.
        •	If a node u is popped from the priority queue, it means we have already found its shortest distance.
        •	If u is pushed into the queue again later with a greater distance, it will be ignored.
	2.	A Node May Appear Multiple Times in the Priority Queue, But We Ignore the Worse Ones
        •	If we process a node u, and later push it again into the queue due to another shorter path, then we only update dist[u].
        •	The older, longer paths for u will eventually get popped, but we ignore them since they don’t give a better answer.
	3.	Checking vis[u] Inside the Loop Can Be Redundant
        •	When a node u is popped from the queue, it may have already been updated with a shorter path.
        •	If u is already processed (vis[u] = true), we ignore it.
        •	However, we can achieve the same effect by checking dist[u] against d.

When is vis[] Useful?
	•	In other shortest path algorithms like BFS (unweighted graph) or Bellman-Ford, vis[] is useful because those algorithms do not guarantee processing in sorted order like a min-heap.
	•	If Dijkstra was implemented without a priority queue (using just a normal queue), then vis[] would be necessary to avoid redundant processing.

// Key Changes:
// 	1.	Removed vis[].
// 	2.	Added if (d > dist[u]) continue; to ignore outdated distance values.
// 	•	If u is pushed multiple times with different distances, we only process the smallest one.

// vis[] is NOT required in Dijkstra when using a priority queue.
// Using only dist[] is sufficient if we check if (d > dist[u]) continue; inside the loop.
// This reduces unnecessary memory usage and ensures better performance. 


1️⃣ Time Complexity Analysis
Dijkstra’s algorithm processes each node and edge efficiently using a priority queue (min-heap).

Breakdown of Operations
	1.	Pushing each node into the priority queue:
	•	Each node is pushed into the priority queue at most once per relaxation.
	•	Cost: O(log V) per push.
	2.	Extracting the minimum distance node from the priority queue:
	•	A node is popped at most once, since we process it only when we find its shortest distance.
	•	Cost: O(log V)
	3.	Relaxing edges of a node (for loop inside while):
	•	Each edge is processed at most once.
	•	Each relaxation results in a push operation into the priority queue.
	•	Cost: O(log V)

Total Complexity Calculation
	•	We process V nodes: O(V log V)
	•	We process each edge at most once, causing a push operation: O(E log V)

🔹 Final Time Complexity:

O((V + E) \log V) = O(E \log V)

(since a connected graph has at least E ≈ V - 1 edges, E dominates V).




2️⃣ Space Complexity Analysis

Dijkstra’s algorithm uses:
	1.	Graph Storage (adj list) → O(V + E)
	2.	Distance Array (dist[]) → O(V)
	3.	Priority Queue (pq) → Stores at most O(V) elements at any time → O(V)
	4.	Parent Array (parent[], if used) → O(V)

🔹 Final Space Complexity:

O(V + E)


🚀 Conclusion
	•	Dijkstra is highly efficient for sparse graphs (E ≈ V), making it near O(V log V).
	•	For dense graphs (E ≈ V²), it slows down to O(V² log V).
	•	Optimized version with a priority queue (min-heap) ensures better performance than naive O(V²) implementations.