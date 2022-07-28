Prims algorithm

Time Complexity: O(NlogN). N iterations and logN for priority queue

Space Complexity: O(N). Three arrays and priority queue

#include <bits/stdc++.h>
using namespace std;

int main(){
    // weighted undirected graph
    int n,m; cin>>n>>m;
    vector<pair<int,int> > adj[n];
    for(int i=0;i<m;i++){
        int f,s,wt; cin>>f>>s>>wt;
        adj[f].push_back({s,wt});
        adj[s].push_back({f,wt});
    }

    int parent[n];
    bool visited[n];
    int key[n];

    for(int i=0;i<n;i++){
        key[i]=INT_MAX; visited[i]=false;
    }


    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
    
    key[0]=0;
    parent[0]=-1;
    pq.push({0,0}); // keyvalue, vertex

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for(auto it: adj[u]){
            int v=it.first;
            int wt=it.second;
            if(!visited[v] and wt<key[v]){
                key[v]=wt;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }

    int wt=0;
    for(int i=1;i<n;i++){
        wt+=key[i];
        cout<<parent[i]<<"->"<<i<<endl;
    }
    
    cout<<wt<<endl;


}
