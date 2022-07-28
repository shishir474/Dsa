int Solution::solve(vector<vector<int> > &A) {
    int m=A.size(), n=A[0].size();
  
    int temp[m][n];
 // prefix sum for each row
    for(int i=0;i<m;i++){
        temp[i][0] = A[i][0];
        for(int j=1;j<n;j++){
            temp[i][j] = A[i][j] + temp[i][j-1];
        }
    }

    int total=0;
    int target = 0;

    // fixing columns;
    for(int c1=0;c1<n;c1++){
        for(int c2=c1;c2<n;c2++){
            map<int,int> mp;
            // sum, freq
            int count=0;
            int sum = temp[0][c2] - (c1>0 ? temp[0][c1-1] : 0);
            mp[sum]++;
            if (sum == target) count++; 
        
            for(int i=1;i<m;i++){
                sum+= temp[i][c2] - (c1>0 ? temp[i][c1-1] : 0);
                if (sum==target) count++;
                if (mp.count(sum-target)) count+=mp[sum-target];
                mp[sum]++;
            }

            total+=count;

        }
    }

    return total;
}
