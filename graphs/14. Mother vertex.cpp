MOTHER VERTEX:
Perform toplogical sort, the s.top() can be my mother vertex(bcoz this will be the last visited vertex in my dfs). Perfrom DFS again to check if all other vertices are reachable from s.top() and if yes , thn it is my mother vertex
Otherwise no mother vertex is present


Disconnetec graph-undirected/directed-> NO vertex can be mother vertex
Connetecd undirected-> Every vertex can be mother vertex
Connetecd directed-> we will have to check
 

#include <bits/stdc++.h>
void dfss(vector<int> g[],int V,bool* visited,stack<int> &s,int sv){
    visited[sv]=true;
    for (int i=0;i<g[sv].size();i++){
        if (!visited[g[sv][i]]){
            dfss(g,V,visited,s,g[sv][i]);
        }
    }
    s.push(sv);
}
void dfs(vector<int> g[],bool* visited,int sv,int V){
    visited[sv]=true;
      for (int i=0;i<g[sv].size();i++){
        if (!visited[g[sv][i]]){
            dfs(g,visited,g[sv][i],V);
        }
    }
}
int findMother(int V, vector<int> g[]) 
{ 
    bool* visited=new bool[V];
    for (int i=0;i<V;i++){
        visited[i]=false;
    }
    stack<int> s;
    for (int i=0;i<V;i++){
        if (!visited[i]){
        dfss(g,V,visited,s,i);
        }
    }
    
     for (int i=0;i<V;i++){
       visited[i]=false;
    }
    dfs(g,visited,s.top(),V);
    for(int i=0;i<V;i++){
        if (!visited[i])
        return -1;
    }
    return s.top();
} 