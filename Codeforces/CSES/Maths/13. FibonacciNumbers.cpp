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
int modinv(int b, int c){
    return modularBinaryExponentitation(b, c-2);
}

struct Matrix{
    int m[2][2];
};


Matrix matrixMultiplication(Matrix A, Matrix B){
    Matrix res;
    res.m[0][0] = ((A.m[0][0]*B.m[0][0])%mod + (A.m[0][1]*B.m[1][0])%mod)%mod;
    res.m[0][1] = ((A.m[0][0]*B.m[0][1])%mod + (A.m[0][1]*B.m[1][1])%mod)%mod;
    res.m[1][0] = ((A.m[1][0]*B.m[0][0])%mod + (A.m[1][1]*B.m[1][0])%mod)%mod;
    res.m[1][1] = ((A.m[1][0]*B.m[0][1])%mod + (A.m[1][1]*B.m[1][1])%mod)%mod; 
    return res;
}

Matrix matrixExponentiation(Matrix base, int pow){
    if(pow == 0) {  // return Identity Matrix
        Matrix I;
        I.m[0][0] = 1; I.m[0][1] = 0;
        I.m[1][0] = 0; I.m[1][1] = 1;
        return I;
    }
    Matrix temp = matrixExponentiation(base,pow/2);
    if(pow%2)
        return matrixMultiplication(matrixMultiplication(temp,temp),base);
    else    
        return matrixMultiplication(temp,temp);
}   


int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    Matrix base;
    base.m[0][0] = 1;
    base.m[0][1] = 1;
    base.m[1][0] = 1;
    base.m[1][1] = 0;

    Matrix res = matrixExponentiation(base,n-1);
    return res.m[0][0];

}

signed main() {
    initcode();
    int n; cin>>n;
    cout<<fib(n)<<endl;

    return 0;
}



