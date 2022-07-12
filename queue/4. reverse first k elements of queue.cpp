Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.


Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.


TC: O(n)
sc: o(k)

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    if(q.empty() || q.size() < k) return q;
    
    int n=q.size();
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}