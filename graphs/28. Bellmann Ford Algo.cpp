
Q.28 Bellman ford algorithm

This algo will also help us to find the shortest path from src to all other Vertices

Then how is it different from djkstra
Dkstra algo will fail if the graph has negative edges. If there is a negative cycle, djkstra algo goes for a TLE. It will keep on minimising the distance  
Djkstra doesnt help you to detect negative Cycle
Bellman ford helps you to detect negative cycles as well
Bellman ford works only on a DG(directed graph). So if you are given an undirected graph, change it to DG by having 2 side edges with the same edgeWt

The only difference between djkstra and bellmand ford is bellman helps you to detect negative cycles
If the path weight is < 0, then the graph has negative cycle

Both djkstra and bellmand ford are single source shortest path algorithm
Bellman only works on DG, if an undirected graph is given you will have to convert it into a DG
For Djkstra, it doesn't matter [Check it once]


Similarity between Djkstra and Bellmand
1. Both are single source shortest path algorithms which means you have a predefined src and you have to compute the shortest dist of all the nodes from that src
2. Both will use dist array initially marked as inf and src as 0

Differnce between Djkstra and Bellman
1. Djkstra fails in case of negative weight cycles. It will keep on updating the dist value and will stuck in an infinite cycle causing TLE
2. Bellman only works on DG, djkstra can work on both undirectged and DG
3. In bellman we will relax all the edges n-1 times, whereas in djkstra we start with pushing the (dist,node) pair for src in the pq and then process all the neighbours 
4. Bellmans TC is kinda quadratic O(V*E), wheares Djkstras TC is O(ElogV), so it's bit more expensive, but it is very useful if the grpah has -ve edge wts or -ve wt cycle, bcoz djkstra doesn't work in those cases


// DOUBT
Does djkstra work in case of -ve edge wt (NO). What about -ve edge wt cycle(NO, will cause TLE)
Does Bellman work in case of -ve edge wt(Yes). What about -ve edge wt cycle(you will be able to detect -ve wt cycle using bellman)
and if the graph has -ve wt cycle, the dist array doesnt make much sense, bcoz the dist will keep on getting reduced




**Bellman implementation** 

Relax all the edges (N-1) times, where N is the number of vertices,
Dist array with all elements marked as inf and src as 0
By relaxing an edge[u,v,wt] I mean if(dist[u] + wt < dist[v]) then update dist[v] = dist[u] + wt;

Edge wise processing is done, doesn't matter the order of edges. and this processing needs to be done (n-1) times
 
WHy (N-1) iterations ? Refer Striver's Video
0 -> 1 -> 2 -> 3 -> 4  

edges: 
[3,4,1]
[2,3,1]
[1,2,1]
[0,1,1]

dist ->  0, inf, inf, inf, inf

1st iteratoin
dist[0] + 1 < dist[1]
     0, 1, inf, inf, inf


In the first iteration you will get value for 1
in second iteration, since you got value of 1 in last iteration, you will be able to calculate value of 2
in third iteration, since you got value of 2 in last iteration, you will get value of 3
in fourth iteration, you will get value of 4 using value of 3

In a grpah of N nodes, in the worst case you will take N-1 edges to reach from first to last, thereby we iterate for N-1 iterations
Try drawing for graph with more than N-1 edges, you won't need to wait for all iterations to be covered
In order to handle worst case scenarios, you iterate for N-1 times


Q. How To detect Negative cycles?
At max we will need N-1 iterations, so we will do 1 extra iteration and try relaxing the edges one more time. If the dist array gets updated, then it means you have a negative weights Cycle

In essence, if during the Nth iteration, relaxation causes updation of dist array, it means you have a negative weights cycle.
Since we already proved that we need only N-1 iteratoins in the worst case


Intution: Assume these are the edges of DG [0,1,-1], [1,2,-2], [2,0,2]
Perform relaxatoin N-1 times, the wt of cycle is -1, so each time weights will keep on reducing by -1
Now perform relaxatoin one more time, the dist array will get updated indicating -ve wt cycle.



Does bellman works in case of -ve weight cycles.
    Yes it does work in case of -ve weight cycles. It can help you to detect -ve wt cycle. If the graph contains -ve wt cycle, then calculating the shortest dist deosnt make any sense, bcoz in each iteration, the distance will keep on minimising

Does bellman works in case of -ve edge.
    Yes, it works

Does Djkstra works in case of -ve weight cycles.   
    No, stucks in TLE. It keeps on reducing the weights

Does Djkstra works in case of -ve edges.
    No





class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    // the problem asks us to check if the graph contains -ve cycle, means will have to use bellman
    // if the edge wts are -ve, use bellman
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V,1e8);
        dist[S] = 0;
        
        // Relax all the edges N-1 times
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int edgeWt = it[2];
                if(dist[u]!=1e8 and dist[u] + edgeWt < dist[v]){ // adding the first condition is a good practise
                    dist[v] = dist[u] + edgeWt;
                }
            }
        }
        
        // Relax 1 more time
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int edgeWt = it[2];
            if(dist[u]!=1e8 and dist[u] + edgeWt < dist[v]){ // if the dist array is getting updated, which it should not in ideal case, it means we have a -ve wt cycle. Return -1
                return {-1};
            }
        }
        
        
        return dist;
        
    }
};


// TC: O(V*E)
// SC: O(V)
