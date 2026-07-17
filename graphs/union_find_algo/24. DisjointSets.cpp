#include<bits/stdc++.h>
using namespace std;

// -- TC: O(4alpha): alpha is near about 1, so it's O(1) for both union and find operations
// -- Refer Strivers lecture to get more clarity 

// -- Disjoint set usecase: () Refer Striver’s Video
// -- Assume you have 2 components in your graph. If someone asks, whether node i and j belong to same component.
// -- Brute force solution: Perform dfs on both components: TC: O(V+E)
// -- Using disjoint sets I can answer this in O(1)
// -- Basically you can answer whether if 2 nodes are part of the same component in O(1) time
// --  Consists of main 2 functions: findParent and union by rank or union by size
// -- Initial configuration : all the nodes are disconnected
// -- At every stage the graph is changing and you might be asked if two nodes belong to same component or not. You can answer this in O(1)

// -- Finding the ultimate parent is not O(1). It is log(n). This is where path compression comes in (optimisation). We store the ultimate parent

// -- Rank: can be considered as the height of the graph
// -- if both the nodes have same rank -> doesn’t really matter which one you treat as child or parent. the node which becomes the child -> its parent needs to be changed and the node which became the parent it’s rank need to increase by 1. Why? bcoz initially both nodes have the same rank, but now when one becomes the child, the height of the tree increase and hence should the rank

// -- Rank is not actually the height. The path compression will be done while finding the ultimate parent. the tree structure willl change, but we do not alter the rank, coz the tree could have another subtree  


struct node{
    int parent, rank;
}

vector<node> dsuf;

// connect lower rank to higher rank: if both nodes has same rank then connect any one to anyone, just modify the parent and increase the rank of the new parent
void unionByRank(int u, int v){ 
    if(dsuf[u].rank < dsuf[v].rank){
        dsuf[u].parent = v;
    }
    else if(dsuf[v].rank < dsuf[u].rank){
        dsuf[v].parent = u;
    }
    else{
        dsuf[u].parent = v;
        dsuf[v].rank++;
    }
}

// -- find ultimate parent and applies path compression
int findUltimateParent(int v){
    if(v == dsuf[v].parent)
        return v;
    return dsuf[v].parent = findUltimateParent(dsuf[v].parent); -- path compression step
}

vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size(); 
        dsuf.resize(n+1);

        // initial config: ith node- parent is i and all nodes rank 0
        for(int i=0;i<=n;i++){
            dsuf[i].parent = i;
            dsuf[i].rank = 0;
        }


        for(int i=0;i<n;i++){
            int a = edges[i][0], b = edges[i][1];
            // -- check if the edge between a and b is redundent. How to verify if this is a redundent edge. 
            // -- if these nodes are already connected which means has the same parent then it's a redundent edge
            int ultp_a = findParent(a), ultp_b = findParent(b); // -- find ultimate parent of a and b

            if(p1==p2){ // -- both nodes has the same ultimate parent -> redundent edge 
                return {a,b};
            }

            // -- both has different ultimate parent which means they both belong to different component and now the component with a lower rank will become the child of the other node
            unionByRank(p1,p2); -- do union of ultimate parents
        }

        return {};
}