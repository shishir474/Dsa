516. Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.



// Solution 1:
 string s [l .. r] we have to find the longest palindromic subs in this string 
1st aapproach is to find the longest common subs of s and reverse(s) --> This will give you the length of the longest palindromic subs in s

// For some reason, solution 1 is more straightforward
    // It directly applies the LCS concept without additional complexity


    
// Solution 2:
// This approach highlights the actual thinking of forming a palindromic subsequence

// Throws MLE (memory limit error) for some reason

class Solution {
public:
    vector<vector<int>> dp;

    // computes the longest palindromic subs in string s[l..r]
    int solve(string s, int l, int r){
        if (l > r) return 0;        // empty string
        if (l == r) return 1;       // single length palindrome
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        if(s[l] == s[r]){
            ans = 2 + solve(s, l+1, r-1);
        }
        else{
            ans = max(solve(s,l,r-1), solve(s,l+1,r));
        }

        return dp[l][r] = ans;

    }

    int longestPalindromeSubseq(string s) {
        // string s [l .. r] we have to find the longest palindromic subs in this string 
        // 1st aapproach is to find the longest common subs of s and reverse(s) --> This will give you the length of the longest palindromic subs in s

        // 2nd approach 
        // string s[l..r]      l and r represents the endpoints of the string
        // if(s[l] == s[r])    // this 2 will form the endpoint of my potential palindromic subs
        //     2 + solve(l+1,r-1);     // and the length of longest palindromic subs in the middle 
        // else
        //     max(solve(l,r-1), solve(l+1,r))  

        // BASE CASE:
        // if (l > r) return 0;        // empty string
        // if (l == r) return 1;       // single length palindrome

        // add memoisation to avoid recomputing the same (l,r) again 

        int n = s.length();
        dp.resize(n, vector<int>(n, -1));   

        return solve(s, 0, s.length() - 1);


    }
};