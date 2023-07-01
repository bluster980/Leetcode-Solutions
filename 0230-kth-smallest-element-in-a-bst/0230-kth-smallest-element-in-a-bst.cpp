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
    vector<int> v;
    void helper(TreeNode* root,int &k){
        if(root->left) helper(root->left,k);
        v.push_back(root->val);
        // if(v.size() == k) return;
        if(root->right) helper(root->right,k);
    }
    int kthSmallest(TreeNode* root, int &k) {
        helper(root,k);
        return v[k-1];
    }
};