Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :

If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]


void solve(vector<int>& A, int idx, vector<int>& path, vector<vector<int> >& res){
    res.push_back(path);
    if(idx==A.size()) return;
  

    for(int i=idx;i<A.size();i++){
        if (i==idx || A[i]!=A[i-1]){
            path.push_back(A[i]);
            solve(A,i+1,path,res);
            path.pop_back();
        }
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > res;
    vector<int> path;
    solve(A,0,path,res);
    return res;
}
