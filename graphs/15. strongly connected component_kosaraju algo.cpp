class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int> adj[], int sv, stack<int>& s, int V,bool* visited){
	    visited[sv] = true;
	    for (int i=0;i<adj[sv].size();i++){
	        if (!visited[adj[sv][i]]){
	            dfs(adj,adj[sv][i], s,V,visited);
	        }
	    }
	    s.push(sv);
	}
	
	void dfss(vector<int> adjT[], int sv,bool* visited){
	    visited[sv] = true;
	    for (int i=0;i<adjT[sv].size();i++){
	        if (!visited[adjT[sv][i]]){
	            dfss(adjT,adjT[sv][i],visited);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> s;
        bool* visited = new bool[V];
        for (int i=0;i<V;i++){
            visited[i] = false;
        }
        for (int i=0;i<V;i++){
            if (!visited[i]){
                dfs(adj,i,s,V,visited);
            }
        }
        
        for (int i=0;i<V;i++){
            visited[i] = false;
        }
        

        // step 2:
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vector<int> v = adj[i];
            for (int k=0;k<v.size();k++){
                adjT[v[k]].push_back(i);
            }
        }
        int c=0;
        while (!s.empty()){
            int top = s.top();
            s.pop();
            if(!visited[top]){
                c++;
                dfss(adjT,top,visited);
            }
        }
        
        return c;
    
        
    }
};
