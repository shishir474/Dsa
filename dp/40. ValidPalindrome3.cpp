// LC Premium 

// https://github.com/doocs/leetcode/blob/main/solution/1400-1499/1406.Stone%20Game%20III/README_EN.md

Description
Given a string s and an integer k, return true if s is a k-palindrome.

A string is k-palindrome if it can be transformed into a palindrome by removing at most k characters from it.

 

Example 1:

Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
Example 2:

Input: s = "abbababa", k = 1
Output: true


Constraints:

1 <= s.length <= 1000
s consists of only lowercase English letters.
1 <= k <= s.length


To solve this problem, we can use dynamic programming to find the length of the longest palindromic subsequence (LPS) in the given string. If the length of the LPS is at least equal to the length of the string minus k, then we can remove at most k characters to make the string a palindrome.

Here's the plan:

1. Create a 2D DP array dp[i][j] that represents the length of the longest palindromic subsequence in the substring s[i..j].
2. Initialize the DP array:
   - If i == j, then dp[i][j] = 1 (a single character is a palindrome).
   - If s[i] == s[j], then dp[i][j] = dp[i+1][j-1] + 2 (expand the palindrome).
   - If s[i] != s[j], then dp[i][j] = max(dp[i+1][j], dp[i][j-1]) (skip one character).
3. Fill the DP array using the above rules.
4. Finally, check if the length of the LPS is at least equal to the length of the string minus k.


class Solution {
public:
    bool canBeKPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the DP array
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1; // Single character is a palindrome
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // Check if we can remove at most k characters
        int lps = dp[0][n - 1];
        return (n - lps) <= k;
    }
};

The time complexity is O(n^2) and the space complexity is O(n^2). Here, n is the length of the string s.