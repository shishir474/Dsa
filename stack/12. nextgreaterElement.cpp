next greater element on right
[1 3 2 4]
Output:
3 4 4 -1

TC: O(n);
sc:O(n);

 vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        vector<long long> res(n);
        res[n-1]=-1;
        s.push(arr[n-1]);
        for(long long i=n-2;i>=0;i--){
            while(!s.empty() && s.top() <= arr[i]) s.pop();
            if (s.empty()) res[i]=-1;
            else res[i] = s.top();
            s.push(arr[i]);
        }
        
        return res;
        
        
}