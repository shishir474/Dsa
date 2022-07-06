/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator{
  stack<TreeNode*> s;
  bool reverse;
public:
  BSTIterator(TreeNode* root, bool isReverse){
      reverse = isReverse;
      pushAll(root);
  }
    
  bool hasNext(){
      return !s.empty();
  }
  
  int next(){
      TreeNode* temp = s.top(); s.pop();
      if (!reverse) pushAll(temp->right);
      else pushAll(temp->left);
      return temp->val;
  }
    
  void pushAll(TreeNode* root){
      while(root){
          s.push(root);
          if(!reverse) root = root->left;
          else root = root->right;
      }
  }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next(),j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        
        return false;
    }
};