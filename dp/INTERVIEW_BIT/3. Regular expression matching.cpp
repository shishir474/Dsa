int Solution::isMatch(const string A, const string B) {
         int m = A.length(), n = B.length(); // m+1 rows and n+1 cols
    int t[m+1][n+1];
    memset(t,0,sizeof(t));
    t[0][0] = 1;
    for(int i=1;i<=n;i++){
        if (B[i-1]=='*'){
            t[0][i] = t[0][i-2];
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (A[i-1]==B[j-1] || B[j-1]=='?'){// ith and jth char match
                t[i][j] = t[i-1][j-1];
            }
            else if(B[j-1]=='*'){
                
                t[i][j] = t[i][j-2];
                
                if (A[i-1]==B[j-2] || B[j-2]=='?'){ // ith and j-1th char match or j-1th char is .
                    t[i][j] = t[i][j] || t[i-1][j];
                }
            }
            else{
                t[i][j] = 0;
            }
        }
    }

    return t[m][n];
}
