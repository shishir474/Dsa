class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        for(int i=1;i<a.size();i++){
            if (a[i][0] <= a[i-1][1]){
                a[i][0]= a[i-1][0];
                a[i][1] = max(a[i-1][1], a[i][1]);
                a[i-1][0] = a[i-1][1] = INT_MAX;
            }
        }
        
        vector<int> temp = {INT_MAX, INT_MAX};
        a.erase(remove(a.begin(),a.end(),temp), a.end());
        return a;
    }
};