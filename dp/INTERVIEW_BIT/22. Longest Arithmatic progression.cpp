int Solution::solve(const vector<int> &A) {
    int n=A.size();
    if(n<=2) return n;
    vector<vector<int> > dp(n, vector<int>(n,-1));
    
    map<int,int> mp;
    
    // k i j
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dp[i][j] = 2;
            int diff = A[j] - A[i];
            int need = 2*A[i]-A[j];
            if(mp.count(need)){
                dp[i][j] = max(dp[i][j], 1+dp[mp[need]][i]); 
            }
            
            ans = max(ans, dp[i][j]);
        }
        mp[A[i]] = i;
    }
    
    return ans;
    
}
