// 1538C - Number of Pairs


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
        int n,l,r; cin>>n>>l>>r;
        vector<int> a(n);

        forn(i,n) cin>>a[i];

        sort(all(a));

        int ans=0;

        forn(i,n){
            int i1 = lower_bound(a.begin(),a.end(),l-a[i]) - a.begin();
            int i2 = upper_bound(a.begin(),a.end(),r-a[i]) - a.begin() - 1;
            // determining no. of pairs we can form with a[i] as one element
 // 3 cases 
            // i<lb<up -> cas3
            if(i1 > i){
                ans+=(i2-i1+1);
            }// lb<up<i
            else if(i2<=i){ // no pairs possible
                continue; 
            }
            else{// lb<=i<ub
                i1 = i+1; // shift lb to i+1 to ignore counting the old pairs
                ans+=(i2-i1+1);
            }

        }

        cout<<ans<<endl;

    }
  

    return 0;
}




ex: n =5 , l=5 r=8;
5 1 2 4 3
        0 1 2 3 4
sort -> 1 2 3 4 5

i=0 -> i1 = lb(4) = 3, i2 = ub(7) = 4
       ans += 2 
i=1 ->  i1= 2, i2=4 ans+=3
i=2-> i1 = 1, i2=4 , i1 = 3, i2=4 -> ans+=2
i =3 -> i1=0, i2=3 ans+=0
i=4 -> i1=0, i2=2 ans+=0