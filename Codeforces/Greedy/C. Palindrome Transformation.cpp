// 1700 rated

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
    int n,p; cin>>n>>p;
    p--;     // p is 1 based converting it to 0 based
    string s; cin>>s;
    if(p>=n/2){
        p = n-p-1;
        reverse(s.begin(),s.end());
    }
    
    int l=-1,r=-1; 

// largest r such that s[i]!=s[n-1-i]
    for(int i=n/2 - 1;i>=p+1; i--){
        if(s[i]!=s[n-1-i]){
            r = i; break;
        }
    }

    for(int i=0;i<p;i++){
        if(s[i]!=s[n-1-i]){
            l = i; break;
        }
    }
    
    
    // cout<<"l "<<l<<" "<<"r "<<r<<endl;

    if(l!=-1 and r!=-1){
        // p to l and then l to r
        int ans1=0;
        ans1+=(p-l);
        for(int i=p;i>=l;i--){
            if(s[i]!=s[n-1-i]) ans1+=min(abs(s[i]-s[n-1-i]),  26 - abs(s[i]-s[n-1-i]));
        }
        ans1+=(r-l);
        for(int i=p+1;i<=r;i++){
            if(s[i]!=s[n-1-i]) ans1+=min(abs(s[i]-s[n-1-i]),  26 - abs(s[i]-s[n-1-i]));   
        }

        // p to r and then r to l
        int ans2=0;
        ans2+=(r-p);
        for(int i=p;i<=r;i++){
            if(s[i]!=s[n-1-i]) ans2+=min(abs(s[i]-s[n-1-i]),  26 - abs(s[i]-s[n-1-i]));
        }
        ans2+=(r-l);
        for(int i=p-1;i>=0;i--){
            if(s[i]!=s[n-1-i]) ans2+=min(abs(s[i]-s[n-1-i]),  26 - abs(s[i]-s[n-1-i]));
        }

       // cout<<ans1<<" "<<ans2<<endl;
        cout<<min(ans1, ans2)<<endl;

    }
    else if(l!=-1 and r==-1){
        int ans1=0;
        ans1+=(p-l);
        for(int i=p;i>=l;i--){
            if(s[i]!=s[n-1-i]) ans1+=min(abs(s[i]-s[n-1-i]),  26 - abs(s[i]-s[n-1-i]));
        }
        cout<<ans1<<endl;
    }
    else if(r!=-1 and l==-1){
        int ans2=0;
        ans2+=(r-p);
        for(int i=p;i<=r;i++){
            if(s[i]!=s[n-1-i]) ans2+=min(abs(s[i]-s[n-1-i]),  26 - abs(s[i]-s[n-1-i]));
        }
        cout<<ans2<<endl;
    }
    else{
        if(s[p]!=s[n-1-p]) cout<<min(abs(s[p]-s[n-1-p]),  26 - abs(s[p]-s[n-1-p]))<<endl;
        else cout<<"0"<<endl;
    }



    return 0;
        
}


// logic
// Assuming that cursor's position is in the first half of string(i.e 1≤p≤n/2) (if it's not, just reverse the string, and change p to n-p+1, then the answer will not change).

// It is not hard to see that, in optimal solution, we only need to move our cusor in the first half of the string only, and the number of "turn" is at most once.

// Therefore, we have below algorithm:

// Find the largest index r after p in the first half of the string (p≤r≤n/2) such that s[r] different to s[n-r+1]. (s[i] denote ith character of our input string s)

// Find the smallest index l after p (1≤l≤p) such that sl different to s[n-l+1].

// In optimal solution, we move our cusor from p to l and then from l to r, or move from p to r and then from r to l. While moving, we also change character of string simultaneously (if needed) (by press up/down arrow keys).

// Be careful with some corner case(for example, does'nt exist such l or r discribed above).

// Complexity: O(n).