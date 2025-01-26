1345. Jump Game IV

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

SOLUTION:
from i, we can jump to i-1,i+1 and all j where arr[j]==arr[i] and j!=i.
we have to return min number of jumps ->USE BFS. BFS Returns minimum no of steps to reach the destination

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==1) return 0;
        
        unordered_map<int,vector<int>> mp; /// element -> last position at which it was present
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        int vis[arr.size()];
        memset(vis,0,sizeof(vis));
        
        q.push(0);
        vis[0]=true;
        
        int steps=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            while(sz--){
                int f=q.front();
                q.pop();
                if(f==arr.size()-1) return steps;
               
               // 1st option
                if(f+1<arr.size() && !vis[f+1]){
                    q.push(f+1);
                    vis[f+1]=true;
                }
               
               // 2nd option
                if(f-1>=0 && !vis[f-1]){
                    q.push(f-1);
                    vis[f-1]=1;
                }
                
                // 3rd option 
                // push all the postions to where we can go from the current pos and mark all this visited
                // later when we encounter 100 again, we dont need to push all the places where 100 is present bcoz that we would have already pushed in the first time. Therefore erasing the key from ma
                if(mp.count(arr[f])){ // first time arr[f] is enountered. push all places where arr[i]==arr[f] and !vis[arr[i]]
                    vector<int> next = mp[arr[f]];
                    for(int k=0;k<next.size();k++){
                        if(!vis[next[k]]){
                            q.push(next[k]);
                            vis[next[k]]=true;
                        }
                    }
                    mp.erase(arr[f]); // erase so that later when we encounter the same key the vector wont be present in the map since we already pushed all the places where 100 was present, in the first encoutner only
                }
               
            }
            
            steps++;
        }
        
        return 0;
        
    }
};