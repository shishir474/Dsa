Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

class Solution {
public:
    void solve(vector<vector<int> >& res, vector<int>& output, map<int,int>& mp, int n){
        if (n==0){
            res.push_back(output);
            return;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
            if (it->second > 0){
                it->second--;
                output.push_back(it->first);
                solve(res,output,mp, n-1);
                output.pop_back();
                it->second++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        vector<int> output;
        vector<vector<int> > res;
        int n=nums.size();
        solve(res,output,mp,n);
        return res;
    }
};