class Solution {
  public:
  // subtree rooted at root is a heap iff both left and t=rigth subtree are heaps and root->value > max(root->left->data, root->right->data)
  bool isHeapUtil(struct Node* root){
        if(root==NULL) return true;
        bool lvalue = isHeapUtil(root->left);
        bool rvalue = isHeapUtil(root->right);
        if(lvalue and rvalue){
            int lmax=INT_MIN, rmax=INT_MIN;
            if(root->left){
                lmax=root->left->data;
            }
            if(root->right){
                rmax=root->right->data;
            }
            if(root->data> lmax and root->data > rmax) return true;
        }
        return false;
  }
  
  bool checkCBT(struct Node* root){
      // level order traversal
      if(root==NULL) return true;
      queue<Node*> q;
      vector<int> res;
      q.push(root);
      while(!q.empty()){
          Node* f=q.front();
          q.pop();
          if(f->left){
              q.push(f->left);
              res.push_back(f->left->data);
          }
          else{
              res.push_back(-1);
          }
          
          if(f->right){
              q.push(f->right);
              res.push_back(f->right->data);
          }
          else{
              res.push_back(-1);
          }
      }
      
      int idx;
      for(int i=0;i<res.size();i++){
          if(res[i]==-1){
              idx=i; break;
          }
      }
      
      for(int i=idx+1;i<res.size();i++){
          if(res[i] > 0) return false;
      }
      return true;
      
  }
  
  
  // IT should be CBT and follow heap order property
    bool isHeap(struct Node* root) {
        if(!checkCBT(root)) return false;
        
        return isHeapUtil(root);
    }