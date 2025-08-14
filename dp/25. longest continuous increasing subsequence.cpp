674. Longest Continuous Increasing Subsequence

Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.


solution:
since its a subarray, it should be continuous. If subsequence we used to go from i-1 till 0 bcoz there diconnectivity is allowed , but since here it is subarray it should be continuous, so a[i]>a[i-1] then only we can extend a[i-1], otherwise dp[i]=1
length will be atleast 1, as there will be atleast 1 length subarrya ending at index i


// We have 2 approaches to solve this problem:

// Sol1: using dp[]
// since we are looking for subarrays(which are contiguous) we are only concerned with prev position's value and we have to determine if we can extend that or not
vector<int> dp(n,1);        // ans will be atleast 1
// dp[i] stores the length of longest strictly increasing subarray ending at the ith index 
for(int i=1;i < n;i++){
    if(arr[i-1] < arr[i]){
        dp[i] = dp[i-1] + 1;
    }
    else{                               // no need of else part, just written for better understanding
        dp[i] = 1;  // reset 
    }
    
    ans = max(ans, dp[i]);
}

// TC: O(n)
// SC: O(n) for DP[]


// Sol2: using 2 pointers -- space optimised
take 2 pointers i and j. i will always point to the starting point of the window. 
initialise j = i+1
keep on incrementing j until a[j] > a[j-1] and j < n
length of the current window = j - i, compare that with ans and update it accordingly
update i to j and again j will be initalised to i+1

int j, ans = 1;         // ans will be atleast 1
for(int i=0; i<n; ){
    j = i+1;
    while(j < n and nums[j-1] < nums[j]) j++;
    ans = max(ans, j-i);
    i = j;
}
// TC: O(n) and SC: O(1)


class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int n=a.size();
        vector<int> t(n,1);
        // t[i]>=1
        
        int ans=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) t[i]=t[i-1]+1;
            ans=max(ans,t[i]);
        }
        
        return ans;
    }
};

// Follow ups
Longest Increasing Subsequence II