// 1306. Jump Game III

// Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

// Notice that you can not jump outside of the array at any time.

 

// Example 1:

// Input: arr = [4,2,3,0,3,1,2], start = 5
// Output: true
// Explanation: 
// All possible ways to reach at index 3 with value 0 are: 
// index 5 -> index 4 -> index 1 -> index 3 
// index 5 -> index 6 -> index 4 -> index 1 -> index 3 
// Example 2:

// Input: arr = [4,2,3,0,3,1,2], start = 0
// Output: true 
// Explanation: 
// One possible way to reach at index 3 with value 0 is: 
// index 0 -> index 4 -> index 1 -> index 3
// Example 3:

// Input: arr = [3,0,2,1,2], start = 2
// Output: false
// Explanation: There is no way to reach at index 1 with value 0.
 

// Constraints:

// 1 <= arr.length <= 5 * 104
// 0 <= arr[i] < arr.length
// 0 <= start < arr.length
class Solution {
public:
    // any index will be vis only once
    int vis[50002];
    bool solve(vector<int>& arr, int i){
        if(i<0 || i>=arr.size() || vis[i]==true) return false;
        if(arr[i]==0) return true;
        
        vis[i]=1;
        
        return solve(arr,i+arr[i]) || solve(arr, i-arr[i]); 
    }
    bool canReach(vector<int>& arr, int start) {
        memset(vis,0,sizeof(vis));
        return solve(arr,start);
    }
};



// USING BFS:
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        int vis[arr.size()];
        memset(vis,0,sizeof(vis));
        
        q.push(start);
        while(!q.empty()){
            int f=q.front(); 
            q.pop();
            if(vis[f]){
                continue;
            }
            vis[f]=true;
            if(arr[f]==0) return true;
            if(f+arr[f] < arr.size()){
                q.push(f+arr[f]);
            }
            if(f-arr[f] >= 0){
                q.push(f-arr[f]);
            }
        }
        
        return false;
    }
};