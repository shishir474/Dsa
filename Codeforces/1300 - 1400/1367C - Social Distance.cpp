
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
 
int calculate(int n, int k){
    if(n<=0) return 0;
    return ceil((n*1.0)/(k+1));
}

int32_t main()
{
    initcode();
    w(t){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        vector<int> v;
        forn(i,n){
            if(s[i]=='1'){
                v.pb(i);
            }
        }

        if(v.size()==0){
            cout<<calculate(n,k)<<endl;
        }
        else if(v.size()==1){
            int i = v[0];
            int left = (i-(k+1)) >= 0 ? calculate(i-k,k) : 0;
            int right = (i+k+1)<=n-1 ? calculate(n-i-k-1, k) : 0;
            cout<<left+right<<endl;
        }
        else{
            int ans=0;  
            int i = v[0];
            int left = (i-(k+1)) >= 0 ? calculate(i-k,k) : 0;

            i = v[v.size()-1];
            int right = (i+k+1)<=n-1 ? calculate(n-i-k-1, k) : 0;

            ans+=left+right;

            for(int i=0;i<v.size()-1;i++){
                int l = v[i], r=v[i+1];
                int sz = r-l-(2*k)-1;  // l+k+1 -> r-(k+1)
                if(sz > 0){
                    ans+=calculate(sz, k);
                }
            }

            cout<<ans<<endl;
        }
        
        
    }

    return 0;
}


// solution 
3 cases 
case 1: if count of 1s  = 0
divide the string into blocks of (k+1) size, n=6, k=1
take ceil value. consider case n=7, k=1

case 2: if count of 1s = 1
let i be the index where 1 is present -> we have to count no . of zeroes from [0,i-(k+1)] and [i+k+1, n-1];

case 3: if count of 1s > 1
consider every consecutive pairs of 1s and determine no. of zeroes that can be coverted between this 2 pair of 1s
+no. of zeroes on left size of first 1 that can be tranformed + no. of zeroes on right side of last 1 that can be transformed 