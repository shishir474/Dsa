Palindrome Partitioning 

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.


Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 
Constraints:

1 <= s.length <= 2000
s consists of lowercase English letters only.



class Solution {
public:
    int t[2002];
    vector<vector<int>> p;

    void isPalindrome(string s){
        int n = s.length();
        for(int i=0;i<n;i++){
            p[i][i] = 1;        // single length strings are always palindrome
        }
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1])
                p[i][i+1] = 1;        // Two length strings are palindrome only if s[i] == s[i+1]
        }
        for(int i=n-3;i>=0;i--){
            for(int j=n-1;j>i+1;j--){
                if(s[i] == s[j] and p[i+1][j-1] == 1){
                    p[i][j] = 1;
                }
            }
        }
    }

    int solve(int i, string s){
        // if s is empty string or s[i:] is already a palindrome -- base case
        if(i >= s.length() or p[i][s.length()-1] == 1) return 0;
        // adding memoisation
        if(t[i] != -1) return t[i];
        

        int ans = INT_MAX;
        for(int k = i; k < s.length(); k++){
            // if s[i..k] is partition is palindrome, 1 cut solve(k+1)
            if(p[i][k] == 1){  // precompute this if s[i..k] is a palindrome
                int tans = 1 + solve(k+1, s);
                ans = min(ans, tans);
            }
        }

        return t[i] =  ans;
    }

    int minCut(string s) {
        // if s is already palindrome
        int n = s.length();
        memset(t, -1, sizeof(t));
        // memset(p, 0, sizeof(p));  // p[i][j] indicates whether string s[i..jj] is a palindrome
        p.resize(n, vector<int>(n,0));
        isPalindrome(s);
        return solve(0, s);
    }
};

// TC: O(n^2)
// SC: O(n) for t[] and O(n^2) for p[][]