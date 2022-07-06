Farthest number 

Given an array Arr[] of size N. For every element in the array, the task is to find the index of the farthest element in the array to the right which is smaller than the current element. If no such number exists then print -1.
Note: 0 based indexing.


Example 1:

Input: 
N=5
Arr[] = {3, 1, 5, 2, 4}
Output: 
3 -1 4 -1 -1
Explanation:
Arr[3] is the farthest smallest element
to the right of Arr[0].
Arr[4] is the farthest smallest element
to the right of Arr[2].
And for the rest of the elements, there is
no smaller element to their right.



class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> arr){
        //code here
        vector<int> ans(N),s(N);
        s[N-1] = arr[N-1];
        for(int i=N-2;i>=0;i--){
            s[i] = min(arr[i], s[i+1]);
        }
        // suffix array is increasing array, so we can apply binary search on that array to get the farthest minimum
        for(int i=0;i<N;i++){
            int lo=i+1,hi=N-1,res=-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(s[mid] < arr[i]){
                    res = mid;
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            ans[i] = res;
        }
        
        return ans;
    }
};