// https://leetcode.com/problems/jump-game-ii/

// https://www.youtube.com/watch?v=dJ7sWiOoK7g

Given an array nums, where each element represents the maximum jump length from that position, find the minimum number of jumps needed to reach the last index.


Greedy/BFS Window Intuition
    Think of the array as a series of "levels" or "windows" you can reach with each jump.
    At each step, you want to jump as far as possible within your current reach, to minimize the total number of jumps.
    How the Algorithm Works

Initialize two pointers:

    l (left) and r (right) define the current window of indices you can reach with the current number of jumps.
    Start with l = 0, r = 0 (you are at the start).
    While you haven''t reached the end:

    For every index k in the current window [l, r], calculate the farthest index you can reach: farthest = max(farthest, k + nums[k]).
    After checking all indices in the current window, increment your jump count (res++).
    Move to the next window: set l = r + 1, r = farthest.
    Repeat until your window covers the last index.

Why is this Greedy?
At each jump, you always choose to jump to the farthest possible position within your current reach, ensuring you use the fewest jumps.

Why is this O(n)?
Each index is visited at most once as part of a window, so the total work is linear.



// Sol1; Greedy 
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int l = 0, r = 0; // defines the window: bfs intuition
        while (r < n-1){
            int farthest = 0; // what's the farthest we can go in this [l,r] window
            for (int k=l;k<=r;k++){
                farthest = max(farthest, k + nums[k]);
            }
            l = r+1; // update left pointer
            r = farthest; // update right pointer
            res+=1; // increment jumps
        }

        return res;

    }
};
//    l l   l 
//    r   r   r
// // 2 3 1 1 4
// l = 0
// r = 0
// jumps = 1+1
// TC: O(n)
// SC: O(1)

// l l   l
// r   r   r
// 2 3 0 1 4



// SOl2: Dp
class Solution {
public:
    int t[10002];
    int solve(vector<int>& nums, int i){
        if(i>=nums.size()-1) 
            return 0;
        if (t[i]!=-1)
            return t[i];
        
        int tans = 1e5;
        for(int k=1;k<=nums[i];k++){
            tans = min(tans, solve(nums, i+k));
        }

        return t[i] = tans+1;
    }

    int jump(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }
};

// TC: O(n^2)
// SC: O(n)

// Bottom up DP solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n); // dp[i]: min jumps needed to reach end from index i
        
        dp[n-1] = 0; // base case: already at the last index, need 0 jumps

        // Fill dp from right to left
        for(int i = n-2; i >= 0; i--) {
            
            int bestVal = INT_MAX; // initialize to max, will store min jumps from i
            
            // Try all possible jumps from current index i
            for(int j = 1; j <= nums[i] && i + j < n; j++) {
                bestVal = min(bestVal, dp[i + j]); // find the minimum jumps among all reachable positions
            }
            
            // If it's possible to reach the end from i, set dp[i] = 1 + bestVal
            // Otherwise, keep it as INT_MAX (though problem guarantees reachability)
            dp[i] = (bestVal != INT_MAX) ? 1 + bestVal : INT_MAX;
        
        }
        
        return dp[0]; // answer: min jumps needed from index 0
    }
};

// TC: O(n^2)
// SC: O(n)

// 2 3 1 1 4
// 2 1 2 1 0    

// 2 3    0    1 4
// 2  1 INT_MAX 1 0 

// NOTE: Question states that you can assume you can always reach the last index, so we don't need to handle cases where it's impossible to reach the end.