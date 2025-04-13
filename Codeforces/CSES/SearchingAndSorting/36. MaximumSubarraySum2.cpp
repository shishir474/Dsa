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
int modularBinaryExponentitation(int base, int exponent) { // compute (a^b)%mod efficiently using binary exponentiation
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


signed main() {
    initcode();
    int n,a,b; cin>>n>>a>>b;
    vector<int> arr(n+1),prefix(n+1,0);
    fore(i,1,n) cin>>arr[i]; // 1 based indexing
    
    // we'll be using 1 based indexing in prefix array, hence following the same convention in the input as well 
    fore(i,1,n){
        prefix[i]=  prefix[i-1] + arr[i];
    }

    set<pii> s; // (prefix_sum, index) -- since prefix_sum may not be unique, hence using set<pii>
    // s.rbegin() will give you the max value
    for(int i=a;i<=b;i++){
        s.insert({prefix[i],i});
    }
    int i=a, j=b+1, k=1, ans = -inf;
    while(k<=n-a+1){
        ans = max(ans, s.rbegin()->first - prefix[k-1]);
        s.erase({prefix[i],i});
        if(j <= n)
        s.insert({prefix[j],j});
        i++; j++; k++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}


// 8 1 2
// -1 3 -2 5 3 -5 2 2
//  0 -1 2 0 
// i=0
// j=
// sum = 3
// ans = 3

// Brute force
// for(int i=0;i<n;i++){
//     for(int len=a;len<=b;len++){
//             int sum = 0;
//             for(int j=i;j<min(n,i+len);j++){
//                 sum += arr[j];
//             }
//             if(sum > max_sum)
//                 max_sum = sum;
//     }
// }

// Outer loop runs n times 
// 2nd inner loop runs (b-a) times 
// 3rd inner loop runs len times 
// so when len=a, it runs a times 
// when len=a+1, it runs a+1 times and so on 

// a + (a+1) + (a+2) + .. + (b)
// (1->b) - (1 -> a)
// b(b+1)/2 - a(a+1)/2
// Overall TC : O(n * (b^/2 - a^2/2 + b/2 - a/2))
// since a,b valuew will varey, so we will have best and worst case complexities 
// best case: when a === b TC: O(n*a)
// worst case: when a=1, b=n TC: O(n^3)

// calculating sum of an interval  -> we can use prefix sums to efficiently compute this in O(1)

// for(int i=1;i<=n;i++){
//     for(int len=a;len<=b;len++){
//             int sum = prefix[i+len-1] - prefix[i-1];     // considerd 1 based indexing for prefix sums, to take care of edge case (i-1) 
//             if(sum > max_sum)
//                 max_sum = sum;
//     }
// }

// Overall Complexity: O(n * (b-a+1))
// in worst case: O(n^2)
// optimisation: comes from the fact that since we want to maximise sum, we effectively want to maximise prefix[i+len-1], since prefix[i-1] will be constant 





// a=3,b=5
//     -1 3 -2 5 3 -5 2 2
//   0 -1 2 0  5 8 3 5  7