

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
    int n,x; cin>>n>>x;
    vector<int> a(n);
    forn(i,n) cin>>a[i];
    sort(all(a));
    // 2 pointers one at low weight + one at heavy weight (low, heavy) combination will give us the most optimised count
    int i = 0;
    int j = n-1;
    int cnt = 0; // no of gondolas required
    while(i <= j){ // NOTE: Each gondola can only acoomodate 1 or 2 child at max.
        if(a[i]+a[j] <= x){ // if both can be accomodated, take both child i.e i++ and j-- and increase the cnt
            cnt++;
            i++; j--;
        }
        else{ // else take the heavier child and increase the cnt. 
        // It's always guaranteed that the child's weight is always <= x
            cnt++;
            j--;
        }
    }

    cout<<cnt<<endl;
}