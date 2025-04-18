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


// Approach 1: using the fact that all the divisors of n are symmetrical around sqrt(n)
// TC: O(sqrt(x)), total TC for n queries : O(n*sqrt(x))
// int solve(int a){
//     int cnt = 0;
//     // using the fact that all the divisors of n are symmetrical around sqrt(n)
//     for(int i=1;i<=sqrt(a);i++){
//         if(a%i == 0){ // i and a/i
//             if(i==(a/i)) cnt++;
//             else cnt+=2;
//         }
//     }
//     return cnt;
// }

// Approach 2: Better than the previous approach
// TC: O(sqrt(x)), total TC for n queries : O(n*sqrt(x))
// int solve(int number){
//     // Generating prime factorisation of a, given that every no other than 1 can be written as product of primes
//     vector<int> powersOfPrimeFactors;
    
//     for(int i=2; i*i<=number; i++){
//         if(number%i == 0){
//             int power = 0;
//             while(number%i == 0){
//                 number/=i;
//                 power++;
//             }
//             powersOfPrimeFactors.push_back(power);
//         }
//     }
//     if(number != 1)
//         powersOfPrimeFactors.push_back(1);
    
//     // evaluating the total no of divisors of n
//     // assume n = p1^a1 X p2^a2 X p3^a3 
//     // then total count factors count = (a1+1) X (a2+1) X (a3+1)
//     int ans = 1;        // ans stores the total factors count
//     for(auto i: powersOfPrimeFactors){
//         ans = ans * (i+1);
//     }
//     return ans;
// }

// approach 3: You can use the same logic to solve sum of divisors or similar problems
vector<int> divisors_cnt;

void solve(){
    divisors_cnt.resize(1000003,0);
    int x = 1000000;
    for(int i=1;i<=x;i++){ // outer loop runs x times
        for(int j=i;j<=x;j+=i){ // inner loop runs logx times
            divisors_cnt[j]+=1;
        }
    }
    // Total time complexity: O(xlogx)
}

signed main() {
    initcode();
    int n; cin>>n;
    // n <= 1e5
    // x <= 1e6
    // approach1,2: O(n * sqrt(x))
    // appraoch3: O(xlogx) + O(n)
    
    // precompute the divisors_cnt 
    solve();
    
    while(n--){
        int x; cin>>x;
        // cout<<solve(x)<<endl;
        cout<<divisors_cnt[x]<<endl;
    }

}

// // precompute the no of divisors for all x's upto 1e6, then this way you will be able to answer each query in O(1)
// total time complexity in this case would be O(x) + O(n)

// 1   2   3   4   5   6   7   8   9   10
// 1   1   1   1   1   1   1   1   1   1
//     1       1       1       1       1
//         1           1           1
//             1               1 
