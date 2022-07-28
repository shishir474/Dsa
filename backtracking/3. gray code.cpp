Gray Code

Medium

147

7
Asked In:
Microsoft
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.

Return any such sequence.


void solve(int& n, int moves, int i, vector<int>& res){
    if(moves==0){
        res.push_back(n);
        return;
    }
    solve(n,moves-1,i+1,res);
    n = n^(1<<i);
    solve(n,moves-1,i+1,res);
}
vector<int> Solution::grayCode(int A) {
    vector<int> res;
    int n=0;
    solve(n,A,0,res);
    return res;
}