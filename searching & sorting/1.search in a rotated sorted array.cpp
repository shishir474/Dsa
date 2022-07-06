   
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

LOGIC:

if(a[lo]<=a[mid]) // mid is in left sorted half : a[lo.....mid] is sorted
{
    if(target > a[mid]) lo=mid+1;  // move right
    else{
        if(target < a[lo])  // target is further less than a[lo] so move right
            lo=mid+1;
        else hi=mid-1;  // move left
    }
}
else{ // mid is in right sorted array : a[mid......hi] is sorted
    if (target < a[mid]) hi=mid-1; // move left
    else{
        if (target > a[hi]) hi=mid-1;// move left
        else lo=mid+1;
    }
}




int search(vector<int>& a, int target) {
        int lo=0,hi=a.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if (a[mid]==target) return mid;
            if (a[lo]<=a[mid]){
                if (target<a[mid]){
                    if (target<a[lo]) lo=mid+1;
                    else hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else{ // mid lies in right sorted array
                if (target>a[mid]){
                    if(target>a[hi]) hi=mid-1;
                    else lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        
        return -1;
        
}




// solution 2:
using concept of index of min element.
Actually index of min element is = number of times array is rotated


class Solution {
public:
    int getIndex(vector<int>& a){
        int n=a.size();
        if (a[0] <= a[n-1]) return 0; // corner case
        
        int lo=0,hi=n-1;
        while(lo<=hi){
            if (a[lo] <= a[hi]) return lo; // to handle corner case. Ifa[lo] <= a[hi] => the array is already sorted so index of min element is lo only
            
            int mid=lo+(hi-lo)/2;
            if (a[mid]<a[(mid-1+n)%n] and a[mid]<a[(mid+1)%n]) return mid;
            else if(a[lo] <= a[mid]){
                lo = mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        
        return -1;
    }
    
    int binarysearch(int lo,int hi,vector<int>& nums,int target){
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] < target) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int i = getIndex(nums);
        // cout<<i;
        int n=nums.size();
        int val1=binarysearch(i,n-1,nums,target);
        if (val1!=-1) return val1;
        int val2=binarysearch(0,i-1,nums,target);
        if (val2!=-1) return val2;
        return -1;
    }
};