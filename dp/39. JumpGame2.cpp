// https://leetcode.com/problems/jump-game-ii/

// https://www.youtube.com/watch?v=dJ7sWiOoK7g


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
        vector<int> dp(n);
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            int bestVal = INT_MAX;
            for(int j=1; j<=nums[i] and i+j < n; j++){
                bestVal = min(bestVal, dp[i+j]);
            }
            dp[i] = (bestVal != INT_MAX) ? 1+bestVal : INT_MAX;     // to avoid overflow, we check if bestVal is INT_MAX, it means we can't reach the end from this index
        }
        return dp[0];
    }
};

// TC: O(n^2)
// SC: O(n)

// 2 3 1 1 4
// 2 1 2 1 0    

// 2 3    0    1 4
// 2  1 INT_MAX 1 0 

// NOTE: Question states that you can assume you can always reach the last index, so we don't need to handle cases where it's impossible to reach the end.