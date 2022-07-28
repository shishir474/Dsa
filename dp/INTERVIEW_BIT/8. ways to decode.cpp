Ways to Decode

Medium

116

40
Asked In:
Facebook
Amazon
NoBroker.Com
more
Problem Description
 
 

A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.



Problem Constraints
1 <= |A| <= 105



Input Format
The first and the only argument is a string A.



Output Format
Return a single integer denoting the total number of ways to decode it modulo 109 + 7.



Example Input
Input 1:

 A = "8"
Input 2:

 A = "12"



const int mod = 1e9+7;

int helper(string s,int i,vector<int>& dp){
    if (i>=s.length()) return 1;
    if (s[i]=='0') return 0;
    if (dp[i] != -1) return dp[i];

    int o1=0,o2=0;
    o1 = helper(s,i+1,dp);

    if (i<s.length()-1 && stoi(s.substr(i,2)) <= 26) o2 = helper(s,i+2,dp);
    return dp[i] = (o1%mod + o2%mod)%mod;
}
int Solution::numDecodings(string A) {
    vector<int> dp(100002,-1);
    return helper(A,0,dp);
}
