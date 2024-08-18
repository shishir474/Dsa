
Q. 25 Cheapest flights within K Stops
https://www.youtube.com/watch?v=9XybHVqTHcQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=38

Djkstra problem with small modification -> cannot use djkstra directly because there can exist a path with a lower cost but it can't be taken bcoz it doesn't satisfy the stops requirements
There can exist a higher cost path which can lead us to the destination in <= K stops

hence distance cannot be our source of judgement. Here stops will be the deciding factor 

ex; [[0,1,5], [0,3,2], [3,1,2], [1,4,1], [1,2,5], [4,2,1]]  -- > {u,v,cost} u to v directed edge with edge weight of cost 
this is the sample graph, run simple djkstra on this and you will see why it fails
The cheaper cost path to 4 is 5 which is {0,3,1,4}. But when we see a path from {0,1,4} we are not able to use this path bcoz it costs us 6 bucks. Djkstra is discarding this path

// NOTE: Why Normal queue would work
// We dont need a pq bcoz we will store it in terms of {stops,{city,dist}}. Stops will always increase by 1. The increase is constant.
// If dist would have been the deciding factor and the edgeWt is not 1 for all the edges, pq would have been a better choice
// Here we are giving more weightage to stops & since the increase in stops is constant, no need of pq. normal queue would suffice
// by doing this we will be saving the logarithmic factor of pq
// problems where you can use queue for djkstra, you could also use pq. But the reverse isn't true. 
// In djkstra, if the edge wt is constant, use q, else use pq 

// Whenever you reach a dest do not stop. We could reach the dest in future with a better price.
// This is a valid question that should we stop at the first encounter of dest or should we continue processing the vertices.
// In some problems we stopped at the very first encouter of dst, whereas in this problem we will have to continue processing coz there is a possibility that in fuutre we could reacch at a better price

// If the dist[dst] == 1e9, it means it was unreachable and you could return -1
// else return dist[dst]
 

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].push_back({v,cost});
        }
        
        queue<pair<int,pair<int,int>>> q;
            
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        q.push({0,{src,0}}); // {stops,{city,cost}} stops will be our deciding factor
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int city = it.second.first;
            int d = it.second.second;
            
            if(stops > K) continue; // I have exhausted all the stops, doesn't matter if I'm at dst or not. If at dst, we will explore neighbours of dst and the stops will be K surely gretaer than K, which will automatically be dropped in the next iteratoin
            // If not at dst and the stops > K, we definately cannot take this path
            
            // I cannot return at the very first encounter of dst, bcoz we can get a better path at a later stage
            
            for(auto it: adj[city]){
                int nb = it.first, edgeWt = it.second;
                if(d+edgeWt < dist[nb]){ 
                    dist[nb] = d+edgeWt;
                    q.push({stops+1,{nb,d+edgeWt}});
                }
            }
            
        }
        
        if(dist[dst]==1e9)
        return -1;
        
        return dist[dst];
        
    }
};
 

// TC: for djkstra implemented using pq is ElogV. But since we are using q for implementing djkstra, the log factor will not be there. So time complexity is O(E)
// E is the total no of edges which is nothing but flights.size()
Hence TC: O(flights.size())

// SC: O(V+E) for adj list + O(V) for dist array + O(V) for queue
// V is n 
// E is flights.size()
