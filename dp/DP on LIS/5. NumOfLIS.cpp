Number of Longest increasing subsequences

arr[] = {1, 3, 5, 4, 7}

the question that we typically ask at each i,j index is -- can we attach nums[j] to nums[i]?
This is only possible if nums[j] < nums[i]

lis[]   {1, 2, 3, 3, 4}
count[] {1, 1, 1, 1, 2}

There are 2 subsequences of length 4 {1,3,5,7} and {1,3,4,7}

vector<int> dp(n, 1), count(n, 1);

for(int i=1; i<n;i++){
    for(int j = 0; j < i; j++){
        if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
            dp[i] = 1 + dp[j];  // we update the dp[i]
            // so inherit the count
            count[i] = count[j];
        }
        else if(arr[j] < arr[i] && dp[j] + 1 == dp[i]){ 
            // increaset the count
            count[i] += count[j];  // found another subsequence with same length
        }
    }
    maxi = max(maxi, dp[i]);       // lis can be found at any index, hence max(dp[i])
}

int nos = 0;
for(int i = 0; i < n; i++){
    if(dp[i] == maxi){      // add all the lis's
        nos += count[i];
    }
}

return nos;     // this gives you the number of longest increasing subsequences

// TC: O(n^2)
// SC: O(n + n) = O(n) 