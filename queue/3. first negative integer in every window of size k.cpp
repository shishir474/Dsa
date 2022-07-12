First negative integer in every window of size k -> queue application\
returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.


Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 

TC; o(n) and SC:O(k) at max ther will be only k elements inside queue
Logic:
We will onluy push negative no , so when window size = k, q.front() will give us the first negative npo. of that window. 
One thing to make sure that on shifting the window if the a[i]==q.front() then we need to pop, coz now it will no longer be part of my window


vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
        vector<long long> res;
        queue<int> q;
        int i=0,j=0;
        while(j<n){
            if(a[j] < 0){
                q.push(a[j]);
            }
            if(j-i+1==k){
                if(q.empty()) res.push_back(0);
                else res.push_back(q.front());
                if(!q.empty() and a[i]==q.front()){
                    q.pop();
                }
                i++;
            }
            j++;
        }
        
        return res;
                                            
 }