// 1700 rated 
// https://www.youtube.com/watch?v=2IMvyqpZz6I

#include<bits/stdc++.h>
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
#define mod             100000000
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
void SieveOfEratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2;i*i<=n;i++){
        if (sieve[i]){
             // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

bool compare(pair<int,int>& p1, pair<int,int>& p2){
    return p1.second < p2.second;
}

bool isPalindrome(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if (s[i]!=s[n-1-i]){
            return false;
        }
    }
    
    return true;
}

bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){
        return false;
    }else{
        return true;
    }
}

int limit_f, limit_h;
int dp[102][102][12][12];

int getAns(int f, int h, int k1, int k2){
    if(f+h==0) return 1; // end of string 
    if(dp[f][h][k1][k2] != -1) return dp[f][h][k1][k2];

    int x=0;
    if(f>0 and k1>0){
         x = getAns(f-1,h,k1-1,limit_h);
    }
    int y=0;
    if(h>0 and k2>0){
         y = getAns(f,h-1,limit_f,k2-1);
    }

    return dp[f][h][k1][k2] = (x+y)%mod; // have to print mod value

}
int32_t main()
{   
    initcode();
    int f,h;
    cin>>f>>h>>limit_f>>limit_h;
    memset(dp,-1,sizeof(dp));
    cout<<getAns(f, h, limit_f, limit_h)<<endl;


    return 0;
}

// logic:
// First tried to calculate no. of strings without any restrictions i.e No of strings of length n1+n2 such that each place can be filled with x or y. ans => pow(2,n1+n2) for each place we have 2 options so 2^(n1+n2)
// Now applying first 2 restrictions:
// Before applying x, check if enough x are available or not
// same with y
// Now applying last 2 restrictions
// if(enough x are available and no more than k1 x are placed) then place x

// restrictions:
// 1. n1 no. of x is only allowed
// 2. n2 no. of y is only allowed
// 3. No more than k1 consecutive x are allowed
// 4. No more than k2 consecutive y are allowed

// since n = f+h every time so we can reduce the number of states from 5 to 4-> state space optimization