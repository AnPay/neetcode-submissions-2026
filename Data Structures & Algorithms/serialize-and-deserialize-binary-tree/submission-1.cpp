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

class Codec {
public:
    void preorder(TreeNode* node, vector<string> &data)
    {
        if(!node)
        {
            data.push_back("N"); 
            return;   
        }    
        data.push_back(to_string(node->val));
        //data.push_back(",");
        preorder(node->left,data);
        preorder(node->right,data);
    }
    TreeNode* recurUtil(vector<string> &data, int &i)
    {
        if(data[i]=="N")
        {
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(data[i]));
        i++;
        node->left = recurUtil(data,i);
        node->right = recurUtil(data,i);
        return node;
    }
    string join(vector<string>& res, string com)
    {
        stringstream s;
        for( auto &ch : res)
        {
            if(&ch != &res[0])
                s<<com;
            s<<ch;
        }
        return s.str();
    }
    vector<string> split(string &res, char com)
    {
        vector<string> nodes;
        stringstream ss(res);
        string item;
        while(getline(ss,item,com)){
            nodes.push_back(item);
        }
        return nodes;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        preorder(root,res);

        return join(res,",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data,',');
        int i =0;
        return recurUtil(nodes,i);
    }
};
