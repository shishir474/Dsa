413. Arithmetic Slices

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

TC: O(n)
SC: O(n)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans=0,n=a.size();
        int t[n];
        memset(t,0,sizeof(t));
        for(int i=2;i<n;i++){
            if(a[i]-a[i-1]==a[i-1]-a[i-2]){
                t[i]=t[i-1]+1;
            }
            else{
                t[i]=0;
            }
            ans+=t[i];
        }
        
        return ans;
    }
};




TC: O(n^2)
SC: O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans=0,n=a.size();
        for(int i=0;i<n-2;i++){
            if(a[i+1]-a[i] == a[i+2]-a[i+1]){
                int d=a[i+1]-a[i];
                for(int j=i+2;j<n;j++){
                    if(a[j]-a[j-1]!=d) break;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};



SImilar problem
1630. Arithmetic Subarrays

Given m query range [l,r] determine if nums[l...r] can be rearranged to get an arithmatic sequence. A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i

n == nums.length
m == l.length
m == r.length
2 <= n <= 500
1 <= m <= 500

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        
        for (auto i = 0, j = 0; i < l.size(); ++i) {
            vector<int> n(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(n.begin(), n.end());
            for (j = 2; j < n.size(); ++j)
                if (n[j] - n[j - 1] != n[1] - n[0])
                    break;
            res.push_back(j == n.size());
        }
        return res;

    }
};