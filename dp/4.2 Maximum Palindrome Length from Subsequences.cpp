1771. Maximize Palindrome Length From Subsequences

You are given two strings, word1 and word2. You want to construct a string in the following manner:

Choose some non-empty subsequence subsequence1 from word1.
Choose some non-empty subsequence subsequence2 from word2.
Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.

A subsequence of a string s is a string that can be made by deleting some (possibly none) characters from s without changing the order of the remaining characters.

A palindrome is a string that reads the same forward as well as backward.

 
Example 1:

Input: word1 = "cacb", word2 = "cbba"
Output: 5
Explanation: Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.
Example 2:

Input: word1 = "ab", word2 = "ab"
Output: 3
Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.
Example 3:

Input: word1 = "aa", word2 = "bb"
Output: 0
Explanation: You cannot construct a palindrome from the described method, so return 0.
 

Constraints:

1 <= word1.length, word2.length <= 1000
word1 and word2 consist of lowercase English letters.


// Intuition:
// here we'll use the intutition which we used in the longest palindromic subsequence problem. 
i.e for string s[l..r] to find the longest palindromic subsequence, 
if s[l] == s[r]:
    2 + solve(s, l+1, r-1);
else:
    max(solve(s,l,r-1), solve(s,l+1,r));

Base case:
if (l > r) return 0;        // empty string
if (l == r) return 1;       // single length palindrome

// add memoisation to avoid recomputation

The only thing which we need to take care is that the final string should span across both the strings word1 and word2

// in the if case - if this condidtion holds true, 
the ans will be only updated if l < x and r >= x where x is the starting point of second string 
s = s1 + s2 
x = s1.length()




class Solution {
public:
    vector<vector<int>> dp;  // DP array for memoization

    int lps(string &s, int l, int r, int &ans, int x) {
        // base cases
        if (l > r) return 0;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];

        // choices
        int len = 0;
        if (s[l] == s[r]) {
            len = 2 + lps(s, l + 1, r - 1, ans, x);

            // Update ans only when the chars are part of both strings
            if (l < x && r >= x) {
                ans = max(ans, len);
            }
        } else {        // Adding (l < x && r >= x) in the else case will NOT work as intended.
            len = max(lps(s, l, r - 1, ans, x), lps(s, l + 1, r, ans, x));
        }

        return dp[l][r] = len;
    }

    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int l = 0;
        int r = s.size() - 1;
        int ans = 0;
        int x = word1.size();  // Boundary between word1 and word2
        int n = s.size();

        dp.resize(n, vector<int>(n, -1));  // Initialize dp array with -1

        lps(s, l, r, ans, x);

        return ans;
    }
};


Adding (l < x && r >= x) in the else case will NOT work as intended.

Why?
In the else case (s[l] != s[r]), you are not forming a new palindrome by matching s[l] and s[r].
You are just taking the maximum length from two subproblems: either skipping s[l] or skipping s[r].

Even if you check (l < x && r >= x) here, the value you get is just the best from the left or right, not a palindrome that is guaranteed to use both sides at this step.

What does the if (s[l] == s[r]) block do?
Only when s[l] == s[r] do you actually extend a palindrome by 2, and only then can you be sure that the palindrome includes both word1 and word2 if l < x && r >= x.

That''s why you update ans only in this block.
If you update ans in the else block...
You might be picking up a palindrome that is entirely within word1 or entirely within word2, because the max of the two subproblems could be from either side, not necessarily spanning both strings.


what should be my ans if word1 = "abc" and word2 = "de"?
ans would be 0, There is no palindrome that can be formed using at least one character from both word1 and word2.
This example demonstrates why updating ans only in the if block is crucial. If you were to update ans in the else block, you might incorrectly count a palindrome that does not span both strings even if l < x and r >= x 