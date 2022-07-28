UNION FIND TO DETECT CYCLE IN UNDIRECTED GRAPH:

Can we detect cycle using Union find in directed graph?
SOLUTION: No, we cannot use union-find to detect cycles in a directed graph. This is because a directed graph cannot be represented using the disjoint-set(the data structure on which union-find is performed).
ANS-> No.

Let me give you an example:

Q1. Take an undirected graph:?

  /\  
 /  \
1--2--3

Is there a cycle in above undirected graph? Yes. And we can find the cycle using Union-Find algo.

Q2. Now look at the similar directed graph:
Pic2

1->2->3 
|    ^|
|     |
-------
Is there a cycle in above directed graph? No! BUT if you use Union-Find algo to detect cycle in above directed graph, it will say YES! Since union-find algo looks at the above diagram as below:
1-2-3
|   |
-----
Is there a cycle in above diagram? Yes! But the original(Q2) question was tampered and this is not what was asked. So Union-find algo will give wrong results for directed graphs.



NOTE: Union find can be used to detect cycle in undirected graphs. 
Union find just needs edgeList. It analyses edges and determines wheterh there exists cycle or not.
It does not require adj list. Just edges will be enough.
If there is an edge between two vertices u and v that are part of the same component, then there exists a cycle


    struct Node{
        int parent,rank;
    };
    
    vector<Node> dsu;
    
    int find(int v){
        if(dsu[v].parent==-1){
            return v;
        }
        return dsu[v].parent = find(dsu[v].parent);
    }
    
    void union_op(int p1, int p2){
        if(dsu[p1].rank > dsu[p2].rank){
            dsu[p2].parent = p1;
        }
        else if(dsu[p1].rank < dsu[p2].rank){
            dsu[p1].parent = p2;
        }
        else{
            dsu[p2].parent = p1;
            dsu[p1].rank++;
        }
    }

    bool detectCycleUtil(vector<pair<int,int> >& edges, int V){
        dsu.resize(V);
        for(int i=0;i<V;i++){
            dsu[i].parent=-1;
            dsu[i].rank=0;
        }
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first, v=edges[i].second;
            int p1=find(u);
            int p2=find(v);
            if(p1==p2) return true;
            union_op(p1,p2);
        }
        
        return false;
    }
    
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    vector<pair<int,int> > edges;
	    set<pair<int,int> > s;
	    
	    for(int i=0;i<V;i++){
	        for(int j: adj[i]){
	            
	            if(s.count({i,j})==0){
	                s.insert({i,j});
	                s.insert({j,i});
	                edges.push_back({i,j});
	            }
	        }
	    }
	    
        return detectCycleUtil(edges,V);
	}