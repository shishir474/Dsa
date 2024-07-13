#include<bits/stdc++.h>
using namespace std;

struct node{
    int parent, rank;
}

vector<node> dsuf;

-- connect lower rank to higher rank: if both nodes has same rank then connect any one to anyone, just modify the parent and increase the rank of the new parent
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

-- find ultimate parent and applies path compression
int findUltimateParent(int v){
    if(v == dsuf[v].parent)
        return v;
    return dsuf[v].parent = findUltimateParent(dsuf[v].parent); -- path compression step
}

vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size(); 
        dsuf.resize(n+1);

        -- initial config: ith node- parent is i and all nodes rank 0
        for(int i=0;i<=n;i++){
            dsuf[i].parent = i;
            dsuf[i].rank = 0;
        }


        for(int i=0;i<n;i++){
            int a = edges[i][0], b = edges[i][1];
            -- check if the edge between a and b is redundent. How to verify if this is a redundent edge. 
            -- if these nodes are already connected which means has the same parent then it's a redundent edge
            int ultp_a = findParent(a), ultp_b = findParent(b); -- find ultimate parent of a and b

            if(p1==p2){ -- both nodes has the same parent -> redundent edge 
                return {a,b};
            }

            -- both has different parent which means they both belong to different component and now the component with a lower rank will become the child of the other node
            unionByRank(p1,p2); -- do union of ultimate parents
        }

        return {};
    }