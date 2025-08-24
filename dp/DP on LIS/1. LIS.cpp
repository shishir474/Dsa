This is the another pattern in dp i.e lis  (longest increasing subsequence)

arr[] = {10, 9, 2, 5, 2, 7, 10}
Any contigous or non contigous sequence of an array is called a subsequence. THE ONLY condition is order needs to be maintainged 

problem is to figure out the length of  longest increasing subsequence


In all the subsequence problem, the pattern which we followed wa pick/not pick.
Either you take it or you decide not to take it 

{8,8,8} --> 1
we are talking about strictly increasing subsequence


BRUTE FORCE 
First approach that comes to mind is to check all subsequences. For this you can either use a power set (basically masking) or recursion 
check for increasing one 
and keep track of the maximum length found so far. 
Thats going to be brute force. Will not dive deep into it. 
In order to generate all the subseuquences, we end up taking 2^n time because if we are generating all the subsequences, the no of subsequences for a string of length i=n is 2^n
This is exponential in nature and will definitely give us TLE 
 

2nd solution : Try all ways --> and this is acheived using recursion
1. Express everything in terms of index.
2. Explore all possibilities in subsequences -->  (take or not take)
3. Take the max length of (not_take, take)
4. base case 


f(n-1,INT_MAX) denotes the length of the longest increasing subsequence in arr[0....n-1]

// The problem with the below recurrence is we are taking value as our changing parameter -- which is not very efficient. Instead lets track the next index which we took

// int f(int i, int next){ 
//     int op1 = 0, op2 = 0;
   
//     op1= f(i-1, next); // not pick
  
//     if(arr[i] < next) // picking element only if arr[i] < next
//     op2 =1 + f(i-1, arr[i]);

//     return max(op1, op2); 
// }


// Here everything is expressed in terms of index. No physical value is being used anywhere
f(int i, int next_idx){
    int op1 = 0, op2 = 0;

    op1 = f(i-1, next_idx); // not pick
    // if we are not including i as part of the lis, i will move to i-1 and next_idx remains the same

    if(next_idx == n || arr[i] < arr[next_idx]) // if the next_idx is n or arr[i] < arr[next_idx] -- we can take the current element
    // taking ith element, so we move i to i-1 and next_idx to i
        op2 = 1 + f(i-1, i);

    return max(op1, op2);       // max(not_take, take)
}

f(n-1, n);      // denotes the length of the longest increasing subsequence in arr[0..n-1] whose next elemeent is at index n

What about base case?
if (i < 0) return 0;        // empty array we return 0;

// The time complexity of this recursive solution is O(2^n) because at each index, you have 2 options take or not_take. So in total it will yield 2^n no of operations
// Space complexity is O(n) for the auxilary stack space

-----------------------------------------------------------
Memoisation

if I draw the recursion tree, you will notice that there are overlapping subproblems. 

Look out for the changing parameters
i goes from n-1 to 0
next_idx goes from n to 0

// zero index based recurrence relation
f(int i, int next_idx){
    if (i < 0) return 0; 
    // adding memoisation 
    if(dp[i] != -1) return dp[i];

    int op1 = 0, op2 = 0;

    op1 = f(i-1, next_idx); // not pick
    // if we are not including i as part of the lis, i will move to i-1 and next_idx remains the same

    if(next_idx == n || arr[i] < arr[next_idx]) // if the next_idx is n or arr[i] < arr[next_idx] -- we can take the current element
    // taking ith element, so we move i to i-1 and next_idx to i
        op2 = 1 + f(i-1, i);

    return dp[i] =  max(op1, op2);       // max(not_take, take)
}

TC: O(n)
// SC: O(n) + O(n) for auxilary stack space


// If I do a coordinate change basically shift all the indices by 1
Basically in order to write my memoisation, I need to convert my code to follow 1 based indexing 
because in the current 0 based indexing i goes from n-1 to -1 and next_idx goes from n to 0
We cannot have -1 index in our dp array 

So we need to shift all the indices by 1

int f(int i, int next_idx, vector<int>& arr){
    if (i == 0) return 0; 

    int op1 = 0, op2 = 0;

    op1 = f(i-1, next_idx, arr, dp); // not pick
    // if we are not including i as part of the lis, i will move to i-1 and next_idx remains the same

    if(next_idx == arr.size()+1 || arr[i-1] < arr[next_idx-1]) // if the next_idx is n or arr[i] < arr[next_idx] -- we can take the current element
    // taking ith element, so we move i to i-1 and next_idx to i
        op2 = 1 + f(i-1, i, arr);

    return dp[i][next_idx] = max(op1, op2);       // max(not_take, take)
}

f(n, n+1, arr);


// added Memoisation 
int f(int i, int next_idx, vector<int>& arr, vector<vector<int>> &dp){
    if (i == 0) return 0; 
    // adding memoisation
    if(dp[i][next_idx] != -1) return dp[i][next_idx];

    int op1 = 0, op2 = 0;

    op1 = f(i-1, next_idx, arr, dp); // not pick
    // if we are not including i as part of the lis, i will move to i-1 and next_idx remains the same

    if(next_idx == arr.size()+1 || arr[i-1] < arr[next_idx-1]) // if the next_idx is n or arr[i] < arr[next_idx] -- we can take the current element
    // taking ith element, so we move i to i-1 and next_idx to i
        op2 = 1 + f(i-1, i, arr, dp);

    return dp[i][next_idx] = max(op1, op2);       // max(not_take, take)
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
    return f(n, n+1, nums, dp);
}
// TC: O(n * n);
// SC: O(n * (n+1)) + O(n) for auxilary stack space


-----------------------------------------------------------
Tabulation solution 
// Converting this solution to tabulation to get rid of auxiliary stack space
 int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+2, 0));

    // idx i goes from n to 1 
    // next_idx goes from n+1 to 1. (here's the catch)
    // What is the definition of next_idx? It will always be greater than the index i.
    // so next_idx lies in range i+1 to n+1

    // This is a classic example where we dont directly write the loop i = 1 to N  and j = 1 to N.
    // Based on the problem statements, the starting and terminating conditions of the loops needs to be adjusted

    // NOTE: dp[i][j] signifies the length of the lis in arr[0..i] where the next_idx is j

    for(int i = 1;  i<=n; i++){
        for(int j = i+1; j<=(n+1); j++){
            dp[i][j] = dp[i-1][j] ;
            if(j == (n+1) || nums[i-1] < nums[j-1]){
                dp[i][j] = max(dp[i][j], 1 + dp[i-1][i]);
            }
        }
    }

    return dp[n][n+1];

}

TC: O(n * n);
SC: O(n * (n+1))
-----------------------------------------------------------

Space optimisation

Since the ith row only depends on the (i-1)th row, we can optimise our space complexity by using a 1D array instead of a 2D array.

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(2, vector<int>(n+2, 0));
    // base case i== 0 dp[0][j] = 0

    int flag = 1;

    for(int i = 1;  i<=n; i++){     // i is the current index 
        for(int j = i + 1; j<=(n+1); j++){      // j is the next_idx and the definition of next_idx is it will always be greater than i (so it should start with i+1)

            dp[flag][j] = dp[flag^1][j] ;

            if(j == (n+1) || nums[i-1] < nums[j-1]){
                dp[flag][j] = max(dp[flag][j], 1 + dp[flag^1][i]);
            }
        }
        flag = flag^1;
    }

    flag = flag^1;
    return dp[flag][n+1];

}
// TC: O(n * n);
// SC: O(2*n)

NOTE: this is not the most optimised solution for LIS. We will see the optimised solution for this in the nex few problems


*********************************************************
NOTE:
The Key is to understand the recurrence, then memoisation, then tabulation, and finally the space optimisation
*********************************************************