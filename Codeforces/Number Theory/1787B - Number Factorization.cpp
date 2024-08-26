// GET PRIME FACTORS OF N and its freq. 

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
#define forn(i,n)       for(int i=0;i<n;++i)
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
        
        queue<pii> q1,q2;
// get prime factors of n and its freq: TC: O(sqrt(n)) n-> 1e9 so will work fine
        fo(rint i=2;i<=sqrt(n);i++){
            if(n%i == 0){
                int cnt=0;
                while(n%i == 0){
                    n/=i;
                    cnt++;
                }
                q1.push({i,cnt});
            }
        } 
        if(n > 1){
            q1.push({n,1});
        }


        int ans=0;

        while(true){
            int val=1;
            while(!q1.empty()){
                pii f = q1.front();
                q1.pop();
                val*=f.first;
                if(f.second > 1){
                    q2.push({f.first, f.second-1});
                }
            }
            ans+=val;
            if(q2.empty()) break; // if q2 is empty => no factors left, so break
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }       
        }
     
        cout<<ans<<endl;


    }
}