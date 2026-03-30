/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> oldToNew;
        return dfs(node,oldToNew);    
    }
private:
    Node* dfs(Node* node, map<Node*,Node*> &oldToNew)
    {
        if(!node)
            return nullptr;
        if(oldToNew.count(node))
            return oldToNew[node];
        Node* nn = new Node(node->val);
        oldToNew[node]=nn;
        for(Node* neighbor: node->neighbors)
            nn->neighbors.push_back(dfs(neighbor,oldToNew));
        return nn;
    }
};
