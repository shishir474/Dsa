Topological Sorting

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no in-coming edges).
 There can be more than one topological sorting for a graph. 

Time Complexity: O(V+E). 
The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is.
Auxiliary space: O(V). 
The extra space is needed for the stack.

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int sv, vector<int> adj[], bool* visited, stack<int>& s){
	    visited[sv] = true;
	    for (int i=0;i<adj[sv].size();i++){
	        if (!visited[adj[sv][i]]){
	            dfs(adj[sv][i], adj,visited,s);
	        }
	    }
	    s.push(sv);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    stack<int> s;
	    bool* visited = new bool[V];
	    for(int i=0;i<V;i++){
	        visited[i] = false;
	    }
	    for (int i=0;i<V;i++){
	        if (!visited[i]){
	            dfs(i,adj,visited,s);
	        }
	    }
	    
	    while (!s.empty()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    return res;
	}
};  




