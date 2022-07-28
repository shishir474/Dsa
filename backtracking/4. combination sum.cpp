 void solve(vector<int> &A,int n, int idx, int S, vector<int>& v,vector<vector<int> >& res){
        if(S==0){
            res.push_back(v);
            return;
        }
        
       for(int i=idx;i<n;i++){
           if (i==idx || A[i]!=A[i-1]){
               if (A[i] > S) break;  // optimisation added, we know that our array is sorted so if A[i]>S , surely nos ahead of A[i] will also be greater than S. They will just make S < 0 and amke unncessary recursive calls
               v.push_back(A[i]);
               solve(A,A.size(),i,S-A[i],v,res);
               v.pop_back();
           }
       }
            
            
    }

    // tHIS QUESTION IS SAME AS GFG' COMBINATION SUM PROBLEM WHRE THE ARRAY CONTAINS duplicates AND A NUMBER CAN BE CAN BE CHOOSEN UNLIMITED NO OF TIMES
vector<vector<int> > Solution::combinationSum(vector<int> &candidates, int target) {
          // sorted the array to handle duplicates. Earlier used set to keep track of unique combinations, but it resulted in TLE
        sort(candidates.begin(), candidates.end());

        vector<vector<int> > res;
        vector<int> v;
        solve(candidates,candidates.size(),0,target,v,res);
      
        return res;
}
