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
    int n; cin>>n;
    vector<pii> v;
    if(n%4 == 0){
      v.pb({n/4, 0});
    }
    if(n%7 == 0){
        v.pb({0,n/7});
    }

    for(int b=1;7*b<=n;b++){
        if((n-(7*b))%4 == 0){
            int a = (n-(7*b))/4;
            v.pb({a,b});
        }
    }

    if(v.size()==0){
        cout<<"-1"<<endl;
    }
    else{
        // pick those pairs that have min sum 
        int mn=INT_MAX;
        forn(i,v.size()){
            mn = min(mn, v[i].first+v[i].second);
        }

        // Now among all those min sum pairs, choose that one which has max no. of 4s in it
        int a=0;
        forn(i,v.size()){
            if(v[i].first+v[i].second == mn){
                a = max(a, v[i].first);
            }
        }

// no of 7s will be 
        int b = mn - a;
        forn(i,a)cout<<"4";
        forn(i,b)cout<<"7";
        cout<<endl;

    }

    return 0;
}
