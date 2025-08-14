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

void solve(vector<int> &v){
    // forn(i,v.size()) cout<<v[i]<<" ";
    // cout<<endl;
    
    for(int i=1;i<v.size();i+=2)
        cout<<v[i]<<" ";
    
    if(v.size()==1){
        cout<<v[0];
        return;
    }
    
    vector<int> newv;
    if(v.size()%2 == 0){ // even size vector, 
        for(int i=0;i<v.size();i+=2)
            newv.pb(v[i]);
        
    }
    else{
        newv.pb(v[v.size()-1]);
        for(int i=0;i<v.size()-1;i+=2)
            newv.pb(v[i]);
    }
    
    solve(newv);
}
// count of subarray with sum = x
signed main(){
    // SOLUTION 1: prefix sums + sets/maps
    // sets won't work if the array contains -ve values.
    // since all values are + ve in array, the prefix sum will never repeat and hence used sets.
    // Can use maps as well(maps will work for cases where -ve values are also there in the array)
    initcode();

    int n,x; cin>>n>>x;
    int arr[n];
    forn(i,n) cin>>arr[i];
    
    set<int> s;
    s.insert(0);
    
    int cs = 0, cnt = 0;
    
    forn(i,n){
        cs+=arr[i];
        if(s.count(cs-x)) cnt++;
        s.insert(cs);
    }
    
    cout<<cnt<<endl;


    // SOLUTION 2: Using prefix sums + sliding window O(N)
    // keep on building the prefix until you have a sum>=x. Moment you have a sum>=x, check if the sum==x increase the cnt and start moving your i pointer one step at a time
    int n,x; cin>>n>>x;
    int arr[n];
    forn(i,n) cin>>arr[i];
    
    int cnt = 0;
    int sum = 0;

    // sliding window solution: keep on extending the window until the sum of the window is atleast x. and now start shrinking from the left. While shringking check if the sum == x increase the cnt, remove ith element and increase i
    // Sliding window solution wont work if the array contains -ve values
    int i=0,j=0;
    while(j < n){
        sum+=arr[j];
        while(sum >= x){
            if(sum==x){
                cnt++;
            }
            sum-=arr[i];
            i++;
        }
        j++;
    }
    
    cout<<cnt<<endl;

    // here both i and j which are independent of each other, move in the same direction. Hence the complexity is n + n= O(n)


    // SOLUTION 3: brute force O(n^3)
    int n,x; cin>>n>>x;
    int arr[n];
    forn(i,n) cin>>arr[i];
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            int sum = 0;
            for(int k=i;k<=j;k++)  
                sum+=arr[k];
            
            if(sum == x) cnt++;

        }
    }


    // SOLUTION 4: brute force optimised using prefix sums O(n^2)
    // In order to check sum of subarray from [i .. j] you dont need to run a loop, you can do it in O(1) using prefix sums
    // sum of subarray from [i..j] = prefix[j] - prefix[i-1]
    int n,x; cin>>n>>x;
    int arr[n+1];
    fore(i,1,n) cin>>arr[i];
    vector<int> prefix(n+1,0);
    fore(i,1,n){
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    int cnt = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(prefix[j] - prefix[i-1] == x) 
                cnt++;
        }
    }

    cout<<cnt<<endl;

    
}
// IMP : HERE we are talking about the count of subarrays with x as target sum. Not about subsequences. In subsequences we have a choice pick/non pick, i.e we can break
// whereas in subarrays, these are contigous, we cannot break them

// the dp solution is for finding the cnt of subsequences with target x, where we were making choice of pick / non pick for each eleemnt
// here we are dealing with subarrays which are contigous, so we use prefix sum
// We keep track of the prefix sum and try to count the no of subaarrays that has a sum = target ending at each index
// We keep a set to store the prefix sums. At index i, we get the prefix sum and check if we have encoutered any prefix with sum cs - target
// If yes, then we found one subarray


/// Solution Intuitions:
// 1st brute force N^3
// 2nd brute force optimised using some preprocessing of prefix sum calculation reduced the complexity to O(n^2)
// 3rd Sliding window: O(n) works only in case where all values are +ve
    // we keep moving our right boundary till the point our sum < x. The moment it becmoes >= x, we stop and start moving our left boundary
    // The reason we stop is bcoz we know since all the values are +ve there is no point moving forward. It would just increase the sum
    // so we move our left boundary to reduce the sum 

    // But in case where we could have -ve array values, lets say your target is 7
    // (8)-1
    // you will stop at 8 coz 8 >= 7 ad start moving your left boundary, 
    // but in case of -ve values, the next could be -ve and it could also contribute to our ans
    // Hence the sliding window solution does not work with -ve values in the array
    

