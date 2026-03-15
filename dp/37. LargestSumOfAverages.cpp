813. Largest Sum of Averages
You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.


Example 1:

Input: nums = [9,1,2,3,9], k = 3
Output: 20.00000
Explanation: 
The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
Example 2:

Input: nums = [1,2,3,4,5,6,7], k = 4
Output: 20.50000
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 104
1 <= k <= nums.length


Intuition
Greedy Won’t Work:
    You can’t just greedily split at the largest numbers, because sometimes grouping numbers together gives a higher average for that segment.

DP Approach:
    The problem asks for the maximum sum of averages for all possible ways to split the array into up to k parts.
    This is a classic DP scenario:
        At each index, try all possible places to split the next partition.
        For each split, recursively solve the rest of the array with one fewer partition.

State:
    i: Current index in the array.
    k: Number of partitions left.
    The answer for state (i, k) is the maximum sum of averages you can get by partitioning nums[i:] into at most k parts.

Transition:
    For each possible end of the first partition (j from i to n-1):

    Compute the average of nums[i..j].
    Recursively solve for solve(j+1, k-1) (the rest of the array with one fewer partition).
    Take the maximum over all possible j.

Base Cases:
    If k == 1, you must take the whole remaining array as one partition.
    If k >= n-i, you can put each remaining element in its own partition (each average is just the element itself).

Prefix Sums:
    Used to quickly compute the sum of any subarray in O(1) time.

Why Memoization?
    There are overlapping subproblems: the same (i, k) state can be reached via different partitioning paths.
    Memoizing (i, k) avoids recomputation and makes the solution efficient.

Complexity
    Time: O(n² * k) (since for each state, you try all possible next splits)
    Space: O(n * k) for memoization


// we have to exhause all the elements in nums
// i represents nums[i .. (n-1)]
solve(i, k){
    for(int j = i; j<nums.size(); j++){
        // nums[i..j] one partition + solve(j+1, k-1)
        // ans for nums[i..j] partition  = sum(nums[i..j]) / (j-i+1) 
        // sum = (i > 0) ? nums[j] - nums[i-1] : nums[j];

        // ans for a parition is sum of avg of each subarray resulting from the partition
        int tans = ans_for_nums_i_to_j_partition + solve(j + 1, k - 1);
        
        // return the maximum average
        ans = max(ans, tans);
    
    }

    return mp[{i,k}] = ans;

}

// we could have also used a dp[][] of size n * k+1
// i will vary from 0 to n-1 -- n poosible values
// k will vary from k = 0 to k -- k+1 possilbe values

// compute the prefix sum of the array  -- this will enable instant retrieval of the subarray sum

Base cases:
if (i >= nums.size()) return 0;     // no elements left in nums[]
if (k == 1) // only 1 single partition left for nums[i .. (n-1)]
    ans for this would be sum(nums[i .. (n-1)]) / size_of_nums_bw_i_and_n_minus_1
    size_of_nums_bw_i_and_n_minus_1 = (n-1) - i + 1 = n - i
    sum = (i > 0) ? nums[n-1] - nums[i-1] : nums[n-1];
    size = (n - i)
    return sum/size;
if (k >= num_of_elements_remaining){  // each element will have its own partition
// if k == (n - i) where (n-i) is the # of elements from (i..(n-1)) -- one partition will contain one element
// if k > (n - i) if the no of partitions remaining > no of elements left, then one parition will contain one element & some partition will be left empty 
// ans for this combination will be 
    sum = (i > 0) ? nums[n-1] - nums[i-1] : nums[n-1];
    return sum * 1.0

}





Brute force: Generate all partitions, TC: O(k^n) SC: O(n) recursve call stack(depth of recursion tree)


TC: O(n*n*k) sc; o(n*k)
DOUBT: Aisa ho sakta hai ki max score aise kiya ho jisme k paritions use hi nai huye ho. 
class Solution {
public:
    map<pair<int,int>, double> t;
    
    double solve(int i, int k,vector<int>& nums, vector<int>& p){
        
        int n=nums.size();
        
        if(i>=nums.size()) return 0;
        else if(k==1){
            int sum= (i>0) ? p[n-1]-p[i-1] : p[n-1];  // arr[i...n-1] sum
            int size=(n-1)-i+1;
            return sum/(size*1.0);
        }
        else if(k>=nums.size()-i){
            int sum=(i>0) ? p[n-1]-p[i-1] : p[n-1]; // arr[i...n-1] sum
            return sum*1.0;
        }
        else if(t.count({i,k})) return t[{i,k}];
        
        
        double ans=0;
        for(int j=i;j<nums.size();j++){
            //arr[i...j] + solve(j+1,k-1);
            int sum= (i>0) ? p[j]-p[i-1] : p[j];  // arr[i...j] sum
            int size=(j)-i+1;
            double x = sum/(size*1.0);
            double tans = x + solve(j+1,k-1,nums,p);
            ans = max(ans, tans);
        }
        
        
        return t[{i,k}] = ans;
        
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        
        vector<int> p(nums.size());
        p[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            p[i]=p[i-1]+nums[i];
        }
        
        t.clear();
        
        return solve(0,k,nums,p);
    }
};