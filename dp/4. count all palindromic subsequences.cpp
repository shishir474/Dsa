// Recurrance Relation:

// If s[i] == s[j], the number of palindromic subsequences is: count(i, j) = 1 + count(i + 1, j) + count(i, j – 1).
// The “+1” counts the new palindrome formed by s[i] and s[j].
// If s[i] != s[j], the relation becomes: count(i, j) = count(i + 1, j) + count(i, j – 1) – count(i + 1,j – 1)
// We subtract count(i + 1, j – 1) because it is counted twice.

class Solution{
    public:
    /*You are required to complete below method */
    const int mod = 1e9+7;
    typedef long long ll;

// count(str):  str = c1mc2, where c1->first char, m-> middle part, c2->last char
//      2 CASES:
//         1. IF c1==c2 then count(c1m) + count(mc2) + 1 i.e count of prefix + count of suffix + 1
//         2. IF c1 != c2  then count(c1m) + count(mc2) - count(m) i.e count of prefix + count of suffix - count of middle
   long long int  countPS(string s)
    {
      ll n = s.size();
       ll dp[n][n];
       memset(dp,0,sizeof(dp));
       
       // dp[i][j]  = count of palindromic subsequences in s[i...j] i.e string s from i to j (inclusive)
       // so our ans is in dp[0][n-1] -> count of palindromic subsequences in the entire string
       
       // single length string
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

extension problem:
count distinct palindromic subsequences : LC HARD HAVENT SOLVED THIS ONE

✅ Summary of Recurrence:

    if (s[i] != s[j]) {
        dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
    }
    else {
        // s[i] == s[j]
        if (no s[i] inside i+1..j-1)
            dp[i][j] = 2 * dp[i+1][j-1] + 2;
        else if (only one s[i])
            dp[i][j] = 2 * dp[i+1][j-1] + 1;
        else
            dp[i][j] = 2 * dp[i+1][j-1] - dp[low+1][high-1];
    }