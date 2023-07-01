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
    vector<int> v; bool ans = true;
    void helper(TreeNode* root){
        if(root == NULL) return ; 
        if(root->left) helper(root->left);
        // cout<<root->val<<" ";
        v.push_back(root->val);
        if(v.size() > 1){
            if(v[v.size()-2] >= v[v.size()-1]) ans = false;
        }
        if(root->right) helper(root->right);
        
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};