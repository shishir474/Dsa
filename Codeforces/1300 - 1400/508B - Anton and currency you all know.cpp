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
    string s; cin>>s;
    int f=0, n=s.length();
    forn(i,n){
        if((s[i]-'0')%2 == 0){
            f=1; break;
        }
    }
    if(f==0){
        cout<<"-1"<<endl;
        return 0;   
    }
    // even present
    f=0; //swap with the first even smaller than the last odd(s[n-1])
    forn(i,n){
        if((s[i]-'0')%2 == 0){
            if(s[i]<s[n-1]){
                swap(s[i], s[n-1]);
                f=1;
                break;
            }   
        }
    }

    // if swapping didn't happen -> that the odd was smaller than all the even nos on its left, so its best to swap with the last even no
    if(f==0){
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2 == 0){
                swap(s[i], s[n-1]);
                break;
            }
        }
    }

    cout<<s<<endl;
}















