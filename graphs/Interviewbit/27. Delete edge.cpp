const int mod= 1e9+7;
typedef long long ll;

ll solve(int sv,int parent, vector<int> adj[], vector<int>& A, map<ll,ll>& mp){

    ll sum=A[sv];
    for(int i=0;i<adj[sv].size();i++){
        if (adj[sv][i] != parent){
              sum = sum + solve(adj[sv][i], sv, adj, A, mp);
        }
    }
    
    return mp[sv] = sum;
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int V = A.size();
    vector<int> adj[V];
    for(int i=0;i<B.size();i++){
        int u=B[i][0]-1, v=B[i][1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

// node,sumOFSubtreerootedATNOde
    map<ll,ll> mp;
    solve(0,-1,adj,A,mp);

    ll ans=0;
    for(int i=0;i<B.size();i++){
        int u=B[i][0]-1, v=B[i][1]-1;
        ll sumu=mp[0]-mp[v];
        ll sumv=mp[v];
        ll temp = (sumu*sumv)%mod;
        ans=  max(ans,temp);
    }

    return ans;

}
