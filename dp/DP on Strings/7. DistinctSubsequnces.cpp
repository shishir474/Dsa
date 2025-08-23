This problem uses the concept of string matching and dp on strings. Till now whatever problems we did were based on lcs.
Now we'll focus on string matching algorithms.

s1 = "babgbag"
s2 = "bag"

Count the #of ways in which you can choose a subsequence in s1 that matches s2.
Here we have 5 occurences  

We have to count all possible ways -- and the way we explore all ways is using recursion.
Question states Count the No of ways

f(){
    base case -- tends to return 1 or 0
    return f() + f()
}


Writing recurrence:
We have 2 string, thus we need to 2 parameters/indexes i and j. 
Explore all possibilites
Count all ways - return the summation of all possibilites
Write down the base case 


f(i,j){
    if(j < 0) return 1;
    if(i < 0) return 0;
    int ans = f(i-1,j);
    if(s1[i] == s2[j]){
        ans += f(i-1,j-1);
    }
    return ans;
}


f(n-1, m-1) -- start call This means no of distinct subsequences of s2[0..j] in s1[0..i]
   i,   j

f(i, j) -- s1[0..i] and s2[0..j]

If the ith and jth char does not match, I can only move in s1. 
But if the characters do match, then I can match them and move in both s1 and s2. Other option would be to not match them and explore other possibilities(so we move only in s1)

if(s1[i] == s2[j])  
    return f(i-1, j-1) + f(i-1, j)
else    
    return f(i-1, j)

TC: Exponential   s1 - 2^n subs and s2 - s^m subsequence. 
Exploring all possibilities
SC: O(n + m) for recursion stack space 


Due to overlapping subproblems - we can use memoization to store the results of subproblems and avoid redundant calculations.
i = 0 to n-1
j = 0 to m-1
dp[n][m]. n*m states in total 
SC: O(n * m) for dp array + O(n + m) for recursion stack space

memoisation gives TLE here. We need to use the tabulation in order to remove this TLE.
We need to remove this Auxilary stack space and the recursion calls we are making -- 
need to write a tabulation code here


Recursion + memoisation

class Solution {
public:
    int dp[1002][1002];
    int f(int i, int j, string s1, string s2){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = f(i-1,j-1,s1,s2) + f(i-1,j,s1,s2);
        }
        else{
            return dp[i][j] = f(i-1,j,s1,s2);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        memset(dp, -1, sizeof(dp));
        return f(n-1, m-1, s, t);
    }
};

// TC: O(n*m)
// SC: O(n*m) + O(n+m) for recursion stack space


-----------------------------------------------------------

Tabulation Solution -- to get rid of auxilary stack space

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
       
        // was getting runtime error because of overflow -- changed it to long long
        // still getting overflow -- converted to double and while returning final value cast it back to integer
        vector<vector<double>> dp(n+1, vector<double>(m+1,0));
        // base case 1: j == 0
        for(int i=0; i<=n;i++) dp[i][0] = 1;
        // base case 2: i== 0. -- already covered
        for(int i = 1; i<=n ;i++){
            for(int j = 1; j<=m ;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
                }
                else{
                    dp[i][j] = dp[i-1][j]; 
                }
            }
        }

        return int(dp[n][m]);
    
    }
};

// TC: O(n*m)
// SC: O(n*m)

long long is a 64 bit integer. Double is a 64 bit floating point type whose range is vastly greater than that of long long.
We were able to avoid overflow by using double, since it can store massive values


-----------------------------------------------------------

// Space optimisation -- since ith row only depends on (i+1)th row, we can reduce the matrix to 2 rows

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
    
        // was getting runtime error because of overflow -- changed it to long long
        // still getting overflow
        vector<vector<double>> dp(2, vector<double>(m+1,0));
        // base case 1: j == 0
        for(int i=0; i<=1;i++) dp[i][0] = 1;
        // base case 2: i== 0. -- already covered

        int flag = 1;
        for(int i = 1; i<=n ;i++){
            for(int j = 1; j<=m ;j++){
                if(s[i-1] == t[j-1]){
                    dp[flag][j] = dp[flag^1][j-1] + dp[flag^1][j]; 
                }
                else{
                    dp[flag][j] = dp[flag^1][j]; 
                }
            }
            flag = flag^1;
        }

        flag = flag^1;
        return int(dp[flag][m]);
    
    }
};



-----------------------------------------------------------

// 1-D array optimisitaion Technique. -- very very cool stuff

// https://www.youtube.com/watch?v=nVG7eTiD2bY&ab_channel=takeUforward

Pending

