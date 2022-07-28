632. Smallest Range Covering Elements from K Lists

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

class Solution {
public:
    struct element{
        int value,row,index;
    };
    struct compare{
        bool operator()(element A,element B){
            return A.value > B.value;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& arr) {
          int k=arr.size();
          vector<pair<int,int> > res;
          priority_queue<element, vector<element>, compare > pq;
          for (int i=0;i<k;i++){
              element e;
              e.value = arr[i][0];
              e.row = i;
              e.index = 0;
              pq.push(e);
          }
          
          while(!pq.empty()){
              element x = pq.top();
              pq.pop();
              res.push_back({x.value, x.row});
              if (x.index+1 < arr[x.row].size()){
                  element temp;
                  temp.row = x.row;
                  temp.index = x.index+1;
                  temp.value = arr[temp.row][temp.index];
                  pq.push(temp);
              }
          }
          
        
            vector<int> ans;
            int len=INT_MAX;
         //     // SLIDING WINDOW
            int i=0,j=0;
            map<int,int> mp;
            while(j<res.size()){
                mp[res[j].second]++;
                if(mp.size()==k){
                    while(mp[res[i].second] > 1){
                        mp[res[i].second]--;
                        i++;
                    }
                    if(res[j].first - res[i].first < len){
                        len=res[j].first - res[i].first;
                        ans = {res[i].first,res[j].first};
                    }
                }
                j++;
            }

            return ans;
        
    }
};