97. Interleaving String
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 

Follow up: Could you solve it using only O(s2.length) additional memory space?





Pattern 
This is a classic "DP on Strings / Subsequence" pattern.

Why?
You are matching three strings, and at each step, you decide whether to take the next character from A or B to match C.

// This is a 3D Dp solution. We are maintainnig 3 pointers (i,j,k) to keep track of s1, s2, and s3 respectively 
    bool check(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3,    unordered_map<string, bool>& mp)
    {
        // base case
        if (p3 == len3)
        {
            return (p1 == len1 && p2 ==  len2) ? true : false;
        }
        
        string key = to_string(p1) + "-" + to_string(p2) + "-" + to_string(p3);
        if (mp.find(key)!=mp.end())
            return mp[key];
        
        bool ans;
        // key is not present so we need to calculate ans. There are 3 cases
        //case 1:
        if (p1 == len1)
        {
       ans = (s2[p2] == s3[p3]) ? check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1,mp) : false; 
            mp[key] = ans;
            return ans;
        }
        else if(p2 == len2)
        { // case 2
     ans = (s1[p1] == s3[p3]) ? check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1,mp) : false; 
            mp[key] = ans;
            return ans;
        }
        else
        {
            // case 3
            bool one = false, two = false;
            if (s1[p1] == s3[p3])
            {
                one = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1,mp);
            }
            if (s2[p2] == s3[p3])
            {
                two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1,mp);
            }
            mp[key] = one || two;
            return mp[key];
            
        }
        
        
}
int Solution::isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        if (len1+len2 != len3) return false;
          
        unordered_map<string, bool> mp;
        return check(s1,s2,s3,len1,len2,len3,0,0,0,mp);
}




// Sol2: Same solution, but slightly different implementation Used 3 Dp matrix to memoise 
class Solution {
public:
    int dp[102][102][202];
    bool solve(int i, int j, int k, string s1, string s2, string s3){
        // Base case:
        if(k == s3.length()){   // if s3 is exhausted, return true only if both s1 and s2 are also exhausted
            return (i==s1.length() and j==s2.length()) ? true : false;
        }
        // memoisation check
        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool ans = false;
        
        // 3 cases:
        if(i == s1.length()){ // i or s1 is exhausted
            // s2's Jth char must match with s3's kth char and we can recurse for the remaining s2 and s3
            if(s2[j] == s3[k]){
                ans = solve(i, j+1, k+1, s1, s2, s3);
            }
            else return dp[i][j][k] = false;
        }
        else if(j == s2.length()){ //j or s2 is exhausted
            // s1's ith char must match with s3's kth char and we can recurse for the remaining s1 and s3
            if(s1[i] == s3[k]){
                ans = solve(i+1, j, k+1, s1, s2, s3);
            }
            else return dp[i][j][k] = false;
        }
        else{ 
            // both s1 and s2 are available
            if(s1[i] == s3[k]){
                ans = ans || solve(i+1, j, k+1, s1, s2, s3);
            }
            if(s2[j] == s3[k]){
                ans = ans || solve(i, j+1, k+1, s1, s2, s3);
            }
        }

        return dp[i][j][k] = ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, s1, s2, s3);
    }
};

// TC: O(len1 * len2 * len3)
// SC: O(len1 * len2 * len3)




// Space Optimised : 2D Dp solution. (built on prev 3D Dp solution by replacing k with i+j)
// -- Essentially we don't need k. At any point k is nothing but i+j
// Removed the 3rd dimension from the DP matrix and replaced k with i+j
class Solution {
public:
    int dp[102][102];
    bool solve(int i, int j, string s1, string s2, string s3){
        // Base case:
        if(i + j == s3.length()){   // if s3 is exhausted, return true only if both s1 and s2 are also exhausted
            return (i==s1.length() and j==s2.length()) ? true : false;
        }
        // memoisation check
        if(dp[i][j] != -1) return dp[i][j];

        bool ans = false;
        
        // 3 cases:
        if(i == s1.length()){ // i or s1 is exhausted
            // s2's Jth char must match with s3's kth char and we can recurse for the remaining s2 and s3
            if(s2[j] == s3[i + j]){
                ans = solve(i, j + 1, s1, s2, s3);
            }
            else return dp[i][j]= false;
        }
        else if(j == s2.length()){ //j or s2 is exhausted
            // s1's ith char must match with s3's kth char and we can recurse for the remaining s1 and s3
            if(s1[i] == s3[i + j]){
                ans = solve(i+1, j, s1, s2, s3);
            }
            else return dp[i][j] = false;
        }
        else{ 
            // both s1 and s2 are available
            if(s1[i] == s3[i+j]){
                ans = ans || solve(i+1, j, s1, s2, s3);
            }
            if(s2[j] == s3[i+j]){
                ans = ans || solve(i, j+1, s1, s2, s3);
            }
        }

        return dp[i][j] = ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2, s3);
    }
};
// TC: O(len1 * len2)
// SC: O(len1 * len2)


// Iterative DP solution Pending
// dp[i][j] represents whether picking (first i characters from s1) s1[0...i-1] and (first j characters from s2) s2[0...j-1] can form s3[0...i+j-1]

//....



Follow-ups / Similar Interview Problems:
    Longest Common Subsequence (LCS)
    Edit Distance (Levenshtein Distance)
    Distinct Subsequences
    Regular Expression Matching
    Wildcard Matching
    Minimum Insertions/Deletions to make two strings equal
    Shortest Common Supersequence
    String Interleaving with more than two strings
    Counting the number of ways to interleave
    Palindrome Partitioning