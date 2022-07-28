Return the length of longest arithmatic subsequence

sol1 gives TLE ON leetcode, so used vectors instead of map. 

INTERVIEW_BIT
Solution1: Using maps
TC:O(n^2)
SC: O(n^2)

0<=A[i]<=1e9; // since diff will be very huge we cannot use vector wala solution. Have to use maps only

int Solution::solve(const vector<int> &A) {
    int n = A.size();
    vector<map<int,int> > v(n);
    if (n==1) return 1;
    int ans=2;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d = A[j]-A[i];
            if (v[i].count(d)){
                v[j][d] = v[i][d] + 1;
            }   
            else{
               v[j][d] = 2;
            }
            ans = max(ans, v[j][d]);
        }
    }

    return ans;
}




LEETCODE Solution
Solution 2: Using vectors
To avoid the TLE, instead of using a map, we can make it really big DP.

Because
2 <= nums.length <= 1000
0 <= nums[i] <= 500

We simply put:
int diff = nums[i] - nums[j] +500;

this will ensure the index: diff is between 0 and 1000, since the maximum can be 1000, the size of the one dimensional dp should be 1001:

if nums[i]=0 and nums[j]=500 so to maintain diff>=0 we add 500
and if nums[i]=500 and nums[j]=0 then difference can become 1000, so in worst case we have to maintain 1001 sized dp


    class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
           int n=nums.size(), res=0;
    
        vector<vector<int>> dp(n, vector<int>(1001,0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                int diff = nums[i] - nums[j] +500; // +500 ensures diff is always >=0
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
                res = max(res, dp[i][diff]);
            }
        }

        return res;
    }
};