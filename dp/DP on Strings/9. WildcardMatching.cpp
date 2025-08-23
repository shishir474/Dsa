Wildcard matching 

You will be given 2 string s1 and s2. The goal is to check if s2 matches s1 with the following rules:
1. '?' matches any single character.
2. '*' matches with sequence of length 0 or more 

You need to implement a function that returns true if s2 matches s1, and false otherwise.

s1 = "abcde"
s2 = "a?c*e" 
True (? matches with b, * matches with d)

s1 = "abcd"
s2 = "a?cc"
False

s1 = "ab*cd"
s2 = "abdefcd"

The first thing which comes to mind is simple string matching.
The main problem arises if its a *. because for ? its very straightforward. They will match.
But for *, you exactly dont know how many characters it will match. It can match 0 or more characters.

If * matches 0 char, then I will try to match b with f 
If * matches 1 char, then I will try to match b with e (* matches "f")
If * matches 2 char, then I will try to match b with d (* matches "ef")
If * matches 3 char, then I will try to match b with b and here it matches (* matches "def"). -- this is the optimal choice 
Since we dont exactly know how many characters * will match, we will have to try all possibilities.  

How to write recurrence?
1. Here we are dealing with 2 strings, hence we will need 2 indexes i and j.
2. Explore comparisons.
3. Out of all comparisons if any way can, you return true
  
s1 = "ab*cd"
s2 = "abdefcd"
f(n-1, m-1) -- this means s1[0..i] and s2[0..j] matches
   i,   j

if(s[i] == s2[j] or s[i]=='?'){
    return f(i-1, j-1);
}
else{       // if the char dont match, s[i] must be a * (if not return false)
    if(s[i] == '*'){
        // * matches 0 char -- f(i-1, j)
        // * matches 1 char -- f(i-1, j-1)
        // * matches 2 char -- f(i-1, j-2)
        // * matches k char -- f(i-1, j-k)
        // we will keep on reducing j till it becomes < 0
        for(int k = 0; k <= j; k++){       //  For *, I can match 0, 1, 2, 3, ... so on chars. 
            if(f(i-1, j-k)){
                return true;
            }
        }

        return false;
    }
    else{       // s[i] and s2[j] don't match and s[i] != '*' or s[i] != '?'
        return false;
    }
}


s1 = "ab*"
s2 = "abdef"        * does not match any char so ab*\abdef --> ab|abdef
                    * matches one char so ab*|abdef --> ab*|abde (ab* again because * can be matched again to more characters)

                                            ab* | abdef
                                                /  \  
                                        ab|abdef    ab* | abde
                                                    /   \
                                                ab|abde  ab*|abd
                                                     /     \
                                                 ab|abd  ab*|ab      
                                                                 /       
                                                                ab|ab 

This recursion tree clearly indicates, that  f(i-1,j), f(i, j-1)
f(i-1,j) -- * matches 0 char
f(i, j-1) -- * matches 1 char (in each step it will delete one char)
Thus all set of chars 0,1,2,.. and so on will be taken care of 

                               
// Either the characters has to be matching or char should be a ? or it has to be a *
if(s[i] == s2[j] or s[i]=='?'){
    return f(i-1, j-1);
}
else{       // if the char dont match, s[i] must be a * (if not return false)
    if(s[i] == '*')
        return f(i-1, j) || f(i, j-1);
    else       // s[i] and s2[j] don't match and s[i] != '*' or s[i] != '?'
        return false;
}

Out of all comparisons if any way can, you return true


// s1 input string and s2 is pattern
Base case:
How to derive the base cases? For this we need to see when our comparisons are completed

if(i < 0 && j < 0) return true; // both strings(input and pattern) are exhausted
if(i < 0 && j >= 0) { // input string is exhausted and pattern has to contain all *, then only it can be matched 
    for(int k = 0; k <= j; k++) {
        if(s2[k] != '*') return false;
    }
    return true;
}
if(j < 0) return false; // pattern is exhausted but input string is not exhausted

if input string gets exhausted, then in order to return true pattern string needs to be also exhausted or pattern strings should contain all *
ex: s1 = "", s2 = "***"
s2 can be matched with s1 here 
if input is not exhausted but pattern is exhausted, then return false
ex: s1 = "abc", s2 = ""  (there is no way to match s1 with s2)


Lemme just quickly walk you through the time complexity. Obviously its recursion we are going to try all possibilities.
It is definitely going to be exponential. * can match 0, 1, 2, ... so on chars. Time complexity is going to be exponential. That is what I am going to say
TC: exponential
SC: will be the auxilary stack space which will be somewhere around O(n+m) where n is the length of the input string and m is the length of the pattern string

We have to figure out if there are overlapping subproblems, then you end up doing memoisation.
How do we do memoisattion?
What are the changing parameters here? i & j 
i varies from 0 to n-1
j varies from 0 to m-1
so [n X m] dp is what we require.

After memoisation,the time complexity will be O(n*m) because those will be no of different states and space complexity will be O(n*m) + O(n+m) for recursion stack space

class Solution {
public:
    int dp[2002][2002];
    bool solve(int i, int j, string s, string p){
        // base case 1
        if(i < 0 && j < 0) return true;
        // base case 2
        if(i < 0 && j>=0){
            // input string is exhausted, but pattern is still non empty. pattern should be all * in order to match an empty string
            for(int k = 0; k<=j; k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        // base case 3
        if(j < 0 && i >= 0){
            // pattern is exhausted , but the input string is still non empty 
            return false;
        }
        // added memoisation 
        if(dp[i][j] != -1) return dp[i][j];


        // Recurence
        if(s[i] == p[j] or p[j]=='?'){
            return dp[i][j] = solve(i-1, j-1, s, p);
        }
        else{
            if(p[j] == '*'){    // matches with 0 char || matches with one char (and can be matched again, hence i remains same)
                return dp[i][j] = solve(i-1,j,s,p) || solve(i,j-1,s,p);
            }
            else{   // either the char should match, or it should be a '?'  or it should be a '*'
                return dp[i][j] = false;
            }
        }

    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(n-1, m-1, s, p);
    }
};

// TC: O(n*m)
// SC: O(n*m) + O(n+m) for auxilary stack space
// Memoisation sol gives MLE 


Memoisation solution using 1 based indexing

class Solution {
public:
    int dp[2002][2002];
    bool solve(int i, int j, string s, string p){
        // base case 1
        if(i == 0 && j == 0) return true;
        // base case 2
        if(i == 0 && j>0){
            // input string is exhausted, but pattern is still non empty. pattern should be all * in order to match an empty string
            for(int k = 1; k<=j; k++){
                if(p[k-1]!='*') return false;
            }
            return true;
        }
        // base case 3
        if(j == 0 && i > 0){
            // pattern is exhausted , but the input string is still non empty 
            return false;
        }
        // added memoisation 
        if(dp[i][j] != -1) return dp[i][j];


        // Recurence
        if(s[i-1] == p[j-1] or p[j-1]=='?'){
            return dp[i][j] = solve(i-1, j-1, s, p);
        }
        else{
            if(p[j-1] == '*'){    // matches with 0 char || matches with one char (and can be matched again, hence i remains same)
                return dp[i][j] = solve(i-1,j,s,p) || solve(i,j-1,s,p);
            }
            else{   // either the char should match, or it should be a '?'  or it should be a '*'
                return dp[i][j] = false;
            }
        }

    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(n, m, s, p);
    }
};


// Tabulation solution

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();

        // I'm. not a big fan of memoiation becuase it involves aux stack space. 
        // steps to convert memoisation solution to tabulation
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));

        // base case 1
        dp[0][0] = true;

        // base case 2: for 1st row for j > 0
        for(int j = 1; j<=m ;j++){
            int flag = true;
            for(int k = 1; k<=j; k++){
                if(p[k-1]!='*'){ 
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }   
        // base case 3: for j==0 basically 1st col and for i > 0
        for(int i = 1; i<=n ;i++){
            dp[i][0] = false;
        }


        for(int i=1; i<=n ;i++){
            for(int j=1;j<=m ;j++){
                if(s[i-1] == p[j-1] or p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1]; 
                }
                else{
                    if(p[j-1] == '*'){    // matches with 0 char || matches with one char (and can be matched again, hence i remains same)
                        dp[i][j] = dp[i-1][j] || dp[i][j-1]; 
                    }
                    else{   // either the char should match, or it should be a '?'  or it should be a '*'
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[n][m];
    }
};

// TC: O(n * m)
// SC: O(n * m)


------------------------------------------------------------------------------------------------------

// Space Optimisation
// Since the ith row only depends on the prev row, we can optimise space by using 2 rows only

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();

        // I'm. not a big fan of memoiation becuase it involves aux stack space. 
        // steps to convert memoisation solution to tabulation
        // write the base case. Determine the changing parameters, and fill the dp array/matrix
        vector<vector<bool>> dp(2, vector<bool>(m+1,false));

        // base case 1
        dp[0][0] = true;

        // base case 2: for i == 0 i.e 1st row for j > 0
        for(int j = 1; j<=m ;j++){
            int flag = true;
            for(int k = 1; k<=j; k++){
                if(p[k-1]!='*'){ 
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }   
        // base case 3: for j==0 basically 1st col and for i > 0
        for(int i = 1; i<=1 ;i++){
            dp[i][0] = false;
        }

        int flag = 1;

        for(int i=1; i<=n ;i++){
            
            dp[flag][0] = false;            // for any i the first col will always be false -- 3rd base case

            for(int j=1;j<=m ;j++){
                if(s[i-1] == p[j-1] or p[j-1]=='?'){
                    dp[flag][j] = dp[flag^1][j-1]; 
                }
                else{
                    if(p[j-1] == '*'){    // matches with 0 char || matches with one char (and can be matched again, hence i remains same)
                        dp[flag][j] = dp[flag^1][j] || dp[flag][j-1]; 
                    }
                    else{   // either the char should match, or it should be a '?'  or it should be a '*'
                        dp[flag][j] = false;
                    }
                }
            }
            flag = flag^1;
        }
        
        flag = flag^1;
        
        return dp[flag][m];
    }
};

// TC: O(n * m)
// SC: O(2 * m)