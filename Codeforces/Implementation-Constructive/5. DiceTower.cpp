// https://codeforces.com/problemset/problem/1266/B

// Good implementation : 
// We just have to check if a given integer falls within the range of numbers


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


bool isInInterval(int n) {
    // We know that the intervals start at 15 and end at 20 with a step of 14
    // for both the start and end values.
    // So, for a given n, find the corresponding interval index i.

    if (n < 15) return false; // n cannot be in any interval if it's smaller than 15.

    // Calculate the interval number based on n
    int i = (n - 15) / 14; // Index of the interval that n might fall into.

    // Calculate the start and end of this interval
    int start = 15 + 14 * i;
    int end = 20 + 14 * i;

    // Check if n lies in this interval
    return n >= start && n <= end;
}

signed main(){
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (isInInterval(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
    
    
    

}