Time Complexity: O(V+E). 
The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.

Auxiliary Space: O(V). 
The queue needs to store all the vertices of the graph. So the space required is O(V)

vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> res;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                int nb=adj[i][j];
                indegree[nb]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            res.push_back(f);
            for(int i: adj[f])
            {
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        
        
        if(res.size()!=V)// Graph contains cycle, Toplogical sort not possble
            return {};
            
        return res;
        
	}