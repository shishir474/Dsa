Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.



Problem Constraints
0 <= N <= 3000

 -107 <= A[i] <= 107



Input Format
The first and the only argument contains an integer array A.    

// This is not the best solution. Most optimised solution is O(nlogn)
int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n=A.size();
    int t[n],t2[n];
    t[0]=1;
    for(int i=1;i<n;i++){
        t[i]=1;
        for(int j=0;j<i;j++){
            if (A[j] < A[i]){
                t[i] = max(t[i], t[j]+1);
            }
        }
    }

    t2[n-1]=1;
    for(int i=n-2;i>=0;i--){
        t2[i]=1;
        for(int j=i+1;j<n;j++){
            if (A[j] < A[i]){
                t2[i] = max(t2[i], t2[j]+1);
            }
        }
    }


// ans=max(ans, t[i]+t[i+1) works iff there are atleast 2 elements
// IF single element is there then it fails, t1[i] +t2[i]-1 covers all cases
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(t[i]+t2[i]-1, ans);
    }

    return ans;

}
