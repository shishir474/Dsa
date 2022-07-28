Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2


// O(n^2) solution is correct but will give tle
// sorting(const vector is given -> cannot perform sorting) and using 2 pointer approach will not work, the order of elements is important
// just maintain a map of element and its index. Check if for a given element its complimentary(target - e) is already present in map -> found a pair with target sum, return the res
vector<int> Solution::twoSum(const vector<int> &nums, int target) {
        map<int,int> mp;
        vector<int> res(2,INT_MAX);
        int n = nums.size();
        for (int i=0;i<n;i++){
            if (mp.find(target-nums[i])!=mp.end()){
                if (i+1 < res[1]){ // if curr value of index2 is smaller than the existing index2, update the ans
                    res[0] = mp[target-nums[i]]+1;
                    res[1] = i+1;
                }
                else if(i+1 == res[1] && mp[target-nums[i]]+1 < res[0]){ // if the curr value of index2 is same as that of ans's index2, but index1 is smaller than ans's index1, update the aans
                     res[0] = mp[target-nums[i]]+1;
                }
            }

            // for same index 2, I'm interseted in min value of index 1. so the 1st occurence is of interest to us, not the second one
            if (mp.count(nums[i]) == 0) // storing the first occurence of element(index 1 should be minimized, hence storing the first occurence)
                mp[nums[i]] = i;
        }
        
        if (res[0]==INT_MAX){
            res.clear();
            return res;
        }
        return res;
}
