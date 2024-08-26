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
#define forn(i,n)      for(int i=0;i<n;++i)
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
vector<bool> SieveOfEratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2;i<=sqrt(n);i++){
        if (sieve[i]){
             // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }
    return sieve;
}
int gcd(int a, int b)
{ // Time Complexity: O(Log min(a, b)) Auxiliary Space: O(Log (min(a,b))
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
    return p1.first > p2.first;
    // if (p1.first == p2.first)
    // return p1.second < p2.second;
    // return p1.first < p2.first;
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
void printGraph(vector<vector<int> >& adj, int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
        int size = adj[i].size();
        for(int j=0;j<size;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){// bit is set
        return false;
    }else{
        return true;
    }
}

vector<int> adj[3000];
vector<bool> vis(2600, false);

// cycle detection
bool dfs(int sv, int par){
    vis[sv]=true;
    for(int nb: adj[sv]){
        if(!vis[nb]){
            if(dfs(nb,sv)) return true;
        }
        else if(vis[nb]==true and nb!=par) return true;
    }

    return false;
}

class Geeks{
public:
    int id;
    Geeks(){
        cout<<"default constructor called"<<endl;   
        id=-1;
    }
    Geeks(int id){
        cout<<"constructor called"<<endl;
        this->id = id;
    }
};

// find all primes between l and r
void segmented_sieve(int l, int r){
    int sz = sqrt(r)+2;
    vector<bool> ans(r-l+1,true);
    // sieve logic: Go from 2 to sqrt(n) and mark all multiples of primes as false.
    // since r can go upto 1e10 we cannot use normal sieve(cannot create an array of that much size). but r-l <= 1e6. so surely we can create array of that size. 
    // first get all primes between 2 to sqrt(r) inclusive. then mark alll its amultiples b/w l and r as false. Whatever is left true in ans is prime.----> Segmented sieve (operating over a segment) 
    vector<bool> primes = SieveOfEratosthenes(sz);

    for(int i=2;i*i<=r;i++){
        if(primes[i]){
            // smallest multiple of i in range l to r inclusive. m is the smallest multiple of p in [l to r], we need to get its indes which is m-l
            int m = (l%i == 0) ? l : l + i - (l%i);
            // cout<<i<<" "<<m<<endl;
            for(int j=m-l;j<=ans.size();j+=i){
                ans[j]=false;
            }
        }
    }
    // this works fine until l > sqrt(r). If l is <=sqrt(r), then we need to correct ans for the range l to sqrt(r). whose correct ans is already computed in primes array, so just copy the value from there.
    if(l <= sqrt(r)){
        for(int i=l;i<=sqrt(r);i++){
            ans[i-l]=primes[i];    
        }
    }
    // cout<<"printint ans"<<endl;
    for(int i=0;i<ans.size();i++){
        if(ans[i]) cout<<l+i<<endl; // l+i is a prime number
    }

}


int32_t main()
{
    initcode();
    w(t){
        int l,r; cin>>l>>r;
        segmented_sieve(l,r);
        cout<<endl;
    }

}









