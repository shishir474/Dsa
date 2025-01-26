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

