Subsequences or subsets --> both mean the same thing.

any contigous or non contiguous part of the array is called a subsequence. Subsequence has to follow the order of the original array.
ex: [1,3,2] ---> [1,2] is a subsequence 

[1,3,2,4,5]. target = 4



First solution to tell in interview --
    We can try generating all the subsequences and check if it sums to the target.
    But do we need to generate all the subsequences? No, we can just check if there exists a subsequence that sums to the target.
    Also generating all subsequences is not very efficient. 


// recursive solution
f(idx, sum){
    if(sum == target) return true;
    if(idx >= n) return false;

    return f(idx+1, sum) || f(idx+1, sum + arr[idx]);

}
TC: O(2^n) -- for every element, you have 2 options either you are going to take that into consideration or leave it
SC: O(n) - auxilary stack space. The max depth of the recursion tree is going to be n. 
 -------------------------------------------------------------

// recursion + memoisation. -- using a map to memoise 
f(idx, sum){
    if(sum == target) return true;
    if(idx >= n) return false;
    if(mp.count({idx, sum})) return mp[{idx, sum}];

    return mp[{idx, sum}] = f(idx+1, sum) || f(idx+1, sum + arr[idx]);
}
// TC: O(n * sum) or O(n * target) because the target must lie in range [min_element(all(arr)), sum(arr)]. 
// SC: O(n * target) + O(n)

// instead of sum, I can also take target as my parameter -- works the same way 
map<pair<int,int>, bool> mp;

bool f(int idx, int target){
    if(target == 0) return true;
    if(idx >= n) return false;
    if(mp.count({idx, target})) return mp[{idx, target}];

    if (arr[idx] <= target){ // I have 2 choices -- I can take or leave the current element
        return mp[{idx, target}] = f(idx+1, target) || f(idx+1, target - arr[idx]);
    }
    else{       // just one choice to leave the current element
        return mp[{idx, target}] = f(idx+1, target);
    }
    
}

bool isSubsetSum(vector<int>& arr, int target) {
    mp.clear();                 // reset the map 
    return f(0, target);
}

// TC: O(n * target)
// SC: O(n * target) + O(n)
// O(n * target) for memoization and O(n) for auxiliary stack space
 -------------------------------------------------------------
 Tabulation solution. - to get rid of auxilary stack space

 idx -- 0 to n;
 target -- target to 0;

Rule of converting recurrence relation to Tabulation solution is 
1. Fill the base case. 
2. Find the changing parameters. This will decide the number of nested loops. Reverse the direction in which we traversed in the recursive solution and write the loop. 
3. Copy paste the recurrence & modify it.

In recurrence idx goes from 0 to N. In tabulation idx goes from N to 0
In recurrence target goes from target to 0. In tabulation target goes from 0 to target

int dp[n+1][target+1];
// 1st basecase target == 0;
for(int i=0; i<=n ;i++) t[i][0] = true;
// 2nd base case idx == n
for(int j = 1; j<=target; j++) t[n][j] = false;

for(int i = n-1; i>=0; i--){
    for(int j = 1; j<=target; j++){
        if (arr[i] <= j){ // I have 2 choices -- I can take or leave the current element
            t[i][j] = t[i+1][j] || t[i+1][j-arr[i]];
        }
        else{       // just one choice to leave the current element
            t[i][j] = t[i+1][j];
        }
    }
}
return t[0][target];


-----------------------------------------------------------------------------

Space optimisation:
Since the ith row only depends on the (i-1)th row, we can reduce the space complexity to O(target) by maintaining only 2 rows in our dp array.

int dp[2][target+1];
// 1st basecase target == 0;
for(int i=0; i<=1 ;i++) t[i][0] = true;
// 2nd base case idx == n
for(int j = 1; j<=target; j++) t[1][j] = false;
    
int flag = 0;
for(int i = n-1; i>=0; i--){
    for(int j = 1; j<=target; j++){
        if (arr[i] <= j){ // I have 2 choices -- I can take or leave the current element
            t[flag][j] = t[1-flag][j] || t[1-flag][j-arr[i]];
        }
        else{       // just one choice to leave the current element
            t[flag][j] = t[1-flag][j];
        }
    }
    flag = 1-flag;
}
flag = 1-flag;
return t[flag][target];

// TC: O(n * target)
// SC: O(target) 


-----------------------------------------------------------------------------

f(idx, target){
    if(target == 0)  return true;
    if(idx < 0) return false;

    if(dp[idx][target] != -1) return dp[idx][target];

    if(arr[idx] <= target)
        return dp[idx][target] = f(idx-1, target) || f(idx-1, target-arr[idx]);
    else
        return dp[idx][target] = f(idx-1, target);
}
f(n-1, target);   // till the n-1 th index, have we found the target -- this is what f(n-1,target) will represent


// The below iterative solution is corresponding to this recurrence solution 

vector<vector<int>> dp(n+1, vector<int>(target+1, -1)); // since you need to initialise with -1 to indicate unvisited state, hence create dp array of type int and not bool 

// base case 
for(int i=0; i<=n ;i++)
    dp[i][0] = 1;

for(int j=1; j<=target; j++)
    dp[0][j] = 0;

for(int i=1; i<=n; i++){
    for(int j=1; j<=target; j++){
        if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        else
            dp[i][j] = dp[i-1][j];
    }
}

return dp[n][target];
// TC: O(n * target)
// SC: O(n * target) 