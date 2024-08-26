#include<bits/stdc++.h>
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
void SieveOfEratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2;i*i<=n;i++){
        if (sieve[i]){
             // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

bool compare(pair<int,int>& p1, pair<int,int>& p2){
    if(p1.first==p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

bool isPalindrome(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if (s[i]!=s[n-1-i]){
            return false;
        }
    }
    
    return true;
}

bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){
        return false;
    }else{
        return true;
    }
}

int32_t main()
{
    initcode();
    int a,b,c; cin>>a>>b>>c;
    
    int op1=0,op2=0,op3=0;

    op1 = a/3 + b/3 + c/3;

    if(min({a,b,c}) >= 1){
        int newa = a-1, newb = b-1, newc = c-1;
        op2 = 1 + newa/3 + newb/3 + newc/3;
    }

    if(min({a,b,c}) >= 2){
        int newa = a-2, newb = b-2, newc = c-2;
        op3 = 2 + newa/3 + newb/3 + newc/3;
    }

    cout<<max({op1,op2,op3});

    return 0;
}


// Solution
// 322B - Ciel and Flowers

// If there are no "mixing bouquet" then the answer will be r/3 + g/3 + b/3. One important observation is that: There always exist an optimal solution with less than 3 mixing bouquet.

// The proof is here: Once we get 3 mixing bouquet, we can change it to (1 red bouquet + 1 green bouquet + 1 blue bouquet)

// So we can try 0, 1, 2 mixing bouquet and make the remain 3 kind of bouquets use above greedy method. Output one with largest outcome.