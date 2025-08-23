1092. Shortest Common Supersequence 
we basically need to return the shortest string that has both str1 and str2 as subsequences. 

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.


Solution:
The idea here is we find the longest common subsequence (lcs) of the two strings.
Then we can construct the shortest common supersequence (scs) using the lcs.
In order to ensure that the length of the supersequence is minimal, we need to take the longest patch of commmon characters from both the strings. 


Length of the supersequnce = n + m - lcs

How to print the supersequence?
In the DP table, if the characters match, we take the character from either string and move diagonally down in the table.
If the characters dont match, we take the character from the string which has the higher value in the DP table and move in that direction.
In the end just append the remaining characters from both strings to the supersequence.

class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
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

        string ans = "";  // constructing shortest supersequence
        int i = 0, j = 0;
        while(i < n and j < m){
            if(text1[i] == text2[j]){
                ans+=text1[i];
                i+=1; j+=1;
            }
            else{
                if(dp[i+1][j] > dp[i][j+1]){
                    ans+=text1[i];
                    i++;
                }
                else{
                    ans+=text2[j];
                    j++;
                }
            }
        }

        while(i < n){
            ans+=text1[i];
            i++;
        }
        while(j < m){
            ans+=text2[j];
            j++;
        }

        return ans;

    }
};