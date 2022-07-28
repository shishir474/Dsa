Intersecting Chords in a Circle

Medium

108

8
Asked In:
Directi
Google
Software Ag
more
Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.

Two ways are different if there exists a chord which is present in one way and not in other.

Return the answer modulo 109 + 7.



Input Format:

The first and the only argument contains the integer A.
Output Format:

Return an integer answering the query as described in the problem statement.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 1

Output 1:
    1

Explanation 1:
    If points are numbered 1 to 2 in clockwise direction, then different ways to draw chords are:
    {(1-2)} only.
    So, we return 1.

Input 2:
    A = 2

Output 2:
    2

Explanation 2:
    If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
    {(1-2), (3-4)} and {(1-4), (2-3)}.
    So, we return 2.


    
const int mod = 1e9+7;
typedef long long ll;
int Solution::chordCnt(int A) {
    // The problem is to find nth catalan number
    ll dp[A+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=A;i++){
        for(int j=0;j<i;j++){
            ll sval = ((dp[j]%mod)*(dp[i-1-j]%mod))%mod;
            dp[i]= (dp[i]%mod +  sval%mod)%mod;
        }
    }

    return dp[A];
}
