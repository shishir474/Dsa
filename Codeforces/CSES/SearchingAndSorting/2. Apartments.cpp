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

// Initially I was thinking of using Lowerbound to find the appropriate apartment, but after utilising that apartment, I also have to erase that value which will take O(n) time
// This will be TLE

// Hence came up with this 2 pointer approach
// signed main(){
//     int n,m,k; cin>>n>>m>>k;
//     vector<int> a(n), b(m);
//     forn(i,n) cin>>a[i];
//     forn(i,m) cin>>b[i];
//     sort(all(a));
//     sort(all(b));
    
//     int i = 0;
//     int j = 0;
//     int cnt = 0;
//     while(i < n){
//         while(j < m and b[j] < a[i]-k) 
//             j++;
//         if(abs(b[j]-a[i]) <= k){
//             cnt++;
//             i++;
//             j++;
//         }
//         else{
//             i++;
//         }

//     }

//     cout<<cnt<<endl;
    
// }



// using multisets: 17/19 passed:
// 2 WA
signed main(){
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(n), b(m);
    forn(i,n) cin>>a[i];
    forn(i,m) cin>>b[i];
    int cnt = 0;
    multiset<int> ms;
    for(auto it: b) ms.insert(it);
    for(auto it: a){
        auto it2 = ms.lower_bound(it-k); 
        if(it2 != ms.end() and *it2 <= it+k){
            cnt++;
            ms.erase(it2);  // O(logn)
        } 
    }

    cout<<cnt<<endl;
    
}