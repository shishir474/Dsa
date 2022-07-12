113. Path Sum II

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

class Solution {
public:
    void solve(TreeNode* root,int ts,vector<int>& output, vector<vector<int>>& res){
        if(!root){
            return;
        }
        if(!root->left and !root->right and ts-root->val==0){
            output.push_back(root->val);
            res.push_back(output);
            output.pop_back();
            return;
        }
        
        output.push_back(root->val);
        solve(root->left,ts-root->val,output,res);    
        solve(root->right,ts-root->val,output,res);
        output.pop_back();
    
 
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> output;
        solve(root,targetSum,output,res);
        return res;
    }
};