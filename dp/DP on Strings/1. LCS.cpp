Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.


Solution :

What is a subsequence?
subsequence is basically a sequence that can be contigous or non-contiguous, but must maintain the relative order of characters.

You can derive all the subsequences using mask 
for any given string of length n, we have 2^n subsequences including the empty subsequence.

text1 can generate 2^5 = 32 subsequences.
text2 can generate 2^3 = 8 subsequences.

Amongst them we are only concerned with common subsequences and then return the length of the longest one.

Brute force -- 
generate all the subsequences of both strings and then find the longest common subsequence among them.
But this is going to be exponential 


-- recursive solution

1. express in terms of indexes
2. explore possibility on that index
3. take the best amongst them 

Single index cannot be used for both the strings. hence we need 2 indexes.

f(i,j) represents the length of longest common subsequence of s1[i:] and s2[j:]

f(0,0) represents the lcs(s1[0:], s2[0:])

exploring all possibilities:
2 comparisons character wise. If the ith and jth char are matching, I got a subs of length 1 
and I need to check f(i+1, j+1) for the rest of the string.

In all the dp string problems, you will see to match or not match the characters. If it matches you will generally add to the ans and move back/ahead
In the array problems, pick or not pick the elements.

If s1[i] and s2[j] characters does not match, there are 2 possibilities:
1. Move the index of s1 ahead and keep s2 same -> f(i+1, j)
2. Move the index of s2 ahead and keep s1 same -> f(i, j+1)
and then we return the max of them.

base case:
if either of the strings are empty :
    return 0;



class Solution {
public:
    int f(int i, int j, string s1, string s2){
        if(i >= s1.length() || j >= s2.length()) return 0;

        if(s1[i] == s2[j]){
            return 1 + f(i+1, j+1, s1, s2);
        }
        else{
            return max(f(i+1,j,s1,s2), f(i,j+1,s1,s2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        return f(0, 0, text1, text2);
    }
};
TC: O(2^n)
SC: O(n) 

------------------------------------------------------

Recursion + memoisatoin

If you draw the recursion tree, you will see that there are overlapping subproblems. Hence we can apply memoisation

class Solution {
public:
    int t[1002][1002];
    int f(int i, int j, string s1, string s2){
        if(i >= s1.length() || j >= s2.length()) return 0;
        // add memoisation
        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]){
            return t[i][j] =  1 + f(i+1, j+1, s1, s2);
        }
        else{
            return t[i][j] = max(f(i+1,j,s1,s2), f(i,j+1,s1,s2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t, -1, sizeof(t));
        return f(0, 0, text1, text2);
    }
};

// TC: O(n * m)
// SC: O(n * m) + O(n + m) 

// O(n * m) for dp array and O(n + m) for recursion stack

            AB | CD.  -- 1
              /\
          A|CD. AB|C. --- 2
           / \.    
        |CD    A|C   -- 3
                / \
              |C   A|.  -- 4

If you see the depth of the recursion stack is O(n + m). There can be n deletions from s1 and m deletions from s2. Thus the auxilary stack space can go upto O(n + m)

------------------------------------------------------

Tabulation Solution -- to get rid of auxilary stack space

// Tabulation / Iterative / Bottom up approach 

// STEPS to convert recursive to iterative :
// 1. copy the base case
// 2. Write the changing parameters in the oppposite fashion
// 3. Copy the recurrence 

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {        
        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case1: if i == n
        // base case2: if j == m
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0;j--){
                if(text1[i] == text2[j]){
                    dp[i][j] =  1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                    
                }
            }
        }

        return dp[0][0];


    }
};


// TC: O(n * m)
// SC: O(n * m) 

------------------------------------------------------
// Space optimisation -- since ith row only depends on (i+1)th row, we can reduce the matrix to 2 rows


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {        
        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        // base case1: if i == n
        // base case2: if j == m
        int flag = 0;

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0;j--){
                if(text1[i] == text2[j]){
                    dp[flag][j] =  1 + dp[flag^1][j+1];
                }
                else{
                    dp[flag][j] = max(dp[flag^1][j], dp[flag][j+1]);
                    
                }
            }

            flag = flag^1;
        }

        flag = flag^1;
        return dp[flag][0];

    }
};

// TC: O(n * m)
// SC: O(m) 


------------------------------------------------------

printing lcs

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {        
        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case1: if i == n
        // base case2: if j == m
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0;j--){
                if(text1[i] == text2[j]){
                    dp[i][j] =  1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                    
                }
            }
        }

        // dp matrix is filled, now start constructing the lcs 
        int i = 0, j = 0;
        string lcs = "";
        while(i < n && j < m){
            if(text1[i] == text2[j]){
                lcs += text1[i];
                i++;
                j++;
            }
            else{
                if(dp[i+1][j] > dp[i][j+1]){
                    i++;
                }
                else{
                    j++;
                }
            }
        }

        cout << "LCS: " << lcs << endl;

    }
};