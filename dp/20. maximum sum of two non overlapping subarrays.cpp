1031. Maximum Sum of Two Non-Overlapping Subarrays

Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.

The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.

A subarray is a contiguous part of an array.

Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

class Solution {
public:
    // x sized subarray, y sized subarray
    int solve(vector<int>& a, int x, int y){
        int n=a.size();
        int t1[n],t2[n];
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        
        int s=0,i,j=0;
        for(i=0;i<x;i++) s+=a[i];
        t1[x-1]=s;
        for(;i<n;i++){
            s+=a[i];
            s-=a[j]; j++;
            t1[i]=max(t1[i-1],s);
        }
        
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
        

        int ans=INT_MIN;
        for(i=x-1;i<n-y;i++){
            ans=max(ans, t1[i]+t2[i+1]);
        }
        return ans;
        

    }

    int maxSumTwoNoOverlap(vector<int>& a, int firstLen, int secondLen) {
        return max(solve(a,firstLen,secondLen), solve(a,secondLen,firstLen));
    }
};