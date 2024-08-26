//1500 rated

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
    return p1.second < p2.second;
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
    int n,q; cin>>n>>q;
    int a[n]; forn(i,n) cin>>a[i];
    int f[n+2];
    memset(f,0,sizeof(f));
    while(q--){
        int l,r; cin>>l>>r;
        f[l]++;
        f[r+1]--;
    }
    for(int i=2;i<n+2;i++){
        f[i]+=f[i-1];
    }
    sort(f,f+n+2,greater<int>()); // decreasing order sort freq array
    sort(a,a+n,greater<int>());
    int ans=0;
    forn(i,n) ans+=a[i]*f[i];
    cout<<ans<<endl;

    return 0;
}

// here we have to return the max sum of all queries. So we count the freq of each index and the index which has the max freq will be assigned max no. and so on. This will give us the max sum

// building freq f array was the main thing here :
// trick is if we want to increase all the indices from li to ri by 1, then do a[li]+=1 and a[ri+1]+=-1
//and then take the prefix sum of the array, you will get the desired result

