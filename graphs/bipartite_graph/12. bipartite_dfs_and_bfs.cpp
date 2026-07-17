line 7: if recursion returns true then we cant directly return true, There is a possbility that all the vertices havenot been colored yet
ex: 0
   / \
  1   2
color[0]=0;
recursion on 1-> color[1]=1;
no neighbours of 1 so it returns true. & we directly returned true, 2 is still not colored
Thats why we directly cant return true. 
But yes if recursion returns false, then we can return false. bcoz now it is guranteed that the the grpah is not bipartite


DFS CODE:

TC: O(V+E);
SC: O(V);

bool checkBipartite(int sv, int c, vector<int> adj[], vector<int>& color){
    color[sv]=c;
    for(int i: adj[sv]){
        if(color[i]==-1){
            if(!checkBipartite(i,1-c,adj,color)) return false;
        }
        else if(color[i]==c) return false;
    }
    
    return true;
}
bool isBipartite(int V, vector<int>adj[]){
    
    vector<int> color(V,-1);

// To take care of disconnected components
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(!checkBipartite(i,0,adj,color))
                return false;
        }
    }
    
    return true;
    
}







BFS CODE:
TC: O(V+E);
SC: O(V);
 bool isBipartiteUtil(int sv, vector<int>& color, vector<int>adj[]){
       color[sv]=0;
	   queue<int> q;
        q.push(sv);
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(int i: adj[f])
            {
                if(color[i]==-1){
                    color[i]=1-color[f];
                    q.push(i);
                }
                else if(color[i]==color[f]){
                  return false;  
                } 
            }
            
        }
        
        return true;    
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    
        vector<int> color(V,-1);
        
// To take care of disconnected components
	     for(int i=0;i<V;i++){
	         if(color[i]==-1){
	             if(!isBipartiteUtil(i,color,adj)) return false;
	         }
	     }
	     
	     return true;
	        
	    
	}