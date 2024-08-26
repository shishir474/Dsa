	// C - K-Complete Word
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

int32_t main()
{
    initcode();
    w(t){
        int n,k; cin>>n>>k;
        string s; cin>>s;

        cout<<s<<endl;
        
        int ans=0;

        for(int i=0;i<k/2;i++){
            int cnt[26] = {};
            for(int st=0;st+(k-1)<n;st+=k){
                int i1= st+i;
                int i2 = st+(k-1-i);
                cnt[s[i1]-'a']++;
                cnt[s[i2]-'a']++;
            }

            int req = 2*(n/k);
            int mx = *max_element(cnt,cnt+26);
            ans+=(req-mx);
        }

// if k odd
        if(k&1){
            // cnt array 26 size initialised with 0;
            int cnt[26]={};
            for(int i=k/2;i<n;i+=k){
                cnt[s[i]-'a']++;
            }

            int req = n/k;
            int mx = *max_element(cnt,cnt+26);
            ans+=(req-mx);
        }

        cout<<ans<<endl;
    }

    return 0;
}




