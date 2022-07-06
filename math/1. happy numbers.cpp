Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1

TC: O(nlogn) SC; O(1);
// Using logic of detecting loop in a linked list
class Solution {
public:
    int solve(int n){
        int s=0;
        while(n){
            s+=(n%10)*(n%10);
            n/=10;
        }
        return s;
    }
    
    bool isHappy(int n) {
        int slow=n, fast=n;
        do{
            slow = solve(slow);
            fast = solve(solve(fast));
        }
        while(slow!=fast);
        
        return slow==1;
    }
};



// O(N) space using set
class Solution {
public:
    int solve(int n){
        int s=0;
        while(n){
            s+=(n%10)*(n%10);
            n/=10;
        }
        return s;
    }
    
    bool isHappy(int n) {
        set<int> s;   
        while(1){
            if (n==1) return true;
            if(s.count(n)) return false;
            s.insert(n);
            n = solve(n);
        }
        return false;
    }
};