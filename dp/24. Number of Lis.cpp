673. Number of Longest Increasing Subsequence

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 
Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 

Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106
The answer is guaranteed to fit inside a 32-bit integer.


// Intuition:

// l[i] stores the length of longest strictly increasing subs ending at the ith index.
// cnt[i] stores the # of strictly increasing subs of length l[i] ending at the ith index.

// Standard LIS Template
for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
        if(arr[j] < arr[i]){
            l[i] = max(l[i], l[j] + 1);
        }
    }
}

// Now in addition to tracking the length of the longest strictly increasing subs ending at ith index, I'll also track the count of subsequences of length l[i] ending at ith index in cnt[i]

vector<int> l(n,1);     // l[i] will be atleast 1

for(int i = 0; i < n; i++){
    
    for(int j = 0; j < i; j++){
        
        if(arr[j] < arr[i]){
            
            if(l[j] + 1 > l[i]){
                
                // update l[i]
                l[i] = l[j] + 1;
                cnt[i] = cnt[j];        // cnt reset. # of subs ending at i = # of subs ending at jth index
            }
            else if(l[j] + 1 == l[i]){
                // l[i] wont update, but cnt[i] will
                cnt[i] += cnt[j];       // #of subs ending at i will be incremented by cnt[j]    
            }
            
        }
    }

    lis_len = max(lis_len, l[i]);

}

// final ans will be sum of cnt[i] where l[i] == lis_len




class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,1), cnt(n,1);
        int max_len = 1;
        for (int i=1;i<n;i++){
            for (int j=0;j<i;j++){
                if (nums[i] > nums[j])
                {
                    if (t[j]+1 > t[i]){ // update lis and cnt
                        t[i] = t[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if (t[j]+1==t[i]){ // lis will note update, but cnt can
                        cnt[i]+=cnt[j];
                    }
                }
            }
            max_len = max(max_len,t[i]);
        }
        
        // take summation of all cnt where t[i]==max_len
        int res=0;
        for (int i=0;i<n;i++){
            if (t[i]==max_len)
                res+=cnt[i];
        }
        
        return res;
    }
};

// TC: O(N^2) - two nested loops
// SC: O(N) for dp[]

// Follow ups
Longest Increasing Subsequence
Medium
Longest Continuous Increasing Subsequence
Easy
Longest Increasing Subsequence II
Hard
