Given 2 integers A and B and an array of integars C of size N.

Element C[i] represents length of ith board.

You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.

Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

sol.

const int mod = 10000003;
typedef long long ll;

bool isPossible(ll mid,vector<int> &C,int A,int B){
    ll painterRequired=1, s=0;
    for(int i=0;i<C.size();i++){
        if(C[i]*B*ll(1) > mid) return false;
        if(s+(C[i]*B*ll(1)) <= mid){
            s+=(C[i]*B*ll(1));
        }
        else{
            painterRequired++;
            if(painterRequired > ll(A)) return false;
            s = C[i]*ll(B)*ll(1);
        }
    }
    
    return painterRequired<=A;
}


int Solution::paint(int A, int B, vector<int> &C) {
    ll sum=0;
    for(int i=0;i<C.size();i++){ 
        sum = (sum%mod + C[i]%mod)%mod; 
    }
    // corner case:
    if(A==1){
        return (sum*B)%mod;
    }
    
    ll lo=0,hi=sum*B,ans=hi%mod;
    while(lo<=hi){
        ll mid = lo+(hi-lo)/2;
        if(isPossible(mid,C,A,B)){
            ans = mid%mod;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    
    return ans%mod;
}
