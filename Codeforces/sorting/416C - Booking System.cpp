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

// bool compare(pair<int,int>& p1, pair<int,int>& p2){
//     int dist1 = abs(p1.first)+abs(p1.second);
//     int dist2 = abs(p2.first)+abs(p2.second);

//     return dist1 < dist2;
// }


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

struct table{
    int size, no;
    table(int s, int num){
        this->size = s;
        this->no = num;
    }
};
struct request{
    int size, sum, no;
    request(int s, int amt, int n){
        this->size = s;
        this->sum = amt;
        this->no = n;
    }
};

bool compare(request &p1, request& p2){
    if(p1.sum==p2.sum){
        return p1.size < p2.size;
    }
    return p1.sum > p2.sum;
}

bool cmp(table& p1, table& p2){
    return p1.size < p2.size;
}

int lower_bound(vector<table> &t, int num){
    int ans=-1;
    int lo=0,hi=t.size()-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(t[mid].size < num){
            lo = mid+1;
        }
        else{
            ans = mid;
            hi = mid-1;
        }
    }

    return ans;
}
int32_t main()
{   
    initcode();
    vector<table> t;
    vector<request> v;
    int n; cin>>n;
    // n request
    forn(i,n){
        int f,s; cin>>f>>s;
        v.pb(request(f,s,i+1));
    }
    int k; cin>>k;
    // k tables
    forn(i,k){
        int x; cin>>x;
        t.pb(table(x,i+1));
    }

    sort(v.begin(),v.end(), compare); //
    sort(t.begin(),t.end(),cmp); //

    int count=0,total=0;
    vector<pii> res;

// n request process
    forn(i,n){
        if(t.size() == 0) break; // when all tables are filled then t.size() will be 0 and then using this lower_bound function will give runtime error

//  execute lower_bound only if t.size() > 0
        int idx = lower_bound(t,v[i].size); //

        if(idx!=-1){
            count++;
            total+=v[i].sum;
            res.pb({v[i].no, t[idx].no});
            t.erase(t.begin()+idx);
        }
    }

    cout<<count<<" "<<total<<endl;
    forn(i,res.size()){
        cout<<res[i].first<<" "<<res[i].second<<"\n";
    }





    return 0;
        
}



