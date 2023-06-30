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
    TreeNode* bst(vector<int>& preorder,int &in, int lowerbound,int upperbound){
        if(preorder.size() <= in || preorder[in]<lowerbound || preorder[in]>upperbound) return NULL;
        TreeNode* root = new TreeNode(preorder[in++]);
        root->left = bst(preorder,in,lowerbound,root->val);
        root->right = bst(preorder,in,root->val,upperbound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int in = 0;
        return bst(preorder,in,INT_MIN,INT_MAX);
    }
};