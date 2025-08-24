Longest Bitonic subseuqnce   

Bitonic here means, you can take a subsequence which is first increasing and then decreasing
arr = {1, 11, 2, 10, 4, 5, 2, 1}

All these are bitonic subsequences
{1,2,10,5,2,1}
{1,2,10,4,2,1}
{1,11,10,5,2,1}
{1,11,10,4,2,1}

I want you to find the length of the longest bitonic subsequence.

Does bitonic only mean increase and decrease? No, it can just be increase or just be decrease as well.
This means the resulting subsequence can be either increasing or decreasing or both.

// If I am standing at 10, the length of the lis is 3 including 10.
// Similarly the length of the lds is 4 including 10.
// arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
// lis[] = {1, 2,  2, 3,  3, 4, 2, 1};
// lds[] = {1, 5,  2, 4,  3, 3, 2, 1};

vector<int> lis(n,1), lds(n,1);
// lis[i] signifies the length of the longest increasing subsequnce till index i (including index i -- this is important)
// lds[i] signifies the length of the longest decreasing subsequence from ith to n-1 th index (including the ith index )

int maxi = 1;
for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
        if(arr[j] < arr[i] && lis[j] + 1 > lis[i] ){
            lis[i] = 1 + lis[j];
        }
    }
    maxi = max(maxi, lis[i]);
}

for(int i = n-1; i>=0 ;i--){
    for(int j = i+1; j < n; j++){
        if(arr[i] > arr[j] and lds[j] + 1 > lds[i]){
            lds[i] = lds[j] + 1;
        }
    }
    maxi = max(maxi, lds[i]);
}


for(int i = 0; i < n; i++){
    maxi = max(maxi, lis[i] + lds[i] - 1); // i is included in both hence -1
}

return maxi; 