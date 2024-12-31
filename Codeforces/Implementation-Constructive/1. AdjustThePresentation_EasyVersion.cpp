// https://codeforces.com/contest/2021/problem/C1

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
    w(t){
        int n,m,q1; cin>>n>>m>>q1;
        int a[n], b[m];
        forn(i,n) cin>>a[i];
        forn(i,m) cin>>b[i];
        set<int> s;
        queue<int> q;
        forn(i,m){
            if(!s.count(b[i])){
              q.push(b[i]);
              s.insert(b[i]);  
            }
        }
        
        int i=0;
        bool not_possible = false;
        while(!q.empty()){
            int val = q.front(); q.pop();
            if(val != a[i]){
                not_possible = true; break;
            }
            i++;
        }
        
        if(not_possible){
            cout<<"TIDAK"<<endl;
        }
        else{
            cout<<"YA"<<endl;
        }
        
        // you have to just check the order of the elements in both the arrays
        // Extract all the unique elements from b and check if they are present in the same order as a
        
        
    }
    

}