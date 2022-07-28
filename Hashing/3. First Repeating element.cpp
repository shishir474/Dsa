int Solution::solve(vector<int> &A) {
    int idx=INT_MAX;
    int ans=-1;

    map<int,int> mp;
    for(int i=0;i<A.size();i++){
        if (mp.count(A[i]) == 0){
            mp.insert({A[i],i});
        }else{
            if (mp[A[i]] < idx){
                idx = mp[A[i]];
                ans=  A[i];
            }
        }
    }

    return ans;
}
