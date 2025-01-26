// https://leetcode.com/problems/decode-ways-ii/



// Recursive Solution gives MLE passes:200/250 test cases passed 

// class Solution {
// public:
// // you are given a string, you have to determing the number of ways in which you can decode this string.
// // Note that the string can also contain * -> which can be decoded as any digit from (1 to 9)
// // you have to return the number of possible decodings
//     int t[100001];
//     const int mod = 1e9+7;

//     int solve(string s, int i){
//         if(i==s.length())
//             return 1;
//         if (t[i] != -1)
//             return t[i];


//         long long op1=0, op2 = 0;
//           // single length
//         if (s[i]!='0'){
//             if(s[i]=='*'){
//                 op1 = (9LL * solve(s, i + 1))%mod;
//             }
//             else{
//                 op1 = solve(s, i + 1);
//             }
//         }
//         // cout<<"idx "<<i<<" "<<"op1 "<<op1<<endl;

//         // two length
//         if((s[i]=='1' or s[i]=='2' or s[i]=='*') and i+1 < s.length()){
//             if(s[i]=='1'){
//                 if(s[i+1]=='*'){
//                     op2 = (9LL * solve(s, i + 2))%mod;
//                 }
//                 else{
//                     op2 = solve(s, i+2);
//                 }
//             }
//             else if (s[i]=='2'){
//                 if(s[i+1]=='*'){
//                     op2 = (6LL * solve(s, i+2))%mod;
//                 }
//                 else if (s[i+1]>='0' and s[i+1]<='6'){
//                     op2 = solve(s, i+2);
//                 }
//             }
//             else if(s[i]=='*'){
//                 if(s[i+1]=='*')
//                     op2 += (15LL * solve(s, i+2))%mod;
//                 else if (s[i+1]>='0' and s[i+1]<='6')
//                     op2 += (2LL * solve(s, i+2))%mod;
//                 else if (s[i+1]>='7' and s[i+1]<='9')
//                     op2 += solve(s, i+2);
//             }

//         }

//         // cout<<"idx "<<i<<" "<<"op2 "<<op2<<endl;


//         return t[i] =  (op1 + op2)%mod;
//     }
//     int numDecodings(string s) {
//         memset(t, -1, sizeof(t));
//         return solve(s, 0);

//     }
// };



// Only iterative solution works for this problem
typedef long long ll;
class Solution {
public:

    int numDecodings(string s) {
        // recursive solution is not working:
        // WIll have to write iterative code
        int n = s.length();
        const int mod = 1e9 + 7;

        vector<ll> dp(n+1, 0);
        dp[0] = 1;

        for (int i=1;i<=n;i++){
            // single length string
            if (s[i-1]!='0'){
                if (s[i-1]=='*')
                    dp[i] = (dp[i] + (9LL*dp[i-1])%mod)%mod;
                else
                    dp[i] = (dp[i] + dp[i-1])%mod;
            }
            // 2 length string
            if (i > 1){
                if (s[i-2]=='1'){
                    if (s[i-1]=='*')
                        dp[i] = (dp[i] + (9LL * dp[i-2])%mod)%mod;
                    else 
                        dp[i]  = (dp[i] +  dp[i-2])%mod;
                }
                else if(s[i-2]=='2'){
                    if (s[i-1]=='*')
                        dp[i] = (dp[i] + (6LL * dp[i-2])%mod)%mod;
                    else if (s[i-1]>='0' and s[i-1]<='6')
                        dp[i] = (dp[i] + dp[i-2])%mod;
                }
                else if(s[i-2]=='*'){
                    if (s[i-1]=='*')
                        dp[i] = (dp[i] + (15LL * dp[i-2])%mod)%mod;
                    else if (s[i-1]>='0' and s[i-1]<='6')
                        dp[i] = (dp[i] + (2LL * dp[i-2])%mod)%mod;
                    else if (s[i-1]>='7' and s[i-1]<='9')
                        dp[i] = (dp[i] + dp[i-2])%mod;
                }
            }
        }


        return dp[n];
    }
};
