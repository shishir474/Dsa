void Solution::sortColors(vector<int> &A) {
    int low=0,mid=0,high=A.size()-1;
    while(mid <= high){   // mid<=high is correct and not mid<high, consider [2,0,1]
        if (A[mid]==0){
            swap(A[low], A[mid]);
            low++; mid++;
        }
        else if(A[mid]==1){
            mid++;
        }
        else{
            swap(A[mid], A[high]);
            high--;
        }
    }
}
