// https://codeforces.com/problemset/problem/1266/A


// 1266A - Competitive Programmer
// Thanks to Chinese remainder theorem, a number is divisible by 60
//  if and only if it is divisible by 3
//  and 20
// .

// A number is divisible by 3
//  if and only if the sum of its digits is divisible by 3
// . Note that as the sum doesn't change if we reorder digits, it applies also to the sum of digits of 𝑠
// .

// A number is divisible by 20
//  if it ends in 20
// , 40
// , 60
// , 80
//  or 00
// . Hence, it is necessary and sufficient if 𝑠
//  contains a 0
//  and then at least one additional even digit.

// Overall, there are three conditions to check:

// The digit sum is divisible by 3
// .
// There is at least a single 0
// .
// There are at least two even digits (including 0
// s).



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
        string s; cin>>s;
        bool even=false;
        int sum=0, zero=0;
        for(auto c: s){
            sum+=(c-'0');
            if(c=='0') zero++;
            else if((c-'0')%2 == 0) even=true;
        }
        if(sum%3 == 0){
            // check if it is divisible by 20
            if(zero>=2)cout<<"red"<<endl;
            else if(zero>=1 and even) cout<<"red"<<endl;
            else cout<<"cyan"<<endl;
        }
        else{
            cout<<"cyan"<<endl;
        }
       
   }
    
    

}