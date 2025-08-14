Solution 1:
// maximum sum subarray - Used Kadanes algorithm
// maximum alternating sum Subarray could start from an even or an odd index

// case 1: If the subarray starts from an even index
// then the problem boils down to finding maximum sum subarray (mss) from (0,n) by negating elements of the odd index

// Case 2; If the subarray starts from an odd index 
// then the problem boils down to finding maximum sum subarray (mss) from (1,n) by negating elements of the even index

// ans = max(sum1, sum2) where sum1 and sum2 represents the max sum in the above 2 cases

// Write a generic kadanes algo and pass the new array(modified) depending on the cases to compute the maximum sum for the given case

// sum1 = max_sum_subarray(arr(0,n)) negate the elements of odd index and then compute
// sum2 = max_sum_subarray(arr(1,n)) negate the elements of even index and then compute

// https://leetcode.ca/2021-10-20-2036-Maximum-Alternating-Subarray-Sum/






Solution 2: Another way of solving this problem

Logic:
The maximum alternating subarray sum is different from the maximum alternating subsequence sum.

Subsequence: You can pick or skip any element (non-contiguous).
Subarray: You must pick a contiguous segment of the array.
Logic for Maximum Alternating Subarray Sum
For a subarray, you must consider every possible contiguous segment, and alternate adding and subtracting elements, starting with either a plus or minus.

// at each index you have 2 options:
either you start fresh or you extend the prev subarray
even[i] means the max altn subarray sum when ith element is at even position in resultant subarray
odd[i] means the max altn subarray sum when ith element is at odd position in resultant subarray

at ith index
even index 
    if fresh start: arr[i]
    else odd + arr[i]

odd index           // odd index means, the ith element is placed at the odd position in the final resultant subarray
    if fresh start: -arr[i]
    else even - arr[i]


    
Transition:

    At each index i:
    even = max(nums[i], odd + nums[i])
    odd = max(-nums[i], even - nums[i])


Key Points
For subarrays, you must consider only contiguous segments.
Use two variables to track the best sum ending at each index, alternating the sign.
At each step, decide whether to start a new subarray or extend the previous one.


int maxAlternatingSubarraySum(vector<int> &nums){
    int n = nums.size();
    long long max_sum = nums[0];
    long long even = nums[0]; // subarray starting at i, first element is +
    long long odd = -nums[0]; // subarray starting at i, first element is -
    for (int i = 1; i < n; ++i) {
        long long new_even = max((long long)nums[i], odd + nums[i]);
        long long new_odd = max(-(long long)nums[i], even - nums[i]);
        even = new_even;
        odd = new_odd;
        max_sum = max({max_sum, even, odd});
    }
    return max_sum;
}

