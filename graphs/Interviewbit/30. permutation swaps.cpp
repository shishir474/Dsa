Permutation Swaps!

Medium

127

3
Asked In:
Directi
Problem Description

Rishabh has a permutation A of N integers 1, 2, ... N but he doesnt like it. Rishabh wants to get a permutation B.

Also, Rishabh has some M good pairs given in a form of 2D matrix C of size M x 2  where (C[i][0], C[i][1]) denotes that two indexes of the permutation A.

In one operation he can swap Ax and Ay only if (x, y) is a good pair.

You have to tell whether Rishabh can obtain permutation B by performing the above operation any number of times on permutation A.

If the permutation B can be obtained return 1 else return 0.



Problem Constraints
2 <= N <= 105
1 <= M <= 105
1 <= A[i], B[i] <= N
A[i] and B[i] are all distinct.
1 <= C[i][0] < C[i][1] <= N


Input Format
First arguement is an integer array A of size N denoting the permutation A.

Second arguement is an integer array B of size N denoting the permutation B.

Third argument is an 2D integer array C of size M x 2 denoting the M good pairs.



Output Format
If the permutation B can be obtained return 1 else return 0.



Example Input
Input 1:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [ 
        [3, 4]
     ]
Input 2:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [
        [2, 4]
     ] 


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 As A != B you have to perform operations on A but there is only good pair available i,e (3, 4) so if you swap
 A3 with A4 you get A = [1, 3, 4, 2] which is not equal to B so we will return 0.
Explanation 2:

 As A != B you have to perform operations on A but there is only good pair available i,e (2, 4) so if you swap
 A2 with A4 you get A = [1, 4, 2, 3] which is equal to B so we will return 1.




SOLUTION:
ex1:
 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [ 
        [3, 4] // 1 based indexing
     ]

NOTE: grouping is done on basis of pairs in C 
groups: [1], [3], [2,4] -> 3 groups(members of one group can be swapped internally to achieve any desired outcome)
i=0 A[0]=1 and B[0]=1 no prob move ahead
i=1 A[1]=3 and B[1]=4 mismatch (also 3 and 4 belong to different components, so they cannot be swapped) HENCE return 0

Input 2:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [
        [2, 4]
     ] 
C[2,4]-> A[1]and A[3] are connected & belong to same group

groups: [1], [3,4], [2] -> 3 groups
NOW start matching
i=0 -> A[0]==B[0] move ahead
i=1 -> A[1]=3 and B[1]=4, Now we can get 4 in place of 3 only if 3 and 4 belong to same component in A. & yes they do SO they can be swapped
TO determine component to which they belong to-> USED DISJOINT SET (DSUF)
return 1;



struct Node{
    int parent,rank;
};

vector<Node> dsuf;

int find(int v){
    if(dsuf[v].parent==-1) return v;
    return dsuf[v].parent = find(dsuf[v].parent);
}
void Union(int p1, int p2){
    if(dsuf[p1].rank > dsuf[p2].rank){
        dsuf[p2].parent = p1;
    }
    else if(dsuf[p1].rank < dsuf[p2].rank){
        dsuf[p1].parent = p2;
    }
    else{
        dsuf[p2].parent = p1;
        dsuf[p1].rank++;
    }
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
   // grouping krni hai bs
   int n=A.size();
   dsuf.resize(n+1);
   for(int i=0;i<=n;i++){
       dsuf[i].parent=-1;
       dsuf[i].rank=0;
   }  
    
    // make connections
  for(int i=0;i<C.size();i++){  // u and v belong to 1 component grouping them
      int u=A[C[i][0]-1], v=A[C[i][1]-1];
      int p1=find(u), p2=find(v);
      if(p1!=p2)
      Union(p1,p2);
  }
  
  for(int i=0;i<A.size();i++){
      if(A[i]!=B[i]){
          int p1=find(A[i]), p2=find(B[i]);
          if(p1!=p2) return 0;
      }
  }
  
return 1;
   
   
    
    
}
