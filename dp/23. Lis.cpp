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