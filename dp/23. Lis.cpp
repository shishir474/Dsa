300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?


// TC: O(n^2) solution brute force
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> t(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]){
                    t[i]=max(t[i],t[j]+1);
                }
            }
            ans=max(ans,t[i]);
        }
        
        return ans;
    }
};

TC: O(nlogn)
SC: O(n)
// INTUITION: 

// This solution uses a greedy approach with binary search O(nlogn) tc
// 1. v vector does not represent a valid LIS at all times but ensures that its length is always equal to length of the LIS
// 2. replacing elements in v ensures that we are greedy in keeping v as tight as possible. This is critical because a smaller v allows us to build longer LIS for subsequent elements
// 3. Length of the v represents the length of the LIS
// 4. Replacing elements in v ensures that future elements have the maximum opportunity to extend the LIS.
// 5. Why upper bound wont work can be understood with the help of the following examples:
// nums = [0,1,0,3,2,3] --[0], [0,1], [0,0]
// nums = [7,7,7,7,7,7,7]
// If we use upper_bound, the final resulting sequence will not strictly increasing. 
// Instead if we use lower bound 
// nums = [0,1,0,3,2,3] --[0], [0,1], [0,1], [0,1,3], [0,1,2], [0,1,2,3]

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> v;
        for(int i=0;i<a.size();i++){
            auto it=lower_bound(v.begin(),v.end(),a[i]);
             // If new element is greater, append to `v`
            if(it==v.end())
                v.push_back(a[i]); 
            else
                *it=a[i];  // Replace the element to maintain smallest possible sequence
        }
        
        return v.size();
    }
};





// Print LIS: TC: O(n^2)
// SC: O(n);
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> t(n,1);
        int ans=1,idx=-1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]){
                    t[i]=max(t[i],t[j]+1);
                }
            }
            if(t[i]> ans){
                ans=t[i];
                idx=i;
            }
        }
        
        vector<int> v;
        int len=ans;
        for(int j=idx;j>=0;j--){
            if(t[j]==len){
                v.push_back(a[j]);
                len--;
                if(len==0) break;
            }
        }
        
        reverse(v.begin(),v.end());
        for(auto i: v) cout<<i<<" ";
        return ans;
    }
};



// Follow up's:
Increasing Triplet Subsequence
Medium
Russian Doll Envelopes
Hard
Maximum Length of Pair Chain
Medium
Number of Longest Increasing Subsequence
Medium
Minimum ASCII Delete Sum for Two Strings
Medium
Minimum Number of Removals to Make Mountain Array
Hard
Find the Longest Valid Obstacle Course at Each Position
Hard
Minimum Operations to Make the Array K-Increasing
Hard
Longest Ideal Subsequence
Medium
Maximum Number of Books You Can Take
Hard
Longest Increasing Subsequence II
Hard
Find the Maximum Length of a Good Subsequence II
Hard
Find the Maximum Length of a Good Subsequence I
Medium
Find the Maximum Length of Valid Subsequence I
Medium
Find the Maximum Length of Valid Subsequence II
Medium
Longest Subsequence With Decreasing Adjacent Difference