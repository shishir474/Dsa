Brute force:
dp[i]->longest arithmatci sequence that ends at given index with diff d

int dp[n];
dp[0]=1;
for(int i=1;i<n;i++){
    dp[i]=1;
    for(int j=i-1;j>=0;j--){
        if(a[i]-a[j]==d){
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
}

OPTIMISED:
SINCE we are interested in pos that has a[i]-d, why dont we maintain map<int,vector<int>> pos
which stores element and its position. So that we can directly jump on to that index.
// dp[i] stores the length of the longest arithmatic subs ending at ith index with given difference diff

unordered_map<int,vector<int> > mp; // value -> vector of positions
        for (int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        
        int max_len=1;
        int dp[arr.size()];
        dp[0]=1;

        for (int i=1;i<arr.size();i++){
            int b=  arr[i]-difference;
            dp[i]=1;
            // Instead of iterating over each elements before index i and see if the difference is D, we will directly explore elements that has got difference D
            // This can be acheived if we maintain a positions map that tracks elements and its vector of postions
            if (mp.count(b)){// direclty jump to index which has a[i]-d
                for (int j=0;j<mp[b].size();j++){
                    if (mp[b][j]<i)
                        dp[i] = max(dp[i],dp[mp[b][j]]+1);
                }
            }
            // dp[i] is evaluated
            max_len = max(max_len,dp[i]);
        }
        
        return max_len;
        




arr[j]-d,  ....   arr[i]
SO ideally we are looking for all positions j where arr[i] - d is present, before i 

Other way could be, we start at ith index and we look for all positions j where arr[i] + d is present on right hand side.

I don''t think there is a much difference in both this approaches 






class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 1, n = arr.size();
        vector<int> dp(n,1);    // length of arithmatic subs ending at ith index is atleast 1
        
        // TC is O(n^2)
        // for(int i=0;i<n;i++){
        //     for(int j=0;j < i;j++){
        //         // I'm essentially looking for all Js where a[i] - a[j] == difference 
        //         if(arr[i]-arr[j] == difference){
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        //     res = max(res, dp[i]);
        // }

        // one thing we could probably do is, maintain a positions map that will allow us to directly jump to those positions or Js where arr[i] - arr[j] == difference and j < i
        unordered_map<int, vector<int>> mp;     // value --> positions vector
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        for(int i=0;i<n;i++){
            vector<int> pos = mp[arr[i] - difference];
            // I'm essentially looking for all Js where a[i] - diff is present on left side
            for(auto j: pos){
                if (j < i){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;

    }
};
// TC: is still O(N^2) but with positions map, we have reduced the complexity from O(N) linear to only the positions where arr[i]-diff is present
// Space Complexity:
// The space complexity is O(N) for the dp array, plus O(N) for the positions map