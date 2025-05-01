// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>;  // policy based data structure
// // ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// // and set.order_by_key(k) -> returns the index of the key k
// // ordered set data structure => adds indexing functionality to sets

// #define int             long long int
// #define ff              first
// #define ss              second
// #define pb              push_back
// // #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int> >
// #define setbits(x)      __builtin_popcountll(x)
// #define zrobits(x)      __builtin_ctzll(x)
// #define mod             1000000007
// #define INF             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x; cin>>x; while(x--)
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define forn(i,n)      for(int i=0;i<n;++i)
// #define fore(i, l, r)   for(int i = l; i <= r; ++i)
// #define all(v)          v.begin(), v.end()

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// void initcode() {
// 	FIO;
// 	// #ifndef ONLINE_JUDGE
// 	// freopen("cpp/input.txt", "r", stdin);
// 	// freopen("cpp/output.txt", "w", stdout);
// 	// #endif // ONLINE_JUDGE
// }
// int gcd(int a, int b)
// {
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }
// int lcm(int a, int b) {
// 	return (a / gcd(a, b) * b);
// }
// int log_a_with_base_b(int a, int b){
//         return log2(a) / log2(b);
// }
// void print_graph(vector<vector<int>> adj){
// 	forn(i,adj.size()){
// 		cout<<i<<": ";
// 		forn(j,adj[i].size()){
// 			cout<<adj[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// }
// int modularBinaryExponentitation(int base, int exponent) {
// 	if(exponent==0) return 1;
// 	int val = modularBinaryExponentitation(base, exponent/2);
// 	if(exponent%2)
// 		return ((val*val)%mod*base)%mod;
// 	else
// 		return (val*val)%mod;
// }

// struct cmp {
// 	bool operator()(const pii& p1, const pii& p2) {
// 		return p1.second < p2.second;
// 	}
// };

// vector<vector<int>> mat, adj;
// vector<int> height;
// int N;

// void evallevel(){
//     // NOTE: There is a difference between height and level. Height indicates the depth of the subtree rooted at a particular node. 
//     // Height can also be interpreted as the depth of the node from the root
//     // Level is different. It is the distance of the nodes from the root, which is same as root
//     int sv = 1;
//     queue<pair<int,int>> q;
//     q.push({sv,-1}); // node, parent
//     height[sv] = 0;
//     while(!q.empty()){
//         int f = q.front().first;
//         int parent = q.front().second;
//         q.pop();
//         for(auto nb: adj[f]){
//             if(nb != parent){
//                 q.push({nb,f});
//                 height[nb] = 1+height[f];
//             }
//         }
//     }
    
// }

// void binaryLifting(){
//     // N+1 X 20 dimension matrix
//     mat.resize(N+1, vector<int>(20, -1));
//     adj.resize(N+1);
//     forn(i,N-1){
//         cin>>mat[i+2][0];
//         adj[i+2].push_back(mat[i+2][0]); // created adj list ---- we need this for height evaluation
//         adj[mat[i+2][0]].push_back(i+2);
//     }
//     for(int j=1;j<20;j++){
//         for(int i=1;i<=N;i++){
//             // mat[i][j] is 2^jth parent of i
//             // 2^jth parent of i = 2^(j-1)th parent of (2^(j-1)th parent of i)
//             int temp_node = mat[i][j-1];
//             if(temp_node != -1)
//                 mat[i][j] = mat[temp_node][j-1];
//         }
//     }

// }

// // this function leverages mat matrix which was populated using binaryLifting appraoch
// // returns kth parent of node x
// int liftNode(int x, int k){
    
//     // for(int i=1;i<=N;i++){
//     //     for(int j=0;j<=2;j++){
//     //         cout<<mat[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     int ans = x;
//     for(int i=19;i>=0;i--){
//         // if ith bit is set
//         if(k&(1<<i)){
//             ans = mat[ans][i];
//             if(ans == -1) return -1;
//         }
//     }
//     return ans;
// }

// // finding LCA using Binary Lifting and Binary Search -- O(log2n) solution 
// // very good intuitive solution , but gives TLE for 2 test cases on CSES
// // We need to implement O(logn) solution
// signed main() {
//     initcode();
//     int n, q; cin>>n>>q;
//     N = n;
//     height.resize(n+1,-1);

//     binaryLifting();
    
//     evallevel();
        
//     // print_graph(adj);
//     // fore(i,1,N) cout<<height[i]<<" ";
//     // cout<<endl;
    
//     while(q--){
//         int u,v; cin>>u>>v;
//         // we've to compute the lca of u and v;
//         // make sure v is closer to the root/lca - we'll judge based on their levels
//         if(height[u] < height[v]) swap(u,v);
//         // take jump of diff from u
//         int new_u = liftNode(u,hright[u]-height[v]);
//         // both new_u and v are at the same level
//         // apply binary search to find the lca: assume we need to take x jump from new_u and v. if we land on different vertices, then we need to take a larger jump
//         // else if we land on the same vertex, then that vertex could be our ans and we should try for a smaller jump
//         // min jump: 0, max_jump=level_v possibilities
//         // min jump 0 handles the case when u and v 

//         int lca = -1;
//         int lo = 0, hi = height[v];
//         while(lo<=hi){
//             int m = lo+(hi-lo)/2;
//             // take m step jump from both u and v
//             int a1 = liftNode(u,m);
//             int a2 = liftNode(v,m);
//             if(a1==a2){ 
//                 lca = a1; // this node could be our lca
//                 hi = m-1; // try reducing the length of the jump
//             }
//             else{ // we landed on a different vertex, would need to take a larger jump
//                 lo = m+1;
//             }
//         }

//         cout<<lca<<endl;


//     }
    
//     // cout<<liftNode(4,2)<<endl;

    
// }

// // complexity of the above solution is O(log^2n) i.e log square n (binary search is logn and then liftNode() is also logN) 

// // We want to determine x (smallest jump) such that we reach the lca node 



// // solution 2:
// // O(Logn) solution for finding LCA  -- CSES Accepted

//             R
        
//             L
//         Lu      Lv

//     u               v   -- u and v are now at the same level 
//     From u and v I would want to reach node Lu and Lv just below the lca. The reason I would like to do this is because, from L onwards all the nodes are same in the path from u to root and v to root
//     Lu and Lv are just 1 level down from L, and hence if we are able to make a jump of length x-1 and were able to reach Lu and Lv, our ans would be liftNode(Lu,1) i.e take jump of 1 from Lu and you will get the LCA
//     Binary Search logic to find x, is good it is log^2n becauase of liftNode operation during each iteration which is itself O(logn)
//     We know that any no can be written as powers of 2, which means x can also be represented sum of powers of 2 
//     assume x-1 = 2^10 + (remainder)
//     the remainder can also be expressed in sums of powers of 2 
//     SO the idea is Take a longest possible jump from U and V such that you land on nodes n1 and n2 and n1!=n2 
//     Repeat this process, and eventually you will land on Lu and Lv
//     Here , we are utilising the fact that the no can be written as sums of powers of 2(which basically helps us in finding Lu and Lv)



// /Users/shishir/Desktop/mac desktop/problem_solving/Dsa/Codeforces/CSES/Trees/7. CompanyQueries2.cpp



// Accepted Solution TC: O(logn)
// O(logn) for lifting and bringing the nodes u and v at the same level.
// and then using logic that if we are able to reach 1 step below the lca, then our job is done(now we just need to take 1 length jump to reach the lca)
// Whatever is the distance that we need to cover in order to reach the lca could be written as sums of powers of 2 
// In the absolute worst case, tha max length jump that the user might need to take is equivalent to level(v)
// assume the largest power of 2 such that 2^pow <= level(v) --> pow can be derived as log2(level(v)) 
// i.e take log with base 2 and you'll have the max pow of 2 that satisfies this condition
// assume level(v) is 10, so max power of 2 such that 2^pow<=10 is for pow = 3
// i.e we can take try taking jumps in 2^3=8, 2^2=4, 2^1=2 and 2^0 = 1
// we can take this 4 jumps(8,4,2,1)
// Start with the longest possible i.e 8. Take that jump and see if you land on different nodes. if yes update, shift/update your nodes new_u and v to n1 and n2(assuming you reached n1 and n2 while performing this jump)
// If you're reaching the same node after taking the jump, try performing lower length jump i.e 4
// Assume you're already at the desrired position(here in this case you wont be able to take any jump not even 1 length as well bcoz then you'll reach the lca)
// so you dont perform any jumps
// one thing is forsure, after this while loop, you will be 1 step lower from the LCA
// You can take 1 more step and that will cause you to reach the lca node



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

vector<vector<int>> mat, adj;
vector<int> height;
int N;

void evallevel(){
    // NOTE: There is a difference between height and level. Height indicates the depth of the subtree rooted at a particular node. 
    // Height can also be interpreted as the depth of the node from the root
    // Level is different. It is the distance of the nodes from the root, which is same as root
    int sv = 1;
    queue<pair<int,int>> q;
    q.push({sv,-1}); // node, parent
    height[sv] = 0;
    while(!q.empty()){
        int f = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto nb: adj[f]){
            if(nb != parent){
                q.push({nb,f});
                height[nb] = 1+height[f];
            }
        }
    }
    
}

void binaryLifting(){
    // N+1 X 20 dimension matrix
    mat.resize(N+1, vector<int>(20, -1));
    adj.resize(N+1);
    forn(i,N-1){
        cin>>mat[i+2][0];
        adj[i+2].push_back(mat[i+2][0]); // created adj list ---- we need this for height evaluation
        adj[mat[i+2][0]].push_back(i+2);
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=N;i++){
            // mat[i][j] is 2^jth parent of i
            // 2^jth parent of i = 2^(j-1)th parent of (2^(j-1)th parent of i)
            int temp_node = mat[i][j-1];
            if(temp_node != -1)
                mat[i][j] = mat[temp_node][j-1];
        }
    }

}

// this function leverages mat matrix which was populated using binaryLifting appraoch
// returns kth parent of node x
int liftNode(int x, int k){
    
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=2;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int ans = x;
    for(int i=19;i>=0;i--){
        // if ith bit is set
        if(k&(1<<i)){
            ans = mat[ans][i];
            if(ans == -1) return -1;
        }
    }
    return ans;
}

// finding LCA using Binary Lifting and Binary Search -- O(log2n) solution 
// very good intuitive solution , but gives TLE for 2 test cases on CSES
// We need to implement O(logn) solution
signed main() {
    initcode();
    int n, q; cin>>n>>q;
    N = n;
    height.resize(n+1,-1);

    binaryLifting();            // O(n)
    
    evallevel();                // O(n)
        
    // print_graph(adj);
    // fore(i,1,N) cout<<height[i]<<" ";
    // cout<<endl;
    
    while(q--){             // O(Qlogn) - O(logn) / query for finding lca(u,v)
        int u,v; cin>>u>>v;
        // we've to compute the lca of u and v;
        // make sure v is closer to the root/lca - we'll judge based on their levels
        if(height[u] < height[v]) swap(u,v);
        // take jump of diff from u
        int new_u = liftNode(u,height[u]-height[v]);
        // both new_u and v are at the same level

        // if v is the ancestor of u, then v is the lca, otherwise minimum of 1 and max level(v) jump is required to reach the lca(this was the range of binary search) 
        if(new_u == v){
            cout<<v<<endl; continue;
        }
        
        int level_v = height[v];

        int pow = log2(level_v); // pow is the largest power of 2 such that 2^pow <= level_v
        // for instance, level_v = 10, max possible jump in power of 2 will be 8, then 4, then 2, then 1 
        // take the max possible jump you can from u and v such that you land on different nodes
        while(pow >= 0){
            int n1 = liftNode(new_u,1<<pow);
            int n2 = liftNode(v, 1<<pow);
            if(n1 != n2){
                new_u = n1;
                v = n2;
            }
            pow--;
        }
        
        // With the above logic we reach x-1(1 level below lca), need 1 step more to reach the lca .
        cout<<liftNode(new_u,1)<<endl;
        

    }
    
    return 0;


    
}







