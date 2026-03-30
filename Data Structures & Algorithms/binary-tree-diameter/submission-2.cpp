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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int dia = left+right;
    int ans = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));

    return max(dia,ans);   
    }
};
/*
            1
        N       2
            3       4
        N       5 N     6        
*/