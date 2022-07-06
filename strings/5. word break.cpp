 bool solve(int idx, string s, unordered_set<string>& set,vector<int>& dp){
        if(idx==s.length()) return true;
        if(dp[idx]!=-1) return dp[idx];
        
        bool ans = false;
        for(int i=idx;i<s.length();i++){
            if(set.count(s.substr(idx,i-idx+1))){
                if (solve(i+1,s,set,dp)) {
                    ans = true; break;
                }
            }
        }
        
        return dp[idx] = ans;
    }
    
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> set(wordDict.begin(),wordDict.end());
    vector<int> dp(s.length(),-1);
    return solve(0,s,set,dp);
}

Brute force TC: O(n*2^n) SC: O(n)
2^n calls in brute force as for every index in worst case, we have 2 options,
either break or not break. Max depth of recursion tree is n(length of the string). Hence SC is O(n)
Optimised using dp-memoisaion. Now only n unique calls and for each call O(n) loop iteration. Hence TC:O(n*n) and SC O(n)
