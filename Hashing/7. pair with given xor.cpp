Problem Description

Given an 1D integer array A containing N distinct integers.

Find the number of unique pairs of integers in the array whose XOR is equal to B.

NOTE:

Pair (a, b) and (b, a) is considered to be same and should be counted once.


Problem Constraints
1 <= N <= 105

1 <= A[i], B <= 107



Input Format
First argument is an 1D integer array A.

Second argument is an integer B.



Output Format
Return a single integer denoting the number of unique pairs of integers in the array A whose XOR is equal to B.



Example Input
Input 1:

 A = [5, 4, 10, 15, 7, 6]
 B = 5
Input 2:

 A = [3, 6, 8, 10, 15, 50]
 B = 5


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 (10 ^ 15) = 5
Explanation 2:

 (3 ^ 6) = 5 and (10 ^ 15) = 5 

int Solution::solve(vector<int> &A, int B) {
    // arr[i] ^ arr[j] is equal to x if and only if arr[i] ^ x is equal to arr[j].  
    set<int> s;
    int c=0;
    for(int i=0;i<A.size();i++){
        if (s.count(A[i]^B)) c++;
        s.insert(A[i]);
    }
    return c;

    // // if the array cntains duplicates use map instead of set
    // map<int,int> mp;
    // int c=0;
    // for(int i=0;i<A.size();i++){
    //     if (mp.count(A[i]^B)) c+=mp[A[i]^B];
    //     mp[A[i]]++;
    // }
    // return c;
}
