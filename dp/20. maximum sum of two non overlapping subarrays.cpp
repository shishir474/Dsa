1031. Maximum Sum of Two Non-Overlapping Subarrays

Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.

The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.

A subarray is a contiguous part of an array.

Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.


// LOGIC:
// I''ll basically store the max sum of subarray of len x till each ith index from left side 
// and I''ll store the max sum of subarray of len y starting at each ith index from right side 
// // This can be easily accomplished using prefix & suffix sums 
// final ans will be t1[i] + t2[i+1]
// t1[i] stores the max sum of subarray of len x ending at ith index and is populated from left to right
// t2[i] stores the max sum of subarray of len y starting at ith index and is populated from right to left

// NOTE: One important point here is y length subarray could come before x len subarray, we'll have to call the solve(input, y, x) and then return the max of both the possible options


class Solution {
public:
    // x sized subarray, y sized subarray
    int solve(vector<int>& a, int x, int y){
        int n=a.size();
        int t1[n],t2[n];
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        
    //     t1 array:
    // t1[i] stores the maximum sum of a subarray of length x ending at index i. It uses a sliding window approach:
	// •	Initialize the sum s to the sum of the first x elements.
	// •	Slide the window one element at a time, updating the sum by adding the next element and removing the first element of the previous window.
	// •	Update t1[i] as the maximum of t1[i-1] and the current window sum s.
        int s=0,i,j=0;
        for(i=0;i<x;i++) s+=a[i];
        t1[x-1]=s;
        for(;i<n;i++){
            s+=a[i];
            s-=a[j]; j++;
            t1[i]=max(t1[i-1],s);
        }
        
//  •	t2 array:
// t2[i] stores the maximum sum of a subarray of length y starting at index i. It uses a similar sliding window approach, but traverses from right to left:
// 	•	Initialize the sum s to the sum of the last y elements.
// 	•	Slide the window backward, updating the sum by adding the previous element and removing the last element of the previous window.
// 	•	Update t2[i] as the maximum of t2[i+1] and the current window sum s.

        s=0;
        j=n-1;
        for(i=n-1;i>=n-y;i--) s+=a[i];
        t2[n-y]=s;
        for(;i>=0;i--){
            s+=a[i];
            s-=a[j]; j--;
            t2[i]=max(t2[i+1],s);
        }
        
        // for(int i=0;i<n;i++)cout<<t1[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<t2[i]<<" ";
        // cout<<endl;
        

    // Once t1 and t2 are built, the next step is to combine these two arrays to find the maximum sum of two non-overlapping subarrays:
    // We can only consider index in range of (x-1 to n-y-1) in order to ensure both arrays are being considered
        int ans=INT_MIN;
        for(i=x-1;i<n-y;i++){
            ans=max(ans, t1[i]+t2[i+1]);
        }
        return ans;

    }

    int maxSumTwoNoOverlap(vector<int>& a, int firstLen, int secondLen) {
        // Its stated that The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.
        // so we have to consider both the cases where the first array lies first and when the first array lies after the second array
        return max(solve(a,firstLen,secondLen), solve(a,secondLen,firstLen));
    }
};