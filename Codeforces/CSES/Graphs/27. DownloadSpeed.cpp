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


vector<vector<int>> adj;
vector<int> parent;
vector<vector<int>> capacity;

// returns the min flow of the augmenting path if possible 
// else returns 0;
int bfs(int s, int t){
    // reinitialise the parent array:
    //  parent -1 indicates that the vertex is not visited yet and parent -2 indicates that the vertex has no parent i.e it is a source vertex
    fill(all(parent),-1);
    parent[s] = -2;

    queue<pair<int,int>> q; // (vertex,flow) here flow is the min curr flow found on this path till now
    q.push({s,INF});   
    
    while(!q.empty()){
        int cur = q.front().first;  // curr vertex
        int flow = q.front().second;  // min flow that we have obtained till now on this path
        q.pop();

        for(auto next: adj[cur]){ // check nb's
            // if nb is not visited and capacity[curr][nb] > 0
            if(parent[next]==-1 and capacity[cur][next]){
                // set the parent
                parent[next] = cur;
                // update the flow by taking the min
                int new_flow = min(flow, capacity[cur][next]);
                if(next == t)
                    return new_flow;
                // push the nb,new_flow into the queue
                q.push({next,new_flow});
            }
        }
    }

    return 0;

}

// computes the max flow between the src and dest vertex
int max_flow(int s, int t){
    int flow = 0;
    int new_flow;

    // until no more augmenting paths are available 
    while(new_flow = bfs(s,t)){ 
        flow += new_flow;
        // update the capacity 
        int cur = t;
        while(cur != s){
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

// Intuition Behind the Max Flow Algorithm
// 	•	The algorithm finds augmented paths from the source to the sink.
// 	•	It pushes as much flow as possible through these paths while respecting capacity limits.
// 	•	It keeps adjusting the residual capacities and iterates until no more flow can be pushed.

// we will be primarily focussing on the shortest paths from src to dest, and in that path we are mainly concerned with the min weight which will be the bottleneck for that path
// so we'll start a bfs from starting vertex i.e src and will keep track of the min weightflow that we encoutered till that point. Initially it's gonna be inf
// (node, currMinFlow)
// while exploring neigbhours of node, compute the new minFlow which will be min(currMinFlow, edgeWeight), update the parent of the node and push the new pair in queue
// only those neighbours which are not visited yet and have some residual capacity ie. capacity[node][nb] > 0
// edgeWeight = capacity[node][nb]
// if you reach dest, return the minFlow that you found till that point. YOU have found one augmenting path. We'll keep on repeating the above steps until we no new augmenting paths are found
// add the flow of the augmenting path to the final maxFlowRes. Update the capacity of each edge that was covered in this path.
// Here we need parent[] to backtrack from dest to src and get the path

signed main() {
    initcode();
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    parent.resize(n+1);
    capacity.assign(n+1, vector<int>(n+1,0));

    forn(i,m){
        int u,v,cap; cin>>u>>v>>cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v]+=cap;
    }

    cout<<max_flow(1,n)<<endl;

    
    
}
