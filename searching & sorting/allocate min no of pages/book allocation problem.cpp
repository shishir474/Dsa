
You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.

You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.


class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int arr[], int n, int m, int min){

        int studentrequired=1,sum=0;
        for (int i=0;i<n;i++){
            if (arr[i] > min)
            return false;
            
            if (sum+arr[i] > min){
                studentrequired++;
                
                if (studentrequired > m)
                return false;
                
                sum = arr[i];
            }else{
                sum+=arr[i];
            }

        }
        
        return true;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int sum = 0;
        for (int i=0;i<n;i++) sum+=arr[i];
        int low = 0, high = sum, ans = INT_MAX;
        while (low <= high){
            int mid = (low + high)/2;
            if (ispossible(arr,n,m,mid)){
                ans= min(ans, mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)