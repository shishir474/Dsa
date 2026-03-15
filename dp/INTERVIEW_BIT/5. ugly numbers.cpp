Smallest sequence with given Primes

Medium

Problem Description
 
Given three prime numbers A, B and C and an integer D.

You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.



Input Format
First argument is an integer A.

Second argument is an integer B.

Third argument is an integer C.

Fourth argument is an integer D.



Output Format
Return an array of size D denoting the first smallest D integers which only have A, B, C or a combination of them as their prime factors.

NOTE: You need to return the array sorted in ascending order.



Example Input
Input 1:

 A = 2
 B = 3
 C = 5
 D = 5


Example Output
Output 1:

 [2, 3, 4, 5, 6]


Example Explanation
Explanation 1:

 4 = A * A i.e ( 2 * 2 ) 
 6 = A * B i.e ( 2 * 3 )



struct input{
    int prime,index,val; // f->value, s->index
};
struct compare{
    bool operator()(const input& a, const input& b){
        return a.val > b.val;
    }
};
vector<int> Solution::solve(int A, int B, int C, int D) {
    // super ugly numbers @ leetcode
    // TC: O(nlogk)
    // 1 has no prime factors, therefore all of its prime factors are in the array primes. Here we do not have to consider 1

    priority_queue<input, vector<input> , compare> pq;
    pq.push({A,0,A});
    pq.push({B,0,B});
    pq.push({C,0,C});

    vector<int> ans(D+1);
    ans[0] = 1;
    for(int i=1;i<D+1; ){
        input mn = pq.top(); pq.pop();
        if (mn.val != ans[i-1]){
            ans[i] = mn.val;
            i++;
        }
        pq.push({mn.prime, mn.index+1, mn.prime*ans[mn.index+1]});
    }

    vector<int> fans(ans.begin()+1, ans.end());
    return fans;

}


Follow Up:
263. Ugly Number

An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

Given an integer n, return true if n is an ugly number.


Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors.
Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
 

Constraints:

-2^31 <= n <= 2^31 - 1

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;
        return n == 1;

        // how to get the prime factors of n?

        pending...


    }
};




Follow Ups      (check neetcode's solution)
Ugly Number 1
Ugly Number 2
Super Ugly Number 