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
    bool temp = true;
    bool isBalanced(TreeNode* root) {
        // return 
        check(root);
        // !=-1;
        return temp;
    }
    int check(TreeNode* root){
        if(root == NULL) return 0;
        int lh = check(root->left);
        int rh = check(root->right);
        if(abs(rh-lh) > 1) temp = false;
        return 1+max(rh,lh);
    }
};