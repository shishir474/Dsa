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

// Brute force
// TC: O(m * nlogn)
// SC: O(n)
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

// Optimised solution

// In order to check if a subarray is an arithmatic sequence 
// while its true that any arithmatic sequence is sorted we don't need to exploit this fact to determine if arr is an arithmetic sequence.

// TC: O(m * n)
// SC: O(n)

// Let's say arr has a length of n, and we have the maximum element in arr as max and the minimum element as min.
// If arr were to form an arithmetic sequence, then the difference diff that defines the sequence must be equal to  
// (max−min) / (n-1)

// Why? Because min must be the first element of the sequence and max must be the final element of the sequence. Thus, if we started at min and iterated to max, we would require n−1 iterations. On each iteration, our value would increase by diff (by definition).
// If diff is not an integer, then we cannot have an arithmetic sequence. If it is, how do we verify if arr is an arithmetic sequence or not?

class Solution {
public:
    bool check(vector<int>& arr) {
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        unordered_set<int> arrSet;
        
        for (int num : arr) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            arrSet.insert(num);
        }
        
        if ((maxElement - minElement) % (arr.size() - 1) != 0) {
            return false;
        }
        
        int diff = (maxElement - minElement) / (arr.size() - 1);
        int curr = minElement + diff;
        
        while (curr < maxElement) {
            if (arrSet.find(curr) == arrSet.end()) {
                return false;
            }
            
            curr += diff;
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        
        return ans;
    }
};