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
    TreeNode* bst(vector<int> &pre,int l,int r,int &in){
        if(in>=pre.size() || pre[in]<l || pre[in]>r)
            return NULL;
        TreeNode* temp = new TreeNode(pre[in++]);
        temp->left = bst(pre,l,temp->val,in);
        temp->right = bst(pre,temp->val,r,in);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int in = 0;
        return bst(preorder,INT_MIN,INT_MAX,in);
    }
};