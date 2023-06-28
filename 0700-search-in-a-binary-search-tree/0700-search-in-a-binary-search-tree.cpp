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
    TreeNode* ans = NULL;
    void search(TreeNode* root, int val) {
        if(root==NULL) return;
        if(root->left && root->val > val) search(root->left,val);
        if(root->val == val) ans = root;
        if(root->right && root->val < val) search(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        search(root,val);
        return ans;
        // return ans;
    }
};