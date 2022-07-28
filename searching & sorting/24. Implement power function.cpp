Implement pow(x, n) % d.
In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. In other words, make sure the answer you return is non negative.



Problem Constraints
-109 <= x <= 109
0 <= n <= 109
1 <= d <= 109


typedef long long ll;

int power(int a, int n, int d, int f){
    if (n==0) return 1;
    if (n==1){
        if (f==0)
            return a;
        else
            return (a + d)%d;
    }

    ll temp = power(a,n/2,d,f);
    ll ans = ((temp%d)*(temp%d))%d;

    if (n&1){
       ans = ((ans%d)*(a+d)%d)%d;
        
    }

    // if (n&1){
    //     //  if(f==0){
    //     //     ans = ((ans%d)*(a%d))%d;
    //     // }
    //     // else{ // a can be -ve, so doing (a+d)%d
    //         ans = ((ans%d)*(a + d)%d + d)%d;
    //     //}
    // }
    return (int)ans;
}

int Solution::pow(int x, int n, int d) {
    if (x==0) return 0;
    int f=0;
    if (x < 0) f=1;
    return power(x,n,d,f);
}
