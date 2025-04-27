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

    // we need visited array we cannot discard it any case
    // Imagine a case where you reached node 3 with 10 cost and you processed all its neighbours and then later you again get node 3 but with 15 cost
    // Processing node 3 again at a higher cost will not lead to anything
    // and since you are using a min heap, you will always get a higher cost node at a later stage
    // The base factor is you've processed a node a lower cost, you don't need to process it again a higher cost
    // Hence checkinf if the node is not visited, then only we visit it and process it


    // We dont need visited array in djkstra implementation using PQ, since PQ already maintains the nodes in sorted fashion 
    int key[n];

    for(int i=0;i<n;i++){
        key[i]=INT_MAX; 
    }


    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
    
    key[0]=0;
    pq.push({0,0}); // distance, vertex

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;  // d is the cost at which we are reaching th uth vertex
        // whereas dist[u] is the shortest cost through which we reach the uth vertex

        pq.pop();

        // if the curr cost > existing cost for reaching the uth vertex
        if(d > dist[u]) continue;

        // process the node only if it is not visited yet
        for(auto it: adj[u]){
            int v=it.first;
            int wt=it.second;
            if(key[u]+wt<key[v]){
                key[v]=key[u]+wt;
                pq.push({key[v],v});
            }
        }
        
    }


    for(int i=1;i<n;i++){
        cout<<i<<" "<<key[i]<<"\n";
    }
    



}

// pq is used because this will give us the lowest code node each time
// if a node is processed(means its neighbours are explored) at a lower cost, then it makes no sense to process the same node again at a higher cost in the pq


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
