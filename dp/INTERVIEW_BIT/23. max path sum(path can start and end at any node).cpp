Example 1:

Input:
     10
    /  \
   2   -25
  / \  /  \
 20 1  3  4
Output: 32
Explanation: Path in the given tree goes
like 10 , 2 , 20 which gives the max
sum as 32.
Example 2:

Input:
     10
   /    \
  2      5
          \
          -2
Output: 17
Explanation: Path in the given tree goes
like 2 , 10 , 5 which gives the max sum
as 17.


Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

Input Format:

The first and the only argument contains a pointer to the root of T, A.
Output Format:

Return an integer representing the maximum sum path.
Constraints:

1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int solve(TreeNode* root, int& ans){
    if(!root) return 0;
    int ls =solve(root->left,ans);
    int rs = solve(root->right,ans);
    
    if(ls>=0 and rs>=0){
        ans = max(ans, ls+rs+root->val);
        return max(ls,rs)+root->val;
    }
    else if(ls>=0 and rs<0){
        ans = max(ans, ls+root->val);
        return ls+root->val;
    }
    else if(ls<0 and rs>=0){
        ans = max(ans, rs+root->val);
        return rs+root->val;
    }
        else if(ls<0 and rs<0){
        ans = max(ans, root->val);
        return root->val;
    }
    
}
int Solution::maxPathSum(TreeNode* root) {
    int ans=INT_MIN; // mx value can be neg. HENCe iinitialise ans with INT_MIN
    solve(root,ans);
    return ans;
}
