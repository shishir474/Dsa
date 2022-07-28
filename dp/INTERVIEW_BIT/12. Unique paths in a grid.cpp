int solve(int i, int j, vector<vector<int> > &A,vector<vector<int> >& t){
    int m = A.size(), n = A[0].size();

    if (A[i][j]==1) return 0;
    if (i==m-1 and j==n-1) return 1;
    if (t[i][j] != -1) return t[i][j];

    int right=0, down=0;
    if (j+1 < n){
        right = solve(i,j+1,A,t);
    }
    if (i+1 < m){
        down = solve(i+1,j,A,t);
    }

    return t[i][j] = right+down;
}
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
     
    if (A[0][0]==1 || A[m-1][n-1]==1) return 0; // start and end must be obstacle free
    vector<vector<int> > t(m, vector<int> (n,-1));

    return solve(0,0,A,t);
}
 
    // DRY RUN

// mat     0 0 0 0 0
//         1 1 0 1 0
//         0 0 0 0 1
//         0 0 0 0 0
//         0 1 0 0 0 

// dp table
//         5 5 5 0 0
//         0 0 5 0 0
//         11 8 5 2 0
//         3 3 3 2 1
//         0 0 1 1 1