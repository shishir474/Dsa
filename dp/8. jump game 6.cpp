JUMP GAME 6:

You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

 

Example 1:

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
Example 2:

Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
Example 3:

Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0
 

Constraints:

1 <= nums.length, k <= 105
-104 <= nums[i] <= 104



USES CONCEPT OF SLIDING WINDOW MAXIMUM  -> FOR THIS USE DEQUE
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> q;
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        q.push_back(0);
        for(int i=1;i<nums.size();i++){
            // remove index that are out of bound 
            while(!q.empty() and q.front()<i-k){
                q.pop_front();
            }
            // q.front() index has the max value
            dp[i]=dp[q.front()]+nums[i];
            // store the elements in strictly decreasing order
            while(!q.empty() and dp[i]>=dp[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        return dp[n-1];
    }
};



/// @brief  Using heap
class Solution {
public:
// iterative O(n^2) solution toh likh lunga
// optimised using heap, instead of checking every j for every i, keep track of the the largest dp[i] values in a heap and calculate dp[i] from right to left. 
// When the largest value is out of bounds of the current index, remove it and keep checking.
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n]; // dp[i] = max score that one can acheive starting from index i and ending at index n-1
        dp[n-1] = nums[n-1];
        
        priority_queue<pair<int,int>> pq; // max heap
        pq.push({dp[n-1], n-1});

        for (int i=n-2;i>=0;i--){
            while(!pq.empty() and pq.top().second > i + k)
                pq.pop();
            int mx = pq.top().first;
            dp[i] = nums[i] + mx;
            pq.push({dp[i], i});
        }

        return dp[0];

        
    }
};

// TC: O(nlogn)
// SC: O(n)