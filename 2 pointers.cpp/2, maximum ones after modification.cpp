Given a binary array A and a number B, we need to find length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.



Problem Constraints
 1 <= N, B <= 105

 A[i]=0 or A[i]=1



Input Format
First argument is an binary array A.

Second argument is an integer B.



Output Format
Return a single integer denoting the length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.



Example Input
Input 1:

 A = [1, 0, 0, 1, 1, 0, 1]
 B = 1
Input 2:

 A = [1, 0, 0, 1, 0, 1, 0, 1, 0, 1]
 B = 2


Example Output
Output 1:

 4
Output 2:

 5


Example Explanation
Explanation 1:

 Here, we should only change 1 zero(0). Maximum possible length we can get is by changing the 3rd zero in the array,
 we get a[] = {1, 0, 0, 1, 1, 1, 1}
Explanation 2:

 Here, we can change only 2 zeros. Maximum possible length we can get is by changing the 3rd and 4th (or) 4th and 5th zeros.

 


// at max we can change k zeroes..  so I will maintain a window which contains exactly k zeroes, and the max sized window will be my ans
// I will keep increasing the right pointer until the zeroCount<k in my window. The moment zeroCount exceeds k, start moveing the left pointer until the zeroCount becomes equal to k 

int Solution::solve(vector<int> &A, int k) {
    // Solution 1:
          int i=0,j=0,cnt=0,ans=0;
    while(j < A.size()){
        if (A[j] == 0) cnt++;
        
        if (cnt > k){
            ans = max(ans, j-i); 
            while(cnt > k){
                if (A[i]==0) cnt--;
                i++;
            }

        }

        j++;
    }

     ans = max(ans, j-i);
    return ans;





    // Solution 2:
    // int i=0,j=0,cnt=0,ans=0;
    // while(j < A.size()){
    //     if (A[j] == 0) cnt++;
        
    //     while(cnt > k){
    //         if (A[i]==0) cnt--;
    //         i++;
    //     }

    //     ans = max(ans, j-i+1);   // i to j ki window hai-> window size: j-i+1
    //     j++;
    // }

    // return ans;

  
}
