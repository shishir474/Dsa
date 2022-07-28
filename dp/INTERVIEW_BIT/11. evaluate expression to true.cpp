// isTrue-> 0 means evaluating for true 
const int mod=1003;
int t[155][155][2];
int solve(int i, int j, int isTrue, string s){
    if(i==j){
        if(isTrue==0)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    
    if(t[i][j][isTrue]!=-1) return t[i][j][isTrue];
    
    int ans=0;
    for(int k=i+1;k<j;k+=2){
        if(s[k]=='&'){
            if(isTrue==0){
                ans = (ans + (solve(i,k-1,0,s)*solve(k+1,j,0,s)))%mod;
            }
            else{
                ans = (ans + (solve(i,k-1,0,s)*solve(k+1,j,1,s)) + (solve(i,k-1,1,s)*solve(k+1,j,0,s)) + (solve(i,k-1,1,s)*solve(k+1,j,1,s)))%mod;
            }
        }
        else if(s[k]=='|'){
            if(isTrue==0){
                ans = (ans + solve(i,k-1,0,s)*solve(k+1,j,1,s) + solve(i,k-1,1,s)*solve(k+1,j,0,s) + solve(i,k-1,0,s)*solve(k+1,j,0,s))%mod;
            }
            else{
                ans = (ans + solve(i,k-1,1,s)*solve(k+1,j,1,s))%mod;
            }
        }
        else if(s[k]=='^'){
            if(isTrue==0){
                ans = (ans + solve(i,k-1,0,s)*solve(k+1,j,1,s) + solve(i,k-1,1,s)*solve(k+1,j,0,s))%mod;
            }
            else{
                ans = (ans + solve(i,k-1,1,s)*solve(k+1,j,1,s) + solve(i,k-1,0,s)*solve(k+1,j,0,s))%mod;
            }
        }
    }
    
    return t[i][j][isTrue] = ans;
    
}
int Solution::cnttrue(string A) {
    memset(t,-1,sizeof(t));
    return solve(0,A.length()-1,0,A);
}
