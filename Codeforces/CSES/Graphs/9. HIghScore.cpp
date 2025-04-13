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
#define mp              make_pair
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


// direct application of bellmann ford algo - since we're given -ve edge weights 
// In the question we have to find the max score, but bellmann gives us min score - so simply we negate the weights of all the edges and then find the min score
// If there exists a -ve edge wt cycle in the graph - we return -1
// else return -1*min_score
const int MAXN = 2502;
int N;
vector<int> adj[MAXN],adjR[MAXN];
vector<bool> vis(MAXN,false),visR(MAXN,false);


void dfs(int sv){
	vis[sv]=true;
	for(auto nb: adj[sv]){
		if(!vis[nb])
			dfs(nb);
	}
}
void dfsR(int sv){
	visR[sv]=true;
	for(auto nb: adjR[sv]){
		if(!visR[nb])
			dfsR(nb);
	}
}

// failing on 2 test cases: 42/44 passed
signed main() {
	initcode();
	int n,m;
	cin>>n>>m;
	N = n;
	vector<vector<int>> edges;
	forn(i,m){
		int u,v,wt; cin>>u>>v>>wt; // 1 directional edge
		adj[u].push_back(v);
		adjR[v].push_back(u);
		edges.push_back({u,v,-1*wt}); // since we need to find the max score, we store edge weight by negating it and then use bellman to find the shortest path from src to dest 
	}

	dfs(1); // covers all vertices that can be reached via 1
	dfsR(N); // covers all vertices that can be reached via N
	// dfsR --> will be performed over reversed graph

	// vis[v]==true and visR[v]==true
	// vis[v]== true means 1 to v path exists
	// and visR[v]==true means N to v path exists in the reversed graph, or v to N path exists in the original graph
	// Both this conditions true means 1 to v is connected and v to N is connected=> which eventually means 1 to N is connected via V

	// dist array stores the min dist of all nodes from the src i.e 1 
	vector<int> dist(n+1,INF);
	dist[1] = 0; // src is 1 and dest is n

	// relax all the edges N-1 times -> this will give you SSSP(single source shortest path) from the source to all the vertices;
	bool improvement = true;
	for(int i=0;i<n and improvement; i++){
		
		improvement = false;
		
		for(auto it: edges){
			
			int u = it[0], v = it[1], edWt = it[2];
			
			if(dist[u] + edWt < dist[v]){  // dist[u]!=INF -> dont add this condition
				dist[v] = dist[u] + edWt;
				improvement = true;

				// bfs(v) checks if you are able to visit the dest node N from v. If you can then it returns true else it returns false
				// we found a -ve wt cycle(essentially a +ve wt cycle in the original graph and the dist[v] will keep on increasing)
				// and if we are able to visit N from V then it means we could generate arbitrarily large value for N. hence printing -1  
				// Found negative wt cycle and if we can reach 1 to v and from v to N 
				// because at the end we have to check if we can reach from 1 to N, and it might  be possible that 1, V and N might not be reachable from each other
				// INstead of checking if their exists a path b/w 1 to v and v to N using bfs call, we can directly use vis arrays to get that ans
				if(i == n-1 and vis[v] and visR[v]){
					cout<<"-1"<<endl;
					return 0;
				}
			}
		}
	}


	// relaxing the edges one more time: if an edge is getting relaxed -> then it implies we have -ve weight cycle 
	// for(auto it: edges){
	// 	int u = it[0], v = it[1], edWt = it[2];
	// 	// if the dist is still getting updated, you have to check if we can reach nth node from v. If yes, then print -1
	// 	// if the bfs() returns true, it means we can reach N (the dest node) and there exists a poitive weight cycle in the graph, which means the dist for the dest will be arbitrarily large
	// 	if(dist[u]!=INF and dist[u] + edWt < dist[v] and bfs(v)){  // dist[u]!=INF not a neccessary condition, but it's good to add to ensure better code quality
	// 		cout<<"-1"<<endl;
	// 		return 0;
	// 	}
	// }

	// at the time of storing the edge weights, we multiplied it with -1 so that we can find the min score
	// and since the problem wants us to return the max score, again multiplying the result by -1
	cout<<-1*dist[n]<<endl;

}


// NOTES:
// 1. Bellman Ford gives you shortest path. It is another SSSP algo
// 2. In bellman Ford we try to relax all the edges N-1 times. Relaxing an edge means if dist[u] + edWt < dist[v] then update dist[v]
// TC: of this operation O(E*V)
// 3 after N-1 iterations, if there are no -ve edge wt cycles then relaxing the edges 1 more time should not cause any difference 
// 4. but if the dist array is still getting updated -> then it MEANS WE we have -ve edge wt cycle 
// In the question, we have been asked to find the maximum score from 1 to N, but bellman helps us compute minimal score
// So to compute the max score, I've negated the edge weights before relaxing them 
// if during the Nth iteration, an edge(u to v) is getting relaxed, and v is reachable from 1 and N is reachable from 1 
// Detecting a -ve edge wt cycle here means, the weights will keep on reducing as we try to relax them more, which means in the original graph, the dist will keep on increaseing and bound to infinity 
// and if this v leads to N and V is reachable from 1, then the dist to N will be infinite

// checking vis[v]==true and visR[v]==true is important, because there exist a situation where the graph contains a negative cycle and it doesn't involved N, then in that case dist for N will not be infinite 

// -ve weight cycle only causes problem if their exists a path b/w 1 to N and that cycle is part of this path  


