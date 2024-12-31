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

// // mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// void initcode(){
//     FIO;
//     #ifndef ONLINE_JUDGE
//     freopen("cpp/input.txt", "r", stdin);
//     freopen("cpp/output.txt", "w", stdout);
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

// int lps(string s){
//     cout<<s<<endl;
//     cout<<s.length()<<endl;
//     return 0;
// }

// bool checkPlus(string s){
//     for(auto c: s){
//         if(c=='+') return true;
//     }
//     return false;
// }
// int32_t main()
// {      

// 	initcode();
// 	int n; cin>>n;
//     int x = 0;
//     while(n--){
//         string s; cin>>s;
//         if(checkPlus(s)){
//             x+=1;
//         }else{
//             x-=1;
//         }
//     }
//     cout<<x<<endl;

// }


// n bulbs all initially are in the on state
// Lets take n=10, after all the operations, you will notice that only the state of perfect squares is changing
// Perfect squares have odd number of divisors
// The numbers that have even number of divisors, there state will be the same as the original state. Numbers with odd divisors like the perfect squares -> their state will change
// So the total no of bulbs that will be in the on state after all the operations would be n - no_of_perfect_squares[from 1 to n]
// no of perfect squares from 1 to n is sqrt(n)
// so n - sqrt(n) on bulbs

// n <  n1 < n2  
// x <=  y <= z => no of on bulbs
// This is monotonic so we can apply binary search



#include <bits/stdc++.h>
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

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("cpp/input.txt", "r", stdin);
    freopen("cpp/output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
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

void solve(string s, int idx, set<string> &ans){
    if(idx==s.length()-1){
        ans.insert(s);
        return;
    }
    
    for(int i=idx; i<s.length(); i++){
        swap(s[i], s[idx]);
        solve(s, idx+1, ans);
        swap(s[i], s[idx]);
    }
}

signed main(){
    string s; cin>>s;
    
    set<string> ans;
    solve(s,0,ans);
    
    cout<<ans.size()<<endl;
    for(auto s: ans) cout<<s<<endl;
    
    
}