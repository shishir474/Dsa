class Solution {
public:
    void reverse(vector<int>& nums, int lo, int hi){
        while(lo<=hi){
            swap(nums[lo], nums[hi]); 
            lo++; hi--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=n-2;i>=0;i--){
            if (nums[i] < nums[i+1]){
                break;
            }
        }
        if (i==-1){
            reverse(nums,0,n-1);
        }
        else{
            for(int k=n-1;k>i;k--){
                if (nums[k] > nums[i]){
                    swap(nums[k],nums[i]);
                    reverse(nums,i+1,n-1);
                    return;
                }
            }
        }
    }
};