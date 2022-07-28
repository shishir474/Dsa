Minimum adjacent swaps to group all 1s
Given an array of 0s and 1s, we need to write a program to find the minimum number of swaps required to group all 1s present in the array together.

Example 1:

Input : arr[ ] = {1, 0, 1, 0, 1}
Output : 1
Explanation:
Only 1 swap is required to group all 1's together. 
Swapping index 1 and 4 will give arr[] = {1, 1, 1, 0, 0}.

Example 2:

Input : arr[ ] = {1, 0, 1, 0, 1, 1} 
Output :  1
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function minSwaps() that takes an array (arr), sizeOfArray (n) and return the minimum number of swaps required and if no 1's are present print -1. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


SOlution:


First count total number of 1’s in the array. Suppose this count is x, now find the subarray of length x of this array with maximum number of 1’s using the concept of window-sliding technique.




    int oc=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) oc++;
    }
    
    if(oc==0) return -1;
    
    int k=oc;
    int i=0,j=0,cnt=0,ans=INT_MAX;
    while(j<n){
        if(arr[j]==0) cnt++;
        if(j-i+1 == k){
            ans = min(ans, cnt);
            if(arr[i]==0) cnt--;
            i++;
        }
        
        j++;
    }
    
    return ans;