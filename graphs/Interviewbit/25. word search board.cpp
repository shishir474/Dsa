Word Search Board

Hard

164

25
Asked In:
Epic Systems
Amazon
Google
more
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.


solution:

int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};

int solve(int i, int j, vector<string> &A, string B, int idx){
    if (idx>=B.size()) return true;
    for(int k=0;k<4;k++){
        int newi=i+X[k], newj = j+Y[k];
        if (newi>=0 and newi<A.size() and newj>=0 and newj<A[0].size() and A[newi][newj]==B[idx]){
            if (solve(newi, newj, A,B, idx+1)) return true;
        }
    }

// charo me si kisi direction me B[idx] nai mila-> return false;
    return false;
}
int Solution::exist(vector<string> &A, string B) {
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if (A[i][j]==B[0]){
                if (solve(i,j,A,B,1)) return 1;
            }
        }
    }

    return 0;
}
