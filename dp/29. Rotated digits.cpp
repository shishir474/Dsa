An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.


Solution1:
Brute force check each numver from 1 to n and increase count if i is good. 
TC: O(nlogn);  n for traversing from 1 to n and logn for checking each number

solution2:
number n can be broken down into 2 small numbers n/10 and n%10
so If we want to check for some n then using values of dp[n/10] and dp[n%10] we can calculate ans for n
For this it is important to keep track of digits which are invalid(cant be rotated), digits which rotate to same digit, and digits which rotate to preoduce diff digit

dp[0] -> invalid digit
dp[1] -> digits which rotate to same digit
dp[2] -> digits which rotate to preoduce diff digit

If n contains any invalid digit, then dp[n]=0
if n contains all digits which rotate to same digits, then dp[n]=1;

a=dp[i/10], b=dp[i%10]
if(a==0 || b==0) dp[i]=0;
else if(a==1 and b==1) dp[i]=1;
else dp[i]=2; cnt++;



class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n+1,0);
        int count = 0;
        for(int i = 0; i <= n; i++){
            if(i < 10){
                if(i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if(i == 2 || i == 5 || i == 6 || i == 9){
                    dp[i] = 2;
                    count++;
                }
            } else {
                int a = dp[i / 10], b = dp[i % 10];
                if(a == 1 && b == 1) dp[i] = 1;
                else if(a >= 1 && b >= 1){
                    dp[i] = 2;
                    count++;
                }
            }
        }
        for (int i=1;i<=n;i++) cout<<i<<" "<<dp[i]<<endl;
        return count;
    }
};