#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define INF 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(i, n) for (int i = 0; i < n; ++i)
#define fore(i, l, r) for (int i = l; i <= r; ++i)
#define all(v) v.begin(), v.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode() {
    FIO;
}

// Comparator for the priority queue to prioritize cells with smaller distance
// struct cmp {
//     bool operator()(const cell &c1, const cell &c2) {
//         return c1.distance > c2.distance;
//     }
// };


vector<vector<int>> adj, dp;


int solve(int sv, int parent){

    // choice 1: dp[i][0] ith node is not part of any edge
    if(dp[sv][0] == -1){
        int ans = 0;
        for(auto nb: adj[sv]){
            if(nb!=parent){
                ans += solve(nb,sv);
            }
        }
        dp[sv][0] = ans;
    }
    

    if(dp[sv][1] == -1){
        // choice 2: dp[i][1] ith node is part of any 1 edge.It can be any edge 
        vector<int> temp, children;
        for(auto nb: adj[sv]){  // calculate the value of each children and save it in temp
            if(nb!=parent){
                children.push_back(nb);
                temp.push_back(solve(nb,sv));
            }
        }

        if(children.size() == 0){
            dp[sv][1] = 0;
        }
        else{
            // calc prefix and suffix sums
            vector<int> prefix(temp.size()), suffix(temp.size());
            prefix[0] = temp[0];
            for(int i=1;i<prefix.size();i++){
                prefix[i] = prefix[i-1] + temp[i];
            }
            suffix[temp.size()-1] = temp[temp.size()-1];
            for(int i=temp.size()-2; i>=0; i--){
                suffix[i] = temp[i] + suffix[i+1];
            }

            int ans2 = 0;
            for(int i=0;i<children.size();i++){
                int tans = 1;
                if(i > 0){
                    tans += prefix[i-1];
                }
                if(i < children.size()){
                    tans += suffix[i+1];
                }
                for(auto nb: adj[children[i]]){
                    if(nb != sv){
                        tans += solve(nb,children[i]);
                    }
                }
                ans2 = max(ans2, tans);
            }
            
            dp[sv][1] = ans2;
        }
        
    }

    return max(dp[sv][0], dp[sv][1]);

}


signed main() {
    initcode();
    int n; cin>>n;
    adj.resize(n+1);
    forn(i,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // n+1 X 2 
    dp.resize(n+1, vector<int>(2,-1));
    
    cout<<solve(1,-1)<<endl;

    cout<<max(dp[1][0], dp[1][1])<<endl;
    
    
    return 0;
}