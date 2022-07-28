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

unordered_map<int,vector<int> > mp;
        for (int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        
        int max_len=1;
        int dp[arr.size()];
        dp[0]=1;

        for (int i=1;i<arr.size();i++){
            int b=  arr[i]-difference;
            dp[i]=1;
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
        






















class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int n=arr.size();
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
        
        // constructing the arithmatic subsequence from i will give TLE. consider case 1,2,3,4,....1000
        // instead at i, check if a[i]+d,exists in map & if it does, then at all pos(lets call it j) at the right side of i mark the length as dp[j] = max(dp[j], dp[i]+1)
        // if we are following this strategy then its better to move backwards.That way we dont even have to initalise our dp[] with 1.
        
        for(int i=0;i<n;i++){
            
            int b=arr[i]+d;
            
            if(mp.count(b)){
                
                for(int j=0;j<mp[b].size();j++){
                    if(mp[b][j]>i){
                        dp[mp[b][j]] = max(dp[mp[b][j]], dp[i]+1);
                    }
                }
                
            }
        }
        
    //  for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};