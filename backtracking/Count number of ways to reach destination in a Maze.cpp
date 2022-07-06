#include <bits/stdc++.h>

using namespace std;
#define R 4
#define C 4

bool isSafe(int i,int j,int maze[][C]){
    if (i>=0 and i<R and j>=0 and j<C and maze[i][j]==0) return true;
    return false;
}
//function to generate all possible permutations of a string
int solve(int i, int j, int maze[][C]) {
  if (i==R-1 and j==C-1){
      return 1;
  }
  
  int ans=0;
  if (isSafe(i+1,j,maze)){
      ans+=solve(i+1,j,maze);
  }
  if (isSafe(i,j+1,maze)){
      ans+=solve(i,j+1,maze);
  }
  
  return ans;
}

int main(){
    
    int maze[R][C] =  {{0,  0, 0, 0},
                       {0, -1, 0, 0},
                       {-1, 0, 0, 0},
                       {0,  0, 0, 0}};
    if (maze[R-1][C-1]!=0) cout<<"NO solution possible";
    else
    cout << solve(0,0,maze);
    return 0;
}