// https://leetcode.com/problems/decode-ways-ii/
639. Decode Ways II

Given a string s containing digits and possibly * (which can be any digit from 1 to 9), count the number of ways to decode it into letters (A-Z, mapped as 1-26).
Return the answer modulo 1e9+7.

Example 1:

Input: s = "*"
Output: 9
Explanation: The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
Each of these can be decoded to the strings "A", "B", "C", "D", "E", "F", "G", "H", and "I" respectively.
Hence, there are a total of 9 ways to decode "*".
Example 2:

Input: s = "1*"
Output: 18
Explanation: The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
Hence, there are a total of 9 * 2 = 18 ways to decode "1*".
Example 3:

Input: s = "2*"
Output: 15
Explanation: The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
"21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".
 

Constraints:

1 <= s.length <= 105
s[i] is a digit or '*'.



Key Observations

Single Character Decoding:
    Only possible if s[i] != '0'
    If s[i] is a digit 1-9, it can be decoded as a single letter.
    If s[i] is *, it can be any of '1' to '9', so 9 possibilities.

Two Character Decoding:
    Only possible if (i + 1 < s.length() and (s[i] == '1' or s[i] == '2' or s[i] == '*'))
    If s[i] and s[i+1] together form a number between 10 and 26, they can be decoded as a letter.
    If either is *, you must consider all valid combinations:
        1* can be 11-19 (9 ways).
        2* can be 21-26 (6 ways).
        ** can be 11-19 and 21-26 (15 ways).

Zero Handling:
    '0' cannot be decoded alone, only as part of '10' or '20'.


// Recursive Solution gives MLE passes:200/250 test cases passed 

Why Recursion/Memoization Fails for Large Inputs
    The number of subproblems is linear, but the recursion stack and repeated calls cause Memory Limit Exceeded (MLE) for large strings.
    Iterative DP is efficient and avoids stack overflow.


// class Solution {
// public:
// // you are given a string, you have to determing the number of ways in which you can decode this string.
// // Note that the string can also contain * -> which can be decoded as any digit from (1 to 9)
// // you have to return the number of possible decodings

//     int t[100001];
//     const int mod = 1e9+7;

//     int solve(string s, int i){
//         if(i==s.length())                // found 1 possible partition
//             return 1;
//         if (t[i] != -1)
//             return t[i];


//         long long op1=0, op2 = 0;
//         // single character decoding
//         if (s[i]!='0'){
//             if(s[i]=='*'){
//                 op1 = (9LL * solve(s, i + 1))%mod;
//             }
//             else{
//                 op1 = solve(s, i + 1);
//             }
//         }
//         // cout<<"idx "<<i<<" "<<"op1 "<<op1<<endl;

//         // two character decoding
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
//                 else if (s[i+1]>='0' and s[i+1]<='6'){   // can be decoded only if stoi(s.substr(i, 2)) <= 26
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





// Follow Up:
Decode Ways:
    String only contains digits. count the number of ways to decode it into letters (A-Z, mapped as 1-26). 
    
    class Solution {
public:
    int t[101];
    int solve(string s, int i){
        if(i>=s.length()) return 1;
        if(t[i] != -1) return t[i];
        
        int ans = 0;
        if(s[i] != '0'){
            ans += solve(s, i+1);
        }
        if(s[i] != '0' and i < s.length()-1 and stoi(s.substr(i,2)) < 27){
            ans += solve(s, i+2);
        }

        return t[i] = ans;
    }
    int numDecodings(string s) {
        memset(t, -1, sizeof(t));
        return solve(s, 0);
    }
};