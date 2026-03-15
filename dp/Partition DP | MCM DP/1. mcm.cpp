first recursive solution, then recursion + memoisation (top down approach)
Have not covered bottom up approach (bit complex)

mcm
printing mcm
evaluate expression to true / boolean parenthesis
min/max value of an expression
palindrome partitioning
scramble string
egg dropping problem 
Burst Ballons


Input: an array or a string

    f(i,j) -- (i,j) represents the left and right indexes of the array 
    /   \
   f(i,k) f(k+1,j)

   psuedo code:
   int solve(int arrp[], int i, int j){
       if(i > j) return 0;  // empty [] or single length arrat

    //    k starting and ending could vary depending on the problem. It can start from k = i to k < j or k = i+1 to k <= j
       for(int k = i | i+1; k < j | k <= j; k++ | k+=2){        // there could be small variations here
           int tans = solve(arrp, i, k) + solve(arrp, k+1, j) + arrp[i-1]*arrp[k]*arrp[j];
           ans = min(ans, tans);
       }

       return ans;

   }

   Time: O(n * n * n) and O(n * n) Space
   n^2 unique recursive calls and O(n) work during each recursive call.


MCM - matrix chain multiplication
   Goal here is to minimise the # of multiplications
   EX: [2,3,6]
   2 matrices A1 (2 X 3) and A2 (3 X 6) ==> will give us a matrix of size (2 X 6)
   Cost of multiplying this 2 matrices = 2 * 3 * 6 = 36

   ((A1 A2) A3) --> c1 cost
   (A1 (A2 A3)) --> c2 cost
    Out of all the possibilities of parenthesization, we need to find the one with the minimum cost.

   4 5 3 2 --> ans = 70-

   (4,5) (5,3,2)
    0   + 5*3*2 + 4*5*2 = 70
   (4,5,3) (3,2)
    4*5*3 + 0 + 4*3*2 = 84 

    min cost: 70

   int solve(int i, int j){
     scheme1: k = i to k = j-1   solve(i,k) and solve(k+1,j)
     scheme2: k = i+1 to k = j   solve(i,k-1) and solve(k,j)
   }
   i = 1, j = n-1
   solve(arr, i, j)



// CODE:
#include <bits/stdc++.h> 

int t[102][102];

int solve(int i, int j, vector<int> &arr){
    if(i + 1 == j) return 0;
    // addding memoisation
    if(t[i][j] != -1) return t[i][j];

    int ans = INT_MAX;
    for(int k = i + 1; k < j; k++){
        int tans = solve(i, k, arr) + solve(k, j, arr) + (arr[i] * arr[k] * arr[j]);
        ans = min(ans, tans);
    }

    return t[i][j] = ans;

}
int matrixMultiplication(vector<int> &arr, int N)
{

    memset(t, -1, sizeof(t));        // t[N+1][N+1] & initialised with -1
    return solve(0,N-1,arr);
}

Time: O(n * n * n) and O(n * n) Space
   n^2 unique recursive calls and O(n) work during each recursive call.
