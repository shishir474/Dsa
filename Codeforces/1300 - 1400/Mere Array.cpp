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
     int n; cin>>n;
     int a[n];
     forn(i,n) cin>>a[i];
     int mini= *min_element(a,a+n);

     // undivisible elements by mini will remain at their original postion. They should be arranged in nondecreasing order. Their position cannot be changed
     // divisible elemtns positons can be altered in any way we watn using swppaing with min elemnt 

     vector<int> v;
     forn(i,n){
        if(a[i]%mini == 0) {
            v.pb(a[i]);
            a[i]=-1;
        }     
    }

// divisible elemnents sorted
    sort(all(v));

// putting elemnetns back into the array
    int k=0;
    forn(i,n){
        if(a[i]==-1){
            a[i] = v[k++];
        }
    }

    // now check if the array is non decreasing 
    // NOTE: Complete array should follow non decreasing order
    int f=0;
    forn(i,n-1){
        if(a[i] > a[i+1]){
            f=1; break;
        }
    }

    if(f){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }




        
        
    }

    return 0;
}



