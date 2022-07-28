Given an integer array A of size N. You have to merge all the elements of the array into one with the minimum possible cost.

The rule for merging is as follows:

Choose any two adjacent elements of the array with values say X and Y and merge them into a single element with value (X + Y) paying a total cost of (X + Y).
Return the minimum possible cost of merging all elements.



Problem Constraints
1 <= N <= 200

1 <= A[i] <= 103



Input Format
First and only argument is an integer array A of size N.



Output Format
Return an integer denoting the minimum cost of merging all elements.



Example Input
Input 1:

 A = [1, 3, 7]
Input 2:

 A = [1, 2, 3, 4]


Example Output
Output 1:

 15
Output 2:

 19


Example Explanation
Explanation 1:

 All possible ways of merging:
 a) {1, 3, 7} (cost = 0) -> {4, 7} (cost = 4) -> {11} (cost = 4+11 = 15)
 b) {1, 3, 7} (cost = 0) -> {1, 10} (cost = 10) -> {11} (cost = 10+11 = 21)
 Thus, ans = 15




int t[201][201];
int helper(vector<int>& A, int i, int j, vector<int> prefix){
    if (j-i+1 == 1) return 0;
    if (j-i+1 == 2) return A[i]+A[i+1];
    if (t[i][j]!=-1) return t[i][j];

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        // [i...k] sum
        int l = prefix[k] - (i>0 ? prefix[i-1] : 0);
        // [k+1...j] sum
        int r = prefix[j] - prefix[k];
        int tans = l+r+helper(A,i,k,prefix)+helper(A,k+1,j,prefix);
        ans = min(ans, tans);
    }

    return t[i][j] = ans;

}
int Solution::solve(vector<int> &A) {
    memset(t,-1,sizeof(t));
    vector<int> prefix(A.size());
    prefix[0] = A[0];
    for(int i=1;i<A.size();i++){
        prefix[i] = prefix[i-1] + A[i];
    }
 return helper(A,0,A.size()-1,prefix);
}

// variation of palindrome partioning 2 on leetcode
