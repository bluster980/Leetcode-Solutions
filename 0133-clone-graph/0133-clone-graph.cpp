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
    void dfs(Node* node,Node* temp,vector<Node*> &vis){
        vis[temp->val] = temp;
        for(auto child:node->neighbors){
            if(vis[child->val] == NULL){
                Node* newNode = new Node(child->val);
                (temp->neighbors).push_back(newNode);
                dfs(child,newNode,vis);
            }
            else{
                (temp->neighbors).push_back(vis[child->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        vector<Node*> vis(1000,NULL);
        Node* temp = new Node(node->val);
        dfs(node,temp,vis);
        return temp;
    }
};