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
    return p1.second > p2.second;
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
    w(t){
        int n; cin>>n;
        int a[n+1]; // parent array
        map<int,int> mp;

        for(int i=2;i<=n;i++) {
            cin>>a[i];
            mp[a[i]]++;
        }
        // for(auto it: mp){
        //     cout<<it.first<<"->"<<it.second<<endl;
        // }
        // cout<<mp.size()<<endl;

// minimum time required to burn the tree;
        int ans= mp.size()+1;
        //cout<<ans<<endl;

        vector<int> v;
        vector<pii> t;
        for(auto it=mp.begin();it!=mp.end();it++){
            t.push_back({it->first, it->second});
        }

// decreasing order me sort krre hai
        sort(t.begin(),t.end(),compare);
        //forn(i,t.size())cout<<t[i].first<<" "<<t[i].second<<endl;

        bool f=0;
        forn(i,t.size()){
            if(i+1+t[i].second-1 > ans){
                f=1;
                v.pb(i+1+t[i].second-1 - ans);
            }
        }

// koi extra nodes nai bache. ALl burnt within the min time frame
        if(f==0){
            cout<<ans<<endl;
            continue;
        }

        // construct the freq array using the algo from v vector in O(N) time 
        int mx = *max_element(v.begin(),v.end());
        vector<int> freq(mx+1,0);
        forn(i,v.size()){
            int e = v[i];
            freq[0]++;
            freq[e]=-1;
        }
        // constructing the prefix array
        for(int i=1;i<=mx;i++){
            freq[i] = freq[i-1]+freq[i];
        }

        // forn(i,mx+1) cout<<freq[i]<<" ";
        // cout<<endl;

        int l=0,r=mx-1;
        while(freq[r]==0) r--;
        
        while(l<=r){
            if(l==r){
                ans++; break;
            }
            l++;
            freq[r]--;
            if(freq[r]==0) r--;
            ans++;
        }


        cout<<ans<<endl;

    
    }
      
    return 0;
}


