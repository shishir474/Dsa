// https://codeforces.com/contest/2020/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int k; cin>>k;
        int lo = 1, hi = 2e18;
        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            // no of bulbs that will be on considering mid as my n
            int on = mid - floor(sqrtl(mid));
            if (on >= k){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        cout<<ans<<endl;
    }
       
}
// main part is choosing lo and hi. k can go upto 1e18. We need atleast k bulbs, hence choosed hi to 2e18
// use sqrtl(n) when n is too large instead of sqrt(n)

// n bulbs all initially are in the on state
// Lets take n=10, after all the operations, you will notice that only the state of perfect squares is changing
// Perfect squares have odd number of divisors
// The numbers that have even number of divisors, there state will be the same as the original state. Numbers with odd divisors like the perfect squares -> their state will change
// So the total no of bulbs that will be in the on state after all the operations would be n - no_of_perfect_squares[from 1 to n]
// no of perfect squares from 1 to n is sqrt(n)
// so n - sqrt(n) on bulbs

// n <  n1 < n2
// x <=  y <= z => no of on bulbs
// This is monotonic so we can apply binary search