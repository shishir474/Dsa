int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

class Solution{
    public:

    bool isValid(int idx,int i, int j,string s,vector<vector<char>>& mat){
        if(i>=0 and i<mat.size() and j>=0 and j<mat[0].size() and mat[i][j]==s[idx]) return true;
        return false;
    }
        
    int dfs(int idx,int i,int j,string s,vector<vector<char>>& mat){
        if(idx >= s.length()) return 1;
        
        char c=mat[i][j];
        mat[i][j]='$';

        int ans=0;

        for(int k=0;k<4;k++){
            int newi=i+X[k], newj=j+Y[k];
            if(isValid(idx,newi,newj,s,mat)){
                ans+=dfs(idx+1,newi,newj,s,mat);
            }
        }
        
        mat[i][j] = c;
        return ans;
    }
        
    
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        int m=mat.size(), n=mat[0].size();
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==target[0]){
                    ans+=dfs(1,i,j,target,mat);
                }
            }
        }
        
        return ans;
         
    }
};





// optimizations: 
Instead of vis array use this strategy to mark a cell vis -> converts sol from O(N*N) space to O(1) space
    char c=mat[i][j];
    mat[i][j]='$';
    .
    .
    .
    mat[i][j] = c; // backtrack

2. Never return before marking/reverting the changes back in the backtracking step. Instead of direct return save the ans in a var, backtrack and then return the ans
