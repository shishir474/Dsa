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
soluiton: Heve written the intuition in Leetcode DP nb-2
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> v;
        for(int i=0;i<a.size();i++){
            auto it=lower_bound(v.begin(),v.end(),a[i]);
            if(it==v.end())
                v.push_back(a[i]);
            else
                *it=a[i];
        }
        
        return v.size();
    }
};





Print LIS: TC: O(n^2)
SC: O(n);

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