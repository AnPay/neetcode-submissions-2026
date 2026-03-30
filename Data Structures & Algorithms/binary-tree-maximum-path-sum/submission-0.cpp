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
    int res = INT_MIN;
    int getMax(TreeNode* root)
    {
        if (!root) return 0;
        int left = getMax(root->left);
        int right = getMax(root->right);
        int path = root->val + std::max(left, right);
        return std::max(0, path);    
    }
    void dfs(TreeNode* node)
    {
        if(!node)
            return;
        int leftSum = getMax(node->left);
        int rightSum = getMax(node->right);
        res = max(res, node->val+leftSum+rightSum);
        dfs(node->left);
        dfs(node->right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
