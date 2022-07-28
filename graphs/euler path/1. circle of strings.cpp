public:
void dfs(int sv,vector<int>& vis, vector<char> adj[]){
    vis[sv]=true;
    for(char i: adj[sv]){
        if(!vis[i-'a']){
            dfs(i-'a', vis, adj);
        }
    }
}

// notConnected return true if the graoh is not connected   
bool NotConnected(vector<char> adj[]){
    int sv=-1;
    for(int i=0;i<26;i++){
        if(adj[i].size()>0){
            sv=i;
        }
    }
    if(sv==-1) return true;
    
    vector<int> vis(26,0);
    dfs(sv,vis,adj);// dfs from non zero degree vertex
    
    // if any vertex with non zero degree is not visited-> groah is disconnected
    for(int i=0;i<26;i++){
        if(adj[i].size()>0 and !vis[i]) return true;
    }
    return false; // => is connected
}

int isCircle(int N, vector<string> A)
{
    vector<char> adj[26];
    vector<int> indegree(26,0), outdegree(26,0);
    
    for(int i=0;i<A.size();i++){
        string s=A[i]; 
        char u=s[0], v=s[s.length()-1];  // u->v
        adj[u-'a'].push_back(v);
        indegree[v-'a']++;
        outdegree[u-'a']++;
    }
    
    if(NotConnected(adj)) return 0;
    
    // indegree==outdegree for every vertex
    for(int i=0;i<26;i++){
        if(indegree[i]!=outdegree[i]) return 0;
    }
    
    return true;
    
    
    
    
}   