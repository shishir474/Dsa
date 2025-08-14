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


For each index i, I have to find the best value in the next j indices and then use that value to calculate dp[i]
but j will be in range [i+1, min(n-1,i+k)]

       0  1  2 3  4 5
input: 1 -1 -2 4 -7 3
score: 7  6  5 7 -4 3

dequeu is storing indices 
i = 4   deque:  5   index 
i = 3   deque:  5 4 index       dp[i] = dp[5]+nums[i] = 7
        deque:  3
i = 2.  deque:  3,2
i = 1.  deque:  3,1
i = 0.  deque:  1
        deque: 0

dq.front() should be <= i+k
store elements in descending order of values in deque
dp[dq.back()] < dp[i] - we'll keep popping until we find a value that is greater than dp[i] or the deque is empty
dp[i] should be less than or equal to dp[dq.back()]

for(int i=n-2;i>=0;i--){
    while(!dq.empty() and dq.front() > i + k)
        dq.pop_front();
    int mx = dp[dq.front()];
    dp[i] = nums[i] + mx;
    while(!dq.empty() and dp[i] > dp[dq.back()])
        dq.pop_back();
    dq.push_back(i);
}





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
            // store the elements in non increasing order(either it will decrease or remain same)
            while(!q.empty() and dp[i]>=dp[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        return dp[n-1];
    }
};
// The time complexity of deque solution is O(n).
    // Each index is pushed and popped from the deque at most once.
    // All operations inside the loop (push, pop) are amortized O(1).
    // The overall complexity is O(n), which is optimal for this problem.
// Space complexity: O(n) (for the dp array and deque).



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
        pq.push({dp[n-1], n-1});          // value, index  

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
    // Each index is pushed/popped atmost once from the heap.
    // The heap operations (push, pop) take O(log n) time.
    // The loop runs for n indices
// SC: O(n)
    // O(n) for the dp array and heap


// Learning: This deque kind of problems can be solved using priority queue as well, but deque is more efficient in terms of time complexity.
// In both cases, we need a while loop to remove elements that are out of bounds, but deque is more efficient as it allows O(1) time complexity for both push and pop operations, while priority queue has O(log n) time complexity for these operations.
// One advantage of using priority queue is we don't need that second while loop to store the elements in non-increasing order, as the priority queue will always give us the maximum element at the top.