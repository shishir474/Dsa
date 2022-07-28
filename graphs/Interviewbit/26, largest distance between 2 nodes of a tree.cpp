Largest Distance between nodes of a Tree

Medium

160

6
Asked In:
Facebook
Google
Problem Description

Given an arbitrary unweighted rooted tree which consists of N nodes.

The goal of the problem is to find largest distance between two nodes in a tree.

Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i will have A[i] equal to -1, it will be root node.



Problem Constraints
1 <= N <= 40000



Input Format
First and only argument is an integer array A of size N.



Output Format
Return a single integer denoting the largest distance between two nodes in a tree.



Example Input
Input 1:

 A = [-1, 0, 0, 0, 3]


Example Output
Output 1:

 3


Example Explanation
Explanation 1:

 node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4

 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3.



 SOLUTION:

helper function() returns height.
For sv get the heights of each subtree recursively, and then calc ans accordingly. if No. of children>=2 -> ans=max(ans,firstMaxHeight + secondMaxHeight)
else if(No.of children==1) ans=max(ans, 1+firstMaxHeight)

NOW return wala part
if(No of children > 0){  atleast one children is present
    return 1+firstMaxHeight bcoz height of the tree rooted at sv will be 1+max(all heights of uske children ke trees ka)
}
else { No. of chilren==0 -> height of the tree is 0
    return 0
}






x

int helper(int sv, vector<int> adj[], int& ans){
    
    int first_mx=0, second_mx=0;

    int count=0;
    for(int i=0;i<adj[sv].size();i++){
        count++;
        int height = helper(adj[sv][i], adj, ans);

        if (height > first_mx){
            second_mx = first_mx;
            first_mx = height;
        }
        else if(height > second_mx){
            second_mx = height;
        }
    }

// count represents the no. of children
    if(count>=2){
        ans = max(ans, first_mx+second_mx+2);
    }
    else if(count==1){
        ans = max(ans, first_mx+1);
    }

// if there exists atleast one children
    if (count>0){
        return 1+first_mx;
    }
    else{ //no children -> height = 0, hence return 0
        return 0;
    }
    
    
}
int Solution::solve(vector<int> &A) {
    int V=A.size();
    vector<int> adj[V];
    int sv;
    for(int i=0;i<A.size();i++){
        if(A[i]==-1){
            sv = i;continue;
        }
        int u=A[i], v=i;
        adj[u].push_back(v);
    }

    int ans=0;
    helper(sv,adj,ans); // helper returns height of the tree
    return ans;
}
