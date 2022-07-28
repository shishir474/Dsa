1. after dfs call, lo[currVertex] lo update krdo with min(lo[currVertex], lo[nbr]) nbr->neighbour
2. Condition to check of currVertex is articulation point: if(lo[nbr]>=tin[node] and parent!=-1) then node is ap
3. Corner case: if parent==-1 and child>1 then also node is ap
4. if vis[nbr] is true-> back edge hai, then update lo[node] with min lo[node] and tin[nbr]
5. Not stored ap directly into res vector, bcoz the same vertes was pushed multiple times, Hence used ap vector, & if currVertex is ap , then mark ap[currVertex]=1
6. at Last just traverse the ap vector, and where ap[i]==1-> i is an ap


void dfs(int sv, int parent, vector<int>& vis, vector<int>& tin, vector<int>& lo, vector<int> adj[], int& timer, vector<int>& ap){
    vis[sv]=true;
    tin[sv]=lo[sv]=timer++;
    
    int child=0;
    
    for(int it: adj[sv]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs(it,sv,vis,tin,lo,adj,timer,ap);
            lo[sv]=min(lo[sv], lo[it]);
// 1st case 
            if(lo[it] >= tin[sv] and parent!=-1){
                ap[sv]=1;
            }
            child++;
        }
        else{
             lo[sv]=min(lo[sv], tin[it]);
        }
    }
// 2nd case
    if(parent==-1 and child>1){
        ap[sv]=1;
    }
    
}
	
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> res;
	    
	    vector<int> vis(V,false);
	    vector<int> lo(V,-1), tin(V,-1),ap(V,0);
	    
	    int timer=0;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,-1,vis,tin,lo,adj,timer,ap);
	        }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(ap[i]){
	            res.push_back(i);
	        }
	    }
	    
	    if(res.size()==0) return {-1};
	   
	    return res;
    }