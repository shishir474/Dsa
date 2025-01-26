// https://codeforces.com/problemset/problem/1195/A

#include <bits/stdc++.h>
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

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("cpp/input.txt", "r", stdin);
    freopen("cpp/output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

signed main(){
        int n,x; cin>>n>>x;
        mii mp;
        forn(i,n){
            int e; cin>>e;
            mp[e]++;
        }
        priority_queue<int> pq;
        for(auto it: mp){
            pq.push(it.second);
        }
        int quota = ceil(n/(2.0)), ans = 0;
        while(quota){
            int t = pq.top(); 
            pq.pop();
            
            if(t%2 == 0){
                if(t/2 <= quota){
                    ans+=t;
                    quota-=(t/2);
                }
                else{
                    ans = quota*2;
                    quota = 0;
                }
            }
            else{
                if(t == 1){ // edge case
                    quota--; ans++; continue;
                }
                if(t/2 <= quota){
                    ans+=(t/2)*2;
                    quota-=(t/2);
                    pq.push(t - (t/2)*2);
                }
                else{
                    ans = quota*2;
                    quota = 0;
                }
            }
        }
        
        cout<<ans<<endl;
        
    
    

}