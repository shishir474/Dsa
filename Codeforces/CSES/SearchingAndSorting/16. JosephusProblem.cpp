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

struct cmp{
    bool operator()(const pii& p1, const pii& p2){
        return p1.first < p2.first;  // Compare by first element
    }
};

// Solve function for Josephus problem 1
void solve(vector<int> &v){
    // forn(i,v.size()) cout<<v[i]<<" ";
    // cout<<endl;
    
    for(int i=1;i<v.size();i+=2)
        cout<<v[i]<<" ";
    
    if(v.size()==1){
        cout<<v[0];
        return;
    }
    
    vector<int> newv;
    if(v.size()%2 == 0){ // even size vector, 
        for(int i=0;i<v.size();i+=2) // add the remaining ones in the same fashion
            newv.pb(v[i]);
    }
    else{
        newv.pb(v[v.size()-1]); // last element is your starting point for the next round
        for(int i=0;i<v.size()-1;i+=2) // add rest of them in the same fashion
            newv.pb(v[i]);
    }
    
    solve(newv);
}

signed main(){
    initcode();
    int n; cin>>n;
    vector<int> v;
    forn(i,n) v.pb(i+1);

    solve(v);

    
}

// main part is figuring out the starting point of the circle
// We always print the even position values
// if n is even, the new vector for the next round(or I can say the subproblem would be) the survivors in the same order as in the original vector
// if n is odd, the last element of the prev, would be your starting point, and then add the rest of the survivors
