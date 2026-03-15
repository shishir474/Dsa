1043. Partition Array for Maximum Sum
Medium

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length


// THis is a MCM based solution where we try partitioning at each point and while we are doing that we also keep track of the max element in that partition in mx and then compute the ans for that partition
// ans for current partition: mx * (k1 - i + 1) + solve(k1 + 1, k, arr)
// where (k1 - i + 1) is the length of the current partition
// solve(k1 + 1, k, arr) gives us the max sum for the rest of the array after the current partition
class Solution {
public:
    int t[502];
    int solve(int i, int k, vector<int>& arr){
        if(i >= arr.size()) return 0;
        // adding memoisation
        if(t[i] != -1) return t[i];

        int ans = INT_MIN, mx = INT_MIN, n = arr.size(); 
        // i is the starting point in my arr. From here I can consider subarray of length atmost k
        for(int k1 = i; k1 < min(n, i + k); k1++){     // applying cuts at each point  
            mx = max(mx, arr[k1]);       // mx tracks the max value in the partition
            int tans = mx * (k1 - i + 1) + solve(k1 + 1, k, arr) ;   // ans for the current partition
            ans = max(ans, tans);       // update the final ans
        }

        return t[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(t, -1, sizeof(t));
        return solve(0, k, arr);
    }
};

// TC: O(N * K) since there will be N recursive calls corresponding to each index and O(K) work during each call in the for loop
// SC: O(N)






// Another way to look at this could be 

                i->
1,  4,  1,  5,  7,  3,  6,  1,  9,  9,  3
1   8   12  20  max(7+20, 7*2 + 12, 7*3 + 8, 7*4 + 1) = 29


// I want to determine the optimal partitioning strategy to maximize the sum of the array after partitioning it into subarrays of length at most k.
// NOTE: that we don't need to find the actual partitions.

// Max allowed partition size is k.
// we can calculate the ans for first k indices
// for each index from i = k to n-1,
    // we keep on finding the maximum value in the last k elements
    // and calculate the maximum sum for that partition.


Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

solution:

0       1       2       3       4       5       6
[1,     15,     7 ,     9,      2,      5,      10]
[1      30      45      54      63                ]

i=3-> max(45+9, 30+18, 1+45)=max(54, 48, 46) = 54

i=4-> max(54+2, 45+18, 30+27)=max(56, 63, 57) = 63



class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int t[n];
        memset(t,0,sizeof(t));
        t[0] = arr[0];
        
        int mx = arr[0];

        // calculating ans for first k indices
        for (int i = 1; i <= k - 1; i++) {
            mx = max(mx, arr[i]);
            t[i] = mx * (i + 1);
        }

        // calculating ans for remaining indices
        for (int i = k; i < n; i++){
            
            int mx = -1;
            // finding max in last k elements

            for (int j = 1; j <= k; j++) {
                mx = max(mx, arr[i - j + 1]);
                t[i] = max(t[i], t[i - j] + mx * j);
            }
        }
        
        
        return t[n-1];
    }
};
// TC: O(n*k)
// SC: O(n)
// where n is the size of the array and k is the maximum allowed partition size.


// CONCLUSION:
// Both the solutions have the same time and space complexity, but their way of solving is different.
// The first solution uses a MCM based intuition where we try partitioning at each point and while we are doing that we also keep track of the max element in that partition in mx and then compute the ans for that partition
// In the second solution, we calculate the maximum sum for the first k indices and then for each index from k to n-1, we keep on finding the maximum value in the last k elements and calculate the maximum sum for that partition.