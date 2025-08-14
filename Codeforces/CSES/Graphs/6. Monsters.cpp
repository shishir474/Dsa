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

vector<vector<char>> mat;
vector<vector<int>> dist;
vector<vector<bool>> vis;

int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

int n, m; 

// NOTEs: 
// apart from basic conditions like the cell should be within matrix, should not contiain #, it must also satisfy condition curr_dist(d) + 1 < monster's distance from that cell(dist[newx][newy])
// Edge to consider: When no monsters are present, A will always be there 
// To check if there exists a path that ends at boundary, can also be implemented via bfs


// Here d + 1 < dist[newx][newy] condition was ensuring that
//  I always land on that cell which the monster hasn't visited yet + it was also working to track the cells that I have visisted till now in my path. 
// if d + 1 was greater than dist[newX][newY], then it means we have already vis that cell. But it fails in one condition where there are no monsters in the matrix and all the cells will contain inf.
// In this case we will get stuck in an infinite cycle of visiting already visited vertices 
// bool dfs(int x, int y, int d, string &s){
//     if(x==0 or x==n-1 or y==0 or y==m-1){
//         return true;
//     }

//     cout<<x<<" "<<y<<" "<<endl;

//     for(int k=0;k<4;k++){
//         int newx = x + X[k];
//         int newy= y + Y[k];
//         if(newx >=0 and newx<n and newy>=0 and newy < m and mat[newx][newy] != '#' and d + 1 < dist[newx][newy]){
//             if(k==0) s+= "U";
//             else if(k==1) s+="R";
//             else if(k==2) s+="D";
//             else if(k==3) s+="L";
//             if(dfs(newx, newy, d+1, s)) return true;
//             s.pop_back();
//         }   
//     }
    
//     return false;

// }


// Everything is same, just added vis[][] to track the visited cells. Marking vis[][] false while backtracking is important, becuae there might exist a path that leads to the boundary, but uses a part of the path that we just explored.
// Thus in order to handle those scenarios, we need to mark the cell unvisited while backtracking, in order to allow future paths to use those cells in its path
// call from main -- dfs(startR, startC, 0, s)  [starting cell, curr_dist, path string]

// When we are exploring all the possibitlies in a matrix, it is important to keep track of the cells we've vis in our curr path. What if the curr path reaches a dead end and we need to backtrack to explore other paths. 
// There might exist a path which is not explored yet but uses a part of the prev vis path and if we hadn't marked it unvisited while backtracking, we could've never got through that path 

bool dfs(int x, int y, int d, string &s){
    if(x==0 or x==n-1 or y==0 or y==m-1){
        return true;
    }
    vis[x][y] = true;

    for(int k=0;k<4;k++){
        int newx = x + X[k];
        int newy= y + Y[k];
        // cell should be within boundary of the matrix, should not contain # and should be reachable before Monster reaches there plus should 
        if(newx >=0 and newx<n and newy>=0 and newy < m and mat[newx][newy] != '#' and d + 1 < dist[newx][newy] and !vis[newx][newy]){
            if(k==0) s+= "U";
            else if(k==1) s+="R";
            else if(k==2) s+="D";
            else if(k==3) s+="L";
            if(dfs(newx, newy, d+1, s)) return true;
            s.pop_back();           // backtrack
        }   
    }
    
    vis[x][y] = false;      // backtrack
    return false;

}

// edge cases:
// 1. No monsters present

// You just have to determine if you can reach any boundary cell of the matrix

signed main() {
   initcode();
   int N,M; cin>>N>>M;
   n = N;
   m = M;
   mat.resize(n, vector<char>(m));
   dist.resize(n, vector<int>(m,INF));
   queue<pii> q;        // stores monsters initial position
   int startR = -1, startC = -1;
   forn(i,n){
    forn(j,m){      
        cin>>mat[i][j];         // ., #, M, A
        if(mat[i][j] == 'A'){
            startR = i; startC = j;
        }
        else if(mat[i][j] == 'M'){
            q.push({i,j});
            dist[i][j] = 0;
        }
    }
   }

    // Multi source BFS 
    // perform bfs to find the shortest dist of each cell from the monsters
   while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int newx = x + X[k];
            int newy= y + Y[k];
            if(newx >=0 and newx<n and newy>=0 and newy < m and mat[newx][newy] != '#' and dist[x][y] + 1 < dist[newx][newy]){
                dist[newx][newy] = dist[x][y] + 1;
                q.push({newx,newy});
            }   
        }
   }


//   forn(i,n){
//     forn(j,m){
//         cout<<dist[i][j]<<" ";
//     }
//     cout<<endl;
//   }

    vis.resize(n,vector<bool>(m,false));            // understanding why vis is required here is the heart of the problem 

    string s = "";
    // we just need to check if we can reach the boundary cells - run a dfs(you might reach a deadend so you'll need to backtrack as well.)
    if(dfs(startR, startC, 0, s)){      // starting cell, curr_dist, path string
        cout<<"YES"<<endl;
        cout<<s.length()<<endl;
        cout<<s<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

   
	return 0;
}






