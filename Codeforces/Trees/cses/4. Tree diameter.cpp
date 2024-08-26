You are given a tree consisting of n nodes.

The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.

Input

The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.

Then there are n−1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output

Print one integer: the diameter of the tree.



#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

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
void SieveOfEratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2;i*i<=n;i++){
        if (sieve[i]){
             // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

bool compare(pair<int,int>& p1, pair<int,int>& p2){
    if (p1.first == p2.first)
    return p1.second < p2.second;
    return p1.first < p2.first;
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool isPalindrome(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if (s[i]!=s[n-1-i]){
            return false;
        }
    }
    
    return true;
}

void printGraph(vector<vector<int> >& adj, int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
        int size = adj[i].size();
        for(int j=0;j<size;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){
        return false;
    }else{
        return true;
    }
}

// solve return max depth 
int solve(vector<int> adj[], int root,int parent, int& ans){
   
   int child=0;
   // get top 2 max depths
   int mx1=0, mx2=0;
   
   for(auto it: adj[root]){
       if(it!=parent){
           child++;
           int d = solve(adj,it,root,ans);
           if(d > mx1){
               mx2 = mx1;
               mx1 = d;
           }
           else if(d > mx2){
               mx2 = d;
           }
       }
   }
   
   if(child==0) return 1;
   
   // Here diameter means max distance between 2 nodes (can be leaf/nonleaf)
    ans = max(ans, mx1+mx2);
   
   return 1+max(mx1,mx2);
   
   
}
int32_t main()
{
	FIO;
	int n; cin>>n;
    vector<int> adj[n];
    forn(i,n-1){
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].pb(x);
    }
    
    int ans=0;
    
    solve(adj,0,-1,ans);
    
    cout<<ans<<endl;
    
}









// #include<bits/stdc++.h>
// using namespace std;

// #define int             long long int
// #define ff              first
// #define ss              second
// #define pb              push_back
// #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int> >
// #define setbits(x)      __builtin_popcountll(x)
// #define zrobits(x)      __builtin_ctzll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x; cin>>x; while(x--)
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define forn(i,n)      for(int i=0;i<n;++i)
// #define fore(i, l, r)   for(int i = l; i <= r; ++i)
// #define all(v)          v.begin(), v.end()

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// void initcode(){
//     FIO;
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif // ONLINE_JUDGE
// }
// void SieveOfEratosthenes(int n)
// {
//     vector<bool> sieve(n+1, true);
//     sieve[0] = sieve[1] = false;
//     for(int i=2;i*i<=n;i++){
//         if (sieve[i]){
//              // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
//             for(int j=i*i;j<=n;j+=i){
//                 sieve[j] = false;
//             }
//         }
//     }
// }
// int gcd(int a, int b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }
// int lcm(int a, int b) { return (a / gcd(a, b) * b); }
// bool isPowerOfTwo(int n)
// {
//     if (n == 0)
//         return false;
//     return (ceil(log2(n)) == floor(log2(n)));
// }

// bool compare(pair<int,int>& p1, pair<int,int>& p2){
//     if (p1.first == p2.first)
//     return p1.second < p2.second;
//     return p1.first < p2.first;
// }

// bool isPalindrome(string s){
//     int n = s.length();
//     for(int i=0;i<n/2;i++){
//         if (s[i]!=s[n-1-i]){
//             return false;
//         }
//     }
    
//     return true;
// }

// void printGraph(vector<vector<int> >& adj, int n){
//     for(int i=1;i<=n;i++){
//         cout<<i<<" ";
//         int size = adj[i].size();
//         for(int j=0;j<size;j++){
//             cout<<adj[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// bool checkUnsetBit(int n, int i){
//     if ((n&(1<<i)) != 0){
//         return false;
//     }else{
//         return true;
//     }
// }

// class hd{
// public:
//     int height, diameter;
// };

// vector<hd> dp(200003);

// void dfs(vector<int> adj[], int root, int parent){
//     cout<<root<<" "<<parent<<endl;

//     dp[root].height = 0;
//     dp[root].diameter = 0;

//     bool leaf=1;
//     for(auto it: adj[root]){
//         if(it!=parent){
//             leaf = 0;
//             dfs(adj,it,root);
//         }
//     }

//     if(leaf) return;

//     int mxh1=INT_MIN, mxh2 = INT_MIN;
//     for(auto it: adj[root]){
//         if(it!=parent){
//             int h = dp[it].height;
//             if(h > mxh1){
//                 mxh2 = mxh1;
//                 mxh1 = h;
//             }
//             else if(h > mxh2){
//                 mxh2 = h;
//             }
//             dp[root].diameter = max(dp[root].diameter, dp[it].diameter);
//         }
//     }

//     cout<<root<<"->"<<mxh1<<" "<<mxh2<<endl;
    
//     dp[root].height = 1+mxh1;

//     if(mxh1!=INT_MIN and mxh2!=INT_MIN){
//         dp[root].diameter = max(dp[root].diameter, 2+mxh1+mxh2);
//     }
//     else{
//         dp[root].diameter = max(dp[root].diameter, 1+mxh1); 
//     }



// }

// int32_t main()
// {
//     initcode();
//     int n; cin>>n;
//     cout<<n<<endl;

//     vector<int> adj[n];
    
//     // for(int i=0;i<200003;i++){
//     //     dp[i].height = 0;
//     //     dp[i].diameter = 0;
//     // }

//     for(int i=0;i<n-1;i++){
//         int x; int y; 
//         cin>>x;
//         cin>>y;

//         cout<<x<<" "<<y<<endl;
//         // adj[x].pb(y);
//         // adj[y].pb(x);
//     }
    
//     cout<<endl;

//     for(int i=0;i<n;i++){
//         cout<<i<<"->";
//         for(int j=0;j<adj[i].size();j++){
//             cout<<adj[i][j]<<" ";
//         }
//         cout<<"\n";
//     }


//     return 0;

//     dfs(adj,0,-1);
    
//     cout<<dp[0].diameter<<endl;
//     cout<<dp[0].height<<endl;

// }



































#include<bits/stdc++.h>
using namespace std;

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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
void SieveOfEratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2;i*i<=n;i++){
        if (sieve[i]){
             // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

bool compare(pair<int,int>& p1, pair<int,int>& p2){
    if (p1.first == p2.first)
    return p1.second < p2.second;
    return p1.first < p2.first;
}

bool isPalindrome(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if (s[i]!=s[n-1-i]){
            return false;
        }
    }
    
    return true;
}

void printGraph(vector<vector<int> >& adj, int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
        int size = adj[i].size();
        for(int j=0;j<size;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){
        return false;
    }else{
        return true;
    }
}

class hd{
public:
    int height, diameter;
};

vector<hd> dp(200003);

void dfs(vector<int> adj[], int root, int parent){
    dp[root].height = 0;
    dp[root].diameter = 0;

    bool leaf=1;
    for(auto it: adj[root]){
        if(it!=parent){
            leaf = 0;
            dfs(adj,it,root);
        }
    }

    if(leaf) return;

    int mxh1=INT_MIN, mxh2 = INT_MIN;
    for(auto it: adj[root]){
        if(it!=parent){
            int h = dp[it].height;
            if(h > mxh1){
                mxh2 = mxh1;
                mxh1 = h;
            }
            else if(h > mxh2){
                mxh2 = h;
            }
            dp[root].diameter = max(dp[root].diameter, dp[it].diameter);
        }
    }

    //cout<<root<<"->"<<mxh1<<" "<<mxh2<<endl;
    
    dp[root].height = 1+mxh1;

    if(mxh1!=INT_MIN and mxh2!=INT_MIN){
        dp[root].diameter = max(dp[root].diameter, 2+mxh1+mxh2);
    }
    else{
        dp[root].diameter = max(dp[root].diameter, 1+mxh1); 
    }



}

int32_t main()
{
    initcode();
    int n; cin>>n;
    
    vector<int> adj[n];
    forn(i,n-1){
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(adj,0,-1);
    
    cout<<dp[0].diameter<<endl;
    //cout<<dp[0].height<<endl;

}


