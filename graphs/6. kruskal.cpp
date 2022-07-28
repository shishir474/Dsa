


#include<bits/stdc++.h>
using namespace std;
struct edges{
    int f,s,wt;
    // edges(int _f,int _s, int _wt){
    //     f = _f;
    //     s = _s;
    //     wt = _wt;
    // }
};
struct node{
    int parent, rank;
};
vector<node> dsuf;

int find(int v){
    if(dsuf[v].parent==-1){
        return v;
    }
    return dsuf[v].parent = find(dsuf[v].parent);
}

void union_op(int fromP, int toP){
    
  if (dsuf[fromP].rank > dsuf[toP].rank){
      dsuf[toP].parent=  fromP;
  } 
  else if(dsuf[fromP].rank < dsuf[toP].rank){
      dsuf[fromP].parent=  toP;
  }
  else{
       dsuf[fromP].parent=  toP;
       dsuf[toP].rank+=1;
  }
  
}

bool compare(edges a, edges b){
    return a.wt < b.wt;
}
void kruskal(edges edge_list[],int e, int v){
  vector<edges> output;
  dsuf.resize(v);
  for (int i=0;i<v;i++){
      dsuf[i].parent = -1;
      dsuf[i].rank = 0;
  }
  
  sort(edge_list, edge_list+e, compare);
  
  int count = 0;
  for (int i=0;i<e;i++){
      if (count==v-1) break;
      edges e = edge_list[i];
      int from = e.f, to = e.s, wt = e.wt;
      int fromP = find(from);
      int toP = find(to);
      if(fromP!=toP){
          count++;
          output.push_back(e);
          union_op(fromP, toP);
      }
  }
  
  for (int i=0;i<output.size();i++){
      cout<<output[i].f<<" "<<output[i].s<<" "<<output[i].wt<<endl;
  } 



    
}

int main(){
    int v,e;
    cin>>v>>e;
    edges edge_list[e];
    for (int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges e;
        e.f = f;
        e.s = s;
        e.wt = w;
        edge_list[i] = e;
        
    }
    
    kruskal(edge_list,e,v);
}

// TIME COMPLEXITY: ELOGE+ELOGV;
