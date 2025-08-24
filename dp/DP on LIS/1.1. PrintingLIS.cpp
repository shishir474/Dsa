The best solution for finding the LIS uses tabulation method
We declare a dp[n]
where dp[i] signifies the length of the longest increasing subsequence that ends at index i.

arr = {5, 4, 11, 1, 16, 8}
dp[]= {1, 1, 2, 1, 3, 2}
return max(dp[i]) where i belongs to [0, n-1]

Initially dp will be intialised to 1, because that element itself could be involved in the lis 

vector<int> dp(n, 1);
int ans = 1;

for(int ind = 0; ind < n; ind++){
    for(int prev = 0; prev < ind; prev++){
        if(arr[prev] < arr[ind]){
            dp[ind] = max(dp[ind], dp[prev] + 1);
        }
    }
    ans =  max(ans, dp[i]);
}

//  TC: O(n^2)
// SC: O(n)


Lets try to trace back the LIS -- above solution would be needed to print the lis 
arr =  {5, 4, 11, 1, 16, 8}
dp[]=  {1, 1, 2, 1, 3, 2}
hash[]={0, 1, 2, 3, 4, 5}   hash will signify the previous index of the element which is involved in the lis. 
Initially hash[i]= i 

Now as and when I update my dp[], also update the hash[] to store the prev position which you included 
dp[]=  {1, 1, 2, 1, 3, 2}
hash[]={0, 1, 0, 3, 2, 0} 

{16, 11, 5} --> {5, 11, 16}


vector<int> dp(n, 1), hash(n);
int ans = 1;

for(int i = 0; i < n; i++){
    hash[i] = i;
    for(int prev = 0; prev < i; prev++){
        if(arr[prev] < arr[i] && dp[prev] + 1 > dp[i]){
            dp[i] = dp[prev] + 1;
            hash[i] = prev;
        }
    }
    if(dp[i] > ans){
        ans = dp[i];
        last_index = i; 
    }
}

vector<int> lis;

int start = last_index;
while(start != hash[start]){
    lis.push_back(arr[start]);
    start = hash[start];
}
lis.push_back(arr[start]);
reverse(lis.begin(), lis.end());