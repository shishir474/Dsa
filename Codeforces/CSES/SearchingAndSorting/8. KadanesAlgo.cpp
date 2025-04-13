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

int modularBinaryExponentitation(int base, int exponent){
    if(exponent==0) return 1;
    int val = modularBinaryExponentitation(base, exponent/2);
    if(exponent%2)
        return ((val*val)%mod*base)%mod;
    else    
        return (val*val)%mod;
}

struct cmp{
    bool operator()(const pii& p1, const pii& p2){
        return p1.first < p2.first;  // Compare by first element
    }
};


// returns the max sum, starting index, and ending index of the max sum subarray
pair<int, pair<int,int>> kadanes(vector<int> &arr){
    int cs = 0, max_sum = -inf;
    int start = 0, end = 0, temp_start = 0;

    // start → stores the beginning index of the optimal subarray.
	// •	end → stores the last index of the optimal subarray.
	// •	tempStart → temporary starting index, resets whenever currentSum becomes 0.

    forn(i,n){
        cs += arr[i];
        if(cs > max_sum){
            max_sum = cs;
            start = temp_start;
            end = i;
        }
        if(cs < 0){
            cs = 0; // reset cs 
            temp_start = i+1;
        }
    }

    return {maxSum, {start, end}};


}
signed main(){
    int n; cin>>n;
    vector<int> arr(n);
    forn(i,n) cin>>arr[i];
    
    pair<int, pair<int,int>> ans = kadanes(arr);
    cout<<ans.first<<endl;
    cout<<"l: "<<ans.second.first<<" "<<"r: "<<ans.second.second<<end;
    
}
