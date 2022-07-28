Return all the bridges in the graph

TC: O(V+E)
SC:O(V)

 void dfs(int sv, int parent, vector<int>& vis, vector<int>& in, vector<int>& lo, vector<int> adj[], int& timer, vector<vector<int>>& res){
    vis[sv]=true;
    in[sv]=lo[sv]=timer++;
    for(int i: adj[sv]){
        if(i==parent) continue;
        if(!vis[i]){
            dfs(i,sv,vis,in,lo,adj,timer,res);
            lo[sv]=min(lo[sv], lo[i]);

            if(lo[i] > in[sv]){
                res.push_back({min(sv,i), max(sv,i)});
            }
        }
        else{
             lo[sv]=min(lo[sv], in[i]);
        }
    }
}
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector<vector<int>> res;
	    
	    vector<int> vis(V,false);
	    vector<int> lo(V,-1), in(V,-1);
	    int timer=0;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,-1,vis,in,lo,adj,timer,res);
	        }
	    }
	    
	    sort(res.begin(),res.end());
	    
	    return res;
	}