Smallest sequence with given Primes

Medium

179

4
Asked In:
Booking.Com
Microsoft
Directi
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
