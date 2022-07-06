// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        int smallest=arr[0]+k;
        int largest = arr[n-1]-k;
        int mn,mx;
        
        // arr[i] inc and arr[i+1] dec
        for(int i=0;i<n-1;i++){
            if (arr[i+1]>=k){
                mx = max(largest, arr[i]+k);
                mn = min(smallest, arr[i+1]-k);
                ans = min(ans, mx - mn);
            }
        }    
        
        return ans;
    
    }
};

// why sorting? i,i+1 pair will give min difference
// arr[i] inc and arr[i+1] dec