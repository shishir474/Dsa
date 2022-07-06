Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6


vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
    // your code here
    vector<int> res;
    deque<int> q;
    int i;
    for(i=0;i<k;i++){
        while(!q.empty() and arr[i]>=arr[q.back()]){ 
            q.pop_back(); 
        }
        q.push_back(i);
    }
    
    for(;i<n;i++){
        res.push_back(arr[q.front()]);
        while(!q.empty() and q.front()<=i-k){
            q.pop_front();
        }
        while(!q.empty() and arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    res.push_back(arr[q.front()]);
    return res;
    
}