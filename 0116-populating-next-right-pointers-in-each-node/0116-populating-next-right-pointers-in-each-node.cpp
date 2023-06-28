/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void levelOrder(Node *temp){
        queue<Node*> q; Node *prev = temp;
        q.push(temp); q.push(NULL);
        while(!q.empty()){
            Node *top = q.front(); q.pop();
            if(top == NULL){
                if(q.empty()) break;
                q.push(NULL); prev->next = NULL;
                prev = q.front();
            }
            else{
                // cout<<top->val<<" ";
                if(prev != top)
                    {prev->next = top; prev=prev->next;}
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        // prev->next = NULL;
    }
    Node* connect(Node* root) {
        if(root==NULL) return root;
        levelOrder(root);
        return root;
    }
};