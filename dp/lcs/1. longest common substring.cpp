 Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB"
Output: 1
 
 
 int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int t[n][m];
        memset(t,0,sizeof(t));
        // first col initialise
        int ans=0;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[0]){
                t[i][0]=1;
                ans = 1;
            }
        }
        // first row 
        for(int j=1;j<m;j++){
            if(s1[0]==s2[j]){
                t[0][j]=1;
                ans = 1;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(s1[i]==s2[j]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = 0;
                }
                ans = max(ans,t[i][j]);
            }    
        }
        
        return ans;
        
    }