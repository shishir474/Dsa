// Dijkstra algorithm -> SINGLE SOURCE SHORTEST PATH

// Time Complexity: O(NlogN). N iterations and logN for priority queue

// Space Complexity: O(N). Three arrays and priority queue

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

    bool visited[n];
    int key[n];

    for(int i=0;i<n;i++){
        key[i]=INT_MAX; visited[i]=false;
    }


    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
    
    key[0]=0;
    pq.push({0,0}); // distance, vertex

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for(auto it: adj[u]){
            int v=it.first;
            int wt=it.second;
            if(!visited[v] and key[u]+wt<key[v]){
                key[v]=key[u]+wt;
                pq.push({key[v],v});
            }
        }
    }


    for(int i=1;i<n;i++){
        cout<<i<<" "<<key[i]<<"\n";
    }
    



}


INPUT: 
9 14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 0 8
7 1 11
7 8 7
8 2 2 
8 6 6
2 5 4
3 5 14

output:
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14
