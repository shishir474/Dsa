Matrix Median

Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.




Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 ``` Matrix=

int upperBound(vector<int> &a, int target){
    int ans = -1;
    int st = 0, end = a.size()-1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if (a[mid]<=target){
            st = mid+1;
        }else{
            ans = mid;
            end = mid-1;
        }
    }

    if (ans==-1) return a.size();
    return ans;

}
int countLessThanEqualTo(vector<vector<int> > &A, int b){
     int n = A.size(), m = A[0].size();
     int cnt=0;
     for(int i=0;i<n;i++){
         /// BOTH BELOW STATEMENTS ARE CORRECT
        // int ind = upper_bound(A[i].begin(), A[i].end(), b) - A[i].begin();
        int ind = upperBound(A[i], b);
        cnt+=ind;
     }

     return cnt;
}

int Solution::findMedian(vector<vector<int> > &A) {
    // 2^32 is approximately equal to 10^9, which is our search space
    // TC: log(2^32)*Nlog(M) , for all rows of the matrix we are applying BS.
    int n = A.size(), m = A[0].size();
    int k = ((n*m)/2) + 1;
    int ans=0;
    int st = 1, end = 1e9;
    while(st<=end){
        int mid = st + (end-st)/2;
        int cnt = countLessThanEqualTo(A, mid);
        if (cnt < k){
            st = mid+1;
        }else{
            // This could be my possible median
            ans = mid;
            end = mid-1;
        }
    }

    return ans;
}
