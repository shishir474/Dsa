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
    // ans will be at max n/2
    initcode();
    int n; cin>>n;
    int a[n];
    forn(i,n) cin>>a[i];
    sort(a,a+n);

    vector<int> v(a+n/2, a+n);


    int c=0;
    for(int i=(n/2)-1 ; i>=0 ; i--){
        //cout<<2*a[i]<<" "<<v[v.size()-1]<<endl;
        if(2*a[i] <= v[v.size()-1]){
        c++; v.pop_back();
       }
    }

    cout<<n-c<<endl;


    
    return 0;
}


// atleast twice se bade hone chahiye-> second half of sorted array ka chance hi nai hai. ab baat ayegi first half me
// best case: first half ke sabhi elements map ho jayenge(think for both odd and even cases) at max n/2 hi map honge
// first half ke elemnets,  second half ke elements ke sath hi map honge, Unko within first half map nhi kr sakte
// map krte time ensure ki hum max element jo ki 2*a[i] se bada hai ussi se map kre. so that it will maximise the chances of mapping other numbers
// and once mapped that element cannot be used for mapping any other element, so usko erase krdo
// important test case : 2 2 4 9 ans will be 2