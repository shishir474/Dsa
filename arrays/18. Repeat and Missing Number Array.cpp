Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4


typedef long long ll;
int findRightmostSetBit(int n){
    for(int i=0;i<=31;i++){
        if(n&(1<<i)) return i;
    }
    return -1;
}
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Most optimised Solution using xor
    ll n = A.size();
    int xor1 = 0;
    for(int i=0;i<n;i++){
        xor1 = xor1^A[i];
    }

    for(int i=1;i<=n;i++){
        xor1 = xor1^i;
    }

    // find the rightmost set bit in xor1, based on which we're going to classify the no's into 2 buckets
    int idx = findRightmostSetBit(xor1);

    int x = 0, y = 0;
    for(int i=0;i<n;i++){
        // if idx bit is set in A[i], insert in set bucket else in unset bucket
        if (A[i] & (1<<idx))
            x = x^A[i];
        else
            y = y^A[i];
    }

    for(int i=1;i<=n;i++){
        if (i & (1<<idx))
            x = x^i;
        else
            y = y^i;
    }

    int freq_x = 0, freq_y = 0;
    for(int i=0;i<n;i++){
        if (A[i]==x){
            freq_x++;
        }
        else if(A[i]==y){
            freq_y++;
        }
    }

    if (freq_x == 2){
       return {x,y};
    }
    else{
       return {y,x};
    }


}
