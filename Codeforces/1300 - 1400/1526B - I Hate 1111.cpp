
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
      int n; cin>>n;
      int f=0;
      while(n>0){
        if((n%11) == 0 || (n%111)==0){
            f=1; break;
        }
        n-=111;
      }

      if(f==1){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }


    }
  

    return 0;
}



SOlution
Notice that 1111=11⋅100+11 and similarly 11111=111⋅100+11. 
This implies that we can construct 1111 and all bigger numbers using only 11 and 111. So it suffices to check whether we can 
construct X from 11 and 111 only.

Suppose X=A⋅11+B⋅111, where A,B≥0. 
// https://www.youtube.com/watch?v=DOF6cF7i_Lw