Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :

If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

void solve(int i, int n, int k, vector<int>& ans, vector<vector<int> >& res){
    if (k==0){
        res.push_back(ans);
        return;
    }
    else if(i > n) return;
    
    // first include krnke call lgao, then exclude wali call, to get the results in sorted order
    ans.push_back(i);
    solve(i+1,n,k-1,ans,res);
    ans.pop_back();

    solve(i+1,n,k,ans,res);
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > res;
    vector<int> ans;
    solve(1, A, B, ans, res);
    return res;
}




