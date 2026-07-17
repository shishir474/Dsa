bool dfs(int sv, vector<bool>& vis, vector<bool>& recStack, vector<int> adj[]){
    if(!vis[sv]){
        vis[sv]=true;           
        recStack[sv]=true;
        for(auto i: adj[sv]){
            if(!vis[i]){
                if(dfs(i,vis,recStack,adj)) return true;
            }
            else if(recStack[i]==true){
                return true;
            }
        }
        recStack[sv]=false;
        return false;
    }
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> vis(V,false),recStack(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,vis,recStack,adj)) return true;
        }
    }
    
    return false;
}