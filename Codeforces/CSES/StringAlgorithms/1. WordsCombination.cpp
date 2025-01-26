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

// first approach that came to my mind:
// O(2^n) exponential complexity
int solve(string s, unordered_set<string>& set){
    if(s.length() == 0){ // we found one way to break/partition hence returning 1
        return 1;
    }
    int ans = 0;
    for(int i=0;i<s.length();i++){
        if(set.count(s.substr(0,i+1))){ // checking the first i chars (i length prefix)
            ans = (ans + solve(s.substr(i+1),set))%mod;
        }
    }

    return ans;
}


signed main(){
    initcode();
    string s; cin>>s;
    int k; cin>>k;
    unordered_set<string> dict;
    int max_len=0;
    forn(i,k){
        string word; cin>>word;
        dict.insert(word);
        max_len = max(max_len, (int)word.size());
    }
    
    // exponential solution - TLE
    // cout<<solve(s, dict)<<endl;
    
    // O(n^2) solution -> TLE
    int n = s.length();
    vector<int> dp(n+1,0);
    dp[n] = 1;
    
    // max_len signifies the max legit length of the prefix 
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n and j-i+1 <= max_len; j++){
            // check if s[i..j] is in the set
            if(dict.count(s.substr(i, j-i+1))){
                dp[i] = (dp[i] + dp[j+1])%mod;
            }
        }
    }

    cout<<dp[0]<<endl;



    
    
    
}