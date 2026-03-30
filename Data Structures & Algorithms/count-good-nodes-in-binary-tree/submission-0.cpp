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
private:
    int dfs(TreeNode* node, int maxSoFar)
    {
        if(!node)
            return 0;
        int count = (node->val>=maxSoFar)?1:0;  //have the local variable
        maxSoFar = max(node->val,maxSoFar);
        count+=dfs(node->left,maxSoFar);
        count+=dfs(node->right,maxSoFar);
        return count; //return local variable so that it goes as ans for every recursive call
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        return dfs(root, root->val);  
    }
};
