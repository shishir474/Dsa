// gfg question test cases are incorrect:
int solve(Node* root, int& ans){
    if(!root) return 0;
    if(!root->left and !root->right) return root->data;
    int ls = solve(root->left, ans);
    int rs = solve(root->right, ans);
    
    // both left and right exists, chance of updating ans
    if(root->left and root->right){
        ans = max(ans, ls+rs+root->data);
        return max(ls,rs)+root->data;
    }
    
    return (!root->left) ? rs+root->data : ls+root->data;
}

int maxPathSum(Node* root)
{
    int ans=INT_MIN;
    
    int val = solve(root, ans);
    
    return ans==INT_MIN ? val : ans;
    
}