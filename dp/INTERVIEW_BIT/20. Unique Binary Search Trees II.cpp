Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

Input Format:

The first and the only argument of input contains the integer, A.
Output Format:

Return an integer, representing the answer asked in problem statement.
Constraints:

1 <= A <= 18
Example:

Input 1:
    A = 3

Output 1:
    5

Explanation 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

int Solution::numTrees(int A) {
    // catalan n
    int t[A+1];
    t[0] = t[1] = 1;
    for(int i=2;i<=A;i++){
        t[i] = 0;
        for(int j=0;j<i;j++){
            t[i] += (t[j]*t[i-1-j]);
        }
    }

    return t[A];
}
