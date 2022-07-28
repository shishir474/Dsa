int Solution::removeDuplicates(vector<int> &A) {
    // int i=0,j=1,n=A.size();
    // while(j<n){
    //     if (A[j]==A[i]){
    //         A[j] = INT_MAX;
    //     }
    //     else{
    //         i = j;
    //     }
    //     j++;
    // }

    // A.erase(remove(A.begin(), A.end(), INT_MAX), A.end());
    // return A.size();

    int j=0, n=A.size();
    for(int i=0;i<n;i++){
        if (i<n-1 and A[i]==A[i+1]) continue;
        else{
            A[j] = A[i]; j++;
        }
    }

    return j;
}
