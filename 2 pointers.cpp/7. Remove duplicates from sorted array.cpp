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

    // Inplace solution 1
    int j=0, n=A.size();
    for(int i=0;i<n;i++){
        if (i<n-1 and A[i]==A[i+1]) continue;
        else{
            A[j] = A[i]; j++;
        }
    }

    return j;
}



// Inplace solution 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,n = nums.size();
         if (n==0)
            return 0;
        while(j<n){
            while (j<n && nums[i]==nums[j]){
                j++;
            }
            if (j==n)
                break;
            nums[i+1] = nums[j];
            i++;
        }
        
        return i+1;
    }
};