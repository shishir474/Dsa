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
            p[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                p[i][i+1]=1;
            }
        }
        for(int i=n-3;i>=0;i--){
            for(int j=n-1;j>i+1;j--){
                if(s[i]==s[j] && p[i+1][j-1]==1){
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