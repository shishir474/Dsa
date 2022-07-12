ALGORITHM
find next smaller element on right side. Let that index is i-> we can expand till i-1
similarly find next smaller element on left side. let that be index j-> we can expand till j+1
=> can expand till [j+1, i-1]
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> lb(n), rb(n);
        stack<long long> s;
        
        s.push(n-1);
        lb[n-1] = n;
    
        for (long long i=n-2;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i])
             s.pop();
            if(s.empty()){
                lb[i] = n;
            }else{
                lb[i] = s.top();
            }
            s.push(i);
        }
        
        while(!s.empty()) 
          s.pop();
        
        s.push(0);
        rb[0] = -1;
        for (long long i=1;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i])
             s.pop();
            if(s.empty()){
                rb[i] = -1;
            }else{
                rb[i] = s.top();
            }
            s.push(i);
        }
        
        long long ans = INT_MIN;
        for (int i=0;i<n;i++){
            long long temp = (lb[i] - rb[i] - 1)*arr[i];
            if(temp > ans) ans = temp;
        }
        
        return ans;
    }
};

'NOTE: Here N is 10^6 so we cannot declare array as usual as it will give segmentation fault. There are 2 possible solutions for this 1. use dynamic array: as they are created in the heap memory space can be easily allocated but also ensure that we need to delete the array .. 2. Use vector as they are underneath implemented as dynamic arrays only