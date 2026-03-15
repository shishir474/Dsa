You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.
// NOTE: that we need to find the min no of moves in the worst case 


// solution1 : using MCM ->  This can be  optimised using binary search

// This solution uses MCM or Partition DP technique to determine the minimum number of attempts needed to find the critical floor.
// We are given N floors and E eggs.
//  K = 1 to N 

// for each K, we'll try dropping an egg from that Kth floor. 
// There will be 2 possible cases:
// case1: egg breaks - this means dropping egg from Kth floor egg is breaking, so we need to check below Kth floor with E-1 eggs
// case2: egg doesn't break - this means we need to check above Kth floor(N - K floors) with E eggs
// Consider the worst case between the two scenarios and then add 1 for the current attempt 

// Now instead of checking linearly each floor one by one, we can use binary search.
// Initial search space [1..N]. If dropping egg from mid floor egg breaks, we'll adjust hi = mid - 1 
// else we'll adjust lo = mid + 1

// NOTE: That we need to find the min no of attempts in the worst case. Hence took max() amongst the two scenarios
// and then used min() to get the final answer.

class Solution {
public:
    int t[10002][102];
    
    int solve(int n, int e){
        if(e == 1) return n;
        if(n == 0 || n == 1) return n;
        
        // adding memoisation
        if(t[n][e]!=-1) return t[n][e];
        
        int ans = INT_MAX;

        // check all the K floors
        for(int k = 1; k <= n; k++){
            // min no of attempts in the worst case -- hence taking max amongst the subproblems
            int tans = 1 + max(solve(k - 1, e - 1), solve(n - k, e)); 
            ans = min(ans, tans); // minimize the worst case value
        }
        
        return t[n][e] = ans;
            
    }

    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return solve(n,k);
    }
};

// TC: O(n * e * n) --> n*e recursive calls and O(n) for each call in the for loop 
// SC: O(n * e) --> dp array of size n*e



// SOLUTION 2: More optimised solution using binary search

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



// Most optimised solution:

// used binary search + optimisation technique where we check if the subproblems are already solved. If yes, then we retrive its value from dp[][] and use it
// else we compute the value using recursion and then we save that value in the dp[][]
// So before making that recursive call, check if that value is already computed.  -- This is a very good technique that can help us to overcome TLE in certain cases 

class Solution {
public:
    int t[10002][102];
    
    int solve(int n, int e){
        if(e == 1) return n;
        if(n == 0 || n == 1) return n;

        if(t[n][e] != -1) return t[n][e];

        int ans = INT_MAX;
        int lo = 1, hi = n;
        while(lo <= hi){
            int m = lo + (hi - lo) / 2;

            int left, right;
            // if subproblem already calculated - use it
            if(t[m - 1][e - 1] != -1){
                left = t[m - 1][e - 1];
            }
            else{  
            // else compute it and save it for future use
                left = solve(m - 1, e - 1);
                t[m - 1][e - 1] = left;
            }

            // if subproblem already calculated - use it
            if(t[n - m][e] != -1){
                right = t[n - m][e];
            }
            else{
             // else compute it and save it for future use
                right = solve(n - m, e);
                t[n - m][e] = right;
            }

            // find the minimum in the worst case   
            int tans = 1 + max(left, right);
            ans = min(ans, tans);

            if(left > right){
                hi = m - 1;
            }
            else{
                lo = m + 1;
            }
            
        }
        
        return t[n][e] = ans;
            
    }
    
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return solve(n,k);
    }
};

Time Complexity: O(n * e * log(n))  -- n * e recursive calls and O(log(n)) for each call in the while loop
Space Complexity: O(n * e)  -- size of the dp[][]
