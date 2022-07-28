Commutable Islands

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:

The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:

Return an integer representing the minimal cost required.
Constraints:

1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3
Examples:

Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6

Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]

Output 2:
    6

Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.


SOLUTION:
Out of al bridges we need A-1 bridges to connect A vertices, SO we will pcik the bridges greedily, one with the min cost first.


NOTE:SEE TC of union find in notebook 


TC: O(nlogn);

SC:O(n)




struct node{
    int parent, rank;
};
bool compare(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}

int find(int u, vector<node>& dsuf){
    if (dsuf[u].parent == -1) return u;
    return dsuf[u].parent = find(dsuf[u].parent, dsuf);
}

void Union(int p1, int p2, vector<node>& dsuf){
    if(dsuf[p1].rank > dsuf[p2].rank){
        dsuf[p2].parent = p1;
    }
    else if(dsuf[p1].rank < dsuf[p2].rank){
        dsuf[p1].parent = p2;
    }else{
        dsuf[p2].parent = p1;
        dsuf[p1].rank++;
    }
}


int Solution::solve(int A, vector<vector<int> > &B) {
   sort(B.begin(), B.end(), compare);

    vector<node> dsuf(A);
    for(int i=0;i<A;i++){
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
    }

    int ans=0;

    for(int i=0;i<B.size();i++){ // edges are sorted by weight
        int u=B[i][0]-1, v=B[i][1]-1, wt=B[i][2];
        int p1 = find(u,dsuf), p2 = find(v,dsuf);
        if (p1!=p2){
            ans+=wt;
            Union(p1,p2,dsuf);
        }
    }

    return ans;
}
