Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].


TC: O(n2log(k)) -> while loop will run n2 times and log k operation for pq
sc; O(k)    

struct cell{
    int val,i,arrayno;
    cell(int v, int idx, int j){
        val=v;
        i=idx;
        arrayno=j;
    }
};
struct compare{
        bool operator()(cell a, cell b){
            return a.val > b.val; 
        }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<cell,vector<cell>,compare> pq; 
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0], 0, i});
    }
    vector<int> res;
    while(!pq.empty()){
        cell t=pq.top();
        int val=t.val,i=t.i;
        int j=t.arrayno;
        pq.pop();
        res.push_back(val);
        if(i+1<arr[j].size()){
            pq.push(cell(arr[j][i+1],i+1,j));
        }
    }
    
    return res;
}