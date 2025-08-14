446. Arithmetic Slices II - Subsequence
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.

Constraints:

1  <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1


// Here we have to count the total no of arithmatic subsequences (not subarrays) of length atleast 3.

// Approach
For each index i, maintain a map dp[i] where dp[i][diff] is the number of arithmetic subsequences ending at index i with common difference diff.
For each pair (j, i) where j < i, calculate diff = nums[i] - nums[j].
Add all subsequences ending at j with difference diff to dp[i][diff], and also count the pair (j, i) as a new subsequence of length 2.
Only subsequences of length ≥ 3 are counted in the final answer.

// Explanation
cnt is the number of arithmetic subsequences ending at j with difference diff (length ≥ 2).
When you extend those by nums[i], they become length ≥ 3, so you add cnt to the result.
dp[i][diff] is incremented by cnt + 1 (the +1 is for the new pair (j, i)).

How do we make sure that we are only considering subsequences of length atleast 3

The count dp[j][diff] represents the number of subsequences of length at least 2 ending at j with difference diff.
When we extend these by nums[i], they become subsequences of length at least 3 ending at i.
So, in the code, we only add dp[j][diff] to the result, which ensures we count only subsequences of length ≥ 3.
result += dp[j][diff]; // Only sequences of length >= 3 are counted here
The new pair (j, i) (length 2) is tracked in dp[i][diff] but not added to the result.
Thus, only subsequences of length at least 3 are included in the final answer.


// We used vector of map where dp[i] is a map & dp[i][diff] stores the no of subs of length atleast 2 ending at index i with difference diff.
// For each index we are tracking the # of subs ending at that particular index, now this difference could be anything and its range is not known. hence we choose vector<unordered_map<int,int>> dp(n)
// dp[i] --> i is the index
// and this map's key is difference diff.

// Also looking at the constraints, looks like difference could go out of bounds, hence used long long for difference

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0; // size should be atleast 3
        vector<unordered_map<long long, int>> dp(n); // dp[i] is a map, dp[i][diff] stores the # of subsequences of length atleast 2 ending at index i with difference diff
        int result = 0;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                long long diff = (long long)nums[i] - nums[j];
                // #of subs of length atleast 2 ending at index j with difference diff is dp[j][diff].
                // so we can extend all these subs by appending nums[i] and their length will be atleast 3
                int cnt = dp[j][diff];
                dp[i][diff] += cnt + 1;     // (+1 for the new pair(j,i)). diff could repeat hence used +=
                result+=cnt;
            }
        }

        return result;
    }
};
// Time Complexity: O(n²)
// Space Complexity: O(n²) (in the worst case)

