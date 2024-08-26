// Problem 189A — Cut Ribbon
// The problem is to maximize x+y+z subject to ax+by+cz=n. Constraints are low, so simply iterate over two variables (say x and y) and find the third variable (if any) from the second equation. Find the maximum over all feasible solutions.

// Other approaches: Use dynamic programming with each state being the remainder of ribbon. Select the next piece to be a, b or c. 

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

int t[4002];
int solve(int n, int a, int b, int c){
    if(n==0) return 0;
    if(n < min({a,b,c})) return -1;

    if(t[n]!=-2) return t[n];

    int o1=-1,o2=-1,o3=-1;
    if(n-a>=0){
        o1 = solve(n-a,a,b,c);
    }
    if(n-b>=0){
        o2 = solve(n-b,a,b,c);
    }
    if(n-c>=0){
        o3 = solve(n-c,a,b,c);
    }

// -1 indicates ans not possible .HEnce putting -1
    if(o1==o2 and o2==o3 and o1==-1) return t[n]= -1;

    return t[n] = 1+ max({o1,o2,o3});
}

int32_t main()
{
    initcode();
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    // BRUTE FORCE : o(n^2) accepted

    // int ans=0;
    // for(int x=0;x<=4000;x++){
    //     for(int y=0;y<=4000;y++){
    //         if((n-(a*x)-(b*y))%c == 0 and (n-(a*x)-(b*y)>=0)){
    //             int z = (n-(a*x)-(b*y))/c;
    //             ans = max(ans, x+y+z);
    //         }
    //     }
    // }
    
    //  cout<<ans<<endl;



// Here we have used -1 as a value in our dp array. Hence cannot initialise it with -1
    // memset(t,-1,sizeof(t));
    for(int i=0;i<4002;i++) t[i]=-2;
    cout<<solve(n,a,b,c)<<endl;

    return 0;
}



