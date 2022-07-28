1130. Minimum Cost Tree From Leaf Values

Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

TC: O(n^4)
SC: O(n^2)
class Solution {
public:
    int t[41][41];
  int helper(vector<int> &arr, int i, int j){
        if (i==j) return 0;
        if (i+1==j) return arr[i]*arr[j];
      
        if (t[i][j]!=-1) return t[i][j];
        
        int ans = INT_MAX;
        for (int k=i;k<j;k++){
            int mx1=  *max_element(arr.begin()+i, arr.begin()+k+1);
            int mx2 = *max_element(arr.begin()+k+1, arr.begin()+j+1);
            ans = min(ans,mx1*mx2 + helper(arr,i,k) + helper(arr,k+1,j));
        }
        
        return t[i][j] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(t,-1,sizeof(t));
        return helper(arr,0,arr.size()-1);
    }
};