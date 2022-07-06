Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
class Solution {
public:
    typedef long long ll;
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> res;
        int n=a.size();
        if(n<4) return res;
        
        sort(a.begin(),a.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l=j+1,r=n-1;
                while(l<r){
                    ll sum = (ll)a[i]+a[j]+a[l]+a[r];
                    if (sum == (ll)(target)){
                        res.push_back({a[i],a[j],a[l],a[r]});
                        while(l<r and a[l]==a[l+1]) l++;
                        while(l<r and a[r]==a[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(sum < (ll)(target)) l++;
                    else r--;
                }
                
                while(j<n-1 and a[j]==a[j+1]) j++;
            }
            while(i<n-1 and a[i]==a[i+1]) i++;
        }
        
        return res;
    }
};