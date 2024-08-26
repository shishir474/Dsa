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
        string s; cin>>s;
        int n=s.length();
        // num1 and num0-> total number of 1's and 0's in the string 
        // done1 and done0-> number of 0's and 1's encoutered so far in the string
        int num0=0,num1=0;
        forn(i,n){
            if(s[i]=='1') num1++;
            else num0++;
        }


        int ans= min(num1,num0);
        int done0=0,done1=0;
        forn(i,n){
            if(s[i]=='0') done0++;
            else done1++;
            int a = done1 + num0-done0;
            int b = done0 + num1 - done1;
            ans = min({ans,a,b});
        }

        cout<<ans<<endl;
    }


    return 0;
}









