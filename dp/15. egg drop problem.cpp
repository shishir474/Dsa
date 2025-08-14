You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.


// recurence relation:
t[n][e] = stores min no of moves required to find the critical floor with n floors and e eggs.
if we drop from mid floor, we've 2 possibilities:
1. egg breaks: we need to check below mid floor with e-1 eggs. so t[mid-1][e-1]
2. egg doesn''t break: we need to check above mid floor with e eggs. so t[n-mid][e]

we'll apply a binary search to find the optimal mid floor to drop the egg from, which minimizes the worst case number of moves.
lo =1, hi = n
while(lo <= hi){
    mid = lo + (hi - lo) / 2;
    int left = t[mid-1][e-1]; // egg breaks
    int right = t[n-mid][e]; // egg doesn't break
    if(left > right){
        hi = mid - 1; // egg breaks: we need to check below mid floor
    } else {
        lo = mid + 1; // egg doesn't break: we need to check above mid floor
    }
    // ans for this iteration will depend on the maximum of left and right, plus one for the current move.
    int tans = 1 + max(left, right); // 1 move for dropping the egg
    ans = min(ans, tans); // minimize the worst case value
}

// base cases:
if e == 1, we need to drop the egg from each floor, so return n
if n == 0 or n == 1, we need to drop the egg from the only floor available, so return n(basically 0 or 1 depending on the case).



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
        while(lo<=hi){
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