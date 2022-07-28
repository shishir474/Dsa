Distinct Subsequences

Medium

251

7
Asked In:
Google
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.

    
// int solve(int i, int j, string a, string b, vector<vector<int> >& dp){
//     if (j==b.length()) return 1;
//     if (i==a.length()) return 0;
//     if (dp[i][j] != -1) return dp[i][j];

//     if (a[i]==b[j]){
//         return dp[i][j] = solve(i+1,j+1,a,b,dp) + solve(i+1,j,a,b,dp);
//     }
//     else{  
//         return dp[i][j] = solve(i+1,j,a,b,dp);
//     }
// }
int Solution::numDistinct(string A, string B) {
    int m=A.length(), n = B.length();
    int t[m+1][n+1];
    for(int i=0;i<=m;i++){
        t[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        t[0][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (A[i-1]==B[j-1]){
                t[i][j] = t[i-1][j-1] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[m][n];
    //vector<vector<int> > dp(m, vector<int> (n,-1));
    // return solve(0,0,A,B,dp);
}
