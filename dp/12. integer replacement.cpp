class Solution {
public:// 1D dp problem, but since n is huge, cant use arrays to memoise. Hence using map
    typedef long long ll;
    unordered_map<ll,ll> mp;
    ll solve(ll n){
        if(n==1) return 0;
        if(mp.count(n)) return mp[n]; // if already computed
        
        if(n%2==0){
            return mp[n]= 1+solve(n/2);
        }
        else{
            return mp[n]= 1+min(solve(n-1),solve(n+1));
        }
            
    }
    int integerReplacement(int n) {
        mp.clear();  // intialise the map
        return solve(n);
    }
};
// if codd gives runtime error and the warning is signed integer overflow, then its a clear case of integer overflow, use long long