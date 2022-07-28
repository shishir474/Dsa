1043. Partition Array for Maximum Sum
    
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

solution:

0       1       2       3       4       5       6
[1,     15,     7 ,     9,      2,      5,      10]
[1      30      45      54      63                ]

i=3-> max(45+9, 30+18, 1+46)=max(54, 48, 47) = 54

i=4-> max(54+2, 45+18, 30+27)=max(56, 63, 57) = 63



class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int t[n];
        memset(t,0,sizeof(t));
        t[0] = arr[0];
        
        int mx = arr[0];
        
        for (int i=1;i<=k-1;i++){
            mx = max(mx,arr[i]);
            t[i] = mx*(i+1);
        }
        
        for (int i=k;i<n;i++){
            int mx = -1;
            for (int j=1;j<=k;j++){
                mx = max(mx,arr[i-j+1]);
                t[i] = max(t[i], t[i-j] + mx*j);
            }
        }
        
        
        return t[n-1];
    }
};