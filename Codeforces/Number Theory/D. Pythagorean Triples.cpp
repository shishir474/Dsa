#include<bits/stdc++.h>
using namespace std;

#define int             long long int
#define endl            "\n"
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
#define forn(i,n)       for(int i=0;i<n;++i)
#define fore(i, l, r)   for(int i = l; i <= r; ++i)
#define all(v)          v.begin(), v.end()

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void initcode(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int gcd(int a, int b)
{ // Time Complexity: O(Log min(a, b)) Auxiliary Space: O(Log (min(a,b))
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


// solved just by brute force. Just consider valid range that can be taken
int32_t main()
{   
    initcode();
    // just solve 2 equations:
    // conclusions: a will be odd bcoz a^2 = 2*b + 1 which is an odd value. c = b+1.
    // b = (a^2 - 1)/2. clearly a cannot go beyond 1e5. to be more precise, since b<=n solving the abouve equation we get relation 
    // (a^2-1)/2 <= n ==> a^2 <= 2*n +1
    // Iterating over a, and do a+=2, start from a=3, bcoz a=3 is not valid clearly

    w(t){
        int n; cin>>n;
        int cnt=0;
        for(int a=3;a*a<=2*n+1;a+=2){
            int b = (a*a - 1)/2, c = b+1;
            if(a<=b and b<=c and c<=n)
                cnt++;
            else
                break;
        }
        cout<<cnt<<endl;

    }
}