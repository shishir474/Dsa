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

int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

bool dfs(int i, int j, int timer, vector<vector<char>> &mat, vector<vector<bool>> &vis, vector<char> &path, vector<vector<int>> &time){
    int n = mat.size(), m = mat[0].size();
    
    vis[i][j] = true;
    
    if(i==0 or i==n-1 or j==0 or j==m-1) { // reached the boundary cell
		return true;
	}
			
    for(int k=0; k<4; k++) {
		int newi = i+X[k], newj = j+Y[k];
		// we will land at the new cell at time timer+1, hence checking if timer+1 < time[newi][newj]
		if(newi>=0 and newi<n and newj>=0 and newj<m and mat[newi][newj]!='#' and !vis[newi][newj] and timer + 1 < time[newi][newj]) {
			if(k==0) path.push_back('U');
			else if(k==1) path.push_back('R');
			else if(k==2) path.push_back('D');
			else path.push_back('L');

			if(dfs(newi, newj, timer+1, mat, vis, path, time)) return true;
        
		}

	}
	
	path.pop_back();
	return false;

}



signed main() {
	initcode();
	int n,m;
	cin>>n>>m;
	vector<vector<char>> mat(n, vector<char>(m)); // 1 to n vertices

	int sx = -1, sy = -1; // starting x and starting y

	vector<vector<int>> time(n,vector<int>(m,INT_MAX));
	queue<pii> q;

	forn(i,n) {
		forn(j,m) {
			cin>>mat[i][j];
			if(mat[i][j] == 'A') {
				sx = i;    // ths is my starting point
				sy = j;
			}
			else if(mat[i][j] == 'M') {
				time[i][j] = 0;
				q.push({i,j});
			}
		}
	}

	// monsters bfs to track the min time a monster takes to reach a certain cell
	while(!q.empty()) {
		int i= q.front().first;
		int j = q.front().second;
		q.pop();

		for(int k=0; k<4; k++) {
			int newi = i+X[k], newj = j+Y[k];
			if(newi>=0 and newi<n and newj>=0 and newj<m and mat[newi][newj]!='#' and time[i][j] + 1 < time[newi][newj]) {
				time[newi][newj] = 1 + time[i][j];
				q.push({newi,newj});
			}
		}

	}
	
// 	forn(i,n){
// 	    forn(j,m){
// 	        cout<<time[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}


	// BFS of A: A cannot visit a cell marked '#' + plus cell which has time 0 for monster
	// we cannot use bfs to construct the path -> Hence will have to go with DFS
	int timer = 0;

    vector<char> path;
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    
	bool ans = dfs(sx,sy,timer,mat,vis,path,time);

	if(ans) {
		cout<<"YES"<<endl;
		cout<<path.size()<<endl;
		forn(i,path.size()) cout<<path[i];
		cout<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}



}

