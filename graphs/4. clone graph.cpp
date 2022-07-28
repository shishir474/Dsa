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
    void dfs(Node* node, Node* copynode, vector<Node*>& vis){
        vis[node->val]=copynode;
        for(int i=0;i<node->neighbors.size(); i++){
            if(vis[node->neighbors[i]->val]==NULL){
                Node* nn = new Node(node->neighbors[i]->val);
                copynode->neighbors.push_back(nn);
                dfs(node->neighbors[i], nn, vis);
            }
            else{
                copynode->neighbors.push_back(vis[node->neighbors[i]->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        vector<Node*> vis(102, NULL);
        Node* copynode = new Node(node->val);
        dfs(node,copynode,vis);
        
        return copynode;
    }
};