You are given an array of N non-negative integers, A0, A1 ,…, AN-1.

Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4

// a,b,c forms sides of triangle only if (a+b><c && b+c>a && c+a>b == true)
// Always make i point the largest side, coz if the other two sides sum is greater than A[i], the other two sides summations are automatically greater than the third side
// [  , , , , , , ] if (a[j]+a[k] > a[i]), then all j's from(j+1, j+2...) upto k-1 are also valid j's. There sum will also be greater than a[i], coz they are greater than a[j]. Hence it contributes (k-j pairs in total). Now decrement k, to check for new pairs
//  j          k i

// https://www.youtube.com/watch?v=PqEiJDdt3S4
const int mod = 1e9+7;

int Solution::nTriang(vector<int> &A) {
    if (A.size() < 3) return 0;

    sort(A.begin(), A.end());
    
    int ans=0;

    for(int i=A.size()-1;i>=2;i--){
        int j=0,k=i-1;  // A[i] is the largest side, so if A[j]+A[k] > A[i], then A[j]+A[i] > A[k] and A[i]+A[k] > A[j]. These 2 conditions automatically becomes true
        while(j < k){
            int sum = A[j] + A[k];
            if(sum > A[i]){
                ans = (ans%mod + (k-j)%mod)%mod;  // all these (k-j) pairs summation will also be greater than A[i]
                k--;
            }
            else{
                j++;    // have to increase sum, sum should be greater than A[i]
            }
        }
    }

    return ans;
}
