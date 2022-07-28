
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.
vector<int> Solution::lszero(vector<int> &A) {
    int st=-1,end=-1,len=0;
    vector<int> res;

    map<int,int> mp;
    int s=0;
    for(int i=0;i<A.size();i++){
        s+=A[i];
        if(s==0){  // corner case: prefix sum = 0
            if (i+1 > len){
                st = 0; end=i;
                len = i+1;
            }
        }
        if (mp.find(s)==mp.end()){
            mp.insert({s,i});
        }else{
            int cl = i - mp[s];
            if (cl > len){
                st = mp[s]+1; end = i;
                len = cl;
            }
        }
    }

    if (st==-1) return res;  // no result exists

    for(int i=st;i<=end;i++) res.push_back(A[i]);
    return res;
}
