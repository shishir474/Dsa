#include<bits/stdc++.h>
using namespace std;
// // SAMPLE INPUT: 
//// 7 9
// 0 1
// 1 2
// 2 5
// 5 6
// 6 4
// 4 3
// 3 0
// 3 2
// 4 5
// // SAMPLE OUTPUT:
// 6
// 0 1 2 5 6 4 3 
// 6
// 0 1 2 3 4 6 5 
// 6
// 0 1 2 3 4 5 6 
// 6
// 0 3 4 6 5 2 1 

// METHOD 1

void hamiltonian(vector<int> adj[], int sv, int n, int mask, vector<int>& path){
   if (mask==((1<<n)-1)){  // the vertex is marked visited but is not yet include in the path
       cout<<path.size()<<endl;
       path.push_back(sv);  // include the vertex in the path
       for (int i=0;i<path.size();i++){ // NOTE: IF THERE IS AN EDGE BETWEEN THE LAST VERTEX AND 0TH VERTEX OF PATH THEN THAT PATH IS HAMILTONIAN CIRCUIT
           cout<<path[i]<<" ";
       }
       cout<<endl;
       path.pop_back();  // remove the vertex from the path before returning  *********IMP STEP*************
       return;
       
   }
 
 
    path.push_back(sv); // include the vertex in path
  
    for (int i=0;i<adj[sv].size();i++){
        int k = adj[sv][i];
        if ((mask&(1<<k))==0){  // write mask&(1<<K) as (mask&(1<<K))==0 bracktes are required ******IMPORTANT******
         
            hamiltonian(adj,adj[sv][i], n,mask|(1<<k), path);
           
        }
    }
   
    path.pop_back(); // remove the vertex from path


    
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    for (int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    
    vector<int> path;

// using mask to keep track of vistied vertices.set bit represents the vertex is visited, unset means not visited yet
    int mask=0;
    mask = mask | (1<<0);
    hamiltonian(adj,0,v,mask,path);
    
}







// METHOD 2 USED SET TO KEEP TRACK OF visited vertices


// #include<bits/stdc++.h>
// using namespace std;

// void hamiltonian(vector<int> adj[], int sv, int n, unordered_set<int>& visited,  vector<int>& path){
//     if (visited.size()==n-1){
//         cout<<path.size()<<endl;
//         path.push_back(sv);
//         for (int i=0;i<path.size();i++){
//             cout<<path[i]<<" ";
//         }
//         path.pop_back();
//         cout<<endl;
//         return;
//     }
 
//     visited.insert(sv);
//     path.push_back(sv);
  
//     for (int i=0;i<adj[sv].size();i++){
//         if (visited.find(adj[sv][i])==visited.end()){
//             hamiltonian(adj,adj[sv][i], n, visited, path);
//         }
//     }
   
//     path.pop_back();
//     visited.erase(sv);

    
// }
// int main(){
//     int v,e;
//     cin>>v>>e;
//     vector<int> adj[v];
//     for (int i=0;i<e;i++){
//         int f,s;
//         cin>>f>>s;
//         adj[f].push_back(s);
//         adj[s].push_back(f);
//     }
    
//     vector<int> path;

//     unordered_set<int> visited;
//     hamiltonian(adj,0,v,visited,path);
// }
