class Solution {
public:
    typedef long long ll;
    int mySqrt(int N) {
        if (N==0) return 0;
        
        ll ans;
        ll lo=1,hi=N;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            if (mid*mid > ll(N)) hi=mid-1;
            else{
                ans = mid;
                lo = mid+1;
            }
        }
        
        return ans;
    }
};