// Palindrome Partitioning 1:
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

class Solution{
    public:
    solve(string s, int i, vector<vector<string>> &res, vector<string> &curr) {
        if(i >= s.length()){
            res.push_back(curr);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(isPalindrome(s, i, j)) {
                curr.push_back(s.substr(i, j - i + 1));
                solve(s, j+1, res, curr);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        solve(s, 0, res, curr);
        return res;
    }

// Time and Space complexity Analysis:
// TC: At each index we have 2 options, cut or not cut leading to 2^n possibilities in the worst case and isPalindrome also takes O(n) time
// Hence overall tc is O(n*2^n)

// SC: Max depth of the recursive call stack space is going to be n, which is basically length of the string
// Hence overall SC is O(n)
}




// Palindrome Partitioning 2:
Given a string s, return the minimum cuts needed to partition s such that every substring of the partition is a palindrome.

class Solution {
public:
// solve(i) -> find ans for s[i...n-1].. since n-1 is always fixed we reduced the matrix to one dimension 
    int solve(string s, int i, vector<int>& dp, vector<vector<int> >& p){
        int n=s.length();
        if(i>=n || p[i][n-1]==1) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans=INT_MAX;
        for(int k=i;k<n;k++){
            if(p[i][k]){
                int tans = solve(s,k+1,dp,p) + 1;
                ans = min(ans, tans);
            }
        }
        
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<int> > p(n, vector<int>(n,0));
        // p[i][j]=1 -> s[i....j] is a palindrome
        // p[][] is precomputed to determine if s[i...k] is a plaindrome or not inside solve function 
        
        for(int i=0;i<n;i++){
            p[i][i]=1;                  // single character is a palindrome
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){           // two consecutive same characters are a palindrome
                p[i][i+1]=1;
            }
        }
        for(int i=n-3;i>=0;i--){
            for(int j=n-1;j>i+1;j--){
                if(s[i]==s[j] && p[i+1][j-1]==1){           // if the first and last characters are same and the substring in between is a palindrome
                    p[i][j]=1;
                }
            }
        }
            
        vector<int> dp(n,-1);
        return solve(s,0,dp,p);
    }
    
    TC: O(n^2);
    sc: O(n^2);
    
    earlier sols had TC of o(n^3);
};







O(n^3) solution:

    bool isPalindrome(string s,int i, int j){
        while (i<j){
            if (s[i]!=s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    int t[2002][2002];
    int solve(string s,int i, int j){
        if (i>j) return 0;
        if (t[i][j]!=-1) return t[i][j];
        if (i==j || isPalindrome(s,i,j)){
            t[i][j]=0;
            return 0;
        } 
       
        
        int ans=INT_MAX;
        for (int k=i;k<j;k++){
            if (isPalindrome(s,i,k)){
                int right;
               if (t[k+1][j]==-1){
                   right = solve(s,k+1,j);
                   t[k+1][j] = right;
               }
               else{
                   right = t[k+1][j];
               }
              int tempans = 1+right;
              ans = min(ans,tempans);
            }
        }
        
        return t[i][j] = ans;
    }
        
int Solution::minCut(string s) {
    // if the string is empty or already a palindrome, no cuts are needed
    if (s.length()==0 || isPalindrome(s,0,s.size()-1)) return 0;
    memset(t,-1,sizeof(t));
    return solve(s,0,s.size()-1);
}


// recursion states:
// if the string is empty or already a palindrome, no cuts are needed return 0;
// I''ll define a solve function that takes the string and two indices i and j, representing the current substring s[i...j].

// PSUEDO CODE:
// solve(string s, int i, int j){  
//     if i > j, return 0; // base case
//     if i == j or s[i...j] is a palindrome, return 0
//     int ans = INT_MAX;
//     for(int k=i;k<j;k++){
//         if(isPalindrome(s, i, k)) {
//             int tans = solve(s, k + 1, j) + 1; 
//             ans = min(ans, tans);
//         }
//     }
// }

// Next step is to add memoization to avoid recomputing results for the same substring.
// We can use a 2D array dp where dp[i][j] stores the minimum cuts needed for the substring s[i...j].
// If dp[i][j] is already computed, we can return it directly.
// If not, we compute it using the logic above and store the result in dp[i][j].
// The final result will be stored in dp[0][n-1] where n is the length of the string s.

// solve(string s, int i, int j){  
//     if i > j, return 0; // base case
//     if dp[i][j] != -1, return dp[i][j]; 
//     if i == j or s[i...j] is a palindrome, return 0
//     int ans = INT_MAX;
//     for(int k=i;k<j;k++){
//         if(isPalindrome(s, i, k)) {
//             int tans = solve(s, k + 1, j) + 1; 
//             ans = min(ans, tans);
//         }
//     }
// }

// TC of the this solution is O(n^3) because we are checking for palindromes in O(n) time for each substring, and we have O(n^2) pairs of (i, j) to consider.
// SC is O(n^2) for the dp array and O(n) for the recursion stack space, leading to an overall space complexity of O(n^2).

// One optimization we can do is to precompute whether each substring s[i...j] is a palindrome or not, which can be done in O(n^2) time.
// This way, we can avoid the O(n) palindrome check in the inner loop, reducing the overall time complexity to O(n^2).
// We can use a 2D array p where p[i][j] is true if s[i...j] is a palindrome.
// We can fill this array in O(n^2)
// and then use it in our solve function to check for palindromes in O(1) time.
// The final solution will have a time complexity of O(n^2) and a space complexity of O(n^2).





// palindrome partitioning 4: Implement later
