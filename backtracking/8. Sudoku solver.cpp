
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.' 

You may assume that there will be only one unique solution.



A sudoku puzzle,



and its solution numbers marked in red.

Note: You must update the input argument A (partially completed grid of Sudoku) to submit your solved Sudoko grid.




bool isSafe(vector<vector<char> > &A, int x, int y, char c){
    for(int j=0;j<A[0].size();j++){
        if (A[x][j] == c) return false;
    }
    for(int i=0;i<A.size();i++){
        if (A[i][y] == c) return false;
    }

    // check in 3*3 submatrix
    int i=(x/3)*3, fi = i+3;
    int j = (y/3)*3, fj = j+3;

    for(int p=i;p<fi;p++){
        for(int q=j; q<fj; q++){
            if (A[p][q] == c) return false;
        }
    }

    return true;

}

bool solveSudokuUtil(vector<vector<char> > &A, int i, int j){
    if (i==A.size()) return true;

    int nexti,nextj;
    if (j==A[0].size()){
        nexti = i+1;
        nextj = 0;
    }
    else{
        nexti = i;
        nextj = j+1;
    }

    if (A[i][j] != '.'){
        return solveSudokuUtil(A, nexti, nextj);
    }
    else{
        for(char c='1'; c<='9'; c++){
            if (isSafe(A,i,j,c)){
                A[i][j] = c;
                if (solveSudokuUtil(A, nexti, nextj)) return true;
                A[i][j] = '.';
            }
        }
        return false;
    }


}
void Solution::solveSudoku(vector<vector<char> > &A) {
    solveSudokuUtil(A,0,0);
}
