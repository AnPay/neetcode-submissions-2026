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
    bool isValid(TreeNode* node, long left, long right)
    {
        if(!node)
            return true;
        if(!(left<node->val && node->val<right))
            return false;
        return isValid(node->left,left,node->val)&&
                isValid(node->right,node->val,right);
    }
    bool isValidBST(TreeNode* root) {
        // if(!root)
        //     return true;
        // bool left,right;
        // left=right=1;
        // if(root->left)
        //     left = (root->val>root->left->val)?1:0;
        // if(root->right)
        //     right = (root->val<root->right->val)?1:0;
        // return (left&&right&&isValidBST(root->left)&&isValidBST(root->right));        

        //Take a min-max range and check if val is within this value
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
