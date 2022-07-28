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