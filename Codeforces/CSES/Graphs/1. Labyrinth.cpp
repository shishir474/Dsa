#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update>; // policy based data structure
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
void initcode(){
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
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

int modularBinaryExponentitation(int base, int exponent){
    if(exponent==0) return 1;
    int val = modularBinaryExponentitation(base, exponent/2);
    if(exponent%2)
        return ((val*val)%mod*base)%mod;
    else    
        return (val*val)%mod;
}

struct cmp{
    bool operator()(const pii& p1, const pii& p2){
        return p1.second < p2.second;  
    }
};

int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

// path string -> tracks current path
// ans string -> tracks the ans string
// void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &vis, string &path, string &ans){
//     int n= mat.size();
//     int m= mat[0].size();
//     // cout<<i<<" "<<j<<endl;

//     // base case
//     if(mat[i][j] == 'B'){
//         // if its the first path or curr path is better than the ans path: update the ans
//         if(ans.size() == 0 or path.size() < ans.size()){
//             ans = path;
//             // cout<<"ans updated "<<ans<<endl;
//         }
//         return;
//     } 

//     vis[i][j] = true;

//     for(int k=0;k<4;k++){
//         int newi= i+X[k], newj = j+Y[k];
//         if(newi>=0 and newi<n and newj>=0 and newj<m and (mat[newi][newj]=='.' or mat[newi][newj]=='B') and !vis[newi][newj]){
            
//             if(k==0) path.push_back('U');
//             else if(k==1) path.push_back('R');
//             else if(k==2) path.push_back('D');
//             else if(k==3) path.push_back('L');

//             dfs(newi,newj,mat,vis,path,ans);

//             path.pop_back();

//         }
//     }
    
//     vis[i][j] = false; 

// }

void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &vis, string &path, string &ans){

    // Implement the BFS solution


}

// Learnings: 

// The main question is why is the DFS solution not working: According to me the recursoin + backtracking approach should work 
// Print the shortest path from src to dest in matrix --> This is the problem

// THe only thing which I came across as a possible reason for using BFS is:
    // we can't use DFS here since we have to find the shortest path. In DFS we will have to explore all the possible paths and then find the min of them all which can cause TLE

// 2 solutions:
// Recursive one : DFS + backtracking which gives TLE and is not optimal
// Using BFS: Since we need to find the shortest path, using BFS makes more sense

signed main(){
    initcode();
    int n,m; cin>>n>>m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    int orig_x=-1, orig_y=-1;
    forn(i,n){
        forn(j,m){
            cin>>mat[i][j];
            if(mat[i][j] == 'A'){
                orig_x = i;
                orig_y = j;
            }
        }
    }

    string path = "",ans="";
    // dfs(orig_x,orig_y,mat,vis,path,ans); 
    bfs(orig_x,orig_y,mat,vis,path,ans)

    if(ans == "") cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
   
    

}

