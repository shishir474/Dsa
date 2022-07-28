Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

class Solution {
public:
    // this adj list is special bcoz if we consider nb of a vertex then every neighbour will be at higher depth than the curr node. bcoz each time we willl want to visit next higher depth than only path obtained will be shortest.In all other cases were at each step depth is no increased by 2, will not result in the shoretest path.
        
void dfs(string sv, string dest, map<string,vector<string>>& adj, vector<string>& path, vector<vector<string>>& res){
    if(sv.compare(dest)==0){
        path.push_back(sv);
        res.push_back(path);
        path.pop_back();
        return;
    }
    
    path.push_back(sv);
    for(auto i: adj[sv]){ // adj matrix is special, no need of vis array here
        dfs(i,dest,adj,path,res);
    }
    path.pop_back();
    
}
    
vector<vector<string> > findLadders(string A, string end, vector<string> &C) {
        vector<vector<string>> res;
        
        unordered_set<string> set(C.begin(),C.end());
        
        if(set.count(end) == 0) return res;
    
    //used visited map to construct special adj matrix
        map<string,int> visited; // stores string->depth
    
        map<string,vector<string>> adj;// special adj list which stores only parent to child relationship
        
        
        queue<string> q;
        q.push(A);
        visited[A]=0;  // depth of starting string is 0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string f=q.front(); 
                q.pop();
                
                for(int i=0;i<f.length();i++)
                {
                    string s=f;
                    for(char ch='a';ch<='z';ch++)
                    {    
                        if(ch==s[i]) continue;   
                        
                        s[i]=ch;
                        
                        if(set.count(s))
                        {
                            if(visited.count(s)==0)
                            {
                                visited[s]=visited[f]+1;
                                adj[f].push_back(s);
                                q.push(s);
                            }
                            else
                            {
                                if(visited[s] == visited[f]+1)
                                {
                                    adj[f].push_back(s);
                                }
                            }
                        }
                        
                    }
                }
            }
        }
    
    
    //  printing adj list
//     for(auto it=adj.begin();it!=adj.end();it++){
//         //vector<int> v = it->second;
//         cout<<it->first<<": ";
//         for(auto i: it->second) cout<<i<<" ";
//         cout<<endl;
//     }
    
  
// step 2:
      vector<string> path;

      dfs(A,end,adj,path,res);

    return res;


}


};