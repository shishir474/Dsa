You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you cant move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.



class Solution {
public:
    int maxSteps = 0;
    void solve(TreeNode* root, bool isLeft,int steps){
        if (root==NULL) return;
        
        maxSteps = max(maxSteps, steps);
        
        if (isLeft){
            solve(root->left,false,steps+1); //desired
            solve(root->right,true,1);  // start new path
        }
        else{
            solve(root->right,true,steps+1); // desired
            solve(root->left,false,1); // start new path
        }
    
    }
    int longestZigZag(TreeNode* root) {
        solve(root,true,0);
        solve(root,false,0);
        return maxSteps;
    }
};