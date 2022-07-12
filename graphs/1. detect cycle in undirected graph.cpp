class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int sv, vector<bool>& vis, vector<int> adj[], int parent){
        vis[sv]=true;
        for(auto i: adj[sv]){
            if(!vis[i]){
                if(dfs(i,vis,adj,sv)) return true;
            }
            else if(i!=parent) return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,-1)) return true;
            }
        }
        
        return false;
    }
};