Combination Sum II

Medium

113

3
Asked In:
Microsoft
Amazon
Infosys
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

void solve(vector<int> &A,int n, int idx, int S, vector<int>& v,vector<vector<int> >& res){
        if(S==0){
            res.push_back(v);
            return;
        }
        
       for(int i=idx;i<n;i++){
           if (i==idx || A[i]!=A[i-1]){
               if (A[i] > S) break;  // optimisation added, we know that our array is sorted so if A[i]>S , surely nos ahead of A[i] will also be greater than S. They will just make S < 0 and amke unncessary recursive calls
               v.push_back(A[i]);
               solve(A,A.size(),i+1,S-A[i],v,res);
               v.pop_back();
           }
       }
            
            
    }


// tHIS QUESTION IS SAME AS LEETCODE combinationSum-ii
vector<vector<int> > Solution::combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int> > res;
        vector<int> v;
        solve(candidates,candidates.size(),0,target,v,res);
      
        return res;
}
