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

vector<vector<int>> edges;

// use bellmann ford to check if the -ve cycle exists in the graph

signed main() {
	initcode();
	int n,m;
	cin>>n>>m;
	vector<vector<pii>> adj(n+1); // [1..n] vertices
    forn(i,m){
        int u,v,wt;
        cin>>u>>v>>wt;
		edges.push_back({u,v,wt}); // it's a one way flight - i.e unidirectional edge
    }

	vector<int> dist(n+1, INF), parent(n+1, -1);
	dist[1] = 0;

	int ptr = -1;
	for(int i=0; i<n and ptr; i++){ // relax all the edges N-1 times
		ptr=  0;
		for(auto edge: edges){ 
			int u = edge[0], v = edge[1], wt = edge[2];
			if(dist[u] + wt < dist[v]){  // dont add dist[u] != INF condition --> fails on certain testcases 
				// if(dist[u]==INF) cout<<u<<" "<<dist[u]<<" "<<wt<<" "<<" "<<v<<" "<<dist[v]<<endl;
				dist[v] = dist[u] + wt;
				parent[v]= u;
				ptr = v;
			}
		}
	}

	// if ptr remains 0 in the nth iteration -> then we dont have a cycle
	if(!ptr){
		cout<<"NO"<<endl;
		return 0;
	}
	
	// go back N-1 times using the parent array to land a vertex that is leading to a cycle / not away from the cycle
	forn(i,n){
		ptr = parent[ptr];
	}

	vector<int> cycle;
	int start = ptr;
	do{
		cycle.push_back(start);
		start = parent[start];
	}
	while(start != ptr);

	cycle.push_back(start);
	reverse(all(cycle));
	
	// print the cycle
	cout<<"YES"<<endl;
	forn(i,cycle.size())
		cout<<cycle[i]<<" ";
	cout<<endl;

	

}




// What is wrong with below code?


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
	bool operator()(const vector<int> &v1, const vector<int> &v2) {
		return v1[2] < v2[2];
	}
};

const int MAXN = 200002;
int N;
vector<int> dist(MAXN,INF),parent(MAXN);
vector<vector<int>> edges;


signed main() {
    initcode();
    int n,m; cin>>n>>m;
    N = n;
    // cout<<"n "<<n<<"m "<<m<<endl;
    forn(i,m){
        int u,v,wt; cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    
    dist[1] = 0; // 1 is the src 
    fill(all(parent),-1);
    int start = -1;
    bool negativeCycleFound = false;
    bool improvement=true;
    
    // cout<<"all edges "<<edges.size()<<endl;
    // for(auto edge: edges){
    //     cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<endl;
    // }
    
    for(int i=0;i<n and improvement; i++){
        improvement = false;

        for(auto edge: edges){
        
            int u = edge[0], v = edge[1], wt = edge[2];
            // cout<<"processing edge "<<u<<" "<<v<<endl;
            // cout<<"before "<<dist[u]<<" "<<dist[v]<<endl;
            
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                parent[v] = u;
                improvement=true;

                if(i==n-1){ // if we are still able to relax an edge in the nth iteration, it means there exists a -ve weight cycle
                    start = u;
                    negativeCycleFound = true; break;
                }
            }
            // cout<<"after "<<dist[u]<<" "<<dist[v]<<endl;
        }
        
        // cout<<"after {i}th itertation:  "<<endl;
        // fore(i,1,n) cout<<dist[i]<<" ";
        // cout<<endl;
        if(negativeCycleFound) break;
    
    }
 
    // fore(i,1,n) cout<<i<<" "<<parent[i]<<endl;
    // cout<<endl;
    
    // cout<<"start "<<start<<endl;

    if(!negativeCycleFound) cout<<"NO"<<endl;
    else{
        vector<int> cycle;
        // will use the parent array to construct the cycle 
        int curr = start;
        do{
            // cout<<"curr "<<curr<<endl;
            cycle.push_back(curr);
            curr = parent[curr];
        }
        while(curr != start);
        cycle.push_back(start);
        reverse(all(cycle));

        cout<<"YES"<<endl;
        for(auto i: cycle) cout<<i<<" ";
        cout<<endl;
    }

    return 0;

}






