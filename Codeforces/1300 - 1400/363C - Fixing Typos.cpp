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

int32_t main()
{
    initcode();
    string s; cin>>s;
    vector<pair<char,int> > v;
    int i,j;
    for(i=0;i<s.length(); ){
        for(j=i+1; j<s.length() and s[j]==s[i]; j++){}
        if(j-i>=3){
            v.pb({s[i],2});
        }else{
            v.pb({s[i],j-i});
        }
        
        i = j;
    }


    for(int i=0;i<v.size();i++){
        if(v[i].second==2){
            for(j=i+1;j<v.size() and v[j].second==2;j++){} // calc freq of 2

                // if freq is odd lets say 3 so we wiil just convert 3/2 i.e 1 pair and that will be the middle one
            if((j-i)%2 == 1){
                int c=0;
                for(int k=i+1; c<(j-i)/2 and k<v.size(); c++,k+=2) v[k].second=1;
            }
            else{
                int c=0;
                for(int k=i; c<(j-i)/2 and k<v.size(); c++,k+=2) v[k].second=1;   
            }
        }
    }



    //string ans="";
    for(int i=0;i<v.size();i++){
        if(v[i].second==1) cout<<v[i].first;
        else cout<<v[i].first<<v[i].first;
    }




    return 0;
}

// consider the case: aabbcc, where we have 3 consecutve 2's freq characters
// Earlier I just checked if 2 consecutives are 2 then make the first one 1 and move forward. but this will not produce optimal result
// abcc is produced 
// But the optimal ans is aabcc (5 length string can be produced)