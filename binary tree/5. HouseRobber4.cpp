// https://leetcode.com/problems/house-robber-iv/description/

// https://www.youtube.com/watch?v=1dnyMAKFeoQ

class Solution {
public:
// checks if we can generate a k length non contigous subs such that the mx element of that subs <= mx
    bool check(vector<int>& nums, int k, int mx){
        int total = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= mx){
                i+=1;
                total+=1;
            }
        }
       return total>=k; // indicates I'm able to generate a k length subsequence
    }

    int minCapability(vector<int>& nums, int k) {
        // you cannot sort the array, coz positions will change
        // map<int,int> mp; // value, idx -- we cannot use map as well, because the values in the array could repeat

        // No need to calculate mn and mx as well in the array. Just set mn and mx to nums values range
        int lo = 1, hi = 1e9+5, upper_limit = 0;
        while(lo <= hi){
            int m = lo+(hi-lo)/2;
            if (check(nums, k, m)){// if check() returns True it means we can generate a k length non contiguous subs where the mx element <= m
            // this will be my capability. I want to minimise my capability
                upper_limit = m;
                hi = m-1;
            }
            else{
                lo = m+1;
            }
        }

        return upper_limit;




        // Intuition: Capability is the max value of all the houses we looted, and we want to minimise the capability.
        // So whenever something like minimising and maximising at the same time is mentioned, high chance that binary search could be used.

        // apply binary search over values of the array [min, max]
        // check if you are able to generate a k length non contigous subsequence such that the max value of that subs<=mid
        //  1-10 mid = 5
        //  1-4 mid = 2
        // 1-2 mid 1
        // 2-2 mid 2

        // TC: O(nlogn)
        // SC: O(1)
    }
};

