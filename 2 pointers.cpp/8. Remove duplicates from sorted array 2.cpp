Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,

Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

int Solution::removeDuplicates(vector<int> &A) {
    // int i=0,j=1,n=A.size();
    // int f=0;
    // while(j<n){
    //     if (A[j]==A[i] && f==0){  // f==0 first time
    //         f=1; j++; continue;
    //     }
    //     else if(A[j]==A[i] && f==1){ // f==1 -> It has come before
    //         A[j]=INT_MAX;
    //     }
    //     else{
    //         i = j;
    //         f = 0;
    //     }
    //     j++;
    // }

    // A.erase(remove(A.begin(),A.end(),INT_MAX), A.end());
    // return A.size();

    int n=A.size();
    int j=0;
    
     for(int i=0;i<n;i++){
         if (i<n-2 and A[i]==A[i+1] and A[i+1]==A[i+2]) continue;
         else{
             A[j] = A[i]; j++;
         }
     }

     return j;
}
