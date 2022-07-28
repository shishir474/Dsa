Time Complexity: O(n*flog(f))
Space Complexity: O(f*n)
where  f-> is the no of floors and n is the no. of eggs
    
 earlier the TC was O(n*f*f) but bcoz of using Binary search Tc reduced to O(n*flogf)

 // Most optimised solution:
class Solution {
public:
    int t[10002][102];
    
    int solve(int n, int e){
        if(e==1) return n;
        if(n==0 || n==1) return n;
        
        if(t[n][e]!=-1) return t[n][e];
        
        int ans=INT_MAX;
        int lo=1,hi=n;
        while(`lo<=hi){
            int m=lo+(hi-lo)/2;
            
            int left,right;
            if(t[m-1][e-1] != -1){
                left=t[m-1][e-1];
            }
            else{
                left = solve(m-1,e-1);
                t[m-1][e-1]=left;
            }
          
            if(t[n-m][e] != -1){
                right=t[n-m][e];
            }
            else{
                right = solve(n-m,e);
                t[n-m][e]=right;
            }
            
            int tans=1+max(left,right);
            ans=min(ans,tans);
            
            if(left > right){
                hi = m-1;
            }
            else{
                lo = m+1;
            }
            
        }
        
        return t[n][e] = ans;
            
    }
    int superEggDrop(int k, int n) {
        
        memset(t,-1,sizeof(t));
        
        return solve(n,k);
    }
};







// solution2 -> can be  optimised using binary search

class Solution {
public:
    int t[10002][102];
    
    int solve(int n, int e){
        if(e==1) return n;
        if(n==0 || n==1) return n;
        
        if(t[n][e]!=-1) return t[n][e];
        
        int ans=INT_MAX;
        for(int k=1;k<=n;k++){
            int tans=1+max(solve(k-1,e-1),solve(n-k,e));
            ans=min(ans,tans); // minimize the worst case value
        }
        
        return t[n][e] = ans;
            
    }
    int superEggDrop(int k, int n) {
        
        memset(t,-1,sizeof(t));
        
        return solve(n,k);
    }
};