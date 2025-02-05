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

vector<vector<pii>> adj;
vector<int> dp, minFlights, maxFlights;
int N;

// returns the min cost from 1 to n
int djkstra(){
    vector<int> dist(N+1, 1e18);
    vector<bool> vis(N+1, false);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1}); // dist node;
    
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(!vis[u]){
            for(auto it: adj[u]){
                int v = it.first;
                int d = it.second;
                if(!vis[v] and dist[u] + d < dist[v]){
                    dist[v] = dist[u] + d;
                    pq.push({dist[v], v});
                }
            }
        }

        vis[u] = true;
    
    }

    return dist[N];

}

// returns the no of min price routes
int countPaths(int sv, int curr_cost, int &min_cost){
    if(curr_cost > min_cost) return 0;          
    if(sv == N){
        return curr_cost == min_cost;           // base case: when sv==N i.e dest and if curr_cost == min_cost return 1 else return 0
    }
    if(dp[sv] != -1) return dp[sv];             // if already computed, return dp[sv]

    int ans = 0;
    for(auto it: adj[sv]){
        int nb = it.first;
        int d = it.second;
        int val = countPaths(nb, curr_cost+d, min_cost);
        ans = (ans + val)%mod;
    }

    // if there are no paths then dp[sv] will be 0
    return dp[sv] = ans;

}

// returns the min no of flights in a min price route;
int countMinFlights(int sv){
    if(sv == N){
        return 0;
    }
    if(minFlights[sv] != -1) return minFlights[sv];

    int ans = 1e18;
    for(auto it: adj[sv]){
        int nb = it.first;
        int d = it.second;
        int val = countMinFlights(nb);
        ans = min(ans, val);
    }

    if(ans == 1e18) return minFlights[sv] = 0;
    else return minFlights[sv] = 1 + ans;
}

// returns the max no of flights in a min price route;
int countMaxFlights(int sv){
    if(sv == N){
        return 0;
    }
    if(maxFlights[sv] != -1) return maxFlights[sv];

    int ans = -1;
    for(auto it: adj[sv]){
        int nb = it.first;
        int d = it.second;
        int val = countMaxFlights(nb);
        ans = max(ans, val);
    }

    if(ans == -1) return maxFlights[sv] = 0;
    else return maxFlights[sv] = 1 + ans;
}

// We have to find following things in this problem:
// 1. Find the min cost path - Djkstra
// 2. Find the no of min cost path
// 3. Find the shortest & longest length of the min cost from src to dest

signed main() {
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    dp.resize(n+1,-1);
    minFlights.resize(n+1,-1);
    maxFlights.resize(n+1,-1);
    N = n;
    forn(i,m){
        int u,v,wt; cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }

    int min_cost = djkstra();

    int num_paths = countPaths(1, 0, min_cost);

    int mn = countMinFlights(1);
    int mx = countMaxFlights(1);

    cout<<min_cost<<" "<<num_paths<<" "<<mn<<" "<<mx<<endl;
  
}


