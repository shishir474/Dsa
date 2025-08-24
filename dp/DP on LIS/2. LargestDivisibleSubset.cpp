Subsequence vs subset?
In subsequence --> maintaining the order is necessary
In subset --> order is not necessary

Longest Divisible subset 
arr = {1,16,7,8,4}
{1,16,8} is a subsequence 
{1,8,16}, {1,16,8}, {1,7,16} --> all these are subsets (so if you are not following the order and you are taking up any element from the array that is what we call as subset )

we have to print the largest divisible subset. It can be of any order 
{1,16,8,4} or {4,8,16,1} and so on and so forth 

The intersting thing about subsets is you can print any longest divisible subset as long as all pair of elements are divisible 
and since the order of subsets does not matter, we can definitely sort the array and the question then boils down to finding the longest divisible subsequence 

If you remember the code of lis which looked like 

for(int i = 0; i < n; i++){    
    for(int j = 0; j < i; j++){
        if(nums[j] < nums[i] && dp[j] + 1 > dp[i]){
            dp[i] = 1 + dp[j];
            hash[i] = j;            // this is where you came from (using hash[] we can trace back to create the lis)
        }
    }
}

After sorting the array, the problem becomes Finding longest divisble subsequence
for ex: {1, 4, 7, 8, 16}
         1  2
        4 is divisible by 1, hence {1,4}
        7 is not divisible by 4, so we cannot include it
        8 is divisible by 4, and this means 8 is also divisible by 1, hence {1,4,8}
        16 is divisible by 8, which also means its divisible by 4 and 1, hence {1,4,8,16}

        So the benefit that we get by sorting the array is that if we check nums[i] % nums[j]== 0, then we can do update dp[i] to dp[j] + 1, because we're certain that nums[i] will also be divisible by all the previous elements in the subset.


        If you dont sort the array you cannot guarantee that nums[i] will be divisible by all the previous elements in the subset

        Hence sorting the array is a crucial step in this problem. Also sorting does not hurt because in subsets order does not matter 


        ex: {5, 9, 18, 54, 108, 540, 90, 180, 360, 720}
            1.  1.  2.  3.  4.   5.  

            at 90, you will see that 540 is divisible by 90, hence you will add 90 to the subset extending the 540 subsequence.
            But this is not valid because 90 is not divisible by 108, which is part of the subset of 540
            This clearly means that just by checking the divisibility of adjacent elements, we cannot guarantee the validity of the subset.

            But if you sort the array, you can be sure that if nums[i] is divisible by nums[j], then nums[i] will also be divisible by all the previous elements in the subset.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); // IMPORTANT STEP
        
        vector<int> dp(n, 1), hash(n);

        int maxi = 1, last_index = 0;

        // after sorting the question boils down to finding the longest divisible subsequence
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;            // use hash to trace back the lis
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last_index = i;
            }

        }

   
        vector<int> res;
        int curr = last_index;
        while(curr != hash[curr]){
            res.push_back(nums[curr]);
            curr = hash[curr];
        }
        res.push_back(nums[curr]);
        reverse(res.begin(), res.end());

        return res;
    }
};

TC: O(n ^ 2)
SC: O(n) for dp array 