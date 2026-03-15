Intersecting Chords in a Circle

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

Intuition
    You have 2*A points on a circle and want to draw A chords such that no two chords intersect.
    The problem asks: In how many ways can you do this?
Why Catalan Numbers?
    The number of ways to draw non-intersecting chords between 2n points on a circle is the nth Catalan number.
    Catalan numbers count many combinatorial structures, including:
        Ways to correctly match parentheses
        Ways to triangulate a polygon
        Ways to draw non-intersecting chords in a circle
How does the DP work?
    Let dp[i] be the number of ways to draw non-intersecting chords with i pairs.
    For each possible first chord (say, between point 1 and point 2k+2), the circle is split into two smaller circles:
        One with k pairs inside the chord
        One with i-1-k pairs outside the chord
    The total number of ways is the sum over all possible splits:
    dp[i] = sum_{k=0}^{i-1} dp[k] * dp[i-1-k]

    This is the classic Catalan recurrence.

Summary
    The problem reduces to finding the nth Catalan number.
    The DP builds up the answer using the Catalan recurrence, counting all ways to split the circle into smaller non-intersecting subproblems.
    
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
