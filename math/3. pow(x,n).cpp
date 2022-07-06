Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104


class Solution {
public:
    double solve(double a, int n){
        if (n==0) return 1;
        else if(n==1) return a;

        double temp = myPow(a,n/2);
        double ans = temp*temp;
        if (n%2==0){
            return ans;
        }
        else{
            ans*=a;
            return ans;
        }
    }
    double myPow(double a, int n) {
        int f=0;
        if(n<0)f=1;  // n can be negative also. 
        n = abs(n);
        double ans = solve(a,n);
        if(f==1){
            double fans =  (1.0/ans);
            return fans;
        }
        else
            return ans;
    }
};
