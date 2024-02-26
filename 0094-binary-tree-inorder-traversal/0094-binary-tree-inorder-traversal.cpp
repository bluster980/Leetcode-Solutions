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
    void intraversal(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        intraversal(root->left,v);
        v.push_back(root->val);
        intraversal(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v; intraversal(root,v);
        return v;
    }
};