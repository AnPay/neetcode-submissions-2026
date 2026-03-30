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
    void traverse(TreeNode* node, vector<int> &nodes)
    {
        if(!node)
            return;
        traverse(node->left,nodes);
        nodes.push_back(node->val);
        traverse(node->right,nodes);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>nodes;
       traverse(root,nodes);
       return nodes[k-1];
    }
};
