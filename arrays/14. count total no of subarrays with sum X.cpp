// Given an unsorted array arr[] of N integers and a sum. The task is to
// count the number of subarrays which add to a given number.
// Example 1:

// Input:
// N=5
// sum=-10
// arr[] = { 10, 2, -2, -20, 10 }
// Output:  3
// Explanation:
// Subarrays with sum -10 are: 
// [10, 2, -2, -20], [2, -2, -20, 10]
// and [-20, 10].


int subArraySum(int arr[], int n, int sum)
{
    //code here.
    map<int,int> mp; // prefix sum->freq
    int psum=0,ans=0;
    for(int i=0;i<n;i++){
        psum+=arr[i];
        if(psum==sum) ans++;
        if (mp.count(psum-sum)){
            ans+=mp[psum-sum];
        }
        mp[psum]++;
    }
    
    return ans;
}