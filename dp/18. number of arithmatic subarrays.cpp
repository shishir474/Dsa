413. Arithmetic Slices

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.


// We have to find the count of total no of arithmatic subarrays
// Count the # arithmatic subarrays ending at each index and then add that to final ans
// one constraint that problem sets is arithmatic subarray size should be atleast 3
// so if n < 3 return 0

// dp[i] stores the # arithmatic subarrays till ith index 
// How to check if ith element is a part of an arithmatic subarray. 
if arr[i] - arr[i-1] == arr[i-1] - arr[i-2]: true then yes and #of arithmatic subarrays till ith will be #of arithmatic subarrays till i-1 + 1
else dp[i] = 0
                              0,1,2,3,4  
ex:                           1,2,3,4,5
#of arithmatic subarrays      0,0,1,2,  

index 2: 1,2,3
index 3: [2,3,4], [1,2,3,4] 
index 4: [3,4,5], [2,3,4,5], [1,2,3,4,5] 
// i.e t[i] = 1 + t[i-1]
1 for [a[i-2],a[i-1],a[i]]
and then a[i] can be appended at the end of t[i-1] subarrays


1   3   5   7   9
0   0   1   2.  3

final ans: 1 + 2 + 3 = 6



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


// Solution2:
I will start from i = 0, and run till i < n-2 (basically till third last element)
If difference between arr[i],arr[i+1] and arr[i+2] is constant, then we can start an arithmatic subarray from i.
Now the total count of subarrays from i will be 
I know the differenc, which should be d = arr[i+1] - arr[i]
Run another loop j from i+2 till j < n
arr[j] - arr[j-1] should be equal to d, if not break else increment the count 

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

// Brute force solution 
// Here you sort each range and then check if that subarray is a arithmatic subarray
//  There are m queries, for each query you will sort the array from l[i] to r[i] which takes O(nlogn) in worst case and then we have m queries
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

// Trick here is 
// Given an array, you do not need to sort it to determine if this array would make an arithmatic array.
// We can simply check this by calculating the diff and then check if all the elements starting from the min all the way to max are present in the set --> which can be done in O(n) time -- if we use unordered_set (since we just need to check the presence of an element)
// If the array was an arithmatic, then its difference d must be (max_element(arr) - min_element(arr)) / n-1
// which means (max_element(arr) - min_element(arr)) % (n-1) == 0