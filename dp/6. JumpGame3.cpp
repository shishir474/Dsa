Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.

// from ith index, I can jump to i + arr[i] or i - arr[i]
// and since each index is visited only once(we used visited array to make sure we dont visit already visited vertex), hence the time complexity is O(n) and space complexity is also O(n) for visited array

// TC: O(n)
// SC: O(n)
// Uses DFS
class Solution {
public:
    vector<bool> vis;
    bool dfs(int i, int n, vector<int>& arr){
        if(arr[i] == 0) return true;
        vis[i] = true;
        if(i+arr[i] < n and !vis[i+arr[i]]){
            if(dfs(i+arr[i], n, arr)) return true;
        }
        if(i-arr[i] >= 0 and !vis[i-arr[i]]){
            if(dfs(i-arr[i], n, arr)) return true;
        }
        return false;

    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vis.resize(n,false);
        return dfs(start, n, arr);
    }
};


// USES BFS
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<bool> vis;
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vis.resize(n,false);
        queue<int> q;
        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            if(arr[f] == 0) return true;
            if(f + arr[f] < n and !vis[f+arr[f]]){
                vis[f+arr[f]] = true;
                q.push(f+arr[f]);
            }
            if(f - arr[f] >=0 and !vis[f-arr[f]]){
                vis[f-arr[f]] = true;
                q.push(f-arr[f]);
            }
        }

        return false;

    }
};