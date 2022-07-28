813. Largest Sum of Averages

You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.

Note that the partition must use every integer in nums, and that the score is not necessarily an integer.

Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.








Brute force: Generate all partitions, TC: O(k^n) SC: O(n) recursve call stack(depth of recursion tree)


TC: O(n*n*k) sc; o(n*k)
DOUBT: Aisa ho sakta hai ki max score aise kiya ho jisme k paritions use hi nai huye ho. 
class Solution {
public:
    map<pair<int,int>, double> t;
    
    double solve(int i, int k,vector<int>& nums, vector<int>& p){
        
        int n=nums.size();
        
        if(i>=nums.size()) return 0;
        else if(k==1){
            int sum= (i>0) ? p[n-1]-p[i-1] : p[n-1];  // arr[i...n-1] sum
            int size=(n-1)-i+1;
            return sum/(size*1.0);
        }
        else if(k>=nums.size()-i){
            int sum=(i>0) ? p[n-1]-p[i-1] : p[n-1]; // arr[i...n-1] sum
            return sum*1.0;
        }
        else if(t.count({i,k})) return t[{i,k}];
        
        
        double ans=0;
        for(int j=i;j<nums.size();j++){
            //arr[i...j] + solve(j+1,k-1);
            int sum= (i>0) ? p[j]-p[i-1] : p[j];  // arr[i...j] sum
            int size=(j)-i+1;
            double x = sum/(size*1.0);
            double tans = x + solve(j+1,k-1,nums,p);
            ans = max(ans, tans);
        }
        
        
        return t[{i,k}] = ans;
        
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        
        vector<int> p(nums.size());
        p[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            p[i]=p[i-1]+nums[i];
        }
        
        t.clear();
        
        return solve(0,k,nums,p);
    }
};