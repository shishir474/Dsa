Problem Description

Given an array A of positive integers,call a (contiguous,not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly B.

(For example: [1, 2, 3, 1, 2] has 3 different integers 1, 2 and 3)

Return the number of good subarrays of A.



Problem Constraints
1 <= |A| <= 40000

1 <= A[i] <= |A|

1 <= B <= |A|



Input Format
The first argument given is the integer array A.

The second argument given is an integer B.



Output Format
Return an integer denoting the number of good subarrays of A.



Example Input
Input 1:

 A = [1, 2, 1, 2, 3]
 B = 2
Input 2:

 A = [1, 2, 1, 3, 4]
 B = 3


Example Output
Output 1:

 7
Output 2:

 3


Example Explanation
Explanation 1:

  Subarrays formed with exactly 2 different integers: [1, 2], [2, 1], [1, 2], [2, 3], [1, 2, 1], [2, 1, 2], [1, 2, 1, 2].
Explanation 2:

  Subarrays formed with exactly 3 different integers: [1, 2, 1, 3], [2, 1, 3], [1, 3, 4].





// THis function returrs count of total no of subarrays having distinct elements in range of 1 to k inclusive
int countSubarraysDistinctElementsInRange(vector<int>& A, int k){
    map<int,int> mp;
    int i=0,j=0,n=A.size();
    int total=0;

    while(j < n){
        mp[A[j]]++;
        if (mp.size() > k) {  // distinct elements > k
            while(mp.size() > k){
                total+=(j-i);
                mp[A[i]]--;
                if (mp[A[i]]==0) mp.erase(A[i]);
                i++;
            }
        }
        j++;
    }

    int sz=j-i;
    total+=(sz*(sz+1))/2;

    return total;
}

// TotalNoOfSubarraysHavingExactlyKDistinctElements = TotalNoOfSubarraysHavingDistinctElementsBetweenOneToK  - TotalNoOfSubarraysHavingDistinctElementsBetweenOneToK-1
// https://www.youtube.com/watch?v=88mGJqbnPVw
int Solution::solve(vector<int> &A, int k) {
   // cout<<countSubarraysDistinctElementsInRange(A,k)<<" "<<countSubarraysDistinctElementsInRange(A,k-1)<<endl;
    return countSubarraysDistinctElementsInRange(A,k) - countSubarraysDistinctElementsInRange(A,k-1);
}
