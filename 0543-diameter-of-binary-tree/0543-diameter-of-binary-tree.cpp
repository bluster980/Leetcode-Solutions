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
    int maxx = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root == NULL) return maxx;
        // int l = diameterOfBinaryTree(root->left);
        // int r = diameterOfBinaryTree(root->right);
        // maxx = max(maxx,l+r);
        // // diameterOfBinaryTree(root->left);
        // // diameterOfBinaryTree(root->right);
        // return 1+maxx;
        check(root);
        return maxx;
    }
    int check(TreeNode* root){
        if(root == NULL) return 0;
        int l = check(root->left);
        int r = check(root->right);
        maxx = max(maxx,l+r);
        return 1+max(l,r);
    }
};