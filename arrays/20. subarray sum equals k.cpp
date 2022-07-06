Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

class Solution {
public:
    int subarraySum(vector<int>& arr, int sum) {
        int n=arr.size();
           map<int,int> mp; // prefix sum->freq
        int psum=0,ans=0;
        for(int i=0;i<n;i++){
            psum+=arr[i];
            if(psum==sum) ans++;
            if (mp.count(psum-sum)){
                ans+=mp[psum-sum];
            }
            mp[psum]++;
        }

        return ans;
    }
};