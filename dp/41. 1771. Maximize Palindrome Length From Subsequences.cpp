// 1771. Maximize Palindrome Length From Subsequences

// You are given two strings, word1 and word2. You want to construct a string in the following manner:

// Choose some non-empty subsequence subsequence1 from word1.
// Choose some non-empty subsequence subsequence2 from word2.
// Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
// Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.

// A subsequence of a string s is a string that can be made by deleting some (possibly none) characters from s without changing the order of the remaining characters.

// A palindrome is a string that reads the same forward as well as backward.

// Example 1:

// Input: word1 = "cacb", word2 = "cbba"
// Output: 5
// Explanation: Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.
// Example 2:

// Input: word1 = "ab", word2 = "ab"
// Output: 3
// Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.
// Example 3:

// Input: word1 = "aa", word2 = "bb"
// Output: 0
// Explanation: You cannot construct a palindrome from the described method, so return 0.
 

// Constraints:

// 1 <= word1.length, word2.length <= 1000
// word1 and word2 consist of lowercase English letters.

class Solution {
public:
    vector<vector<int>>dp; // DP array for memoisation

    // pass string s as global variable: Otherwise gives Memory Limit Exceed error
    int lps(string &s, int l, int r, int &ans, int x){
        // base cases
        if(l > r) return 0;
        if(l == r) return 1;
        if(dp[l][r] != -1) return dp[l][r];

        // choices
        int len = 0;
        if(s[l]==s[r]){
            len = 2 + lps(s, l+1, r-1, ans, x);

            // update ans only when the char are part of both the strings
            if(l < x and r>=x){
                cout<<l<<" "<<r<<" "<<len<<endl;
                ans = max(ans, len);
            }
        }
        else{
            len = max(lps(s, l, r-1, ans, x), lps(s, l+1, r, ans, x));
        }

        return dp[l][r] = len;
    }
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int l = 0;
        int r = s.size() - 1; 
        int ans = 0;
        int x = word1.size(); // boundary
        int n = s.size();
        
        dp.resize(n, vector<int>(n,-1));

        lps(s,l,r,ans,x);
        
        return ans;
    }
};

// TC: O(n * n)
// SC: O(n*n)
// where n = word1.length()+word2.length()