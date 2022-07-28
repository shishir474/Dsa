Graph will be connected. Hamiltonian path doesnt make sense if the graph is disconneted, bcoz we cannot visit every vertex

Ex:Following graph is hamiltonian,if we start from 1st vertex, but starting from other vertex will not give hamiltonaina path. So we need to check from every vertex, which one gives hamiltonian path
1--2--3--4--5--6--8
   |           |
   -------------
class Solution{
    public:
    bool dfs(int sv,int n, vector<int> adj[], int mask){
        if(mask==((1<<n)-1)) return true;
        
        for(int it: adj[sv]){
            if((mask&(1<<it))==0){
                if(dfs(it,n,adj,mask|(1<<it))) return true;
            }
        }
        
        return false;
    }

    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> adj[N];
        for(int i=0;i<M;i++){
            int u=Edges[i][0], v=Edges[i][1];
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        
        int mask=0;// check from every vertex,which one gives hamiltonina oaht we dont know
        for(int i=1;i<N;i++){
            if(dfs(i,N,adj,mask|(1<<i))) return true;
        }
        return false;
    }
};