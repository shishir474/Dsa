 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n1=nums1.size(), n2 = nums2.size();
        int lo = 0, hi = n1;  // hi = n1-1 hona chahei, but usse wa ara hai [1,2] , [3,4] ke liye. hence hi=n1 set kiya hai
        while(lo <= hi){
            int cut1 = (lo + hi)/2;
            int cut2 = (n1+n2)/2 - cut1;
            
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            
            if (l1 <= r2 && l2 <= r1){
                if ((n1+n2)%2 == 0){
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }else{
                    return double(min(r1,r2));
                }
            }
            else if(l1 > r2){
                // left shift
                hi = cut1 - 1;
            }
            else{
                // right shift
                lo = cut1+1;
            }
            
        }
        
        // This function should return something
        return 0.0;
    }

        Tc: O(log(min(n1,n2)), Sc: O(1));
    Here we are applying bs on smaller array , because the complexity of bs is search space, so the smaller the search space, smaller the complexity. 
    cut1 is basically acting as the mid, bs is applied on nums1
    cut1 and cut2 basically represents the partition. Out of all the posilbe paritions, we have to find the one where the left half is smaller than the right half
     
    l1  r1  Obviously, l1<=r1 and l2 <= r2 
    l2  r2
    The partition which satisfies the constraint l1<=r2 and l2<=r1 is the valid one
    Once we find the valid partition, now if n1+n2 is even then median is the avg. of (max(l1,l2) + min(r1,r2))/2
    and if n1+n2 is odd median formula becomes max(l1,l2), we have partitioned in such a way that median becomes max(l1,l2) in odd case
    
    Shifting part:
    Ideally l2<=r1 but if it is not then we have to increase r1 means move right i.e lo = mid+1, which is lo = cut1+1;
    otherwise move left
    
if cut1 is 0, means we're taking 0 values from a1 and half - cut1 values from a2
    so l1 is nothing , l2 ,r1,r2 will have some values. So default value of l1 should be set to INT_MIN
    same is the case with l2 -> default value of l2 should be INT_MIN
    
        if cut1==n1 ->  we're considering all elements of a1 and and remaing from a2. So in this case value of r1 should be set to INT_MAX. similarly for r2
    Calculated cut2 as (n1+n2+1)/2 -> works for odd and even both
    