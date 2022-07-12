class Solution
{
    public:
    
    bool solve(Node* root, int S){
        if(root==NULL) return false;
        if(!root->left and !root->right){
            return root->data==S;
        }
        return solve(root->left,S-root->data) || solve(root->right,S-root->data);
    }
    bool hasPathSum(Node *root, int S) {
       if(root==NULL) return S==0; // corner case handles separtely
      
       return solve(root,S);
    }
};