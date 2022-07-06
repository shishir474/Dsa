Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
Note: You have to return the answer module 109+7;
 

Example 1:

Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"

Solution:
CountPS(i,j)
// Every single character of a string is a palindrome 
// subsequence 
if i == j
   return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
Else if (str[i] == str[j)]
   return   countPS(i+1, j) + countPS(i, j-1) + 1;

else
   // check for rest sub-sequence and  remove common
   // palindromic subsequences as they are counted
   // twice when we do countPS(i+1, j) + countPS(i,j-1)
   return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1)

   
class Solution{
    public:

    const int mod = 1e9+7;
    typedef long long ll;

   long long int  countPS(string s)
    {
        ll n = s.size();
        ll dp[n][n];
        memset(dp,0,sizeof(dp));

        for(ll i=0;i<n;i++){
           dp[i][i] = 1;
        }
       
       // two length string -> 4 subs (empty one is not considered) ab -> "","a","b","ab" -> 2 , "cc" -> "","c","c","cc" -> 3
        for(ll i=0;i<n-1;i++){
           if (s[i]==s[i+1]){
               dp[i][i+1] = 3;
           }else{
               dp[i][i+1] = 2;
           }
        }
       
        for(ll i = n-3;i>=0;i--){
           for(ll j=i+2;j<n;j++){
               if (s[i]==s[j]){
                   dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1)%mod;
               }else{
                    ll a = dp[i][j-1] + dp[i+1][j];
                    ll b = dp[i+1][j-1];
                    dp[i][j] = (a - b + mod)%mod;
               }
           }
        }
    
       return dp[0][n-1];
    }
     
};
