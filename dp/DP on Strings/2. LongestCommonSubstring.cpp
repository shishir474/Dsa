s1= "abcd"
s2= "abzd"

longest common substring: "ab"
longest commong subsequence: "abd" 


Recursive Solution:

We can write a recursive solution but we would need a 3rd variable to check the continuity of the substring.
This 3D dp solution is not recommended. We will directly write a iterative solution.


Tabulation Solution

// For this problem we will directly write the tabulation solution. 

int longestCommonSubstring(string text1, string text2) {        
    int n = text1.size(), m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] =  1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    // longest commong substring will be maximum value in the entire dp matrix
    return ans;

}

// TC: O(n * m)
// SC: O(n * m)


------------------------------------------------------
// Space optimisation -- since ith row only depends on (i+1)th row, we can reduce the matrix to 2 rows

int LCSubStr(string &text1, string &text2)
{

    int n = text1.size(), m = text2.size();

    vector<vector<int>> dp(2, vector<int>(m+1, 0));
    
    int ans = 0;

    int flag = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[flag][j] =  1 + dp[flag^1][j-1];
            }
            else{
                dp[flag][j] = 0;
            }
            ans = max(ans, dp[flag][j]);
        }
        flag = flag^1;
    }

    flag = flag^1;
    // longest commong substring will be maximum value in the entire dp matrix
    return ans;
}

// TC: O(n * m)
// SC: O(m)
