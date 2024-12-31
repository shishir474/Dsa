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


int solve(vector<int> &count){
    for(int i=1000000; i>=1; i--){ /// i stands for possible values of gcd
        
        int multiples = 0;
        
        for(int j = i; j <= 1000000; j+=i){
            multiples+=count[j];
        }
        
        if(multiples >= 2) // if we got atleast 2 multiples, it means i is the greatest gcd
            return i;
    }
    
    return -1;
}
signed main(){
    int n; cin>>n;
    vector<int> count(1000001, 0); // count array - stores the freq of elements. Element can lie in the following range: 1 <= e <= 1e6
    
    forn(i,n){
        int e; cin>>e;
        count[e]++;
    }
    
    cout<<solve(count)<<endl;
}

// create an array of size [1,mx] assuming mx is the max element in the array
// Store the freq of each element
// Now iterate from mx to 1 and check if this i could be your gcd
// How a particular i could be your gcd. start from that i and move in steps of i till you are <= mx and count the total freq of elements 
// if this freq>=2 is atleast 2, then that i is your ans
// gcd(a,b) assuming a < b, will always be <= a