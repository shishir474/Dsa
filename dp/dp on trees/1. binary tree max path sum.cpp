The path can start and end at any node, return the max path sum:

class Solution {
public:
    int solve(TreeNode* root, int& ans){
        if(!root) return 0;
        
        int lps=solve(root->left, ans);
        int rps=solve(root->right,ans);
        
        if(lps>=0 and rps>=0)
            ans=max(ans,root->val+lps+rps);
        else if(lps>=0 and rps<0)
            ans=max(ans,root->val+lps);
        else if(rps>=0 and lps<0) // ignore leftpath value and consider rootand rightpathvalue
            ans=max(ans,root->val+rps);
        else  // both lps and rps <0 so better to just take rootvalue only
            ans=max(ans,root->val);
        
        // return root->val + max(lps,rps); is wrong, if max value is negative its better to return just root->val
        int returnvalue= root->val;
        if(max(lps,rps)>=0) returnvalue+=max(lps,rps);
        return returnvalue;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans; 
    }
};