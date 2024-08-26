
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


// returns count Of pairs (a[i],a[j]) with sum>0
int countPairs(vector<int>& arr){
    int ans=0;
    int i=0,j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j] > 0){
            ans+=(j-i);
            j--;
        }
        else{
            i++;
        }
    }

    return ans;
}

int32_t main()
{
    initcode();
  int n; cin>>n;
  vector<int> a(n), b(n), arr(n);
  forn(i,n) cin>>a[i];
  forn(i,n) cin>>b[i];

  forn(i,n)arr[i] = a[i]-b[i];  

  sort(all(arr));

  cout<<countPairs(arr)<<endl;

    return 0;
}

Solution:
 a[i] -> given array
 b[i] -> given array
 arr[i] = a[i] - b[i]

 ai+aj>bi+bj -> given inequality
Let's rewrite the inequality from ai+aj>bi+bj to (ai−bi)+(aj−bj)>0. 
Now we just need to count no. of pairs(i,j) s.t  arr[i]+arr[j] > 0
