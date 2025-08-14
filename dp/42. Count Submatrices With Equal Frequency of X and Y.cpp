// Prefix sums on matrices


// logic: 
1. compute the # of x till (i,j) i.e from (0,0) to (i,j)
    // fill first row
    t[0][0] = (mat[0][0] == 'X') ? 1 : 0;
    for(int j =1;j < m;j++){
        t[0][j] = t[0][j-1] + (mat[0][j] == 'X') ? 1 : 0;
    }
    // fill first col
    for(int i =1; i < n; i++){
        t[i][0] = t[i-1][0] + (mat[i][0] == 'X') ? 1 : 0;
    }
    // process 1st row and 1st col onwards
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            t1[i][j] = (t1[i-1][j] + t1[i][j-1]) - t1[i-1][j-1];
            if(mat[i][j] == 'X') t1[i][j]++;
        }
    }
2. compute the # of y till (i,j) i.e from (0,0) to (i,j)
    Similar to above steps 

3. Final ans calculation
for(int i=0; i < n; i++){
    for(int j = 0; j < m; j++){
        // #no of x till (i,j)  and #no of y till (i,j) are same and is greater than 0, increment the ans
        if(t1[i][j] == t2[i][j] and t1[i][j] > 0)   
            ans++;
    }
}


class Solution {
public:
    
    vector<vector<int>> gridBlockSum(vector<vector<char>>& grid, char ch) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> pre(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j] = (grid[i][j] == ch);
                if(i>0) pre[i][j] += pre[i-1][j];
                if(j>0) pre[i][j] += pre[i][j-1];
                if(i>0 && j>0) pre[i][j] -= pre[i-1][j-1];
            }
        }
        
        return pre;
    }
    
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> xCount = gridBlockSum(grid, 'X');
        vector<vector<int>> yCount = gridBlockSum(grid, 'Y');

        // for(int i=0;i<xCount.size();i++){
        //     for(int j=0;j<xCount[i].size();j++){
        //         cout<<xCount[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        // for(int i=0;i<yCount.size();i++){
        //     for(int j=0;j<yCount[i].size();j++){
        //         cout<<yCount[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += ((xCount[i][j] == yCount[i][j]) && xCount[i][j] > 0);
            }
        }
        return ans;
    }
};


Follow Up
1224. Maximum Equal Frequency
Hard