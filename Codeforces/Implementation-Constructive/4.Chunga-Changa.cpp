// https://codeforces.com/contest/1181/problem/A



// Concept:

// (x+y)/z == (x/z)+(y/z)

// This condition holds true not only for cases where xmodz is 0 or ymodz is 0 or both are true
// Its also true for cases where xmod and ymodz not equal to 0
// Integer division trucates the remainder part from both the terms, & they might end up equivalent to the LHS

// Hence x%z = 0 or y%z = 0 is not necessary here for this condition to be valid





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

signed main(){
    int x,y,z;
    cin>>x>>y>>z;
    
    cout<<x%z<<" "<<y%z<<endl;
    cout<<x/z<<" "<<y/z<<endl;

    // total number of coconuts bought willl always be (x+y)/z
    // Now the matter is about min amount of coins that needs to be exchanged
    if((x+y)/z == (x/z)+(y/z)){ // No need to exchange any coins, even though its possible that x and y are not perfectly divisible by z
        cout<<(x+y)/z<<" "<<"0"<<endl;
    }
    else{ // min value represents the min coins that needs to be transferred
        cout<<(x+y)/z<<" "<<min(z-(x%z), z-(y%z))<<endl;
    }
    
    
    

}