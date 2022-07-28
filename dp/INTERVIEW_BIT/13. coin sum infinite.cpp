You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

Example :

Input : 
	S = [1, 2, 3] 
	N = 4

Return : 4

Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}	


const int mod = 1000007;
int Solution::coinchange2(vector<int> &A, int B) {
    int n=A.size();
    int t[2][B+1];

    t[0][0] = t[1][0] = 1;

    for(int j=1;j<=B;j++){
        t[0][j] = 0;
    }
     
    // if (A[i-1] <= j){
    //     t[i][j] = t[i-1][j] + t[i][j-A[i-1]];
    // }
    // else{
    //     t[i][j] = t[i-1][j]
    // }

    int flag = 1;                                 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=B;j++){
            if (A[i-1] <= j){
                t[flag][j] = (t[flag^1][j]%mod + t[flag][j-A[i-1]]%mod)%mod;
            }else{
                t[flag][j] = t[flag^1][j];
            }
        }
        flag = flag^1;
    }
    
    flag = flag^1;
    return t[flag][B];
}