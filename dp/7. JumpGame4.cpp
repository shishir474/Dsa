Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 

Constraints:

1 <= arr.length <= 5 * 104
-108 <= arr[i] <= 108


class Solution {
public:
// from i, I can go to all the below positions
//  i+1, i-1, all indices j where nums[j] == nums[i]

// problem with this solution is we'll stuck in an infinite loop, we need a mechanism such that an index which is visited is not visited again
//     int t[100002];
//     int solve(int i, vector<int> &arr, map<int,vector<int>> &mp){
//         cout<<i<<" ";
//         int n = arr.size();
//         if(i==n-1) return 0;
//         if(t[i] != -1) return t[i];

//         int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
//         if(i+1 < n){
//             op1 = solve(i+1, arr, mp);
//         }
//         if(i-1 >= 0){
//             op2 = solve(i-1, arr, mp);
//         }
//         for(int k=0;k<mp[arr[i]].size();i++){
//             int pos = mp[arr[i]][k];
//             op3 = min(op3, solve(pos, arr, mp));
//         }

//         return min({op1,op2,op3}) + 1;

//     }
//     int minJumps(vector<int>& arr) {
//         // value -> positions map
//         map<int, vector<int>> mp;
//         for(int i=0;i<arr.size();i++){
//             mp[arr[i]].push_back(i);
//         }
//         memset(t,-1,sizeof(t));
//         return solve(0, arr, mp);
//     }
// };


    int minJumps(vector<int>& arr) {
        int n = arr.size();
        // value -> positions map
        map<int, vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool> vis(n, false);
        queue<pair<int,int>> q;  // index, steps;
        q.push({0,0});
        vis[0] = true;

        while(!q.empty()){
            int i =q.front().first;
            int steps= q.front().second;
            q.pop();
            if(i == n-1) return steps;

            if(i+1 < n and !vis[i+1]){
                vis[i+1] = true;
                q.push({i+1, steps+1});
            }

            if(i-1 >= 0 and !vis[i-1]){
                vis[i-1] = true;
                q.push({i-1, steps+1});
            }
            
            // This if condition is not necessary, but it optimises the solution
            // as we process only the first time we encounter a value, and not for every index
            // This way we avoid processing the same value multiple times, which can lead to unnecessary computations
            // Iterating through this loop just to get rejected by !vis[pos] is not efficient
            if(mp.count(arr[i])){              // optimisation step: process only for the first time
                for(int k=0;k<mp[arr[i]].size();k++){
                    int pos = mp[arr[i]][k];
                    if(!vis[pos]){
                        vis[pos] = true;
                        q.push({pos, steps+1});
                    }
                }
                mp.erase(arr[i]); // erase this key, so that it is not processed again
            }
            
        }

        return 0;
    }
};

// 0,0 
// 1,1
// 4,1
// 2,2
// 3,2
// 5,2