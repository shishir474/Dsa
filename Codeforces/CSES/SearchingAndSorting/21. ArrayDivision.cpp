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

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
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

bool isPossible(int mx, int arr[], int n, int k){
    int part = 1, i = 0;
    while(i < n){
        int sum = 0;
        while(i < n and sum + arr[i] <= mx){
            sum+=arr[i];
            i++;
        }
        if(i==n) break;
        part++;
    }
    // calculate the # of partitions required to accomodate all elements given that each subarray can atmost contain sum m
    // if the # of partitions required <= k(which is our limit) -> then we can distribute the elements across k partition
    // but if the required # of partitions is itself greater than k, then its not possible for current value of mid and we'll have to increase the value of mid
    return part<=k;
}

signed main(){
    initcode();
    int n,k; cin>>n>>k;
    int arr[n];
    int sum = 0;
    forn(i,n) {
        cin>>arr[i];
        sum+=arr[i];
    }
    
    int mx = *max_element(arr,arr+n);
    
    int ans = 0;
    int lo = mx, hi = sum;
    while(lo <= hi){
        int m = lo + (hi-lo)/2;
        if(isPossible(m, arr, n, k)){
            ans = m;
            hi = m - 1;
        }
        else{
            lo = m+1;
        }
    }
    
    cout<<ans<<endl;
    
    
}

// 5, 3
// 2 4 7 3 5 = 21

// 7-21, mid = 14 [13,8] part = 2 <= 3 True
// 7-13, mid = 10 [6,10,5] part =3 <=3 true
// 7-9, mid = 8 [6,7,8] part=3<=3 true
// 7-7, mid = 7 [6,7,3,5] part=4 > 3 false 



// the requirement here is to partition the array into k subarrays such that the max sum of all subarrays is as minimal as possible
// The maximum minimal sum(what's the max possible value for minimum sum?) will always be equivalent to max element of the array. Consider the case where each partition contains 1 element
// Maximum sum will be in the case where all the elements are part of one single partition
// Now between this lo and hi, there is a monotonic behaviour. If for a particular mid, we are able to partition this into k partitions, then we will be able to do it for values larger than mid as well
// The pivot point where the function changes its behaviour, will be our ans

// Intuition:

// you have to partition the array into k parts, ensuring that the max possible sum of the partition is as minimal as possilbe. You have to return this max sum
// ifPossible function checks can we partition the array into <=k partitions such that max allowed sum of a partition is m.
// if not it means we need more that k partitions 
// so we'll have a range of sum values(possible sums of partition) - what's the max sum possible(entire array), what's the max minimum sum possible(max element of the array)
// If we consider this range of values and check if we are able to partition the array into atmost k partition for mid m - this this could be our ans & we should try for a better value
// if the no of partitions required given the condition that each partition cannot have more than m sum is greater than k, then obviously we have to increase the limit i.e increase mid capacity

// Homogeneceity nature --> leading to use of binary search

// if it is possible to partition the array into k partitions by keeping mid as the max cap, then obviuolsy it's possible to partitiion it into k partitoins for values > m.
// So mid could be our possible ans and now we should try for smaller values of mid
// if not possible for mid (meaning requires more than k paritions, so obvioulsy it will not be possible for values less mid as well) - hence we should try for values > mid

