// Prefix sums on matrices

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